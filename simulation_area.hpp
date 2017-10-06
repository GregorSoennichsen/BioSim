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

#include "tga_image.hpp"



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

};

#endif // SIMULATION_AREA_HPP
