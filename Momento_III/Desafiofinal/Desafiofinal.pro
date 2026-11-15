TEMPLATE = app
CONFIG += c++17
CONFIG -= console
CONFIG -= app_bundle

QT += core gui widgets

SOURCES += \
        crash.cpp \
        main.cpp \
        nivel.cpp \
        nivelrio.cpp \
        obstaculo.cpp \
        pieza.cpp \
        plataforma.cpp \
        residuo.cpp \
        ventanajuego.cpp

HEADERS += \
    crash.h \
    nivel.h \
    nivelrio.h \
    obstaculo.h \
    pieza.h \
    plataforma.h \
    residuo.h \
    ventanajuego.h
