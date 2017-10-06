/*
 * mainwindow.hpp
 *
 *  Created on: 03.10.2017
 *      Author: Gregor Soennichsen
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "data/creaTypeManager.hpp"

namespace Ui {
    class MainWindow;
}



/**
 * @brief MainWindow      Main class managing all processes of BioSim.
 *
 * MainWindow is the main class to handle all the application logic. It
 * manages the Qt gui and has an instance of the CreaTypeManager class.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:

        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:

        void initCreatureChoice();

        Ui::MainWindow *ui;
        CreaTypeManager *creaTypeManager;

    private slots:

        void updateCreatureInfo(QString creaName);
        void buttonPlacePressed();
        void buttonStartPressed();
        void buttonStopPressed();
        void buttonStepPressed();
        void scrollVertMoved(int newValue);
        void scrollHorizMoved(int newValue);
};



#endif // MAINWINDOW_HPP
