#ifndef RACIONAL_H
#define RACIONAL_H
// Practica 01 - Racional
// Isaac Avila Saenz 238925
//Héctor Alejandro Hernández Villanueva 248895
// Este programa implementa una clase Racional para realizar operaciones con números racionales.

class Racional
{
    public:
        Racional();
        void set(int,int);
        Racional Sumar(Racional r);
        Racional Restar(Racional r);
        Racional Multiplicar(Racional r);
        Racional Dividir(Racional r);
        void imprimir();
    private:
       int num, den;
};

#endif // RACIONAL_H