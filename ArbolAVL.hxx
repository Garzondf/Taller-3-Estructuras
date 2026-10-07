#ifndef ARBOL_AVL_HXX
#define ARBOL_AVL_HXX

#include "ArbolAVL.h"
#include <list> 

ArbolAVL::ArbolAVL() {
    raiz = nullptr;
}

bool ArbolAVL::esVacio()  {
    return raiz == nullptr;
}

void ArbolAVL::insertar(std::string codigo) {
//falta
}
   

void ArbolAVL::eliminar(std::string codigo) {
   //falta 
}

void ArbolAVL::inorden(std::list<std::string>& lista)  {
    
    std::list<NodoArbolAVL*> nodos_pendientes;
    NodoArbolAVL* actual = raiz;

    while (actual != nullptr || !nodos_pendientes.empty()) {
        while (actual != nullptr) {
            nodos_pendientes.push_back(actual);
            actual = actual->obtenerIzquierdo();
        }
        
        actual = nodos_pendientes.back();
        nodos_pendientes.pop_back();
        
        lista.push_back(actual->obtenerDato());
        
        actual = actual->obtenerDerecho();
    }
}

#endif