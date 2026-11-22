TEMPLATE = app
CONFIG += c++17
CONFIG -= console
CONFIG -= app_bundle

QT += core gui widgets

SOURCES += \
        compuerta.cpp \
        crash.cpp \
        main.cpp \
        nivel.cpp \
        nivelaguasclaras.cpp \
        nivelrio.cpp \
        obstaculo.cpp \
        pieza.cpp \
        plataforma.cpp \
        residuo.cpp \
        ventanaaguasclaras.cpp \
        ventanajuego.cpp


HEADERS += \
    compuerta.h \
    crash.h \
    nivel.h \
    nivelaguasclaras.h \
    nivelrio.h \
    obstaculo.h \
    pieza.h \
    plataforma.h \
    residuo.h \
    ventanaaguasclaras.h \
    ventanajuego.h
