#ifndef ARBOL_RN_HXX
#define ARBOL_RN_HXX

#include "ArbolRN.h"

bool ArbolRN::esVacio()  {
    return contenedor.empty();
}

void ArbolRN::insertar(std::string codigo) {
    contenedor.insert(codigo);
}

void ArbolRN::eliminar(std::string codigo) {
    contenedor.erase(codigo);
}

void ArbolRN::inorden(std::list<std::string>& lista)  {
    std::set<std::string>::iterator it = contenedor.begin();
    while (it != contenedor.end()) {
        lista.push_back(*it);
        ++it;
    }
}

#endif