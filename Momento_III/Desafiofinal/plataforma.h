#ifndef PLATAFORMA_H
#define PLATAFORMA_H

class Plataforma
{
private:
    double posX;
    double posY;
    double ancho;
    double alto;

public:
    Plataforma(double x, double y, double anchoNuevo, double altoNuevo);

    double getX() const;
    double getY() const;
    double getAncho() const;
    double getAlto() const;
};

#endif // PLATAFORMA_H