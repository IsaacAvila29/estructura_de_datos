#define MAX 5

#include "pila.h"

inline bool Pila::Push(tipodato elDato)
{
	if (Full()) // la pila está llena
		return false;
	elementos[++cima] = elDato;
	return true;
}

inline bool Pila::Full()
{
	return (cima == MAX - 1);
}

inline bool Pila::Pop(tipodato &elDato)
{
	if (Empty()) return false;
	elDato = elementos[cima--];
	return true;
}

inline bool Pila::Empty()
{
	return (cima == -1);
}

inline bool Pila::Vertope(tipodato &elDato)
{
	if (Empty()) return false;
	elDato = elementos[cima];
	return true;
}