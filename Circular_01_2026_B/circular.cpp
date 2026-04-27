//
//  LCircular.cpp
//  Lcircular
//
//  Created by Patricia Parroquin on 21/04/26.
//
/*
 Director proyecto: Patricia C. Parroquin Amaya
 Asesor:            Patricia C. Parroquin Amaya
 Programador:       Patricia C. Parroquin Amaya
 */

#include "circular.h"
#include <iostream>
using namespace std;

// Constructor simple: inicializa el dato; siguiente se asigna manualmente
Nodo::Nodo(tipodato elDato) : dato(elDato), siguiente(NULL) {}

// -----------------------------------------------------------------------

bool LCircular::Empty()
{
    return (!final); // verdadero si final == NULL, falso en caso contrario
}

// -----------------------------------------------------------------------

bool LCircular::InsertarInicio(tipodato elDato)
{
    Nodo* nuevo = NULL; // por seguridad se pone a NULL para que no apunte a zona de memoria aleatoria

    if (Empty()) { // CASO 1: LISTA VACÍA, SERÁ EL PRIMER NODO
        if (!(nuevo = new Nodo(elDato)))
            return false; // no hay memoria
        nuevo->siguiente = nuevo; // apunta a sí mismo
        final = nuevo;
    }
    else { // CASO 2: UNO O MÁS NODOS
        if (!(nuevo = new Nodo(elDato, final->siguiente))) // nuevo->siguiente = primer nodo
            return false;
        final->siguiente = nuevo; // antiguo ultimo apunta al nuevo (que ahora es el primero)
    }
    return true;
}

// -----------------------------------------------------------------------

bool LCircular::Imprimir()
{
    if (Empty()) {
        cout << "La lista esta vacia.\n";
        return false;
    }
    Nodo* actual = final->siguiente; // primer nodo
    do {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != final->siguiente);
    cout << endl;
    return true;
}

// -----------------------------------------------------------------------

Nodo* LCircular::Buscar(tipodato elDato)
{
    if (Empty()) return NULL;
    Nodo* actual = final->siguiente; // primer nodo
    do {
        if (actual->dato == elDato) return actual;
        actual = actual->siguiente;
    } while (actual != final->siguiente);
    return NULL;
}

// -----------------------------------------------------------------------

bool LCircular::InsertarDespues(tipodato referencia, tipodato elDato)
{
    Nodo* nodoRef = Buscar(referencia);
    if (!nodoRef) return false; // referencia no encontrada

    Nodo* nuevo = new Nodo(elDato, nodoRef->siguiente); 
    if (!nuevo) return false;

    nodoRef->siguiente = nuevo;
    if (nodoRef == final) // si se inserto despues del ultimo, el nuevo es el ultimo
        final = nuevo;
    return true;
}

// -----------------------------------------------------------------------

bool LCircular::Borrar(tipodato elDato)
{
    if (Empty()) return false;

    Nodo* actual   = final->siguiente; // primer nodo
    Nodo* anterior = final;

    do {
        if (actual->dato == elDato) {
            if (actual == final && actual->siguiente == actual) { // unico nodo
                final = NULL;
            } else {
                anterior->siguiente = actual->siguiente;
                if (actual == final) // era el ultimo: retroceder el puntero final
                    final = anterior;
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != final->siguiente);

    return false; // no se encontro el dato
}

// -----------------------------------------------------------------------

LCircular::~LCircular()
{
    while(!Empty()) {
        tipodato borrado = final->siguiente->dato; // dato del primer nodo
       if (Borrar(final->siguiente->dato)) // borrar el primer nodo repetidamente
       {
        cout << "Destruyendo: " << borrado << endl;
       }
    }
    // if (Empty()) return;
    // Nodo* primero = final->siguiente;
    // Nodo* actual  = primero;
    // Nodo* temp;
    // do {
    //     temp   = actual;
    //     actual = actual->siguiente;
    //     delete temp;
    // } while (actual != primero);
    // final = NULL;
}

