#include "Matriz.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//******** Matriz.cpp **************
 Matriz::Matriz (int col, int fil )
{
    columna=col;
    fila=fil;
    llenarMatriz();
}
 void Matriz::llenarMatriz ( )
{
    //se desarrolla por el equipo
    // usando las funciones para generar números
    // aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            matriz[i][j] = std::rand() % 10; // valores 0..9
        }
    }
}

 bool Matriz::SumarMatriz(Matriz M2, Matriz& Result)
{
    if(fila!=M2.fila || columna!=M2.columna)
    {
        return false;
    }
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            Result.matriz[i][j]=matriz[i][j] + M2.matriz[i][j];
        }
    }
    return true;
}
 bool Matriz::RestarMatriz(Matriz M2, Matriz& Result) {
    if(fila!=M2.fila || columna!=M2.columna)
    {
        return false;
    }
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            Result.matriz[i][j]= this->matriz[i][j] - M2.matriz[i][j];
        }
    }
    Result.fila = fila;
    Result.columna = columna;
    return true;
}

 bool Matriz::Multiplicar(Matriz M2, Matriz& Result) {
    if(columna != M2.fila) {
        return false; // dimensiones incompatibles
    }
    // Resultado: filas de this x columnas de M2
    int rFil = fila;
    int rCol = M2.columna;
    // inicializar a 0
    for(int i=0;i<rFil;i++){
        for(int j=0;j<rCol;j++){
            Result.matriz[i][j] = 0;
        }
    }
    for(int i=0;i<rFil;i++){
        for(int j=0;j<rCol;j++){
            for(int k=0;k<columna;k++){
                Result.matriz[i][j] += this->matriz[i][k] * M2.matriz[k][j];
            }
        }
    }
    Result.fila = rFil;
    Result.columna = rCol;
    return true;
}

void Matriz::Imprimir() {
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}