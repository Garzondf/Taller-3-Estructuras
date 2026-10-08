#ifndef ARBOL_RN_H
#define ARBOL_RN_H

#include <set>
#include <list>
#include <string>

class ArbolRN {
  protected:
    std::set<std::string> RN;
    
  public:
    ~ArbolRN();
    bool esVacio();
    void insertar(std::string val);
    void eliminar(std::string val);
    void inOrden(std::list<std::string>& lista);
};

#include "ArbolRN.hxx"

#endif