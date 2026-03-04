#include <iostream>
#include "Matriz.cpp"
using namespace std;


int main(int argc, const char * argv[]) {
  
//g++ -std=c++17 -Wall -Wextra Matriz_01_2026_B/main.cpp -o Matriz_01_2026_B/main
//./Matriz_01_2026_B/main

    int r,c;
    do{
        std::cout << "Teclee renglones y columnas:";
        std::cin >>r >>c;
        if (r>10 || c >10)
            std::cout << "max 10" <<std::endl;
    }while (r>10 || c >10);
    Matriz M1(r,c);
    M1.Imprimir();
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}