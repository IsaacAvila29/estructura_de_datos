#include "Conjunto.h"

inline Conjunto::Conjunto() 
{
    card = 0;
}

inline bool Conjunto::Member(typeinfo elDato)
{
    for(int i=0; i<card; i++)
        if(elementos[i] == elDato) {return true;}
    
    return false;
}
inline bool Conjunto::AddElem(typeinfo elDato)
{
    if(card == maxCard || Member(elDato)) {return false;}
    
    elementos[card++] = elDato;
    return true;
}
inline bool Conjunto::RmvElem(typeinfo elDato)
{
    for(int i=0; i<card; i++)
        if(elementos[i] == elDato) {
            elementos[i] = elementos[--card];
            return true;
        }


    return false;

}

inline void Conjunto::Copy(Conjunto& otro)
{
    card = otro.card;
    for(int i=0; i<card; i++)
        elementos[i] = otro.elementos[i];
}
