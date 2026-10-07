#ifndef ARBOL_RN_H
#define ARBOL_RN_H

#include <set>
#include <list>
#include <string>

class ArbolRN {
private:
    std::set<std::string> contenedor;

public:
    bool esVacio() ;
    void insertar(std::string codigo);
    void eliminar(std::string codigo);
    void inorden(std::list<std::string>& lista) ;
};

#include "ArbolRN.hxx"

#endif