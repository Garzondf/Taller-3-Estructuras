#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H

#include "NodoArbolAVL.h"
#include <list>
#include <string>

class ArbolAVL {
private:
    NodoArbolAVL* raiz;

public:
    ArbolAVL(); // CreateArbolAVL
    bool esVacio() ;
    void insertar(std::string codigo);
    void eliminar(std::string codigo);
    void inorden(std::list<std::string>& lista) ;
};

#include "ArbolAVL.hxx"

#endif