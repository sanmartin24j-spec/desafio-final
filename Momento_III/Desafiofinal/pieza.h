#ifndef PIEZA_H
#define PIEZA_H

class Pieza
{
private:
    double posicionX;
    double posicionY;
    bool recogida;

public:
    Pieza(double x, double y);

    bool recoger(double xCrash, double yCrash);

    bool estaRecogida() const;
};

#endif // PIEZA_H