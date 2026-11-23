#ifndef AGENTEAUTONOMO_H
#define AGENTEAUTONOMO_H

class AgenteAutonomo
{
private:
    double x;
    double y;
    double velocidad;

    int residuosRecolectados;

    double objetivoX;
    double objetivoY;
    bool objetivoActivo;
    bool patrullaDerecha;

public:
    AgenteAutonomo(double posicionX, double posicionY);

    void percibir(double residuoX, double residuoY);
    void razonar();
    void actuar(double tiempo);
    void aprender();

    double getX() const;
    double getY() const;
    int getResiduosRecolectados() const;
    void patrullar(double tiempo);
};

#endif // AGENTEAUTONOMO_H
