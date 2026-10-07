#ifndef NODO_ARBOL_AVL_H
#define NODO_ARBOL_AVL_H

#include <string>

class NodoArbolAVL {
private:
    std::string dato;
    NodoArbolAVL* izquierdo;
    NodoArbolAVL* derecho;
    int altura;

public:
    NodoArbolAVL(std::string val);
    
    std::string obtenerDato() ;
    void fijarDato(std::string val);
    
    NodoArbolAVL* obtenerIzquierdo() ;
    void fijarIzquierdo(NodoArbolAVL* nodo);
    
    NodoArbolAVL* obtenerDerecho() ;
    void fijarDerecho(NodoArbolAVL* nodo);
    
    int obtenerAltura() ;
    void fijarAltura(int alt);
};

#include "NodoArbolAVL.hxx"

#endif