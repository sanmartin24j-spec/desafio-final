#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QGraphicsView>
#include <QKeyEvent>
#include "crash.h"

class VentanaJuego : public QGraphicsView
{
private:
    Crash* crash;

protected:
    void keyPressEvent(QKeyEvent* evento) override
    {
        if (evento->key() == Qt::Key_Space)
        {
            crash->saltar();
        }
        else if (evento->key() == Qt::Key_D)
        {
            crash->movimientoderecha(1);
        }
        else if (evento->key() == Qt::Key_A)
        {
            crash->movimientoizquierda(1);
        }

        QGraphicsView::keyPressEvent(evento);
    }

public:
    VentanaJuego(QGraphicsScene* escena, Crash* personaje) : QGraphicsView(escena), crash(personaje)
    {
        setFocusPolicy(Qt::StrongFocus);
    }
};

#endif