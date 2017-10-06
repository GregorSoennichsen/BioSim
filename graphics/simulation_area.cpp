/*
 * simulation_area.cpp
 *
 *  Created on: 04.10.2017
 *      Author: Gregor Soennichsen
 */

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <iostream>
#include <string>

#include "../data/tga_image.hpp"

#include "simulation_area.hpp"

using namespace std;



// Create a colored triangle

//const float vertexData[6][3] = {
//   {  0.00f,  0.75f, 1.0f },  { 1.0f, 0.0f, 0.0f },
//   { -0.75f, -0.75f, 1.0f },  { 0.0f, 1.0f, 0.0f },
//   {  0.75f, -0.75f, 1.0f },  { 0.0f, 0.0f, 1.0f }
//};

//const int positionTupelSize = 3;
//const int colorTupelSize = 3;
//const int sizeofVertex  = sizeof(float) * 6;
//const int firstPosition = sizeof(float) * 0;
//const int firstColor    = sizeof(float) * 3;
//const int numberOfVertices = 3;



// create a colored square

const float vertexData[12][3] = {

   { -0.5f,  0.5f, 1.0f },  { 1.0f, 0.0f, 0.0f },
   { -0.5f, -0.5f, 1.0f },  { 0.0f, 1.0f, 0.0f },
   {  0.5f, -0.5f, 1.0f },  { 0.0f, 0.0f, 1.0f },

   { -0.5f,  0.5f, 1.0f },  { 1.0f, 0.0f, 0.0f },
   {  0.5f, -0.5f, 1.0f },  { 0.0f, 0.0f, 1.0f },
   {  0.5f,  0.5f, 1.0f },  { 0.0f, 1.0f, 0.0f }

};


// geometry().width()  geometry().height()




const int positionTupelSize = 3;             // 3D-Coord
const int colorTupelSize = 3;                // RGB
const int sizeOfVertex  = sizeof(float) * 6; // 3D-Koord mit RGB
const int firstPosition = sizeof(float) * 0; // direkt an 0
const int firstColor    = sizeof(float) * 3; // eine 3D-Koord nach 0
const int numberOfVertices = 6;              // Anzahl (Koord, Color) Paare



// Create shader source code

const char *vertexShaderSource =
        "#version 330\n"
        "layout(location = 0) in vec3 position;\n"
        "layout(location = 1) in vec3 color;\n"
        "out vec4 vColor;\n"
        "\n"
        "void main()\n"
        "{\n"
        "  gl_Position = vec4(position, 1.0);\n"
        "  vColor = vec4(color, 1.0f);\n"
        "}\n"
        "\n";

const char *fragmentShaderSource =
        "#version 330\n"
        "in highp vec4 vColor;\n"
        "out highp vec4 fColor;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   fColor = vColor;\n"
        "}\n"
        "\n";



SimulationArea::SimulationArea(QWidget *parent) :

    QOpenGLWidget(parent),
    image(new TgaImage("ressources/terrain/shallow_water.tga"))
{
}



SimulationArea::~SimulationArea() {

    delete image;
    vertexArray.destroy();
    buffer.destroy();
    delete shaderProgram;
}



void SimulationArea::initializeGL() {

    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // build and compile shader program (Do not release until VAO is created)

    shaderProgram = new QOpenGLShaderProgram();
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    shaderProgram->link();
    shaderProgram->bind();

    // Create Buffer (Do not release until VAO is created)

//    for(int i=0; i <= geometry().width()/TILES_W; i++)        // ------------ tile position test
//        cout << i << " " << rcTOgl_x(i) << endl;

    buffer.create();
    buffer.bind();
    buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    buffer.allocate(vertexData, sizeOfVertex * numberOfVertices);

    // Create Vertex Array Object

    vertexArray.create();
    vertexArray.bind();
    shaderProgram->enableAttributeArray(0);
    shaderProgram->enableAttributeArray(1);
    shaderProgram->setAttributeBuffer(0, GL_FLOAT, firstPosition, positionTupelSize, sizeOfVertex);
    shaderProgram->setAttributeBuffer(1, GL_FLOAT, firstColor,    colorTupelSize,    sizeOfVertex);

    // Release (unbind) all

    vertexArray.release();
    buffer.release();
    shaderProgram->release();

}



void SimulationArea::resizeGL(int w, int h) {

    (void)w;
    (void)h;

}



void SimulationArea::paintGL() {

    // Clear
    glClear(GL_COLOR_BUFFER_BIT);

    // Render using our shader
    shaderProgram->bind();

    vertexArray.bind();
    glDrawArrays(GL_TRIANGLES, 0, numberOfVertices);
    vertexArray.release();

    shaderProgram->release();

}
