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

bool LCircular::InsertarDespues(tipodato dato_buscado, tipodato nuevoDato)
{
    Nodo* aux = Buscar(dato_buscado), *nuevo = NULL;
    if (!aux) return false; // no existe el dato buscado
    if (!(nuevo = new Nodo (nuevoDato, aux -> siguiente))) return false; // No hay memoria    
    aux -> siguiente = nuevo;
    return true;
   
}

// -----------------------------------------------------------------------

bool LCircular::Borrar(tipodato elDato)
{
    Nodo *aux = Buscar(elDato), *anterior = NULL;
    if(!aux) return false;
    anterior = final -> siguiente;
    while (anterior -> siguiente != aux)
    {
        anterior = anterior -> siguiente;
    }
    anterior -> siguiente = aux -> siguiente;
    delete aux;
    return true;
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

