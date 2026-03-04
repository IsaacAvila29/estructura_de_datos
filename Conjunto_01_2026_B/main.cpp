//Practica Conjunto
// Isaac Avila Saenz 238925
// Héctor Alejandro Hernández Villanueva 248895
#include <iostream>
#include "Conjunto.h"

using namespace std;

// prototipos definidos en menu_ops.cpp
unsigned int menu();
unsigned int submenu();
unsigned int submenu2();
void operaciones(Conjunto&, Conjunto&, Conjunto&);

int main(int argc, const char * argv[]) {

    Conjunto C1, C2, Result;

    setlocale(LC_ALL, "spanish");

    operaciones(C1, C2, Result);

    return EXIT_SUCCESS;
}
