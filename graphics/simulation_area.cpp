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

#include "ressourcesloc.hpp"
#include "tileManager.hpp"
#include "../data/tga_image.hpp"

#include "simulation_area.hpp"

using namespace std;



// create a textured square

float quadData[20] = {

    -0.4f, -0.4f, -1.0f,   0.0f, 0.0f,     // top left
     0.4f, -0.4f, -1.0f,   1.0f, 0.0f,     // bottom left
     0.4f,  0.4f, -1.0f,   1.0f, 1.0f,     // bottom right
    -0.4f,  0.4f, -1.0f,   0.0f, 1.0f      // top right

};

const int numberOfElemPos = 3;      // floats in Pos-3D-Coord
const int numberOfElemTex = 2;      // floats in Tex-3D-Coord

const int sizeOfVertex  = sizeof(float) * (numberOfElemPos + numberOfElemTex);      // sizeof (Pos-3D-Koord + Tex-2D-Coord)

const int offsetPos = sizeof(float) * 0;                    // direkt an 0
const int offsetTex = sizeof(float) * (numberOfElemPos);    // direkt nach der 1. Pos-3D-Koord

const int sizeOfPos = numberOfElemPos * sizeof(float);
const int sizeOfTex = numberOfElemTex * sizeof(float);

const int stridePos = sizeOfVertex;
const int strideTex = sizeOfVertex;

const int numberOfVertices = 4;                             // Anzahl (Pos, Tex) Paare



// Create shader source code

const char *vertexShaderSource =
        "#version 330 core\n"

        "layout(location = 0) in vec4 aVertexCoord;"
        "layout(location = 1) in vec4 aTexCoord;"

        "varying mediump vec4 vTexCoord;"

        "void main()"
        "{"
        "       gl_Position = aVertexCoord;"
        "       vTexCoord   = aTexCoord;"
        "}";

const char *fragmentShaderSource =
        "#version 330 core\n"

        "uniform sampler2D texSampler;"

        "varying mediump vec4 vTexCoord;"

        "void main()"
        "{"
        "       gl_FragColor = texture2D(texSampler, vTexCoord.st);"
        "}";





SimulationArea::SimulationArea(QWidget *parent) :

    QOpenGLWidget(parent),
    tileManager(0),
    texture(0)
{
}



SimulationArea::~SimulationArea() {

    vertexArray.destroy();
    buffer.destroy();
    delete shaderProgram;
}



void SimulationArea::initializeGL() {

    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    logGLVersion();

    tileManager->init();
    texture = tileManager->getTileAt(1,1)->terrainImage->texture;

    // Init Shader Programs

    shaderProgram = new QOpenGLShaderProgram();
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex,   vertexShaderSource);
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    shaderProgram->link();
    shaderProgram->bind();

    // Create Buffer and buffer Vertex Coordinates

    buffer.create();
    buffer.bind();
    buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);

    vector<float> vertexData;
    unsigned int i, x, y;

    for(i=0; i<20; i++) {
        vertexData.push_back(tileManager->getTileAt(1,1)->quadData[i] );
    }

    buffer.allocate(vertexData.data(), vertexData.size() * sizeof(float)); // sizeOfVertex * numberOfVertices

    // Create Vertex Array Object

    vertexArray.create();
    vertexArray.bind();

    // Configure Shader Input

    shaderProgram->setUniformValue("texture", 0);

    shaderProgram->enableAttributeArray(0);
    shaderProgram->enableAttributeArray(1);
    shaderProgram->setAttributeBuffer(0, GL_FLOAT, offsetPos, numberOfElemPos, stridePos);
    shaderProgram->setAttributeBuffer(1, GL_FLOAT, offsetTex, numberOfElemTex, strideTex);

    // Release all

    vertexArray.release();
    buffer.release();
    shaderProgram->release();

}



void SimulationArea::resizeGL(int w, int h) {

    (void)w;
    (void)h;

}



void SimulationArea::paintGL() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render Vertices and Textures

    shaderProgram->bind();
    vertexArray.bind();
    texture->bind();

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    texture->release();
    vertexArray.release();
    shaderProgram->release();

}
