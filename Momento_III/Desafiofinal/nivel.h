#ifndef NIVEL_H
#define NIVEL_H

#include <string>

class Nivel
{
protected:
    std::string nombre;
    int dificultad;
    bool completado;

public:
    Nivel(const std::string& nombreNuevo, int dificultadNueva);

    virtual ~Nivel() = default;

    virtual void iniciar() = 0;
    virtual void actualizar(double tiempo) = 0;

    bool estaCompletado() const;
};

#endif // NIVEL_H