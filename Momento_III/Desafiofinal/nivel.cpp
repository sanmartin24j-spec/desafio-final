#include "nivel.h"

Nivel::Nivel(const std::string& nombreNuevo, int dificultadNueva)
{
    nombre = nombreNuevo;
    dificultad = dificultadNueva;
    completado = false;
}

bool Nivel::estaCompletado() const
{
    return completado;
}