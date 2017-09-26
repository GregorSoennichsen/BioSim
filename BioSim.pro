TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    extractdata.cpp \
    creaturetypes.cpp

DISTFILES +=

HEADERS += \
    extractdata.hpp \
    creaturetypes.hpp \
    helpfunctions.hpp

OTHER_FILES += \
    CreatureTable.txt \
    CreatureTable_mitFehlern.txt
