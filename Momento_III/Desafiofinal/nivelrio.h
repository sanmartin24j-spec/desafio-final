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
    Obstaculo barreraSuperior;
    Residuo residuo1;
    Pieza pieza1;
    Pieza pieza2;
    Pieza pieza3;
    int piezasRecolectadas;
    double maquinaX;
    double maquinaY;



public:
    NivelRio();

    void iniciar() override;
    void actualizar(double tiempo) override;
    void mostrarEstado() const;
    void recogerPiezas();
    Crash& getCrash();
    double getBarreraX() const;
    double getBarreraY() const;

    double getBarreraSuperiorX() const;
    double getBarreraSuperiorY() const;

    double getResiduoX() const;
    double getResiduoY() const;

    void actualizarPeligros(double tiempo);
    void recibirGolpe(bool golpeDeResiduo);

    int getPiezasRecolectadas() const;

    bool pieza1Recogida() const;
    bool pieza2Recogida() const;
    bool pieza3Recogida() const;
    bool activarMaquina(bool cercaDeMaquina);

    double getMaquinaX() const;
    double getMaquinaY() const;

};

#endif // NIVELRIO_H