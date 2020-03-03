//Author: Piotr Piechowicz
#include <iostream>

using namespace std;

typedef int elementtype;

struct celltype
{
    elementtype element;
    celltype * next;
};

typedef celltype * position;

class Lista
{
    protected :
        position l; // wskaŸnik do g³owy listy
    public:

        Lista()
        {
            l=new celltype;
            l->next=NULL;

        } //konstruktor
        ~Lista()
        {
            position k;
            while(l->next!=NULL)
            {
            k = l;
            delete l;
            l=k;
            }
        } //destruktor
        void Insert(elementtype x, position p)
        {
            position t = new celltype;
            t->next=p->next;
            p->next = t;
            t->element = x;
        }
        void Delete(position p)
        {
            position k=p->next;
            p->next=k->next;
            delete k;
        }
        elementtype Retrieve(position p)
        {
            return p->next->element;
        }
        position Locate(elementtype x)
        {
            position k = l;
            while(k->next->element!=x)
            {
                k=k->next;
            }
            return k;
        }
        position First()
        {
            return l;
        }
        position Next(position p)
        {
          return p->next;
        }
        position Previous(position p)
        {
         position k=l;
         while(k->next!=p)
         {
             k=k->next;
         }
         return k;
        }
        position END()
        {
            position k =l;
            while(k->next!=NULL)
            {
                k=k->next;
            }
        return k;
        }
        void print()
        {
            position k=l;
            int numer=0;
            while(k->next!=NULL)
            {   numer++;
                k=k->next;
                cout<<"Numer "<<numer<<": "<<k->element<<endl;
            }
            cout<<endl;
        }
};

int main()
{
Lista *l1= new Lista();
//l.last=-1;
l1->Insert(100,l1->First());
l1->print();

for (int i=0; i<3;i++)
l1->Insert(i,l1->First());
l1->print();

l1->Insert(20,l1->Previous(l1->END()));
l1->print();
l1->Delete(l1->Locate(20));
l1->print();

    return 0;
}
