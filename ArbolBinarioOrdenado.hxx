#ifndef ARBOL_BINARIO_ORDENADO_HXX
#define ARBOL_BINARIO_ORDENADO_HXX

#include "ArbolBinarioOrdenado.h"

ArbolBinarioOrdenado::ArbolBinarioOrdenado() {
    raiz = nullptr;
}

ArbolBinarioOrdenado::~ArbolBinarioOrdenado() {
    if (raiz != nullptr) {
        std::list<NodoBinario*> cola;
        cola.push_back(raiz);
        
        while (!cola.empty()) {
            NodoBinario* actual = cola.front();
            cola.pop_front();
            
            if (actual->obtenerHijoIzq() != nullptr) {
                cola.push_back(actual->obtenerHijoIzq());
            }
            if (actual->obtenerHijoDer() != nullptr) {
                cola.push_back(actual->obtenerHijoDer());
            }
            delete actual;
        }
    }
    raiz = nullptr;
}

bool ArbolBinarioOrdenado::esVacio() {
    return raiz == nullptr;
}

bool ArbolBinarioOrdenado::insertar(std::string val) {
    if (raiz == nullptr) {
        raiz = new NodoBinario(val);
        return true;
    }
    
    NodoBinario* actual = raiz;
    while (true) {
        if (val == actual->obtenerDato()) {
            return false;
        } else if (val < actual->obtenerDato()) {
            if (actual->obtenerHijoIzq() == nullptr) {
                actual->fijarHijoIzq(new NodoBinario(val));
                return true;
            }
            actual = actual->obtenerHijoIzq();
        } else {
            if (actual->obtenerHijoDer() == nullptr) {
                actual->fijarHijoDer(new NodoBinario(val));
                return true;
            }
            actual = actual->obtenerHijoDer();
        }
    }
}

bool ArbolBinarioOrdenado::eliminar(std::string val) {
    NodoBinario* actual = raiz;
    NodoBinario* padre = nullptr;

    while (actual != nullptr && actual->obtenerDato() != val) {
        padre = actual;
        if (val < actual->obtenerDato()) {
            actual = actual->obtenerHijoIzq();
        } else {
            actual = actual->obtenerHijoDer();
        }
    }

    if (actual == nullptr) return false; 

    // 0 o 1 hijo
    if (actual->obtenerHijoIzq() == nullptr || actual->obtenerHijoDer() == nullptr) {
        
        NodoBinario* hijo;
        if (actual->obtenerHijoIzq() != nullptr) {
            hijo = actual->obtenerHijoIzq();
        } else {
            hijo = actual->obtenerHijoDer();
        }
        
        if (padre == nullptr) {
            raiz = hijo;
        } else if (actual == padre->obtenerHijoIzq()) {
            padre->fijarHijoIzq(hijo);
        } else {
            padre->fijarHijoDer(hijo);
        }
        delete actual;
    } 
    // 2 hijos
    else {
        NodoBinario* sucesor = actual->obtenerHijoDer();
        NodoBinario* padreSucesor = actual;
        
        while (sucesor->obtenerHijoIzq() != nullptr) {
            padreSucesor = sucesor;
            sucesor = sucesor->obtenerHijoIzq();
        }
        
        actual->fijarDato(sucesor->obtenerDato());
        
        if (padreSucesor == actual) {
            padreSucesor->fijarHijoDer(sucesor->obtenerHijoDer());
        } else {
            padreSucesor->fijarHijoIzq(sucesor->obtenerHijoDer());
        }
        delete sucesor;
    }
    
    return true;
}

void ArbolBinarioOrdenado::inOrden(std::list<std::string>& lista) {
    lista.clear();
    std::list<NodoBinario*> nodos_pendientes;
    NodoBinario* actual = raiz;

    while (actual != nullptr || !nodos_pendientes.empty()) {
        while (actual != nullptr) {
            nodos_pendientes.push_back(actual);
            actual = actual->obtenerHijoIzq();
        }
        
        actual = nodos_pendientes.back();
        nodos_pendientes.pop_back();
        
        lista.push_back(actual->obtenerDato());
        
        actual = actual->obtenerHijoDer();
    }
}

#endif