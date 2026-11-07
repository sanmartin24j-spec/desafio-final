#include <iostream>
#include "crash.h"
#include "plataforma.h"
#include "obstaculo.h"
#include "residuo.h"
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


    /*
    Crash crash;
    Plataforma plataforma1(0, -3, 10, 1);

    crash.saltar();

    for (int i = 0; i < 5; i++)
    {
        crash.actualizarFisica(0.5, plataforma1);
        crash.mostrarestado();
    }

    crash.movimientoderecha(15);
    crash.verificarApoyo(plataforma1);

    for (int i = 0; i < 5; i++)
    {
        crash.actualizarFisica(0.5, plataforma1);
        crash.mostrarestado();
    }

    Obstaculo barrera(10, -2, 5, 1);

    for (double tiempo = 0; tiempo <= 7; tiempo += 0.5)
    {
        barrera.actualizarMovimiento(tiempo);

        cout << "Tiempo: " << tiempo
             << " | Posicion X: " << barrera.getX()
             << " | Posicion Y: " << barrera.getY()
             << endl;
    }
    */


    /*
    Crash crash;
    Obstaculo barrera(5, 0, 0, 1);

    crash.movimientoderecha(5);

    if (barrera.detectarColision(crash.getX(), crash.getY()))
    {
        cout << "Crash golpeo la barrera" << endl;
        crash.perderVida();
    }

    crash.mostrarestado();

*/

/*
    Crash crash;

    cout << "INICIO DEL NIVEL" << endl;
    crash.mostrarestado();

    for (int i = 1; i <= 3; i++)
    {
        if (crash.estaVivo())
        {
            crash.movimientoderecha(5);

            cout << "\nChoque numero: " << i << endl;

            crash.perderVida();

            crash.mostrarestado();
        }
    }

    if (!crash.estaVivo())
    {
        cout << "\nGAME OVER" << endl;
    }

*/
/*
    Residuo residuo1(5, -20, 10);

    for (int i = 0; i < 5; i++)
    {
        residuo1.actualizar(0.5);

        cout << "Tiempo: " << (i + 1) * 0.5<< " | X: " << residuo1.getX()<< " | Y: " << residuo1.getY()<< endl;
    }
*/

    Crash crash;
    Residuo residuo1(5, -20, 10);

    crash.movimientoderecha(5);

    for (int i = 0; i < 5; i++)
    {
        residuo1.actualizar(0.5);

        cout << "Tiempo: " << (i + 1) * 0.5<< " | Residuo Y: " << residuo1.getY()<< endl;

        if (residuo1.detectarColision(crash.getX(), crash.getY()))
        {
            cout << "Crash fue golpeado por un residuo" << endl;

            crash.perderVida();
            residuo1.reiniciar();

            crash.mostrarestado();
        }
    }

    return 0;
}
