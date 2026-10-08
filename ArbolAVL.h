#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H

#include "NodoAVL.h"
#include <list>
#include <string>

class ArbolAVL {
  protected:
    NodoAVL* raiz;
    
  public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    bool insertar(std::string val);
    bool eliminar(std::string val);
    void inOrden(std::list<std::string>& lista);
    NodoAVL* balanceo(NodoAVL* nodo);
    NodoAVL* rotacionIzquierda(NodoAVL* x);
    NodoAVL* rotacionDerecha(NodoAVL* y);
};

#include "ArbolAVL.hxx"

#endif