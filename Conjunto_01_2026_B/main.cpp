//Practica Conjunto
// Isaac Avila Saenz 238925
// Héctor Alejandro Hernández Villanueva 248895
#include <iostream>
#include "Conjunto.h"
#include "Conjunto.cpp"
using namespace std;
//Ejecutar el programa
//g++ "Conjunto_01_2026_B/main.cpp" -o "Conjunto_01_2026_B/main"

unsigned int menu(){
    unsigned int opc = 0;
    std::cout << "\nOperaciones de Conjuntos\n";
    std::cout << "1) AddElem\n";
    std::cout << "2) RmvElem\n";
    std::cout << "3) Copy\n";
    std::cout << "4) Equal\n";
    std::cout << "5) Intersect\n";
    std::cout << "6) Union\n";
    std::cout << "7) Salir\n";
    std::cout << "Elija opcion: ";
    while(!(std::cin >> opc) || opc < 1 || opc > 7){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opcion invalida. Elija (1-7): ";
    }
    return opc;
}


void operaciones(Conjunto &C1, Conjunto &C2, Conjunto &Result);

int main(){
    Conjunto C1, C2, Result;
    std::cout << "Programa Conjuntos\n";
    operaciones(C1, C2, Result);
    return 0;
}

unsigned int submenu(){
    unsigned int opc=0;
    std::cout << "\nSubmenu:\n";
    std::cout << "1) Conjunto1\n";
    std::cout << "2) Conjunto2\n";
    std::cout << "3) Regresar\n";
    std::cout << "Elija opcion: ";
    while(!(std::cin >> opc) || opc < 1 || opc > 3){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opcion invalida. Elija (1-3): ";
    }
    return opc;
}

unsigned int submenu2(){
    unsigned int opc=0;
    std::cout << "\nSubmenu Copy:\n";
    std::cout << "1) Conjunto1 -> Conjunto2\n";
    std::cout << "2) Conjunto2 -> Conjunto1\n";
    std::cout << "3) Regresar\n";
    std::cout << "Elija opcion: ";
    while(!(std::cin >> opc) || opc < 1 || opc > 3){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opcion invalida. Elija (1-3): ";
    }
    return opc;
}

void operaciones(Conjunto &C1, Conjunto &C2, Conjunto &Result){
    unsigned int opcMain = 0;
    typeinfo dato;
    do{
        opcMain = menu();
        switch(opcMain){
            case 1:{ // AddElem
                unsigned int s = submenu();
                if(s==3) break;
                std::cout << "Teclee elemento a adicionar: ";
                std::cin >> dato;
                bool ok = (s==1) ? C1.AddElem(dato) : C2.AddElem(dato);
                if(ok) std::cout << dato << " Insertado!\n";
                else std::cout << "Error: ya existe o no cabe\n";
                std::cout << "C1: "; C1.Print();
                std::cout << "C2: "; C2.Print();
                break;
            }
            case 2:{ // RmvElem
                unsigned int s = submenu();
                if(s==3) break;
                std::cout << "Teclee elemento a remover: ";
                std::cin >> dato;
                bool ok = (s==1) ? C1.RmvElem(dato) : C2.RmvElem(dato);
                if(ok) std::cout << "eliminado: " << dato << "\n";
                else std::cout << "Error: dato no existe\n";
                std::cout << "C1: "; C1.Print();
                std::cout << "C2: "; C2.Print();
                break;
            }
            case 3:{ // Copy
                unsigned int s = submenu2();
                if(s==3) break;
                if(s==1){ // C1 -> C2 : destination.Copy(source)
                    C2.Copy(C1);
                    std::cout << "Copiado C1 -> C2\n";
                } else {
                    C1.Copy(C2);
                    std::cout << "Copiado C2 -> C1\n";
                }
                std::cout << "C1: "; C1.Print();
                std::cout << "C2: "; C2.Print();
                break;
            }
            case 4:{ // Equal
                if(C1.Equal(C2)) std::cout << "SON IGUALES\n";
                else std::cout << "NO SON IGUALES\n";
                std::cout << "C1: "; C1.Print();
                std::cout << "C2: "; C2.Print();
                break;
            }
            case 5:{ // Intersect
                C1.Intersect(C2, Result);
                std::cout << "Resultado Interseccion (C1 ∩ C2):\n";
                std::cout << "C1: "; C1.Print();
                std::cout << "C2: "; C2.Print();
                std::cout << "Result: "; Result.Print();
                break;
            }
            case 6:{ // Union
                C1.Union(C2, Result);
                std::cout << "Resultado Union (C1 ∪ C2):\n";
                std::cout << "C1: "; C1.Print();
                std::cout << "C2: "; C2.Print();
                std::cout << "Result: "; Result.Print();
                break;
            }
            case 7:{ // Salir
                std::cout << "Saliendo...\n";
                break;
            }
            default:
                break;
        }
    }while(opcMain != 7);
}
