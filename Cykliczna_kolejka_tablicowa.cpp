//Author: Piotr Piechowicz
#include <iostream>

using namespace std;

const int maxlength=50;
typedef int elementtype;
typedef int position;

class Kolejka
{
    protected :
    elementtype Queue[maxlength];
    position Front; // Indeks elementu czo³owego
    position Rear; // Indeks ostatniego elementu

    public:
    Kolejka()
    {
        Front=0;
        Rear=maxlength-1;
    }
    int AddOne(int i)
    {
        return (i+1)%maxlength;
    }
    void Enqueue(elementtype x)
    {
        if(AddOne(AddOne(Rear))==Front)
        {
            cout<<"Lista pelna!"<<endl;
        }
        else
        {
            Rear=AddOne(Rear);
            Queue[Rear]=x;
        }
    }
    void Dequeue()
    {
     if(Empty())
            cout<<"Kolejka Pusta!"<<endl;
     else
     {
            cout<<"Usuwam 1szy elelement"<<endl;
        Front=AddOne(Front);
     }
    }
    elementtype FrontElem()
    {
        if(Empty())
            cout<<"Kolejka Pusta!"<<endl;
        else
            return Queue[Front];

    }
    void Makenull()
    {
        cout<<"Czyszcze kolejke"<<endl;
        Front=AddOne(Rear);
    }
    bool Empty()
    {
        if(AddOne(Rear)==Front)
            return true;
        else
            return false;
    }
};

int main()
{

    Kolejka *c1=new Kolejka();

    cout<<"Czy pusty : "<<c1->Empty()<<endl;
    cout<<"Wstawiam 5 "<<endl;
    c1->Enqueue(5);
    cout<<"Czy pusty : "<<c1->Empty()<<endl;
    cout<<"Zwracam pierwszy ele: "<<c1->FrontElem()<<endl;
    c1->Dequeue();
    cout<<"Czy pusty : "<<c1->Empty()<<endl;
    cout<<"Wstawiam 4 "<<endl;
    c1->Enqueue(4);
    cout<<"Wstawiam 3 "<<endl;
    c1->Enqueue(3);
    cout<<"Wstawiam 2 "<<endl;
    c1->Enqueue(2);
    cout<<"Zwracam pierwszy ele: "<<c1->FrontElem()<<endl;
    cout<<"Wstawiam 1 "<<endl;
    c1->Enqueue(1);
    cout<<"Zwracam pierwszy ele: "<<c1->FrontElem()<<endl;
    c1->Dequeue();
    cout<<"Zwracam pierwszy ele: "<<c1->FrontElem()<<endl;
    cout<<"Wstawiam 6 "<<endl;
    c1->Enqueue(6);
    cout<<"Zwracam pierwszy ele: "<<c1->FrontElem()<<endl;
    c1->Dequeue();
    c1->Dequeue();
    cout<<"Zwracam pierwszy ele: "<<c1->FrontElem()<<endl;
    c1->Makenull();
    cout<<"Czy pusty : "<<c1->Empty()<<endl;


    return 0;
}
