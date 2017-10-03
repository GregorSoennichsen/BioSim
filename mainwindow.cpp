/*
 * mainwindow.cpp
 *
 *  Created on: 03.10.2017
 *      Author: Gregor Soennichsen
 */

#include "mainwindow.hpp"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}
