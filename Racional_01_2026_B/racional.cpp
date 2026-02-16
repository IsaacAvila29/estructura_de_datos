#include "racional.h"
// Practica 01 - Racional
// Isaac Avila Saenz 238925
//Héctor Alejandro Hernández Villanueva 248895
// Este programa implementa una clase Racional para realizar operaciones con números racionales.

static int gcd_int(int a, int b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0) return b;
    if (b == 0) return a;
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
#include <iostream>
using namespace std;

// Inline parece no funcionar para el compilador de MacOs


Racional::Racional()
{
    num = 0;
    den = 1;
}

void Racional::set(int Num,int Den)
{
    if (Den == 0) return;
    num = Num;
    den = Den;
}


Racional Racional::Sumar(Racional R2)
{
    Racional Result;
    if (den == R2.den) {
        Result.num = num + R2.num;
        Result.den = den;
    } else {
        Result.num = num * R2.den + den * R2.num;
        Result.den = den * R2.den;
    }
    return Result;
}

Racional Racional::Restar(Racional R2)
{
    Racional Result;
    if (den == R2.den) {
        Result.num = num - R2.num;
        Result.den = den;
    } else {
        Result.num = num * R2.den - den * R2.num;
        Result.den = den * R2.den;
    }
    return Result;
}

Racional Racional::Multiplicar(Racional R2)
{
    Racional Result;
    Result.num = num * R2.num;
    Result.den = den * R2.den;
    return Result;
}

Racional Racional::Dividir(Racional R2)
{
    Racional Result;
    if (R2.num == 0) {
        cerr << "Division por cero\n";
        return Result; // Return 0/1
    }
    Result.num = num * R2.den;
    Result.den = den * R2.num;
    return Result;
}

void Racional::imprimir()
{
    cout << num << "/" << den << '\n';
}