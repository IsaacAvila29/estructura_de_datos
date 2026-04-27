#include "cola.h"

inline bool Cola::Empty(){
    return (Inicio == -1 && Final == -1);
}
inline bool Cola::Full(){
    return (Final + 1) % MAX == Inicio;
}

inline bool Cola::Insert(tipodato dato){
    if(Full()) return false;
    Final = (Final + 1) % MAX;
    elem[Final] = dato;
    if(Inicio == -1) Inicio = Final;
    return true;
}

inline bool Cola::Erase(tipodato &dato){
   if(Empty()) return false;
   dato = elem[Inicio];

}