// ...existing code...
#include "racional.h"

// Some standard library implementations (on older toolchains) may
// not provide std::gcd even with C++17. Provide a small local gcd
// implementation to be portable.

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

Racional::Racional()
{
    num = 0;
    den = 1;
}

bool Racional::set(int Num,int Den)
{
    if (Den == 0) return false;
    num = Num;
    den = Den;
    return true;
}

static void normalize(Racional &r)
{
    if (r.den == 0) return;
    if (r.den < 0) { r.num = -r.num; r.den = -r.den; }
    int g = gcd_int(r.num, r.den);
    if (g > 1) { r.num /= g; r.den /= g; }
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
    normalize(Result);
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
    normalize(Result);
    return Result;
}

Racional Racional::Multiplicar(Racional R2)
{
    Racional Result;
    Result.num = num * R2.num;
    Result.den = den * R2.den;
    normalize(Result);
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
    normalize(Result);
    return Result;
}

void Racional::imprimir()
{
    cout << num << "/" << den << '\n';
}
int Racional::Decimal()
{
    return float(num) / float(den);
}