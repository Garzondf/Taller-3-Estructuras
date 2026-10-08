#ifndef NODO_BINARIO_H
#define NODO_BINARIO_H

#include <string>

class NodoBinario {
  protected:
    std::string dato;
    NodoBinario* hijoIzq;
    NodoBinario* hijoDer;
    
  public:
    NodoBinario(std::string val);
    std::string obtenerDato();
    void fijarDato(std::string val);
    NodoBinario* obtenerHijoIzq();
    NodoBinario* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario* nodo);
    void fijarHijoDer(NodoBinario* nodo);
};

#include "NodoBinario.hxx"

#endif