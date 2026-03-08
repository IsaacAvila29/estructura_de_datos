//Practica Matrices
// Isaac Avila Saenz 238925
// Héctor Alejandro Hernández Villanueva 248895
#include "Matriz.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//******** Matriz.cpp **************
 Matriz::Matriz (int fil, int col )
{
    fila = fil;
    columna = col;
    llenarMatriz();
}
 void Matriz::llenarMatriz ( )
{
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            matriz[i][j] = std::rand() % 10; // valores 0..9
        }
    }
}

 bool Matriz::SumarMatriz(const Matriz& M2, Matriz& Result) const
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
    Result.fila = fila;
    Result.columna = columna;
    return true;
}
 bool Matriz::RestarMatriz(const Matriz& M2, Matriz& Result) const {
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

 bool Matriz::Multiplicar(const Matriz& M2, Matriz& Result) const {
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

