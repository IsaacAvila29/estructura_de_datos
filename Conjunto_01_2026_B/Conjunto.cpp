#include "Conjunto.h"
#include <iostream>

Conjunto::Conjunto() 
{
    card = 0;
}

bool Conjunto::Member(typeinfo elDato) const
{
    for(int i=0; i<card; i++)
        if(elementos[i] == elDato) {return true;}
    
    return false;
}
bool Conjunto::AddElem(typeinfo elDato)
{
    if(card == maxCard || Member(elDato)) {return false;}
    
    elementos[card++] = elDato;
    return true;
}
bool Conjunto::RmvElem(typeinfo elDato)
{
    for(int i=0; i<card; i++)
        if(elementos[i] == elDato) {
            elementos[i] = elementos[--card];
            return true;
        }


    return false;

}

void Conjunto::Copy(Conjunto& otro)
{
    card = otro.card;
    for(int i=0; i<card; i++)
        elementos[i] = otro.elementos[i];
}


bool Conjunto::Print()
{
    for(int i=0; i<card; i++)
        std::cout << elementos[i] << " ";
    std::cout << std::endl;
    return true;
}

void Conjunto::Intersect(const Conjunto Conj2, Conjunto& Result)
{
    Result.card = 0;
    for (int i=0; i < card; i++)
        if(Conj2.Member(elementos[i]))
            Result.AddElem(elementos[i]);
}

bool Conjunto::Union(Conjunto Conj2, Conjunto& Result)
{
    Result.Copy(*this);
    for (int i=0; i < Conj2.card; i++)
        if(!Member(Conj2.elementos[i]))
            Result.AddElem(Conj2.elementos[i]);
    
    return true;
}

Conjunto::~Conjunto() {}

