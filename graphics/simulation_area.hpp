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
#include <QOpenGLTexture>

#include <vector>

#include "../data/tga_image.hpp"
#include "tileManager.hpp"

using namespace std;



const int TILES_X = 3;
const int TILES_Y = 3;

const int TILES_W = 32;
const int TILES_H = 32;



class SimulationArea : public QOpenGLWidget, protected QOpenGLFunctions {

    Q_OBJECT

    public:

        SimulationArea(QWidget *parent);
        ~SimulationArea();

        void setTileManager(TileManager *manager) { tileManager = manager; }

    protected:

        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;

    private:

        TileManager *tileManager;

        QOpenGLBuffer buffer;
        QOpenGLVertexArrayObject vertexArray;
        QOpenGLShaderProgram *shaderProgram;

        inline void logGLVersion() {
            // ****************** LOG ****************************
            cout << "--------" << endl;
            cout << "OpenGL Version: " << glGetString((GL_VERSION)) << endl;
            cout << "--------" << endl << endl;
            // ***************************************************
        }

};

#endif // SIMULATION_AREA_HPP
