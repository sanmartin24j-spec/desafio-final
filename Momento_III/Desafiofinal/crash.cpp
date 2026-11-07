#include "crash.h"
#include <iostream>

using namespace std;

Crash::Crash()
{
    movimientoX=0;
    movimientoY=0;
    vidas=3;
    velocidadVertical=0;
    gravedad=10;
    enSuelo=true;
}

void Crash::movimientoderecha(int num)
{
    movimientoX=movimientoX+num;
}

void Crash::movimientoizquierda(int num)
{
    movimientoX=movimientoX-num;
}

void Crash::subir(int num)
{
    movimientoY=movimientoY-num;
}

void Crash::bajar(int num)
{
    movimientoY=movimientoY+num;
}

void Crash::velocidadY(int num)
{
    velocidadVertical=num;
}

void Crash::actualizarvelocidad(double tiempo)
{
    velocidadVertical=velocidadVertical+gravedad*tiempo;
}

void Crash::actualizarPosicion(double tiempo)
{
    movimientoY=movimientoY+velocidadVertical*tiempo + 0.5 * gravedad * tiempo *tiempo;
}

void Crash::verificarSuelo()
{
    if (movimientoY >= 0 &&  velocidadVertical>0)
    {
        movimientoY=0;
        velocidadVertical=0;
        enSuelo=true;
    }
}

void Crash::saltar()
{
    if(enSuelo==true)
    {
        velocidadVertical=-10;
        enSuelo=false;
    }
}

void Crash::actualizarFisica(double tiempo, const Plataforma& plataforma)
{
    if (!enSuelo)
    {
        double posicionAnteriorY = movimientoY;

        actualizarPosicion(tiempo);
        actualizarvelocidad(tiempo);

        bool aterrizo = aterrizarEnPlataforma(plataforma, posicionAnteriorY);

        if (!aterrizo)
        {
            verificarSuelo();
        }
    }
}

void Crash::mostrarestado()
{
    cout<<"Posición X: "<<movimientoX<<endl;
    cout<<"Posición Y: "<<movimientoY<<endl;
    cout<<"velocidad en Y: "<<velocidadVertical<<endl;
    cout<<"vidas: "<<vidas<<endl;
}

bool Crash::aterrizarEnPlataforma(
    const Plataforma& plataforma,
    double posicionAnteriorY)
{
    bool dentroX =
        movimientoX >= plataforma.getX() &&
        movimientoX <= plataforma.getX() + plataforma.getAncho();

    bool cruzoSuperficie =
        posicionAnteriorY <= plataforma.getY() &&
        movimientoY >= plataforma.getY();

    if (dentroX && cruzoSuperficie && velocidadVertical > 0)
    {
        movimientoY = plataforma.getY();
        velocidadVertical = 0;
        enSuelo = true;
        return true;
    }

    return false;
}

void Crash::verificarApoyo(const Plataforma& plataforma)
{
    bool dentroX =
        movimientoX >= plataforma.getX() &&
        movimientoX <= plataforma.getX() + plataforma.getAncho();

    bool sobrePlataforma =
        movimientoY == plataforma.getY();

    if (enSuelo && sobrePlataforma && !dentroX)
    {
        enSuelo = false;
    }
}

double Crash::getX() const
{
    return movimientoX;
}

double Crash::getY() const
{
    return movimientoY;
}

int Crash::getVidas() const
{
    return vidas;
}

void Crash::perderVida()
{
    if (vidas > 0)
    {
        vidas--;

        if (vidas > 0)
        {
            reiniciarPosicion();
        }
    }
}

void Crash::reiniciarPosicion()
{
    movimientoX = 0;
    movimientoY = 0;
    velocidadVertical = 0;
    enSuelo = true;
}

bool Crash::estaVivo() const
{
    return vidas > 0;
}