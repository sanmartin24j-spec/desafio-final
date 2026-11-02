#ifndef CRASH_H
#define CRASH_H

class Crash
{
private:
    int vidas;
    double movimientoX;
    double movimientoY;
    double velocidadVertical;

public:
    Crash();
    void movimientoderecha(int num);
    void movimientoizquierda(int num);
    void subir (int num);
    void bajar (int num);
    void velocidadY(int num);
    void mostrarestado();


};

#endif // CRASH_H
