#ifndef NIVELRIO_H
#define NIVELRIO_H

#include "nivel.h"
#include "crash.h"
#include "plataforma.h"
#include "obstaculo.h"
#include "residuo.h"
#include "pieza.h"

class NivelRio : public Nivel
{
private:
    double tiempoTranscurrido;

    Crash crash;
    Plataforma plataforma1;
    Obstaculo barrera;
    Residuo residuo1;
    Pieza pieza1;
    Pieza pieza2;
    Pieza pieza3;
    int piezasRecolectadas;


public:
    NivelRio();

    void iniciar() override;
    void actualizar(double tiempo) override;
    void mostrarEstado() const;
    void recogerPiezas();
    Crash& getCrash();
};

#endif // NIVELRIO_H