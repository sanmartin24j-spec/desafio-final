#include "nivelrio.h"
#include <iostream>
#include <cmath>

NivelRio::NivelRio()
    : Nivel("PTAR San Fernando", 1),
    tiempoTranscurrido(0),
    crash(),
    plataforma1(0, -3, 10, 1),
    barrera(10, -2, 5, 1),
    residuo1(5, -20, 10),
    pieza1(2, 0),
    pieza2(4, 0),
    pieza3(6, 0),
    piezasRecolectadas(0),
    maquinaX(15),
    maquinaY(-6)
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

void NivelRio::recogerPiezas()
{
    if (completado || !crash.estaVivo())
    {
        return;
    }

    if (pieza1.recoger(crash.getX(), crash.getY()))
    {
        piezasRecolectadas++;
        std::cout << "Pieza 1 recogida" << std::endl;
    }

    if (pieza2.recoger(crash.getX(), crash.getY()))
    {
        piezasRecolectadas++;
        std::cout << "Pieza 2 recogida" << std::endl;
    }

    if (pieza3.recoger(crash.getX(), crash.getY()))
    {
        piezasRecolectadas++;
        std::cout << "Pieza 3 recogida" << std::endl;
    }

    if (piezasRecolectadas == 3)
    {
        std::cout << "Todas las piezas recolectadas" << std::endl;
        std::cout << "Dirigete a la maquina central" << std::endl;
    }
}
double NivelRio::getBarreraX() const
{
    return barrera.getX();
}

double NivelRio::getBarreraY() const
{
    return barrera.getY();
}

double NivelRio::getResiduoX() const
{
    return residuo1.getX();
}

double NivelRio::getResiduoY() const
{
    return residuo1.getY();
}

void NivelRio::actualizarPeligros(double tiempo)
{
    tiempoTranscurrido += tiempo;

    barrera.actualizarMovimiento(tiempoTranscurrido);
    residuo1.actualizar(tiempo);
}

void NivelRio::recibirGolpe(bool golpeDeResiduo)
{
    if (!crash.estaVivo() || completado)
    {
        return;
    }

    crash.perderVida();

    if (golpeDeResiduo)
    {
        residuo1.reiniciar();
    }

    if (!crash.estaVivo())
    {
        std::cout << "GAME OVER" << std::endl;
    }
}

int NivelRio::getPiezasRecolectadas() const
{
    return piezasRecolectadas;
}

bool NivelRio::pieza1Recogida() const
{
    return pieza1.estaRecogida();
}

bool NivelRio::pieza2Recogida() const
{
    return pieza2.estaRecogida();
}

bool NivelRio::pieza3Recogida() const
{
    return pieza3.estaRecogida();
}

bool NivelRio::activarMaquina(bool cercaDeMaquina)
{
    if (!crash.estaVivo() || completado)
    {
        return false;
    }

    if (piezasRecolectadas < 3)
    {
        std::cout << "Faltan piezas para reparar la planta"
                  << std::endl;
        return false;
    }

    if (cercaDeMaquina)
    {
        completado = true;

        std::cout << "PLANTA REPARADA" << std::endl;
        std::cout << "NIVEL 1 COMPLETADO" << std::endl;

        return true;
    }

    std::cout << "Acercate a la maquina central"
              << std::endl;

    return false;
}

double NivelRio::getMaquinaX() const
{
    return maquinaX;
}

double NivelRio::getMaquinaY() const
{
    return maquinaY;
}