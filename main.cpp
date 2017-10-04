/*
 * main.cpp
 *
 *  Created on: 26.09.2017
 *      Author: Gregor Soennichsen
 */

#include "mainwindow.hpp"
#include <QApplication>



/**
 * @brief main          Entry point of the program.
 * @param argc          Number of command line arguments stored in argv.
 * @param argv          Pointer on all command line arguments.
 *
 * The main function creates an QApplication object and the window, that
 * is going to display the BioSim gui.
 */
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
