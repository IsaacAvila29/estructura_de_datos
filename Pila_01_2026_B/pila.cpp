// Practica Pila
// Isaac Avila Saenz 238925
// Héctor Alejandro Hernández Villanueva 248895
#define MAX 5

#include "pila.h"

bool Pila::Push(tipodato elDato)
{
	if (Full()) // la pila está llena
		return false;
	elementos[++cima] = elDato;
	return true;
}

bool Pila::Full()
{
	return (cima == MAX - 1);
}

bool Pila::Pop(tipodato &elDato)
{
	if (Empty()) return false;
	elDato = elementos[cima--];
	return true;
}

bool Pila::Empty()
{
	return (cima == -1);
}

bool Pila::Vertope(tipodato &elDato)
{
	if (Empty()) return false;
	elDato = elementos[cima];
	return true;
}