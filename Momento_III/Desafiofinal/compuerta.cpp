#include "compuerta.h"
#include <cmath>

Compuerta::Compuerta(double posicionX, double posicionY)
    : x(posicionX),
    y(posicionY),
    abierta(false)
{
}

bool Compuerta::abrir(double crashX, double crashY)
{
    if (abierta)
    {
        return false;
    }

    double distanciaX = std::abs(crashX - x);
    double distanciaY = std::abs(crashY - y);

    if (distanciaX <= 1.5 && distanciaY <= 1.5)
    {
        abierta = true;
        return true;
    }

    return false;
}

double Compuerta::getX() const
{
    return x;
}

double Compuerta::getY() const
{
    return y;
}

bool Compuerta::estaAbierta() const
{
    return abierta;
}

void Compuerta::reiniciar()
{
    abierta = false;
}