#ifndef ARBOL_BINARIO_ORDENADO_H
#define ARBOL_BINARIO_ORDENADO_H

#include "NodoBinarioOrdenado.h"
#include <list>
#include <string>

class ArbolBinarioOrdenado {
private:
    NodoBinarioOrdenado* raiz;

public:
    ArbolBinarioOrdenado(); // CreateArbolBinarioOrdenado
    bool esVacio() ;
    void insertar(std::string codigo);
    void eliminar(std::string codigo);
    void inorden(std::list<std::string>& lista) ;
};

#include "ArbolBinarioOrdenado.hxx"

#endif