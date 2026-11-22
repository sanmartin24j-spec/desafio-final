#ifndef VENTANAAGUASCLARAS_H
#define VENTANAAGUASCLARAS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QKeyEvent>

#include "crash.h"
#include "nivelaguasclaras.h"

class VentanaAguasClaras : public QGraphicsView
{
private:
    QGraphicsScene escena;
    QGraphicsRectItem* crashGrafico;
    QGraphicsTextItem* tiempoTexto;

    QGraphicsRectItem* compuertaGrafica1;
    QGraphicsRectItem* compuertaGrafica2;
    QGraphicsRectItem* compuertaGrafica3;

    QGraphicsTextItem* compuertasTexto;
    QGraphicsTextItem* resultadoTexto;

    void actualizarCompuertas();

    QTimer temporizador;

    Crash crash;
    NivelAguasClaras nivel;

    void actualizarJuego();

protected:
    void keyPressEvent(QKeyEvent* evento) override;

public:
    VentanaAguasClaras();
};

#endif