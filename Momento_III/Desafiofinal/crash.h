#ifndef CRASH_H
#define CRASH_H

#include "plataforma.h"

class Crash
{
private:
    int vidas;
    double movimientoX;
    double movimientoY;
    double velocidadVertical;
    double gravedad;
    bool enSuelo;

public:
    Crash();
    void movimientoderecha(int num);
    void movimientoizquierda(int num);
    void subir (int num);
    void bajar (int num);
    void velocidadY(int num);
    void mostrarestado();
    void actualizarvelocidad(double tiempo);
    void actualizarPosicion(double tiempo);
    void verificarSuelo();
    void saltar();
    void actualizarFisica(double tiempo, const Plataforma& plataforma);
    bool aterrizarEnPlataforma(const Plataforma& plataforma, double posicionAnteriorY);
    void verificarApoyo(const Plataforma& plataforma);
    double getX() const;
    double getY() const;
    int getVidas() const;
    void perderVida();
    void reiniciarPosicion();
    bool estaVivo() const;

};

#endif // CRASH_H
