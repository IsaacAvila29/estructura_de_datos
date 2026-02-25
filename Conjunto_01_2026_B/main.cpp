#include <iostream>
#include "Conjunto.h"
#include "Conjunto.cpp"
using namespace std;
//Ejecutar el programa
//g++ "Conjunto_01_2026_B/main.cpp" -o "Conjunto_01_2026_B/main"
int main() {
    Conjunto C1, C2, Result;
    typedef int dato;
    dato dato_val;

    for(int i=0; i<5; i++){
        std::cout << "Teclee elemento: ";
        std::cin >> dato_val;

        if(C1.AddElem(dato_val))
            std::cout << dato_val << " Insertado!\n";
        else
            std::cout << " Error! ya existe o no cabe" << endl;
    }

    if(!(C1.Print()))
        std::cout << "Conjunto vacío!\n";

    if(!(C1.Print()))
    std::cout << "Conjunto vacío!\n";
    C1.Copy(C2);
    cout << "Imoruimiento del segundo conjunto: " << endl;
    if(!(C1.Print()))
    std::cout << "Conjunto vacío!\n";
    if(!(C2.Print()))
    std::cout << "Conjunto vacío!\n\n";

    for(int i=0;i<2;i++){
        std::cout << "Teclee dato a remover: ";
        std::cin >> dato_val;
        if(C1.RmvElem(dato_val)){
            std::cout << "eliminado: " <<dato_val <<endl;
            if(!(C1.Print()))
                std::cout << "Conjunto vacio!\n";
        }
        else
            std::cout << "Error, dato no existe!\n";
    }

    C1.Intersect(C2, Result);
    cout << "Intersección de C1 y C2: " << endl;    
    if(!(Result.Print()))
        std::cout << "No se encontró intersección!\n";

    return 0;
}

