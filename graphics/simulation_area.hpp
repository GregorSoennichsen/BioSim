/*
 * simulation_area.hpp
 *
 *  Created on: 04.10.2017
 *      Author: Gregor Soennichsen
 */

#ifndef SIMULATION_AREA_HPP
#define SIMULATION_AREA_HPP

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include "../data/tga_image.hpp"



const int TILES_X = 3;
const int TILES_Y = 3;

const int TILES_W = 32;
const int TILES_H = 32;



class SimulationArea : public QOpenGLWidget, protected QOpenGLFunctions {

    Q_OBJECT

    public:

        SimulationArea(QWidget *parent);
        ~SimulationArea();

    protected:

        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;

    private:

        TgaImage *image;

        QOpenGLBuffer buffer;
        QOpenGLVertexArrayObject vertexArray;
        QOpenGLShaderProgram *shaderProgram;

        GLuint posAttr;
        GLuint colAttr;
        GLuint matrixUniform;

        inline float rcTOgl_x(int x) {

            return ( (2 * x * TILES_W) / static_cast<float> (geometry().width()) ) - 1;

        }

};

#endif // SIMULATION_AREA_HPP
