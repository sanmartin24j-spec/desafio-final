#include "obstaculo.h"
#include <cmath>

Obstaculo::Obstaculo(double x, double y, double amplitudNueva, double velocidadNueva)
{
    posicionX = x;
    posicionY = y;
    centroX = x;
    amplitud = amplitudNueva;
    velocidadAngular = velocidadNueva;
}

void Obstaculo::actualizarMovimiento(double tiempo)
{
    posicionX = centroX + amplitud * sin(velocidadAngular * tiempo);
}

double Obstaculo::getX() const
{
    return posicionX;
}

double Obstaculo::getY() const
{
    return posicionY;
}

bool Obstaculo::detectarColision(double xCrash, double yCrash) const
{
    double distanciaX = std::abs(posicionX - xCrash);
    double distanciaY = std::abs(posicionY - yCrash);

    return distanciaX <= 1.0 && distanciaY <= 1.0;
}