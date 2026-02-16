#ifndef RACIONAL_H
#define RACIONAL_H


class Racional
{
    public:
        Racional();
        void set(int,int);
        Racional Sumar(Racional r);
        Racional Restar(Racional r);
        Racional Multiplicar(Racional r);
        Racional Dividir(Racional r);
        void imprimir();
    private:
       int num, den;
};

#endif // RACIONAL_H