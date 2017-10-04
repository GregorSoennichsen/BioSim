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

SOURCES += main.cpp\
        mainwindow.cpp \
    creature_types.cpp \
    stringFile_manip.cpp \
    tga_image.cpp \
    ui_mainwindow.cpp \
    simulation_area.cpp

HEADERS  += mainwindow.hpp \
    creature_types.hpp \
    stringFile_manip.hpp \
    tga_image.hpp \
    ui_mainwindow.hpp \
    simulation_area.hpp

FORMS    += \
    mainwindow.ui

DISTFILES += \
    images/land/birne.tga \
    images/land/busch.tga \
    images/land/eiche.tga \
    images/land/emu.tga \
    images/land/gras.tga \
    images/land/hund.tga \
    images/land/kaktus.tga \
    images/land/kuh.tga \
    images/land/pferd.tga \
    images/land/schaf.tga \
    images/land/sonnenblume.tga \
    images/land/tanne.tga \
    images/land/tiger.tga \
    images/land/ursus.tga \
    images/wasser/algen.tga \
    images/wasser/delphin.tga \
    images/wasser/forelle.tga \
    images/wasser/hai.tga \
    images/wasser/krabbe.tga \
    images/wasser/plankton.tga \
    images/wasser/seetang.tga \
    images/wasser/wels.tga \
    CreatureTable.txt \
    CreatureTable_mitFehlern.txt
