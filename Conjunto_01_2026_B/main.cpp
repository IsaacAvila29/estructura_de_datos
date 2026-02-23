#include <iostream>
#include "Conjunto.h"
#include "Conjunto.cpp"
using namespace std;
//Ejecutar el programa
//g++ "Conjunto_01_2026_B/main.cpp" -o "Conjunto_01_2026_B/main"
int main() {
    Conjunto A, B, Resultado;
    int n, elem;

    cout << "¿Cuántos elementos tiene el conjunto A? (max " << maxCard << "): ";
    cin >> n;
    cout << "Ingresa los elementos de A:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  A[" << i << "]: ";
        cin >> elem;
        if (!A.AddElem(elem))
            cout << "  (elemento repetido o conjunto lleno, ignorado)" << endl;
    }

    cout << "¿Cuántos elementos tiene el conjunto B? (max " << maxCard << "): ";
    cin >> n;
    cout << "Ingresa los elementos de B:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  B[" << i << "]: ";
        cin >> elem;
        if (!B.AddElem(elem))
            cout << "  (elemento repetido o conjunto lleno, ignorado)" << endl;
    }

    cout << "\nConjunto A: ";
    A.Print();

    cout << "Conjunto B: ";
    B.Print();

    A.Intersect(B, Resultado);
    cout << "Interseccion A ∩ B: ";
    Resultado.Print();

    // Unión A ∪ B
    A.Union(B, Resultado);
    cout << "Union A ∪ B: ";
    Resultado.Print();

    return 0;
}