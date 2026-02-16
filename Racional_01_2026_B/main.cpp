// Practica 01 - Racional
// Isaac Avila Saenz 238925
// Este programa implementa una clase Racional para realizar operaciones con números racionales.
#include <iostream>
#include "racional.h"
#include <limits>

using namespace std;

// Función para manejar errores
void handleError(const string& mensaje) {
    cerr << "ERROR: " << mensaje << endl;
}

// Limpia el estado de entrada y descarta la línea restante
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función para ingresar un número racional
bool ingresarRacional(Racional& rac, const string& etiqueta) {
    int numerador, denominador;
    while (true) {
        cout << "Ingresa el numerador y denominador del " << etiqueta << " racional: ";
        cin >> numerador >> denominador;
        if (cin.fail()) {
            handleError("Entrada invalida. Debes introducir dos numeros enteros.");
            clearInput();
            continue;
        }
        if (denominador == 0) {
            handleError("El denominador no puede ser cero.");
            continue;
        }
        rac.set(numerador, denominador);
        return true;
    }
}

// Función para mostrar el menú de opciones
int mostrarMenu() {
    int opcion;
    while (true) {
        cout << "\n--- MENU DE OPERACIONES ---" << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Todas las operaciones" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        if (cin.fail()) {
            handleError("Entrada invalida. Debes introducir el numero de la opcion.");
            clearInput();
            continue;
        }
        if (opcion < 1 || opcion > 5) {
            handleError("Opcion fuera de rango. Elige entre 1 y 5.");
            continue;
        }
        return opcion;
    }
}

// Función para ejecutar la operación seleccionada
void ejecutarOperacion(int opcion, Racional& Rac1, Racional& Rac2) {
    Racional R3;
    
    cout << "\n--- RESULTADOS ---" << endl;
    switch(opcion) {
        case 1:
            R3 = Rac1.Sumar(Rac2);
            cout << "Suma: ";
            R3.imprimir();
            break;
        case 2:
            R3 = Rac1.Restar(Rac2);
            cout << "Resta: ";
            R3.imprimir();
            break;
        case 3:
            R3 = Rac1.Multiplicar(Rac2);
            cout << "Multiplicacion: ";
            R3.imprimir();
            break;
        case 4:
            R3 = Rac1.Dividir(Rac2);
            cout << "Division: ";
            R3.imprimir();
            break;
        case 5:
            R3 = Rac1.Sumar(Rac2);
            cout << "Suma: ";
            R3.imprimir();

            R3 = Rac1.Restar(Rac2);
            cout << "Resta: ";
            R3.imprimir();

            R3 = Rac1.Multiplicar(Rac2);
            cout << "Multiplicacion: ";
            R3.imprimir();

            R3 = Rac1.Dividir(Rac2);
            cout << "Division: ";
            R3.imprimir();
            break;
        default:
            handleError("Opcion no valida.");
    }
}

int main()
{
    Racional Rac1, Rac2;
    int opcion;
    char continuar;

    bool pedirNumeros = true;
    do {
        cout << "\n=== CALCULADORA DE NUMEROS RACIONALES ===" << endl;

        if (pedirNumeros) {
            // Ingresar primer racional
            if (!ingresarRacional(Rac1, "primer")) {
                continue;
            }

            // Ingresar segundo racional
            if (!ingresarRacional(Rac2, "segundo")) {
                continue;
            }
        } else {
            cout << "Usando los mismos numeros introducidos anteriormente." << endl;
        }

        // Mostrar menú y obtener opción
        opcion = mostrarMenu();

        // Ejecutar operación
        ejecutarOperacion(opcion, Rac1, Rac2);

        cout << "\n¿Deseas realizar otra operacion? (s/n): ";
        cin >> continuar;

        if (continuar == 's' || continuar == 'S') {
            char cambiar;
            cout << "¿Deseas usar otros numeros? (s/n): ";
            cin >> cambiar;
            pedirNumeros = (cambiar == 's' || cambiar == 'S');
        }

    } while (continuar == 's' || continuar == 'S');

    cout << "\nGracias por usar la calculadora!" << endl;
    return 0;
}