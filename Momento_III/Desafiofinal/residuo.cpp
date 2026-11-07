#include "residuo.h"
#include <cmath>

Residuo::Residuo(double x, double y, double aceleracionNueva)
{
    posicionX = x;
    posicionY = y;
    alturaInicial = y;
    velocidadVertical = 0;
    aceleracion = aceleracionNueva;
}

void Residuo::actualizar(double tiempo)
{
    posicionY = posicionY + velocidadVertical * tiempo + 0.5 * aceleracion * tiempo * tiempo;

    velocidadVertical = velocidadVertical + aceleracion * tiempo;

    if (posicionY >= 0)
    {
        posicionY = 0;
        velocidadVertical = 0;
    }
}

void Residuo::reiniciar()
{
    posicionY = alturaInicial;
    velocidadVertical = 0;
}

double Residuo::getX() const
{
    return posicionX;
}

double Residuo::getY() const
{
    return posicionY;
}

bool Residuo::detectarColision(double xCrash, double yCrash) const
{
    double distanciaX = std::abs(posicionX - xCrash);
    double distanciaY = std::abs(posicionY - yCrash);

    return distanciaX <= 1.0 && distanciaY <= 1.0;
}