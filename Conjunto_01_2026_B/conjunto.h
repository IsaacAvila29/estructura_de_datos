#ifndef CONJUNTO_H
#define CONJUNTO_H
#define maxCard 10
typedef int typeinfo;


class Conjunto
{
    private:
      int elementos[maxCard];
      int card;
    public:
        Conjunto();
        bool Member(typeinfo); //
        bool AddElem(typeinfo); //
        void RmvElem(typeinfo);
        void Copy(Conjunto&); //
        bool Equal(Conjunto);
        bool Print(); //
        void Intersect(Conjunto, Conjunto&);
        bool Union(Conjunto, Conjunto&);
        //void RmvAll();
        virtual ~Conjunto();

};

#endif // CONJUNTO_H