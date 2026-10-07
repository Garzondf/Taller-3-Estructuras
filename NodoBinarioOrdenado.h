#ifndef NODO_BINARIO_ORDENADO_H
#define NODO_BINARIO_ORDENADO_H

#include <string>

class NodoBinarioOrdenado {
private:
    std::string dato;
    NodoBinarioOrdenado* izquierdo;
    NodoBinarioOrdenado* derecho;

public:
    NodoBinarioOrdenado(std::string val);
    
    std::string obtenerDato() ;
    void fijarDato(std::string val);
    
    NodoBinarioOrdenado* obtenerIzquierdo() ;
    void fijarIzquierdo(NodoBinarioOrdenado* nodo);
    
    NodoBinarioOrdenado* obtenerDerecho() ;
    void fijarDerecho(NodoBinarioOrdenado* nodo);
};

#include "NodoBinarioOrdenado.hxx"

#endif