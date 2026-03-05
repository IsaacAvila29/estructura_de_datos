#ifndef MATRIZ_H
#define MATRIZ_H


# define maxCol 10
# define maxFila 10
typedef int tipodato;


class Matriz
{
     public:

        Matriz (int col, int fil );  //en clase
        void llenarMatriz ( ); //en clase
        bool SumarMatriz (Matriz, Matriz&);
    	bool RestarMatriz (Matriz, Matriz&);
	    bool Multiplicar(Matriz, Matriz&);
	    void Imprimir( ); //en clase

     private:
       tipodato matriz[maxFila][maxCol];
       int columna, fila;
};

#endif // MATRIZ_H