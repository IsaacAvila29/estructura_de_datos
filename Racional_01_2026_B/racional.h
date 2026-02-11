#ifndef RACIONAL_H
#define RACIONAL_H

class Racional {
public:
    int num;
    int den;
    Racional();
    bool set(int Num, int Den);
    Racional Sumar(Racional R2);
    Racional Restar(Racional R2);
    Racional Multiplicar(Racional R2);
    Racional Dividir(Racional R2);
    void imprimir();
    int Decimal();
};

#endif // RACIONAL_H
