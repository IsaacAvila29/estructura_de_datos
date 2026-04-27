//
//  main.cpp
//  Lcircular
//
//  Created by Patricia Parroquin on 21/04/26.
//
/*
 Director proyecto: Patricia C. Parroquin Amaya
 Asesor:            Patricia C. Parroquin Amaya
 Programador:       Patricia C. Parroquin Amaya
 */

#include <iostream>
#include "circular.cpp"
using namespace std;

int main(int argc, const char * argv[]) {

    LCircular lista;

    cout << "Insertando al inicio: 10, 20, 30\n";
    lista.InsertarInicio(10);
    lista.InsertarInicio(20);
    lista.InsertarInicio(30);
    lista.Imprimir();

    cout << "\nInsertando 99 despues del 20...\n";
    lista.InsertarDespues(20, 99);
    lista.Imprimir();

    cout << "\nBuscando 20... " << (lista.Buscar(20) ? "ENCONTRADO" : "NO encontrado") << "\n";
    cout << "Buscando 55... " << (lista.Buscar(55) ? "ENCONTRADO" : "NO encontrado") << "\n";

    cout << "\nBorrando el 99...\n";
    lista.Borrar(99);
    lista.Imprimir();

    return EXIT_SUCCESS;
}
