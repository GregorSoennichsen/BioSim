/*
 * ui_mainwindow.cpp
 *
 *  Created on: 04.10.2017
 *      Author: Gregor Soennichsen
 */

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "simulation_area.hpp"

#include "ui_mainwindow.hpp"



void Ui_MainWindow::setupUi(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));
    MainWindow->resize(711, 440);
    MainWindow->setMinimumSize(QSize(711, 440));
    MainWindow->setMaximumSize(QSize(711, 440));
    MainWindow->setStyleSheet(QStringLiteral(""));

    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    frameMain = new QFrame(centralWidget);
    frameMain->setObjectName(QStringLiteral("frameMain"));
    frameMain->setGeometry(QRect(0, 0, 711, 451));
    frameMain->setStyleSheet(QStringLiteral("QFrame#frameMain { background-color: lightgrey }"));
    frameMain->setFrameShape(QFrame::NoFrame);
    frameMain->setFrameShadow(QFrame::Plain);

    setupUiCreaChoice(frameMain);
    setupUiStatus(frameMain);
    setupUiControl(frameMain);
    setupUiSim(frameMain);

    MainWindow->setCentralWidget(centralWidget);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);

}



void Ui_MainWindow::setupUiCreaChoice(QFrame *frameMain) {

    frameCreaChoice = new QFrame(frameMain);
    frameCreaChoice->setObjectName(QStringLiteral("frameCreaChoice"));
    frameCreaChoice->setGeometry(QRect(410, 20, 281, 261));
    frameCreaChoice->setAutoFillBackground(false);
    frameCreaChoice->setStyleSheet(QStringLiteral("QFrame#frameCreaChoice { background-color: rgb(240, 240, 240)}"));
    frameCreaChoice->setFrameShape(QFrame::StyledPanel);
    frameCreaChoice->setFrameShadow(QFrame::Plain);

    verticalLayout_3 = new QVBoxLayout(frameCreaChoice);
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setContentsMargins(11, 11, 11, 11);
    verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

    comboCrea = new QComboBox(frameCreaChoice);
    comboCrea->setObjectName(QStringLiteral("comboCrea"));

    verticalLayout_3->addWidget(comboCrea);

    frameCreaStren = new QFrame(frameCreaChoice);
    frameCreaStren->setObjectName(QStringLiteral("frameCreaStren"));
    frameCreaStren->setFrameShape(QFrame::StyledPanel);
    frameCreaStren->setFrameShadow(QFrame::Raised);
    labelCreaStren = new QLabel(frameCreaStren);
    labelCreaStren->setObjectName(QStringLiteral("labelCreaStren"));
    labelCreaStren->setGeometry(QRect(10, 10, 101, 16));
    lineCreaStren = new QLineEdit(frameCreaStren);
    lineCreaStren->setObjectName(QStringLiteral("lineCreaStren"));
    lineCreaStren->setGeometry(QRect(120, 10, 133, 20));
    lineCreaStren->setReadOnly(true);

    verticalLayout_3->addWidget(frameCreaStren);

    frameCreaSpe = new QFrame(frameCreaChoice);
    frameCreaSpe->setObjectName(QStringLiteral("frameCreaSpe"));
    frameCreaSpe->setFrameShape(QFrame::StyledPanel);
    frameCreaSpe->setFrameShadow(QFrame::Raised);
    labelCreaSpe = new QLabel(frameCreaSpe);
    labelCreaSpe->setObjectName(QStringLiteral("labelCreaSpe"));
    labelCreaSpe->setGeometry(QRect(10, 10, 101, 16));
    lineCreaSpe = new QLineEdit(frameCreaSpe);
    lineCreaSpe->setObjectName(QStringLiteral("lineCreaSpe"));
    lineCreaSpe->setGeometry(QRect(120, 10, 133, 20));
    lineCreaSpe->setReadOnly(true);

    verticalLayout_3->addWidget(frameCreaSpe);

    frameCreaLife = new QFrame(frameCreaChoice);
    frameCreaLife->setObjectName(QStringLiteral("frameCreaLife"));
    frameCreaLife->setFrameShape(QFrame::StyledPanel);
    frameCreaLife->setFrameShadow(QFrame::Raised);
    labelCreaLife = new QLabel(frameCreaLife);
    labelCreaLife->setObjectName(QStringLiteral("labelCreaLife"));
    labelCreaLife->setGeometry(QRect(10, 10, 101, 16));
    lineCreaLife = new QLineEdit(frameCreaLife);
    lineCreaLife->setObjectName(QStringLiteral("lineCreaLife"));
    lineCreaLife->setGeometry(QRect(120, 10, 133, 20));
    lineCreaLife->setReadOnly(true);

    verticalLayout_3->addWidget(frameCreaLife);

    frameCreaProp = new QFrame(frameCreaChoice);
    frameCreaProp->setObjectName(QStringLiteral("frameCreaProp"));
    frameCreaProp->setFrameShape(QFrame::StyledPanel);
    frameCreaProp->setFrameShadow(QFrame::Raised);
    labelCreaProp = new QLabel(frameCreaProp);
    labelCreaProp->setObjectName(QStringLiteral("labelCreaProp"));
    labelCreaProp->setGeometry(QRect(10, 10, 101, 16));
    lineCreaProp = new QLineEdit(frameCreaProp);
    lineCreaProp->setObjectName(QStringLiteral("lineCreaProp"));
    lineCreaProp->setGeometry(QRect(120, 10, 133, 20));
    lineCreaProp->setReadOnly(true);

    verticalLayout_3->addWidget(frameCreaProp);

    buttonPlace = new QPushButton(frameCreaChoice);
    buttonPlace->setObjectName(QStringLiteral("buttonPlace"));

    verticalLayout_3->addWidget(buttonPlace, 0, Qt::AlignRight);

}



