#include "agenteautonomo.h"
#include <cmath>
#include <algorithm>


AgenteAutonomo::AgenteAutonomo(double posicionX,double posicionY)
    : x(posicionX),
    y(posicionY),
    velocidad(2.0),
    residuosRecolectados(0),
    objetivoX(0),
    objetivoY(0),
    objetivoActivo(false),
    patrullaDerecha(true)
{
}


void AgenteAutonomo::percibir(double residuoX, double residuoY)
{
    if (!objetivoActivo)
    {
        objetivoX = residuoX;
        objetivoY = residuoY;
        objetivoActivo = true;
    }
}

void AgenteAutonomo::razonar()
{
    if (!objetivoActivo)
    {
        return;
    }

}

void AgenteAutonomo::actuar(double tiempo)
{
    if (!objetivoActivo)
    {
        return;
    }

    double dx = objetivoX - x;
    double dy = objetivoY - y;

    double distancia = std::sqrt(dx * dx + dy * dy);

    if (distancia <= 0.2)
    {
        x = objetivoX;
        y = objetivoY;

        objetivoActivo = false;
        aprender();
        return;
    }

    double desplazamiento = velocidad * tiempo;

    if (desplazamiento >= distancia)
    {
        x = objetivoX;
        y = objetivoY;

        objetivoActivo = false;
        aprender();
        return;
    }

    x += (dx / distancia) * desplazamiento;
    y += (dy / distancia) * desplazamiento;
}


void AgenteAutonomo::aprender()
{
    residuosRecolectados++;

    velocidad = std::min(velocidad + 0.2, 4.0);
}

double AgenteAutonomo::getX() const
{
    return x;
}

double AgenteAutonomo::getY() const
{
    return y;
}

int AgenteAutonomo::getResiduosRecolectados() const
{
    return residuosRecolectados;
}

void AgenteAutonomo::patrullar(double tiempo)
{
    double desplazamiento = velocidad * tiempo;

    if (patrullaDerecha)
    {
        x += desplazamiento;

        if (x >= 29)
        {
            x = 29;
            patrullaDerecha = false;
        }
    }
    else
    {
        x -= desplazamiento;

        if (x <= 2)
        {
            x = 2;
            patrullaDerecha = true;
        }
    }
}