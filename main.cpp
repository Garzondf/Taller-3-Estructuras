#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <ctime>
#include "ArbolBinarioOrdenado.h"
#include "ArbolAVL.h"
#include "ArbolRN.h"

using namespace std;

int main(int argc, char* argv[]) {
    string nombre_archivo = argv[1];

    ArbolBinarioOrdenado arbol_binario;
    ArbolAVL arbol_avl;
    ArbolRN arbol_rn;

    char operacion;
    string codigo;

    list<string> lista_binario;
    list<string> lista_avl;
    list<string> lista_rn;

    // Procesar y medir el Arbol Binario Ordenado
    clock_t inicio_bin = clock();
    ifstream archivo_bin(nombre_archivo);
    while (archivo_bin >> operacion >> codigo) {
        if (operacion == 'A' || operacion == 'a') arbol_binario.insertar(codigo);
        else if (operacion == 'E' || operacion == 'e') arbol_binario.eliminar(codigo);
    }
    archivo_bin.close();
    arbol_binario.inorden(lista_binario);
    clock_t fin_bin = clock();
    double tiempo_bin = double(fin_bin - inicio_bin) / CLOCKS_PER_SEC;

    // Procesar y medir el Arbol AVL
    clock_t inicio_avl = clock();
    ifstream archivo_avl(nombre_archivo);
    while (archivo_avl >> operacion >> codigo) {
        if (operacion == 'A' || operacion == 'a') arbol_avl.insertar(codigo);
        else if (operacion == 'E' || operacion == 'e') arbol_avl.eliminar(codigo);
    }
    archivo_avl.close();
    arbol_avl.inorden(lista_avl);
    clock_t fin_avl = clock();
    double tiempo_avl = double(fin_avl - inicio_avl) / CLOCKS_PER_SEC;

    // Procesar y medir el Arbol RN
    clock_t inicio_rn = clock();
    ifstream archivo_rn(nombre_archivo);
    while (archivo_rn >> operacion >> codigo) {
        if (operacion == 'A' || operacion == 'a') arbol_rn.insertar(codigo);
        else if (operacion == 'E' || operacion == 'e') arbol_rn.eliminar(codigo);
    }
    archivo_rn.close();
    arbol_rn.inorden(lista_rn);
    clock_t fin_rn = clock();
    double tiempo_rn = double(fin_rn - inicio_rn) / CLOCKS_PER_SEC;

    // Mostrar los tiempos en pantalla
    cout << "\n=== TIEMPOS DE EJECUCION (Llenado + Recorrido) ===\n";
    cout << "Arbol Binario Ordenado: " << tiempo_bin << " segundos.\n";
    cout << "Arbol AVL:              " << tiempo_avl << " segundos.\n";
    cout << "Arbol Rojinegro (RN):   " << tiempo_rn << " segundos.\n";

    // Comparar recorridos al final
    if (lista_binario == lista_avl && lista_avl == lista_rn) {
        cout << "\n[Validacion Exitosa]: Todos los arboles generaron la misma lista ordenada.\n";
    } else {
        cout << "\n[Advertencia]: Los datos no estan bien entre arboes.\n";
    }

    return 0;
}