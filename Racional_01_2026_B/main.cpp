#include <iostream>
#include "racional.h"

using namespace std;

int main()
{
    Racional Rac1, Rac2, R3;
    int numerador, denominador;

    cout << "Ingresa el numerador y denominador del primer racional: ";
    cin >> numerador >> denominador;

    if (Rac1.set(numerador, denominador) == false) {
        cout << "Denominador no puede ser cero." << endl;
        return 1;
    }

    cout << "Ingresa el numerador y denominador del segundo racional: ";
    cin >> numerador >> denominador;

    if (Rac2.set(numerador, denominador) == false) {
        cout << "Denominador no puede ser cero." << endl;
        return 1;
    }

    R3 = Rac1.Sumar(Rac2);
    cout << "Suma: " << R3.num << "/" << R3.den << '\n';

    R3 = Rac1.Restar(Rac2);
    cout << "Resta: " << R3.num << "/" << R3.den << '\n';

    R3 = Rac1.Multiplicar(Rac2);
    cout << "Multiplicacion: " << R3.num << "/" << R3.den << '\n';

    return 0;
}