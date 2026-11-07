#include "plataforma.h"

Plataforma::Plataforma(double x, double y, double anchoNuevo, double altoNuevo)
{
    posX = x;
    posY = y;
    ancho = anchoNuevo;
    alto = altoNuevo;
}

double Plataforma::getX() const
{
    return posX;
}

double Plataforma::getY() const
{
    return posY;
}

double Plataforma::getAncho() const
{
    return ancho;
}

double Plataforma::getAlto() const
{
    return alto;
}