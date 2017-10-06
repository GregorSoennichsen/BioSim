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
    data/stringFile_manip.cpp \
    data/tga_image.cpp \
    graphics/simulation_area.cpp \
    graphics/ui_mainwindow.cpp \
    data/creaTypeManager.cpp

HEADERS  += mainwindow.hpp \
    data/stringFile_manip.hpp \
    data/tga_image.hpp \
    graphics/simulation_area.hpp \
    graphics/ui_mainwindow.hpp \
    data/creaTypeManager.hpp

FORMS    += \
    mainwindow.ui

DISTFILES += \
    ressources/creature_tiles/land/birne.tga \
    ressources/creature_tiles/land/busch.tga \
    ressources/creature_tiles/land/eiche.tga \
    ressources/creature_tiles/land/emu.tga \
    ressources/creature_tiles/land/gras.tga \
    ressources/creature_tiles/land/hund.tga \
    ressources/creature_tiles/land/kaktus.tga \
    ressources/creature_tiles/land/kuh.tga \
    ressources/creature_tiles/land/pferd.tga \
    ressources/creature_tiles/land/schaf.tga \
    ressources/creature_tiles/land/sonnenblume.tga \
    ressources/creature_tiles/land/tanne.tga \
    ressources/creature_tiles/land/tiger.tga \
    ressources/creature_tiles/land/ursus.tga \
    ressources/creature_tiles/wasser/algen.tga \
    ressources/creature_tiles/wasser/delphin.tga \
    ressources/creature_tiles/wasser/forelle.tga \
    ressources/creature_tiles/wasser/hai.tga \
    ressources/creature_tiles/wasser/krabbe.tga \
    ressources/creature_tiles/wasser/plankton.tga \
    ressources/creature_tiles/wasser/seetang.tga \
    ressources/creature_tiles/wasser/wels.tga \
    ressources/terrain/deep_sea.tga \
    ressources/terrain/earth.tga \
    ressources/terrain/rocks.tga \
    ressources/terrain/sand.tga \
    ressources/terrain/shallow_water.tga \
    ressources/terrain/snow.tga \
    ressources/CreatureTable.txt \
    ressources/CreatureTable_mitFehlern.txt \
    Qt Dlls.lnk/libEGL.dll \
    Qt Dlls.lnk/libEGLd.dll \
    Qt Dlls.lnk/libgcc_s_dw2-1.dll \
    Qt Dlls.lnk/libGLESv2.dll \
    Qt Dlls.lnk/libGLESv2d.dll \
    Qt Dlls.lnk/libstdc++-6.dll \
    Qt Dlls.lnk/libwinpthread-1.dll \
    Qt Dlls.lnk/opengl32sw.dll \
    Qt Dlls.lnk/qt.conf \
    Qt Dlls.lnk/Qt53DCore.dll \
    Qt Dlls.lnk/Qt53DCored.dll \
    Qt Dlls.lnk/Qt53DExtras.dll \
    Qt Dlls.lnk/Qt53DExtrasd.dll \
    Qt Dlls.lnk/Qt53DInput.dll \
    Qt Dlls.lnk/Qt53DInputd.dll \
    Qt Dlls.lnk/Qt53DLogic.dll \
    Qt Dlls.lnk/Qt53DLogicd.dll \
    Qt Dlls.lnk/Qt53DQuick.dll \
    Qt Dlls.lnk/Qt53DQuickd.dll \
    Qt Dlls.lnk/Qt53DQuickExtras.dll \
    Qt Dlls.lnk/Qt53DQuickExtrasd.dll \
    Qt Dlls.lnk/Qt53DQuickInput.dll \
    Qt Dlls.lnk/Qt53DQuickInputd.dll \
    Qt Dlls.lnk/Qt53DQuickRender.dll \
    Qt Dlls.lnk/Qt53DQuickRenderd.dll \
    Qt Dlls.lnk/Qt53DRender.dll \
    Qt Dlls.lnk/Qt53DRenderd.dll \
    Qt Dlls.lnk/Qt5Bluetooth.dll \
    Qt Dlls.lnk/Qt5Bluetoothd.dll \
    Qt Dlls.lnk/Qt5CLucene.dll \
    Qt Dlls.lnk/Qt5CLucened.dll \
    Qt Dlls.lnk/Qt5Concurrent.dll \
    Qt Dlls.lnk/Qt5Concurrentd.dll \
    Qt Dlls.lnk/Qt5Core.dll \
    Qt Dlls.lnk/Qt5Cored.dll \
    Qt Dlls.lnk/Qt5DBus.dll \
    Qt Dlls.lnk/Qt5DBusd.dll \
    Qt Dlls.lnk/Qt5Designer.dll \
    Qt Dlls.lnk/Qt5DesignerComponents.dll \
    Qt Dlls.lnk/Qt5DesignerComponentsd.dll \
    Qt Dlls.lnk/Qt5Designerd.dll \
    Qt Dlls.lnk/Qt5Gamepad.dll \
    Qt Dlls.lnk/Qt5Gamepadd.dll \
    Qt Dlls.lnk/Qt5Gui.dll \
    Qt Dlls.lnk/Qt5Guid.dll \
    Qt Dlls.lnk/Qt5Help.dll \
    Qt Dlls.lnk/Qt5Helpd.dll \
    Qt Dlls.lnk/Qt5Location.dll \
    Qt Dlls.lnk/Qt5Locationd.dll \
    Qt Dlls.lnk/Qt5Multimedia.dll \
    Qt Dlls.lnk/Qt5Multimediad.dll \
    Qt Dlls.lnk/Qt5MultimediaQuick_p.dll \
    Qt Dlls.lnk/Qt5MultimediaQuick_pd.dll \
    Qt Dlls.lnk/Qt5MultimediaWidgets.dll \
    Qt Dlls.lnk/Qt5MultimediaWidgetsd.dll \
    Qt Dlls.lnk/Qt5Network.dll \
    Qt Dlls.lnk/Qt5Networkd.dll \
    Qt Dlls.lnk/Qt5Nfc.dll \
    Qt Dlls.lnk/Qt5Nfcd.dll \
    Qt Dlls.lnk/Qt5OpenGL.dll \
    Qt Dlls.lnk/Qt5OpenGLd.dll \
    Qt Dlls.lnk/Qt5Positioning.dll \
    Qt Dlls.lnk/Qt5Positioningd.dll \
    Qt Dlls.lnk/Qt5PrintSupport.dll \
    Qt Dlls.lnk/Qt5PrintSupportd.dll \
    Qt Dlls.lnk/Qt5Purchasing.dll \
    Qt Dlls.lnk/Qt5Purchasingd.dll \
    Qt Dlls.lnk/Qt5Qml.dll \
    Qt Dlls.lnk/Qt5Qmld.dll \
    Qt Dlls.lnk/Qt5Quick.dll \
    Qt Dlls.lnk/Qt5QuickControls2.dll \
    Qt Dlls.lnk/Qt5QuickControls2d.dll \
    Qt Dlls.lnk/Qt5Quickd.dll \
    Qt Dlls.lnk/Qt5QuickParticles.dll \
    Qt Dlls.lnk/Qt5QuickParticlesd.dll \
    Qt Dlls.lnk/Qt5QuickTemplates2.dll \
    Qt Dlls.lnk/Qt5QuickTemplates2d.dll \
    Qt Dlls.lnk/Qt5QuickTest.dll \
    Qt Dlls.lnk/Qt5QuickTestd.dll \
    Qt Dlls.lnk/Qt5QuickWidgets.dll \
    Qt Dlls.lnk/Qt5QuickWidgetsd.dll \
    Qt Dlls.lnk/Qt5Script.dll \
    Qt Dlls.lnk/Qt5Scriptd.dll \
    Qt Dlls.lnk/Qt5ScriptTools.dll \
    Qt Dlls.lnk/Qt5ScriptToolsd.dll \
    Qt Dlls.lnk/Qt5Scxml.dll \
    Qt Dlls.lnk/Qt5Scxmld.dll \
    Qt Dlls.lnk/Qt5Sensors.dll \
    Qt Dlls.lnk/Qt5Sensorsd.dll \
    Qt Dlls.lnk/Qt5SerialBus.dll \
    Qt Dlls.lnk/Qt5SerialBusd.dll \
    Qt Dlls.lnk/Qt5SerialPort.dll \
    Qt Dlls.lnk/Qt5SerialPortd.dll \
    Qt Dlls.lnk/Qt5Sql.dll \
    Qt Dlls.lnk/Qt5Sqld.dll \
    Qt Dlls.lnk/Qt5Svg.dll \
    Qt Dlls.lnk/Qt5Svgd.dll \
    Qt Dlls.lnk/Qt5Test.dll \
    Qt Dlls.lnk/Qt5Testd.dll \
    Qt Dlls.lnk/Qt5WebChannel.dll \
    Qt Dlls.lnk/Qt5WebChanneld.dll \
    Qt Dlls.lnk/Qt5WebSockets.dll \
    Qt Dlls.lnk/Qt5WebSocketsd.dll \
    Qt Dlls.lnk/Qt5Widgets.dll \
    Qt Dlls.lnk/Qt5Widgetsd.dll \
    Qt Dlls.lnk/Qt5WinExtras.dll \
    Qt Dlls.lnk/Qt5WinExtrasd.dll \
    Qt Dlls.lnk/Qt5Xml.dll \
    Qt Dlls.lnk/Qt5Xmld.dll \
    Qt Dlls.lnk/Qt5XmlPatterns.dll \
    Qt Dlls.lnk/Qt5XmlPatternsd.dll \
    Qt Dlls.lnk/qtenv2.bat \
    Qt Dlls.lnk/assistant.exe \
    Qt Dlls.lnk/canbusutil.exe \
    Qt Dlls.lnk/designer.exe \
    Qt Dlls.lnk/dumpcpp.exe \
    Qt Dlls.lnk/dumpdoc.exe \
    Qt Dlls.lnk/idc.exe \
    Qt Dlls.lnk/lconvert.exe \
    Qt Dlls.lnk/licheck.exe \
    Qt Dlls.lnk/linguist.exe \
    Qt Dlls.lnk/lrelease.exe \
    Qt Dlls.lnk/lupdate.exe \
    Qt Dlls.lnk/moc.exe \
    Qt Dlls.lnk/pixeltool.exe \
    Qt Dlls.lnk/qcollectiongenerator.exe \
    Qt Dlls.lnk/qdbus.exe \
    Qt Dlls.lnk/qdbuscpp2xml.exe \
    Qt Dlls.lnk/qdbusviewer.exe \
    Qt Dlls.lnk/qdbusxml2cpp.exe \
    Qt Dlls.lnk/qdoc.exe \
    Qt Dlls.lnk/qgltf.exe \
    Qt Dlls.lnk/qhelpconverter.exe \
    Qt Dlls.lnk/qhelpgenerator.exe \
    Qt Dlls.lnk/qlalr.exe \
    Qt Dlls.lnk/qmake.exe \
    Qt Dlls.lnk/qml.exe \
    Qt Dlls.lnk/qmleasing.exe \
    Qt Dlls.lnk/qmlimportscanner.exe \
    Qt Dlls.lnk/qmllint.exe \
    Qt Dlls.lnk/qmlmin.exe \
    Qt Dlls.lnk/qmlplugindump.exe \
    Qt Dlls.lnk/qmlprofiler.exe \
    Qt Dlls.lnk/qmlscene.exe \
    Qt Dlls.lnk/qmltestrunner.exe \
    Qt Dlls.lnk/qscxmlc.exe \
    Qt Dlls.lnk/qtdiag.exe \
    Qt Dlls.lnk/qtpaths.exe \
    Qt Dlls.lnk/qtplugininfo.exe \
    Qt Dlls.lnk/rcc.exe \
    Qt Dlls.lnk/testcon.exe \
    Qt Dlls.lnk/uic.exe \
    Qt Dlls.lnk/windeployqt.exe \
    Qt Dlls.lnk/xmlpatterns.exe \
    Qt Dlls.lnk/xmlpatternsvalidator.exe \
    Qt Dlls.lnk/fixqt4headers.pl \
    Qt Dlls.lnk/syncqt.pl \
