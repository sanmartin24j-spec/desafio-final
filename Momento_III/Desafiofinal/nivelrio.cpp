#include "nivelrio.h"
#include <iostream>

NivelRio::NivelRio()
    : Nivel("PTAR San Fernando", 1),
    tiempoTranscurrido(0),
    crash(),
    plataforma1(0, -3, 10, 1),
    barrera(10, -2, 5, 1),
    residuo1(5, -20, 10)
{}
void NivelRio::iniciar()
{
    tiempoTranscurrido = 0;
    completado = false;

    std::cout << "Iniciando nivel: " << nombre << std::endl;
}

void NivelRio::actualizar(double tiempo)
{
    tiempoTranscurrido += tiempo;

    crash.actualizarFisica(tiempo, plataforma1);
    barrera.actualizarMovimiento(tiempoTranscurrido);
    residuo1.actualizar(tiempo);

    if (residuo1.detectarColision(crash.getX(), crash.getY()))
    {
        crash.perderVida();
        residuo1.reiniciar();

        std::cout << "Crash golpeado por residuo" << std::endl;
    }
    else if (barrera.detectarColision(crash.getX(), crash.getY()))
    {
        crash.perderVida();

        std::cout << "Crash golpeado por barrera" << std::endl;
    }
}

Crash& NivelRio::getCrash()
{
    return crash;
}

void NivelRio::mostrarEstado() const
{
    std::cout << "Tiempo: " << tiempoTranscurrido << std::endl;
    std::cout << "Crash X: " << crash.getX() << std::endl;
    std::cout << "Crash Y: " << crash.getY() << std::endl;
    std::cout << "Vidas: " << crash.getVidas() << std::endl;
    std::cout << "Barrera X: " << barrera.getX() << std::endl;
    std::cout << "Residuo Y: " << residuo1.getY() << std::endl;
}