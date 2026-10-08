#ifndef ARBOL_RN_HXX
#define ARBOL_RN_HXX

#include "ArbolRN.h"

ArbolRN::~ArbolRN() {
    RN.clear();
}

bool ArbolRN::esVacio() {
    return RN.empty();
}

void ArbolRN::insertar(std::string val) {
    RN.insert(val);
}

void ArbolRN::eliminar(std::string val) {
    RN.erase(val);
}


void ArbolRN::inOrden(std::list<std::string>& lista) {
    for (std::string valor : RN) {
        lista.push_back(valor);
    }
}

#endif