#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo
{
private:
    double posicionX;
    double posicionY;
    double centroX;
    double amplitud;
    double velocidadAngular;

public:
    Obstaculo(double x, double y, double amplitudNueva, double velocidadNueva);
    bool detectarColision(double xCrash, double yCrash) const;

    void actualizarMovimiento(double tiempo);

    double getX() const;
    double getY() const;
};

#endif // OBSTACULO_H