#ifndef CONJUNTO_H
#define CONJUNTO_H
#define maxCard 10
typedef int typeinfo;


class Conjunto
{
    private:
      typeinfo elementos[maxCard];
      unsigned short int card; // Para ahorrar memoria:)
    public:
        //Este es el constructor
        Conjunto();

        bool Member(typeinfo); //Recordando que typeinfo es un int, entonces el parametro de esta funcion es un int
        bool AddElem(typeinfo); //Como precondicion, que no este lleno, ni que el elemento este repetido
        bool RmvElem(typeinfo);
        void Copy(Conjunto&); //
        bool Equal(Conjunto);//Comparamos que dos conjuntos sean iguales.
        bool Print(); //
        void Intersect(Conjunto, Conjunto&);
        bool Union(Conjunto, Conjunto&);
        //void RmvAll();
        virtual ~Conjunto();

};

#endif // CONJUNTO_H