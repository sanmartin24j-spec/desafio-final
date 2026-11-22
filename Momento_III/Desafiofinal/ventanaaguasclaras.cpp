#include "ventanaaguasclaras.h"

#include <QBrush>
#include <QColor>
#include <QPen>
#include <QString>
#include <QFont>

VentanaAguasClaras::VentanaAguasClaras()
    : QGraphicsView(),
    escena(0, 0, 640, 400),
    crashGrafico(nullptr),
    tiempoTexto(nullptr)


{
    setScene(&escena);
    setWindowTitle("Nivel 2 - PTAR Aguas Claras");
    setFixedSize(660, 430);
    setFocusPolicy(Qt::StrongFocus);

    nivel.iniciar();

    // Fondo del nivel
    escena.setBackgroundBrush(QColor("#D6F0F5"));

    // Representación inicial de Crash
    crashGrafico = escena.addRect(
        0, 0, 24, 32,
        QPen(Qt::NoPen),
        QBrush(QColor("#F97316"))
        );

    // Crear las tres compuertas
    compuertaGrafica1 = escena.addRect(
        0, 0, 34, 34,
        QPen(Qt::NoPen),
        QBrush(QColor("#DC2626"))
        );

    compuertaGrafica2 = escena.addRect(
        0, 0, 34, 34,
        QPen(Qt::NoPen),
        QBrush(QColor("#DC2626"))
        );

    compuertaGrafica3 = escena.addRect(
        0, 0, 34, 34,
        QPen(Qt::NoPen),
        QBrush(QColor("#DC2626"))
        );

    // Posiciones según los objetos del nivel
    compuertaGrafica1->setPos(
        nivel.getCompuerta1().getX() * 20,
        nivel.getCompuerta1().getY() * 20
        );

    compuertaGrafica2->setPos(
        nivel.getCompuerta2().getX() * 20,
        nivel.getCompuerta2().getY() * 20
        );

    compuertaGrafica3->setPos(
        nivel.getCompuerta3().getX() * 20,
        nivel.getCompuerta3().getY() * 20
        );


    compuertasTexto = escena.addText("COMPUERTAS: 0/3");
    compuertasTexto->setDefaultTextColor(QColor("#123456"));
    compuertasTexto->setPos(430, 10);
    compuertasTexto->setZValue(10);


    resultadoTexto = escena.addText("NIVEL 2 COMPLETADO");
    resultadoTexto->setDefaultTextColor(QColor("#15803D"));
    resultadoTexto->setFont(QFont("Arial", 22, QFont::Bold));
    resultadoTexto->setPos(155, 180);
    resultadoTexto->setZValue(100);
    resultadoTexto->setVisible(false);


    tiempoTexto = escena.addText("TIEMPO: 120");

    tiempoTexto->setDefaultTextColor(QColor("#123456"));
    tiempoTexto->setPos(10, 10);
    tiempoTexto->setZValue(10);

    // Actualización del nivel
    temporizador.setInterval(50);

    connect(&temporizador, &QTimer::timeout,
            this, [this]()
            {
                actualizarJuego();
            });

    temporizador.start();
}

void VentanaAguasClaras::actualizarCompuertas()
{
    if (nivel.getCompuerta1().estaAbierta())
    {
        compuertaGrafica1->setBrush(QColor("#16A34A"));
    }

    if (nivel.getCompuerta2().estaAbierta())
    {
        compuertaGrafica2->setBrush(QColor("#16A34A"));
    }

    if (nivel.getCompuerta3().estaAbierta())
    {
        compuertaGrafica3->setBrush(QColor("#16A34A"));
    }

    compuertasTexto->setPlainText(
        "COMPUERTAS: " +
        QString::number(nivel.getCompuertasAbiertas()) +
        "/3"
        );
}

void VentanaAguasClaras::keyPressEvent(QKeyEvent* evento)
{
    if (nivel.getTiempoRestante() <= 0 ||
        nivel.estaCompletado())
    {
        return;
    }

    if (evento->key() == Qt::Key_W)
    {
        crash.moverArriba(1);
    }
    else if (evento->key() == Qt::Key_S)
    {
        crash.moverAbajo(1);
    }
    else if (evento->key() == Qt::Key_A)
    {
        crash.movimientoizquierda(1);
    }
    else if (evento->key() == Qt::Key_D)
    {
        crash.movimientoderecha(1);
    }

    else if (evento->key() == Qt::Key_C)
    {
        bool abierta = nivel.intentarAbrirCompuerta(
            crash.getX(),
            crash.getY()
            );

        if (abierta)
        {
            actualizarCompuertas();
        }

        if (nivel.estaCompletado())
        {
            resultadoTexto->setVisible(true);
            temporizador.stop();
        }
    }

    crash.limitarMovimientoCenital(
        0, 30.8,
        0, 18.4
        );

    crashGrafico->setPos(
        crash.getX() * 20,
        crash.getY() * 20
        );
}

void VentanaAguasClaras::actualizarJuego()
{
    nivel.actualizar(0.05);

    tiempoTexto->setPlainText(
        "TIEMPO: " +
        QString::number(nivel.getTiempoRestante(), 'f', 1)
        );

    if (nivel.getTiempoRestante() <= 0)
    {
        temporizador.stop();

        resultadoTexto->setPlainText("TIEMPO AGOTADO");
        resultadoTexto->setDefaultTextColor(QColor("#B91C1C"));
        resultadoTexto->setVisible(true);
    }
}