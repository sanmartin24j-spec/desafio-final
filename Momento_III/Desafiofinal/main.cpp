#include <iostream>
#include "crash.h"
using namespace std;

int main()
{
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



    return 0;
}
