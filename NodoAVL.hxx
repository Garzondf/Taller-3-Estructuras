#ifndef NODO_AVL_HXX
#define NODO_AVL_HXX

#include "NodoAVL.h"

NodoAVL::NodoAVL(std::string val) {
    dato = val;
    hijoIzq = nullptr;
    hijoDer = nullptr;
    altura = 1; // cada nodo empieza con altura 1
}
std::string NodoAVL::obtenerDato() { return dato; }
void NodoAVL::fijarDato(std::string val) { dato = val; }
NodoAVL* NodoAVL::obtenerHijoIzq() { return hijoIzq; }
NodoAVL* NodoAVL::obtenerHijoDer() { return hijoDer; }
void NodoAVL::fijarHijoIzq(NodoAVL* nodo) { hijoIzq = nodo; }
void NodoAVL::fijarHijoDer(NodoAVL* nodo) { hijoDer = nodo; }
int NodoAVL::obtenerAltura() { return altura; }
void NodoAVL::fijarAltura(int alt) { altura = alt; }

#endif