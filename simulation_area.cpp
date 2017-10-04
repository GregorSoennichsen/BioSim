/*
 * simulation_area.cpp
 *
 *  Created on: 04.10.2017
 *      Author: Gregor Soennichsen
 */

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "simulation_area.hpp"



SimulationArea::SimulationArea(QWidget *parent) :

    QOpenGLWidget(parent)
{

}



SimulationArea::~SimulationArea() {


}



void SimulationArea::initializeGL() {

    initializeOpenGLFunctions();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}



void SimulationArea::resizeGL(int w, int h) {


}



void SimulationArea::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT);

}
