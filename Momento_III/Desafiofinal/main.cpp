#include <iostream>
#include "crash.h"
using namespace std;

int main()
{
    /*
    Crash crash;

    crash.saltar();
    crash.saltar();

    for (int i = 0; i < 5; i++)
    {
        crash.actualizarPosicion(0.5);
        crash.actualizarvelocidad(0.5);
        crash.verificarSuelo();
        crash.mostrarestado();
    }

    crash.saltar();

    for (int i = 0; i < 5; i++)
    {
        crash.actualizarPosicion(0.5);
        crash.actualizarvelocidad(0.5);
        crash.verificarSuelo();
        crash.mostrarestado();
    }
    */

    Plataforma plataforma1(0, -3, 10, 1);

    cout << "Plataforma creada" << endl;
    cout << "X: " << plataforma1.getX() << endl;
    cout << "Y: " << plataforma1.getY() << endl;
    cout << "Ancho: " << plataforma1.getAncho() << endl;
    cout << "Alto: " << plataforma1.getAlto() << endl;



    return 0;
}
