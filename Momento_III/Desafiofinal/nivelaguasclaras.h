#ifndef NIVELAGUASCLARAS_H
#define NIVELAGUASCLARAS_H

#include "nivel.h"
#include "compuerta.h"

class NivelAguasClaras : public Nivel
{
private:
    double tiempoRestante;
    int compuertasAbiertas;
    Compuerta compuerta1;
    Compuerta compuerta2;
    Compuerta compuerta3;

public:
    NivelAguasClaras();

    void iniciar() override;
    void actualizar(double tiempo) override;

    bool abrirCompuerta();

    double getTiempoRestante() const;
    int getCompuertasAbiertas() const;

    bool intentarAbrirCompuerta(double crashX, double crashY);

    const Compuerta& getCompuerta1() const;
    const Compuerta& getCompuerta2() const;
    const Compuerta& getCompuerta3() const;

};

#endif