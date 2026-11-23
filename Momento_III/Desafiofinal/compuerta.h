#ifndef COMPUERTA_H
#define COMPUERTA_H

class Compuerta
{
private:
    double x;
    double y;
    bool abierta;

public:
    Compuerta(double posicionX, double posicionY);

    bool abrir(double crashX, double crashY);

    double getX() const;
    double getY() const;
    bool estaAbierta() const;
    void reiniciar();
};
#endif // COMPUERTA_H
