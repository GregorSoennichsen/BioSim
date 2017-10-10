#-------------------------------------------------
#
# Project created by QtCreator 2017-10-03T12:27:24
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BioSimQt
TEMPLATE = app

LIBS   += -lopengl32
LIBS   += -lglu32
LIBS   += -lglut32

SOURCES +=\
        mainwindow.cpp \
    data/stringFile_manip.cpp \
    data/tga_image.cpp \
    graphics/simulation_area.cpp \
    graphics/ui_mainwindow.cpp \
    data/creaTypeManager.cpp \
    graphics/tileManager.cpp \
    main.cpp

HEADERS  += mainwindow.hpp \
    data/stringFile_manip.hpp \
    data/tga_image.hpp \
    graphics/simulation_area.hpp \
    graphics/ui_mainwindow.hpp \
    data/creaTypeManager.hpp \
    graphics/tileManager.hpp \
    ressourcesloc.hpp

FORMS    += \
    mainwindow.ui

RESOURCES +=
