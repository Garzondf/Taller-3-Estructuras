#ifndef NODO_BINARIO_ORDENADO_HXX
#define NODO_BINARIO_ORDENADO_HXX

#include "NodoBinarioOrdenado.h"

NodoBinarioOrdenado::NodoBinarioOrdenado(std::string val) {
    dato = val;
    izquierdo = nullptr;
    derecho = nullptr;
}

std::string NodoBinarioOrdenado::obtenerDato()  { return dato; }
void NodoBinarioOrdenado::fijarDato(std::string val) { dato = val; }

NodoBinarioOrdenado* NodoBinarioOrdenado::obtenerIzquierdo()  { return izquierdo; }
void NodoBinarioOrdenado::fijarIzquierdo(NodoBinarioOrdenado* nodo) { izquierdo = nodo; }

NodoBinarioOrdenado* NodoBinarioOrdenado::obtenerDerecho()  { return derecho; }
void NodoBinarioOrdenado::fijarDerecho(NodoBinarioOrdenado* nodo) { derecho = nodo; }

#endif