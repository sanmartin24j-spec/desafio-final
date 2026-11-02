#include <iostream>
#include "crash.h"
using namespace std;

int main()
{
    Crash crash;

    crash.movimientoderecha(5);
    crash.movimientoizquierda(2);
    crash.subir(5);
    crash.bajar(3);
    crash.velocidadY(-10);

    crash.mostrarestado();


    return 0;
}
