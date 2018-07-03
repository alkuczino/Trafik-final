#-------------------------------------------------
#
# Project created by QtCreator 2017-12-18T21:44:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trafff
TEMPLATE = app


SOURCES += \
    Buttons.cc \
    Camera.cc \
    Car.cc \
    Config.cc \
    Editor.cc \
    Grass.cc \
    Junction.cc \
    Map.cc \
    Moving.cc \
    NotMoving.cc \
    Pavement.cc \
    Pedestrian.cc \
    Road.cc \
    RoadVertical.cc \
    Simulator.cc \
    main.cpp

HEADERS  += \
    Buttons.h \
    Camera.h \
    Car.h \
    Config.h \
    Editor.h \
    Grass.h \
    Junction.h \
    Map.h \
    Moving.h \
    NotMoving.h \
    Pavement.h \
    Pedestrian.h \
    Road.h \
    RoadVertical.h \
    Simulator.h

FORMS    +=

DISTFILES += \
    Resources/car.png \
    Resources/road.png \
    Resources/grass.png \
    Resources/junction.png \
    Resources/roadVertical.png \
    Resources/pavement.png

RESOURCES += \
    img.qrc
