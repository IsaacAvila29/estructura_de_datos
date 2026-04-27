//
//  LCircular.h
//  Lcircular
//
//  Created by Patricia Parroquin on 21/04/26.
//
/*
 Director proyecto: Patricia C. Parroquin Amaya
 Asesor:            Patricia C. Parroquin Amaya
 Programador:       Patricia C. Parroquin Amaya
 */

#ifndef LCIRCULAR_H
#define LCIRCULAR_H

#include <iostream>

typedef int tipodato;

class Nodo {
    friend class LCircular;
    tipodato dato;
    Nodo* siguiente;
    Nodo(tipodato elDato);
    Nodo(tipodato elDato, Nodo* elSiguiente) : dato(elDato), siguiente(elSiguiente) {};
};

class LCircular {
    Nodo* final; // apunta al ultimo nodo; final->siguiente es el primero

public:
    LCircular() { final = NULL; };
    bool InsertarInicio(tipodato);      // 2
    bool Imprimir();                    // 3
    bool Empty();                       // 1
    Nodo* Buscar(tipodato);             // 4
    bool InsertarDespues(tipodato, tipodato);
    bool Borrar(tipodato);
    ~LCircular();
};

#endif // LCIRCULAR_H
