#ifndef ARBOL_BINARIO_ORDENADO_H
#define ARBOL_BINARIO_ORDENADO_H

#include "NodoBinario.h"
#include <list>
#include <string>

class ArbolBinarioOrdenado {
private:
    NodoBinario* raiz;

public:
    ArbolBinarioOrdenado();
    ~ArbolBinarioOrdenado();
    bool esVacio();
    bool insertar(std::string codigo);
    bool eliminar(std::string codigo);
    void inOrden(std::list<std::string>& lista);
};

#include "ArbolBinarioOrdenado.hxx"

#endif