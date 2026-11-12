#include "pieza.h"
#include <cmath>

Pieza::Pieza(double x, double y)
{
    posicionX = x;
    posicionY = y;
    recogida = false;
}

bool Pieza::recoger(double xCrash, double yCrash)
{
    if (recogida)
    {
        return false;
    }

    double distanciaX = std::abs(posicionX - xCrash);
    double distanciaY = std::abs(posicionY - yCrash);

    if (distanciaX <= 1.0 && distanciaY <= 1.0)
    {
        recogida = true;
        return true;
    }

    return false;
}

bool Pieza::estaRecogida() const
{
    return recogida;
}