//Practica Matrices
// Isaac Avila Saenz 238925
// Héctor Alejandro Hernández Villanueva 248895

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matriz.h"

using namespace std;

void sumar(const Matriz& M1, const Matriz& M2){
    Matriz Result(maxFila, maxCol);
    if(!M1.SumarMatriz(M2, Result)){
        cout << "Dimensiones incompatibles para suma" << endl;
        return;
    }
    cout << "Resultado de la suma:\n";
    Result.Imprimir();
}

void restar(const Matriz& M1, const Matriz& M2){
    Matriz Result(maxFila, maxCol);
    if(!M1.RestarMatriz(M2, Result)){
        cout << "Dimensiones incompatibles para resta" << endl;
        return;
    }
    cout << "Resultado de la resta:\n";
    Result.Imprimir();
}

void multiplicar(const Matriz& M1, const Matriz& M2){
    // resultado tiene filas de M1 y columnas de M2
    Matriz Result(maxFila, maxCol);
    if(!M1.Multiplicar(M2, Result)){
        cout << "Dimensiones incompatibles para multiplicacion" << endl;
        return;
    }
    cout << "Resultado de la multiplicacion:\n";
    Result.Imprimir();
}

void Menu(Matriz& M1, Matriz& M2){
    unsigned short int seleccion = 0;
    do{
        cout << "\nBienvenido. Selecciona la operacion a realizar:\n";
        cout << "1 - Sumar\n2 - Restar\n3 - Multiplicar\n4 - Mostrar matrices\n5 - Salir\n";
        cout << "Opcion: ";
        if(!(cin >> seleccion)){
            cin.clear();
            cin.ignore(10000, '\n');
            seleccion = 0;
        }
        switch(seleccion){
            case 1:
                sumar(M1, M2);
                break;
            case 2:
                restar(M1, M2);
                break;
            case 3:
                multiplicar(M1, M2);
                break;
            case 4:
                cout << "Matriz 1:\n"; M1.Imprimir();
                cout << "---------------------\nMatriz 2:\n"; M2.Imprimir();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                if(seleccion!=0) cout << "Opcion no valida" << endl;
        }
    }while(seleccion != 5);
}

int main(int argc, const char * argv[]) {

    // g++ -std=c++17 -Wall -Wextra Matriz_01_2026_B/main.cpp Matriz_01_2026_B/Matriz.cpp -o Matriz_01_2026_B/main
    // ./Matriz_01_2026_B/main

    std::srand((unsigned)std::time(nullptr));

    int r,c;
    do{
        std::cout << "Teclee renglones y columnas: ";
        std::cin >> r >> c;
        if (!std::cin){
            std::cin.clear(); std::cin.ignore(10000, '\n');
            r = c = 0;
        }
        if (r>10 || c >10)
            std::cout << "max 10" <<std::endl;
    }while (r>10 || c >10 || r<=0 || c<=0);
    Matriz M1(r,c);
    Matriz M2(r,c);

    cout << "Matriz 1:\n";
    M1.Imprimir();

    cout<< "=====================" << endl ;

    cout << "Matriz 2:\n";
    M2.Imprimir();

    Menu(M1, M2);
    return EXIT_SUCCESS;
}
