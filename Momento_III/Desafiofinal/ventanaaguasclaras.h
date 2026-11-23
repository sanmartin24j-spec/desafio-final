#ifndef VENTANAAGUASCLARAS_H
#define VENTANAAGUASCLARAS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QKeyEvent>
#include "agenteautonomo.h"
#include <vector>

#include "crash.h"
#include "nivelaguasclaras.h"

struct ResiduoNivel
{
    double x;
    double y;
    bool disponible;
    QGraphicsEllipseItem* grafico;
};

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

    AgenteAutonomo agente;

    QGraphicsEllipseItem* agenteGrafico;


    QGraphicsTextItem* agenteTexto;



    std::vector<ResiduoNivel> residuos;
    int indiceObjetivo;

    int buscarResiduoMasCercano() const;


protected:
    void keyPressEvent(QKeyEvent* evento) override;

public:
    VentanaAguasClaras();
};

#endif