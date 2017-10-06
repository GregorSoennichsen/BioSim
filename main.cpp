/*
 * main.cpp
 *
 *  Created on: 26.09.2017
 *      Author: Gregor Soennichsen
 */

#include "mainwindow.hpp"
#include <QApplication>

#include <iostream>
#include <stdio.h>
#include <dirent.h>




std::string current_working_directory()
{
    char* cwd = _getcwd( 0, 0 ) ; // **** microsoft specific ****
    std::string working_directory(cwd) ;
    std::free(cwd) ;
    return working_directory ;
}



/**
 * @brief main          Entry point of the program.
 * @param argc          Number of command line arguments stored in argv.
 * @param argv          Pointer on all command line arguments.
 *
 * The main function creates an QApplication object and the window, that
 * is going to display the BioSim gui.
 */
int main(int argc, char *argv[]) {

    // ****************** LOG ****************************
    cout << endl << "--------" << endl;
    cout << "Current Directory: " << current_working_directory() << endl;
    cout << "--------" << endl << endl;
    // ***************************************************

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
