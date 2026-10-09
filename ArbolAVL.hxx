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

    int AIzqY = 0;
    if (y->obtenerHijoIzq() != nullptr) { AIzqY = y->obtenerHijoIzq()->obtenerAltura(); }
    int ADerY = 0;
    if (y->obtenerHijoDer() != nullptr) { ADerY = y->obtenerHijoDer()->obtenerAltura(); }
    
    if (AIzqY > ADerY) { y->fijarAltura(1 + AIzqY); } 
    else { y->fijarAltura(1 + ADerY); }

    int AIzqX = 0;
    if (x->obtenerHijoIzq() != nullptr) { AIzqX = x->obtenerHijoIzq()->obtenerAltura(); }
    int ADerX = 0;
    if (x->obtenerHijoDer() != nullptr) { ADerX = x->obtenerHijoDer()->obtenerAltura(); }

    if (AIzqX > ADerX) { x->fijarAltura(1 + AIzqX); } 
    else { x->fijarAltura(1 + ADerX); }

    return x;
}

NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->obtenerHijoDer();
    NodoAVL* T2 = y->obtenerHijoIzq();

    y->fijarHijoIzq(x);
    x->fijarHijoDer(T2);

    int AIzqX = 0;
    if (x->obtenerHijoIzq() != nullptr) { AIzqX = x->obtenerHijoIzq()->obtenerAltura(); }
    int ADerX = 0;
    if (x->obtenerHijoDer() != nullptr) { ADerX = x->obtenerHijoDer()->obtenerAltura(); }
    
    if (AIzqX > ADerX) { x->fijarAltura(1 + AIzqX); } 
    else { x->fijarAltura(1 + ADerX); }

    int AIzqY = 0;
    if (y->obtenerHijoIzq() != nullptr) { AIzqY = y->obtenerHijoIzq()->obtenerAltura(); }
    int ADerY = 0;
    if (y->obtenerHijoDer() != nullptr) { ADerY = y->obtenerHijoDer()->obtenerAltura(); }

    if (AIzqY > ADerY) { y->fijarAltura(1 + AIzqY); } 
    else { y->fijarAltura(1 + ADerY); }

    return y;
}

NodoAVL* ArbolAVL::balanceo(NodoAVL* nodo) {
    if (nodo == nullptr) { return nullptr; }

    int AIzq = 0;
    if (nodo->obtenerHijoIzq() != nullptr) { AIzq = nodo->obtenerHijoIzq()->obtenerAltura(); }
    int ADer = 0;
    if (nodo->obtenerHijoDer() != nullptr) { ADer = nodo->obtenerHijoDer()->obtenerAltura(); }

    if (AIzq > ADer) { nodo->fijarAltura(1 + AIzq); } 
    else { nodo->fijarAltura(1 + ADer); }

    int balance = AIzq - ADer;

    //izquierda
    if (balance > 1) {
        int AIzqHijo = 0;
        int ADerHijo = 0;
        if (nodo->obtenerHijoIzq() != nullptr) {
            if (nodo->obtenerHijoIzq()->obtenerHijoIzq() != nullptr) {
                AIzqHijo = nodo->obtenerHijoIzq()->obtenerHijoIzq()->obtenerAltura();
            }
            if (nodo->obtenerHijoIzq()->obtenerHijoDer() != nullptr) {
                ADerHijo = nodo->obtenerHijoIzq()->obtenerHijoDer()->obtenerAltura();
            }
        }
        
        if (AIzqHijo - ADerHijo < 0) {
            nodo->fijarHijoIzq(rotacionIzquierda(nodo->obtenerHijoIzq()));
        }
        return rotacionDerecha(nodo);
    }

    //derecha
    if (balance < -1) {
        int AIzqHijo = 0;
        int ADerHijo = 0;
        if (nodo->obtenerHijoDer() != nullptr) {
            if (nodo->obtenerHijoDer()->obtenerHijoIzq() != nullptr) {
                AIzqHijo = nodo->obtenerHijoDer()->obtenerHijoIzq()->obtenerAltura();
            }
            if (nodo->obtenerHijoDer()->obtenerHijoDer() != nullptr) {
                ADerHijo = nodo->obtenerHijoDer()->obtenerHijoDer()->obtenerAltura();
            }
        }
        
        if (AIzqHijo - ADerHijo > 0) {
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