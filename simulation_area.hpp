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



class SimulationArea : public QOpenGLWidget, protected QOpenGLFunctions {

    public:

        SimulationArea(QWidget *parent);
        ~SimulationArea();

    protected:

        void initializeGL();
        void resizeGL(int w, int h);
        void paintGL();

};

#endif // SIMULATION_AREA_HPP
