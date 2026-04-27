// #ifndef COLA_H
// #define COLA_H
// #define MAX 5
// typedef int tipodato;

// class Cola
// {
//     public:
//         Cola(){Inicio=0;Final=0;numElementos=0;};
//         bool Empty();
//         bool Full();
//         bool Insert(tipodato);
//         bool Erase(tipodato &);

//     private:
//         unsigned Inicio,Final,numElementos;
//         tipodato elem[MAX];

// };

// #endif // COLA_H

// PROPUESTA 2. NO REQUIERE VARIABLE PARA NO. DE ELEMENTOS 
// NUESTRAS VARIABLES FRENTE Y FINAL EMPIEZAN EN -1

#ifndef COLA_H
#define COLA_H
#define MAX 5
typedef int tipodato;

class Cola
{
    public:
        Cola(){Inicio=-1;Final=-1;};
        bool Empty();
        bool Full();
        bool Insert(tipodato);
        bool Erase(tipodato &);

    private:
        int Inicio,Final;
        tipodato elem[MAX];

};

#endif // COLA_H