TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    extractdata.cpp \
    creaturetypes.cpp \
    helpfunctions.cpp \
    tgaimage.cpp

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
    images/wasser/wels.tga

HEADERS += \
    extractdata.hpp \
    creaturetypes.hpp \
    helpfunctions.hpp \
    tgaimage.hpp

OTHER_FILES += \
    CreatureTable.txt \
    CreatureTable_mitFehlern.txt
