
#ifndef RESIDUO_H
#define RESIDUO_H


class Residuo
{
private:
    double posicionX;
    double posicionY;
    double alturaInicial;
    double velocidadVertical;
    double aceleracion;

public:
    Residuo(double x, double y, double aceleracionNueva);
    bool detectarColision(double xCrash, double yCrash) const;

    void actualizar(double tiempo);
    void reiniciar();

    double getX() const;
    double getY() const;
};

#endif
