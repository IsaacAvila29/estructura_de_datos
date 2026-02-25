#include <iostream>
#include "Conjunto.h"
#include "Conjunto.cpp"
using namespace std;
//Ejecutar el programa
//g++ "Conjunto_01_2026_B/main.cpp" -o "Conjunto_01_2026_B/main"
int main(int argc, const char * argv[]) {

    // **************declarando variables *********

    Conjunto C1,C2, Result;

    typeinfo dato;

    setlocale(LC_ALL, "spanish");

    // **************probando AddElem *********

    cout << "C1 elementos\n";

    if(!(C1.Print()))
        std::cout << "Conjunto vacío!\n";

    

    for(int i=0;i<5;i++){

        std::cout << "Teclee elemento: ";

        std::cin>>dato;

        

        if(C1.AddElem(dato))

            std::cout <<dato << " Insertado!\n";

        else

            std::cout << " Error! ya existe o no cabe" <<endl;

    }

    // **************imprimiendo C1 *********

 

    cout << "C1 elementos\n";

    if(!(C1.Print()))

        std::cout << "Conjunto vacío!\n";

    

    

    // **************probando Copy C1 a C2

    C1.Copy(C2);

    cout << "C1 elementos\n";

    if(!(C1.Print()))

        std::cout << "C1 Conjunto vacío!\n";

    cout << "C2 elementos\n";

    if(!(C2.Print()))

        std::cout << "C2 Conjunto vacío!\n\n";

    // **************probando Equal C1 a C2

    if(C1.Equal(C2))

        cout << "los conjuntos son iguales\n";

    else

        cout << "los conjuntos NO son iguales\n";

 

    if(!(C1.Print()))

        std::cout << "C1 Conjunto vacío!\n";

    cout << "C2 elementos\n";

    if(!(C2.Print()))

        std::cout << "C2 Conjunto vacío!\n\n";

    

    // borrando 2 datos

    for(int i=0;i<2;i++){

        std::cout << "Teclee dato a remover: ";

        std::cin>>dato;

        if(C1.RmvElem(dato)){

            std::cout << "eliminado: " <<dato <<endl;

            if(!(C1.Print()))

                std::cout << "Conjunto vacío!\n";

        }

        else

            std::cout << "Error, dato no existe!\n";

        

    }

    // **************probando Equal C1 a C2

    if(C1.Equal(C2))

        cout << "los conjuntos son iguales\n";

    else

        cout << "los conjuntos NO son iguales\n";

    

    if(!(C1.Print()))

        std::cout << "C1 Conjunto vacío!\n";

    cout << "C2 elementos\n";

    if(!(C2.Print()))

        std::cout << "C2 Conjunto vacío!\n\n";

    

    // ***********probando Intersect ************

    //para saber que elem pertenecen a ambos conjuntos

    C1.Intersect(C2, Result);

    std::cout << "Resultado de intersección\n";

    

    if(!(Result.Print()))

        std::cout << "No se intersectan!\n";

    

    std::cout << "Hello, World!\n";

    return EXIT_SUCCESS;

}


