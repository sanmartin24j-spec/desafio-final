#include "nivelaguasclaras.h"

NivelAguasClaras::NivelAguasClaras()
    : Nivel("PTAR Aguas Claras", 2),
    tiempoRestante(120.0),
    compuertasAbiertas(0),
    compuerta1(5, 5),
    compuerta2(16, 10),
    compuerta3(27, 15)
{
}

void NivelAguasClaras::iniciar()
{
    tiempoRestante = 120.0;
    compuertasAbiertas = 0;
    completado = false;

    compuerta1.reiniciar();
    compuerta2.reiniciar();
    compuerta3.reiniciar();
}

void NivelAguasClaras::actualizar(double tiempo)
{
    if (completado || tiempoRestante <= 0)
    {
        return;
    }

    tiempoRestante -= tiempo;

    if (tiempoRestante < 0)
    {
        tiempoRestante = 0;
    }
}


double NivelAguasClaras::getTiempoRestante() const
{
    return tiempoRestante;
}

int NivelAguasClaras::getCompuertasAbiertas() const
{
    return compuertasAbiertas;
}

bool NivelAguasClaras::intentarAbrirCompuerta(
    double crashX,
    double crashY)
{
    if (completado || tiempoRestante <= 0)
    {
        return false;
    }

    bool seAbrio = false;

    if (compuerta1.abrir(crashX, crashY))
    {
        seAbrio = true;
    }
    else if (compuerta2.abrir(crashX, crashY))
    {
        seAbrio = true;
    }
    else if (compuerta3.abrir(crashX, crashY))
    {
        seAbrio = true;
    }

    if (seAbrio)
    {
        compuertasAbiertas++;

        if (compuertasAbiertas == 3)
        {
            completado = true;
        }
    }

    return seAbrio;
}

const Compuerta& NivelAguasClaras::getCompuerta1() const
{
    return compuerta1;
}

const Compuerta& NivelAguasClaras::getCompuerta2() const
{
    return compuerta2;
}

const Compuerta& NivelAguasClaras::getCompuerta3() const
{
    return compuerta3;
}