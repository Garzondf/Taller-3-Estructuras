#ifndef NODO_AVL_H
#define NODO_AVL_H

#include <string>

class NodoAVL {
  protected:
    std::string dato;
    NodoAVL* hijoIzq;
    NodoAVL* hijoDer;
    int altura;
    
  public:
    NodoAVL(std::string val);
    std::string obtenerDato();
    void fijarDato(std::string val);
    NodoAVL* obtenerHijoIzq();
    NodoAVL* obtenerHijoDer();
    void fijarHijoIzq(NodoAVL* nodo);
    void fijarHijoDer(NodoAVL* nodo);
    int obtenerAltura();
    void fijarAltura(int alt);
};

#include "NodoAVL.hxx"

#endif