#ifndef NODO_ARBOL_AVL_HXX
#define NODO_ARBOL_AVL_HXX

#include "NodoArbolAVL.h"

NodoArbolAVL::NodoArbolAVL(std::string val) {
    dato = val;
    izquierdo = nullptr;
    derecho = nullptr;
    altura = 1; 
}

std::string NodoArbolAVL::obtenerDato()  { return dato; }
void NodoArbolAVL::fijarDato(std::string val) { dato = val; }

NodoArbolAVL* NodoArbolAVL::obtenerIzquierdo()  { return izquierdo; }
void NodoArbolAVL::fijarIzquierdo(NodoArbolAVL* nodo) { izquierdo = nodo; }

NodoArbolAVL* NodoArbolAVL::obtenerDerecho()  { return derecho; }
void NodoArbolAVL::fijarDerecho(NodoArbolAVL* nodo) { derecho = nodo; }

int NodoArbolAVL::obtenerAltura()  { return altura; }
void NodoArbolAVL::fijarAltura(int alt) { altura = alt; }

#endif