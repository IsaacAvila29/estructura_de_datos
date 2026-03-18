#ifndef PILA_H
#define PILA_H
#define MAX 5
typedef int tipodato;


class Pila
{
    public:
        Pila(){cima=-1;};
        bool Push(tipodato );
        bool Pop (tipodato &);
        bool Empty();
        bool Full();
        bool Vertope(tipodato &);

    private:
        tipodato elementos[MAX];
        int cima;
};

#endif // PILA_H