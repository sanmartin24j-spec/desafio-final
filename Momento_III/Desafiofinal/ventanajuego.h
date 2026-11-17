#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QGraphicsView>
#include <QKeyEvent>
#include "crash.h"
#include "nivelrio.h"
#include <QGraphicsItem>
#include <QDebug>

class VentanaJuego : public QGraphicsView
{
private:
    Crash* crash;
    NivelRio* nivel;
    QGraphicsItem* crashGrafico;
    QGraphicsItem* maquinaGrafica;
    QGraphicsTextItem* victoriaTexto;

protected:
    void keyPressEvent(QKeyEvent* evento) override
    {
        if (nivel->estaCompletado() || !crash->estaVivo())
        {
            evento->accept();
            return;
        }
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
        else if (evento->key() == Qt::Key_C)
        {
            nivel->recogerPiezas();

            bool cerca =
                crashGrafico->collidesWithItem(maquinaGrafica);

            bool activada = nivel->activarMaquina(cerca);

            if (activada)
            {
                victoriaTexto->setVisible(true);
            }
        }
        QGraphicsView::keyPressEvent(evento);
    }

public:
    VentanaJuego(QGraphicsScene* escena,
    Crash* personaje,
    NivelRio* nivelActual,
    QGraphicsItem* figuraCrash,
    QGraphicsItem* figuraMaquina,
    QGraphicsTextItem* textoVictoria)
    : QGraphicsView(escena),
        crash(personaje),
        nivel(nivelActual),
        crashGrafico(figuraCrash),
        maquinaGrafica(figuraMaquina),
        victoriaTexto(textoVictoria)
    {
        setFocusPolicy(Qt::StrongFocus);
    }
};

#endif