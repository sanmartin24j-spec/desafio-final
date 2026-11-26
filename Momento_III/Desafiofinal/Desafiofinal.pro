TEMPLATE = app
CONFIG += c++17
CONFIG -= console
CONFIG -= app_bundle

QT += core gui widgets

SOURCES += \
        agenteautonomo.cpp \
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
    agenteautonomo.h \
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

RESOURCES += \
    recursos.qrc
