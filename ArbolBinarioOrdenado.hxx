#ifndef ARBOL_BINARIO_ORDENADO_HXX
#define ARBOL_BINARIO_ORDENADO_HXX

#include "ArbolBinarioOrdenado.h"

ArbolBinarioOrdenado::ArbolBinarioOrdenado() {
    raiz = nullptr;
}

bool ArbolBinarioOrdenado::esVacio()  {
    return raiz == nullptr;
}

void ArbolBinarioOrdenado::insertar(std::string codigo) {
    if (raiz == nullptr) {
        raiz = new NodoBinarioOrdenado(codigo);
        return;
    }
    
    NodoBinarioOrdenado* actual = raiz;
    while (true) {
        if (codigo < actual->obtenerDato()) {
            if (actual->obtenerIzquierdo() == nullptr) {
                actual->fijarIzquierdo(new NodoBinarioOrdenado(codigo));
                break;
            }
            actual = actual->obtenerIzquierdo();
        } else if (codigo > actual->obtenerDato()) {
            if (actual->obtenerDerecho() == nullptr) {
                actual->fijarDerecho(new NodoBinarioOrdenado(codigo));
                break;
            }
            actual = actual->obtenerDerecho();
        } else {
            break; // Si ya existe no hace nada
        }
    }
}

void ArbolBinarioOrdenado::eliminar(std::string codigo) {
    NodoBinarioOrdenado* actual = raiz;
    NodoBinarioOrdenado* padre = nullptr;

    while (actual != nullptr && actual->obtenerDato() != codigo) {
        padre = actual;
        if (codigo < actual->obtenerDato()) {
            actual = actual->obtenerIzquierdo();
        } else {
            actual = actual->obtenerDerecho();
        }
    }

 //falta
}

void ArbolBinarioOrdenado::inorden(std::list<std::string>& lista)  {
  //falta
}

#endif