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


void Crash::mostrarestado()
{
    cout<<"Posición X: "<<movimientoX<<endl;
    cout<<"Posición Y: "<<movimientoY<<endl;
    cout<<"velocidad en Y: "<<velocidadVertical<<endl;
    cout<<"vidas: "<<vidas<<endl;
}
