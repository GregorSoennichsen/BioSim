/*
 * mainwindow.cpp
 *
 *  Created on: 03.10.2017
 *      Author: Gregor Soennichsen
 */

#include <QMessageBox>

#include <iostream>
#include <exception>
#include <string>
#include <vector>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "creature_types.hpp"

using namespace std;



/**
 * @brief MainWindow::MainWindow            Constructor to initialize BioSim.
 * @param parent                            The theoretical parent of the main window.
 *
 * The Constructor initializes the application, the gui and data as the creature types.
 * All loaded creature types are added to the creature choice combi box and the first
 * creature's data are shown. Moreover connections between several events and methods
 * are determined.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    creaTypes(new CreatureTypes("CreatureTable.txt"))
{
    ui -> setupUi(this);
    initCreatureChoice();

    connect(ui -> comboCrea,   SIGNAL(currentTextChanged(QString)), this, SLOT(updateCreatureInfo(QString)));
    connect(ui -> buttonPlace, SIGNAL(pressed()), this, SLOT(buttonPlacePressed()));
    connect(ui -> buttonStart, SIGNAL(pressed()), this, SLOT(buttonStartPressed()));
    connect(ui -> buttonStop,  SIGNAL(pressed()), this, SLOT(buttonStopPressed()));
    connect(ui -> buttonStep,  SIGNAL(pressed()), this, SLOT(buttonStepPressed()));
}



/**
 * @brief MainWindow::~MainWindow           Destructor clearing memory.
 *
 * The Destructor deletes the allocated main memory space for the ui data
 * and the creature types manager.
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete creaTypes;
}



/**
 * @brief MainWindow::initCreatureChoice    Initializes the creature choice area.
 *
 * For every creature type stored in the creature types manager an entry in the
 * combo box is made. If at least one type exists, the data belonging to the first
 * type of all is shown in the informations area.
 */
void MainWindow::initCreatureChoice() {

    vector<string> creaTypesNames = creaTypes->getTypeNames();

    unsigned int i;
    for(i=0; i < creaTypesNames.size(); i++)
        ui -> comboCrea -> addItem( QString(creaTypesNames[i].c_str()) );

    if(creaTypesNames.size() > 0)
        updateCreatureInfo( QString(creaTypesNames[0].c_str()) );

}



/**
 * @brief MainWindow::updateCreatureInfo    Shows the data of one creature type.
 * @param creaName                          Creature type whose informations shall be displayed.
 *
 * Gets the informations belonging to a creature type and updates the relevant gui elements.
 * This method is in addition connected to the 'currentTextChanged' event of the combo box with
 * the result that every time a new creature type is chosen, the right informations are displayed.
 * Throws runtime error, if a name could not be found.
 */
void MainWindow::updateCreatureInfo(QString creaName) {

    try {

        CreaTyp type = creaTypes -> getTypeInfo(creaName.toStdString());

        ui -> lineCreaStren -> setText( QString(to_string(type.strength).c_str()) );
        ui -> lineCreaSpe   -> setText( QString(to_string(type.speed).c_str()) );
        ui -> lineCreaLife  -> setText( QString(to_string(type.lifetime).c_str()) );

        string props;
        for(const string &s : type.properities)
            props += s + " ";

        ui -> lineCreaProp  -> setText( QString(props.c_str()) );

    }

    catch(const runtime_error &e) {
        throw runtime_error("creature type name: '" + creaName.toStdString() +
                            "' could not be found while updating info area");
    }
}



/**
 * @brief MainWindow::buttonPlacePressed    Defines the reaction when the 'place' button is pressed.
 *
 * Shows a message box, that tells the user, he has clicked the 'place' button.
 */
void MainWindow::buttonPlacePressed() {

    QMessageBox::question(this, "Button pressed", "The place button was clicked", QMessageBox::Ok);

}



/**
 * @brief MainWindow::buttonStartPressed    Defines the reaction when the 'start' button is pressed.
 *
 * Shows a message box, that tells the user, he has clicked the 'start' button.
 */
void MainWindow::buttonStartPressed() {

    QMessageBox::question(this, "Button pressed", "The start button was clicked", QMessageBox::Ok);

}



/**
 * @brief MainWindow::buttonStopPressed     Defines the reaction when the 'stop' button is pressed.
 *
 * Shows a message box, that tells the user, he has clicked the 'stop' button.
 */
void MainWindow::buttonStopPressed() {

    QMessageBox::question(this, "Button pressed", "The stop button was clicked", QMessageBox::Ok);

}



/**
 * @brief MainWindow::buttonStepPressed    Defines the reaction when the 'step' button is pressed.
 *
 * Shows a message box, that tells the user, he has clicked the 'step' button.
 */
void MainWindow::buttonStepPressed() {

    QMessageBox::question(this, "Button pressed", "The step button was clicked", QMessageBox::Ok);

}
