#ifndef NODO_BINARIO_HXX
#define NODO_BINARIO_HXX

#include "NodoBinario.h"

NodoBinario::NodoBinario(std::string val) {
    dato = val;
    hijoIzq = nullptr;
    hijoDer = nullptr;
}

std::string NodoBinario::obtenerDato() {
    return dato;
}

void NodoBinario::fijarDato(std::string val) {
    dato = val;
}

NodoBinario* NodoBinario::obtenerHijoIzq() {
    return hijoIzq;
}

NodoBinario* NodoBinario::obtenerHijoDer() {
    return hijoDer;
}

void NodoBinario::fijarHijoIzq(NodoBinario* nodo) {
    hijoIzq = nodo;
}

void NodoBinario::fijarHijoDer(NodoBinario* nodo) {
    hijoDer = nodo;
}

#endif