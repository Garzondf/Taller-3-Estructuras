#include <iostream>
#include <fstream>
#include <ctime>
#include <list>
#include <string>
#include "ArbolBinarioOrdenado.h"
#include "ArbolAVL.h"
#include "ArbolRN.h"
#include <iomanip>//para ver bien la tabla de comparacion
using namespace std;

int main(int argc, char* argv[]) {
    
    string nombre_archivo = argv[1];


    ifstream archivoBin(nombre_archivo);
    if (!archivoBin.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    char operacion;
    string codigo;
    
    ArbolBinarioOrdenado arbolBinario;
    clock_t t_inicio_bin = clock();
    while (archivoBin >> operacion >> codigo) {
        if (operacion == 'A') {
            arbolBinario.insertar(codigo);
        } else if (operacion == 'E') {
            arbolBinario.eliminar(codigo);
        }
    }
    archivoBin.close();

    list<string> listaBinario;
    arbolBinario.inOrden(listaBinario);
    clock_t t_fin_bin = clock();
    double tiempo_bin = (t_fin_bin - t_inicio_bin) / double(CLOCKS_PER_SEC);


    ArbolAVL arbolAVL;
    clock_t t_inicio_avl = clock();

    ifstream archivoAvl(nombre_archivo);
    while (archivoAvl >> operacion >> codigo) {
        if (operacion == 'A') {
            arbolAVL.insertar(codigo);
        } else if (operacion == 'E') {
            arbolAVL.eliminar(codigo);
        }
    }
    archivoAvl.close();

    list<string> listaAVL;
    arbolAVL.inOrden(listaAVL);
    clock_t t_fin_avl = clock();
    double tiempo_avl = (t_fin_avl - t_inicio_avl) / double(CLOCKS_PER_SEC);


    ArbolRN arbolRN;
    clock_t t_inicio_rn = clock();

    ifstream archivoRn(nombre_archivo);
    while (archivoRn >> operacion >> codigo) {
        if (operacion == 'A') {
            arbolRN.insertar(codigo);
        } else if (operacion == 'E') {
            arbolRN.eliminar(codigo);
        }
    }
    archivoRn.close();

    list<string> listaRN;
    arbolRN.inOrden(listaRN);
    clock_t t_fin_rn = clock();
    double tiempo_rn = (t_fin_rn - t_inicio_rn) / double(CLOCKS_PER_SEC);
//impresion por linea de comandos hecha con IA
  
    cout << left << setw(15) << "Binario" << setw(15) << "AVL" << setw(15) << "RN" << "\n";
    cout << "---------------------------------------------\n";

    std::list<string>::iterator itBin = listaBinario.begin();
    std::list<string>::iterator itAvl = listaAVL.begin();
    std::list<string>::iterator itRn = listaRN.begin();

    while (itBin != listaBinario.end() || itAvl != listaAVL.end() || itRn != listaRN.end()) {
        if (itBin != listaBinario.end()) {
            cout << left << setw(15) << *itBin;
            ++itBin;
        } else {
            cout << left << setw(15) << "-";
        }

        if (itAvl != listaAVL.end()) {
            cout << left << setw(15) << *itAvl;
            ++itAvl;
        } else {
            cout << left << setw(15) << "-";
        }

        if (itRn != listaRN.end()) {
            cout << left << setw(15) << *itRn;
            ++itRn;
        } else {
            cout << left << setw(15) << "-";
        }

        cout << "\n";
    }

    cout << "Tiempos de ejecucion:\n";
    cout << "Arbol Binario: " << tiempo_bin << " s\n";
    cout << "Arbol AVL: " << tiempo_avl << " s\n";
    cout << "Arbol RN: " << tiempo_rn << " s\n\n";

}