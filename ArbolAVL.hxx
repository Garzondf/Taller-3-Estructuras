#ifndef ARBOL_AVL_HXX
#define ARBOL_AVL_HXX

#include "ArbolAVL.h"

ArbolAVL::ArbolAVL() {
    raiz = nullptr;
}

ArbolAVL::~ArbolAVL() {
    if (raiz != nullptr) {
        std::list<NodoAVL*> cola;
        cola.push_back(raiz);
        
        while (!cola.empty()) {
            NodoAVL* actual = cola.front();
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

bool ArbolAVL::esVacio() {
    return raiz == nullptr;
}

NodoAVL* ArbolAVL::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->obtenerHijoIzq();
    NodoAVL* T2 = x->obtenerHijoDer();

    x->fijarHijoDer(y);
    y->fijarHijoIzq(T2);

    int altIzqY = 0;
    if (y->obtenerHijoIzq() != nullptr) { altIzqY = y->obtenerHijoIzq()->obtenerAltura(); }
    int altDerY = 0;
    if (y->obtenerHijoDer() != nullptr) { altDerY = y->obtenerHijoDer()->obtenerAltura(); }
    
    if (altIzqY > altDerY) { y->fijarAltura(1 + altIzqY); } 
    else { y->fijarAltura(1 + altDerY); }

    int altIzqX = 0;
    if (x->obtenerHijoIzq() != nullptr) { altIzqX = x->obtenerHijoIzq()->obtenerAltura(); }
    int altDerX = 0;
    if (x->obtenerHijoDer() != nullptr) { altDerX = x->obtenerHijoDer()->obtenerAltura(); }

    if (altIzqX > altDerX) { x->fijarAltura(1 + altIzqX); } 
    else { x->fijarAltura(1 + altDerX); }

    return x;
}

NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->obtenerHijoDer();
    NodoAVL* T2 = y->obtenerHijoIzq();

    y->fijarHijoIzq(x);
    x->fijarHijoDer(T2);

    int altIzqX = 0;
    if (x->obtenerHijoIzq() != nullptr) { altIzqX = x->obtenerHijoIzq()->obtenerAltura(); }
    int altDerX = 0;
    if (x->obtenerHijoDer() != nullptr) { altDerX = x->obtenerHijoDer()->obtenerAltura(); }
    
    if (altIzqX > altDerX) { x->fijarAltura(1 + altIzqX); } 
    else { x->fijarAltura(1 + altDerX); }

    int altIzqY = 0;
    if (y->obtenerHijoIzq() != nullptr) { altIzqY = y->obtenerHijoIzq()->obtenerAltura(); }
    int altDerY = 0;
    if (y->obtenerHijoDer() != nullptr) { altDerY = y->obtenerHijoDer()->obtenerAltura(); }

    if (altIzqY > altDerY) { y->fijarAltura(1 + altIzqY); } 
    else { y->fijarAltura(1 + altDerY); }

    return y;
}

NodoAVL* ArbolAVL::balanceo(NodoAVL* nodo) {
    if (nodo == nullptr) { return nullptr; }

    int altIzq = 0;
    if (nodo->obtenerHijoIzq() != nullptr) { altIzq = nodo->obtenerHijoIzq()->obtenerAltura(); }
    int altDer = 0;
    if (nodo->obtenerHijoDer() != nullptr) { altDer = nodo->obtenerHijoDer()->obtenerAltura(); }

    if (altIzq > altDer) { nodo->fijarAltura(1 + altIzq); } 
    else { nodo->fijarAltura(1 + altDer); }

    int balance = altIzq - altDer;

    // Desbalance izquierda
    if (balance > 1) {
        int altIzqHijo = 0;
        int altDerHijo = 0;
        if (nodo->obtenerHijoIzq() != nullptr) {
            if (nodo->obtenerHijoIzq()->obtenerHijoIzq() != nullptr) {
                altIzqHijo = nodo->obtenerHijoIzq()->obtenerHijoIzq()->obtenerAltura();
            }
            if (nodo->obtenerHijoIzq()->obtenerHijoDer() != nullptr) {
                altDerHijo = nodo->obtenerHijoIzq()->obtenerHijoDer()->obtenerAltura();
            }
        }
        
        if (altIzqHijo - altDerHijo < 0) {
            nodo->fijarHijoIzq(rotacionIzquierda(nodo->obtenerHijoIzq()));
        }
        return rotacionDerecha(nodo);
    }

    // Desbalance derecha
    if (balance < -1) {
        int altIzqHijo = 0;
        int altDerHijo = 0;
        if (nodo->obtenerHijoDer() != nullptr) {
            if (nodo->obtenerHijoDer()->obtenerHijoIzq() != nullptr) {
                altIzqHijo = nodo->obtenerHijoDer()->obtenerHijoIzq()->obtenerAltura();
            }
            if (nodo->obtenerHijoDer()->obtenerHijoDer() != nullptr) {
                altDerHijo = nodo->obtenerHijoDer()->obtenerHijoDer()->obtenerAltura();
            }
        }
        
        if (altIzqHijo - altDerHijo > 0) {
            nodo->fijarHijoDer(rotacionDerecha(nodo->obtenerHijoDer()));
        }
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

bool ArbolAVL::insertar(std::string val) {
    if (raiz == nullptr) {
        raiz = new NodoAVL(val);
        return true;
    }

    std::list<NodoAVL*> camino; 
    NodoAVL* actual = raiz;

    while (actual != nullptr) {
        if (val == actual->obtenerDato()) { return false; }
        
        camino.push_back(actual);
        
        if (val < actual->obtenerDato()) {
            if (actual->obtenerHijoIzq() == nullptr) {
                actual->fijarHijoIzq(new NodoAVL(val));
                break;
            }
            actual = actual->obtenerHijoIzq();
        } else {
            if (actual->obtenerHijoDer() == nullptr) {
                actual->fijarHijoDer(new NodoAVL(val));
                break;
            }
            actual = actual->obtenerHijoDer();
        }
    }

    while (!camino.empty()) {
        NodoAVL* p = camino.back();
        camino.pop_back();

        NodoAVL* sub_raiz = balanceo(p);

        if (camino.empty()) {
            raiz = sub_raiz;
        } else {
            NodoAVL* padre = camino.back();
            if (padre->obtenerHijoIzq() == p) {
                padre->fijarHijoIzq(sub_raiz);
            } else {
                padre->fijarHijoDer(sub_raiz);
            }
        }
    }
    return true;
}

bool ArbolAVL::eliminar(std::string val) {
    std::list<NodoAVL*> camino;
    NodoAVL* actual = raiz;
    NodoAVL* padre = nullptr;

    while (actual != nullptr && actual->obtenerDato() != val) {
        camino.push_back(actual);
        padre = actual;
        
        if (val < actual->obtenerDato()) {
            actual = actual->obtenerHijoIzq();
        } else {
            actual = actual->obtenerHijoDer();
        }
    }

    if (actual == nullptr) { return false; }

    if (actual->obtenerHijoIzq() == nullptr || actual->obtenerHijoDer() == nullptr) {
        NodoAVL* hijo;
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
        
    } else {
        camino.push_back(actual); 
        NodoAVL* sucesor = actual->obtenerHijoDer();
        NodoAVL* padreSucesor = actual;

        while (sucesor->obtenerHijoIzq() != nullptr) {
            camino.push_back(sucesor);
            padreSucesor = sucesor;
            sucesor = sucesor->obtenerHijoIzq();
        }

        actual->fijarDato(sucesor->obtenerDato());

        NodoAVL* hijoSucesor = sucesor->obtenerHijoDer();
        
        if (padreSucesor == actual) {
            padreSucesor->fijarHijoDer(hijoSucesor);
        } else {
            padreSucesor->fijarHijoIzq(hijoSucesor);
        }
        delete sucesor;
    }

    while (!camino.empty()) {
        NodoAVL* p = camino.back();
        camino.pop_back();

        NodoAVL* sub_raiz = balanceo(p);

        if (camino.empty()) {
            raiz = sub_raiz;
        } else {
            NodoAVL* padre = camino.back();
            if (padre->obtenerHijoIzq() == p) {
                padre->fijarHijoIzq(sub_raiz);
            } else {
                padre->fijarHijoDer(sub_raiz);
            }
        }
    }
    return true;
}

void ArbolAVL::inOrden(std::list<std::string>& lista) {
    lista.clear();
    std::list<NodoAVL*> nodos_pendientes;
    NodoAVL* actual = raiz;

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