void Ui_MainWindow::setupUiStatus(QFrame *frameMain) {

    labelStatus = new QLabel(frameMain);
    labelStatus->setObjectName(QStringLiteral("labelStatus"));
    labelStatus->setGeometry(QRect(20, 410, 671, 20));
    labelStatus->setAutoFillBackground(false);
    labelStatus->setStyleSheet(QStringLiteral("QLabel { background-color:rgb(156, 179, 191) }"));
    labelStatus->setFrameShape(QFrame::StyledPanel);
    labelStatus->setFrameShadow(QFrame::Plain);
    labelStatus->setAlignment(Qt::AlignCenter);

}



void Ui_MainWindow::setupUiSim(QFrame *frameMain) {

    frameSim = new QFrame(frameMain);
    frameSim->setObjectName(QStringLiteral("frameSim"));
    frameSim->setGeometry(QRect(20, 20, 371, 371));
    frameSim->setStyleSheet(QStringLiteral(""));
    frameSim->setFrameShape(QFrame::NoFrame);
    frameSim->setFrameShadow(QFrame::Plain);

    openGLSimArea = new SimulationArea(frameSim);
    openGLSimArea->setObjectName(QStringLiteral("openGLSimArea"));
    openGLSimArea->setGeometry(QRect(0, 0, 351, 351));

    scrollVertSim = new QScrollBar(frameSim);
    scrollVertSim->setObjectName(QStringLiteral("scrollVertSim"));
    scrollVertSim->setGeometry(QRect(350, 0, 20, 351));
    scrollVertSim->setOrientation(Qt::Vertical);
    scrollHorizSim = new QScrollBar(frameSim);
    scrollHorizSim->setObjectName(QStringLiteral("scrollHorizSim"));
    scrollHorizSim->setGeometry(QRect(0, 350, 351, 20));
    scrollHorizSim->setOrientation(Qt::Horizontal);

}



void Ui_MainWindow::setupUiControl(QFrame *frameMain) {

    frameControl = new QFrame(frameMain);
    frameControl->setObjectName(QStringLiteral("frameControl"));
    frameControl->setGeometry(QRect(410, 300, 281, 91));
    frameControl->setStyleSheet(QStringLiteral("QFrame#frameControl { background-color: rgb(240, 240, 240) }"));
    frameControl->setFrameShape(QFrame::StyledPanel);
    frameControl->setFrameShadow(QFrame::Plain);
    frameControl->setLineWidth(1);
    verticalLayout_4 = new QVBoxLayout(frameControl);
    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setContentsMargins(11, 11, 11, 11);
    verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
    frameCtrlText = new QFrame(frameControl);
    frameCtrlText->setObjectName(QStringLiteral("frameCtrlText"));
    frameCtrlText->setFrameShape(QFrame::StyledPanel);
    frameCtrlText->setFrameShadow(QFrame::Raised);
    labelCtrlText = new QLabel(frameCtrlText);
    labelCtrlText->setObjectName(QStringLiteral("labelCtrlText"));
    labelCtrlText->setGeometry(QRect(10, 0, 106, 13));

    verticalLayout_4->addWidget(frameCtrlText);

    frameCtrlButtons = new QFrame(frameControl);
    frameCtrlButtons->setObjectName(QStringLiteral("frameCtrlButtons"));
    frameCtrlButtons->setFrameShape(QFrame::StyledPanel);
    frameCtrlButtons->setFrameShadow(QFrame::Raised);
    horizontalLayout = new QHBoxLayout(frameCtrlButtons);
    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    buttonStart = new QPushButton(frameCtrlButtons);
    buttonStart->setObjectName(QStringLiteral("buttonStart"));

    horizontalLayout->addWidget(buttonStart);

    buttonStop = new QPushButton(frameCtrlButtons);
    buttonStop->setObjectName(QStringLiteral("buttonStop"));

    horizontalLayout->addWidget(buttonStop);

    buttonStep = new QPushButton(frameCtrlButtons);
    buttonStep->setObjectName(QStringLiteral("buttonStep"));

    horizontalLayout->addWidget(buttonStep);

    verticalLayout_4->addWidget(frameCtrlButtons);

}



void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow) {

    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BioSim", 0));
    labelCreaStren->setText(QApplication::translate("MainWindow", "St\303\244rke:", 0));
    labelCreaSpe->setText(QApplication::translate("MainWindow", "Geschwindigkeit:", 0));
    labelCreaLife->setText(QApplication::translate("MainWindow", "Leben:", 0));
    labelCreaProp->setText(QApplication::translate("MainWindow", "Eigenschaften:", 0));
    buttonPlace->setText(QApplication::translate("MainWindow", "Platzieren", 0));
    labelStatus->setText(QApplication::translate("MainWindow", "Statusleiste", 0));
    labelCtrlText->setText(QApplication::translate("MainWindow", "Simulationssteuerung:", 0));
    buttonStart->setText(QApplication::translate("MainWindow", "Start", 0));
    buttonStop->setText(QApplication::translate("MainWindow", "Stopp", 0));
    buttonStep->setText(QApplication::translate("MainWindow", "Schritt", 0));

}
