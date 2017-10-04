/*
 * ui_mainwindow.hpp
 *
 *  Created on: 03.10.2017
 *      Author: Gregor Soennichsen
 */

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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



class Ui_MainWindow
{

    public:

        QWidget *centralWidget;
        QFrame *frameMain;

        QFrame *frameCreaChoice;
        QVBoxLayout *verticalLayout_3;
        QComboBox *comboCrea;
        QFrame *frameCreaStren;
        QLabel *labelCreaStren;
        QLineEdit *lineCreaStren;
        QFrame *frameCreaSpe;
        QLabel *labelCreaSpe;
        QLineEdit *lineCreaSpe;
        QFrame *frameCreaLife;
        QLabel *labelCreaLife;
        QLineEdit *lineCreaLife;
        QFrame *frameCreaProp;
        QLabel *labelCreaProp;
        QLineEdit *lineCreaProp;
        QPushButton *buttonPlace;

        QLabel *labelStatus;

        QFrame *frameControl;
        QVBoxLayout *verticalLayout_4;
        QFrame *frameCtrlText;
        QLabel *labelCtrlText;
        QFrame *frameCtrlButtons;
        QHBoxLayout *horizontalLayout;
        QPushButton *buttonStart;
        QPushButton *buttonStop;
        QPushButton *buttonStep;

        QFrame *frameSim;
        SimulationArea *openGLSimArea;
        QScrollBar *scrollVertSim;
        QScrollBar *scrollHorizSim;

        void setupUi(QMainWindow *MainWindow);
        void setupUiCreaChoice(QFrame *frameMain);
        void setupUiStatus(QFrame *frameMain);
        void setupUiSim(QFrame *frameMain);
        void setupUiControl(QFrame *frameMain);
        void retranslateUi(QMainWindow *MainWindow);

};



namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}



#endif // UI_MAINWINDOW_H
