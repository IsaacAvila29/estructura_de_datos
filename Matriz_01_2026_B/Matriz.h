//Practica Matrices
// Isaac Avila Saenz 238925
// Héctor Alejandro Hernández Villanueva 248895
#ifndef MATRIZ_H
#define MATRIZ_H


# define maxCol 10
# define maxFila 10
typedef int tipodato;


class Matriz
{
     public:
 
  Matriz (int fil, int col );  //filas, columnas
        void llenarMatriz ( ); //en clase
        bool SumarMatriz (const Matriz&, Matriz&) const;
    	bool RestarMatriz (const Matriz&, Matriz&) const;
       bool Multiplicar(const Matriz&, Matriz&) const;
	    void Imprimir( ); //en clase

     private:
       tipodato matriz[maxFila][maxCol];
       int columna, fila;
};

#endif // MATRIZ_H