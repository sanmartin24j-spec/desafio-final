#include "crash.h"
#include <iostream>

using namespace std;

Crash::Crash()
{
    movimientoX=0;
    movimientoY=0;
    vidas=3;
    velocidadVertical=0;
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

void Crash::mostrarestado()
{
    cout<<"Posición X: "<<movimientoX<<endl;
    cout<<"Posición Y: "<<movimientoY<<endl;
    cout<<"velocidad en Y: "<<velocidadVertical<<endl;
    cout<<"vidas: "<<vidas<<endl;
}
