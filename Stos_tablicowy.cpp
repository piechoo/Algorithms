//Author: Piotr Piechowicz
#include <iostream>

using namespace std;

const int maxlegth=20;
typedef int elementtype;
typedef int position;

class Stos
{
    int S[maxlegth] ;
    position Top;//szczyt stosu

    public:

        Stos()
        {
            Top=-1;
        }

        void Push(elementtype x)
        {
            if(Top+1<maxlegth)
            {
                Top++;
                S[Top]=x;
            }
        }

        bool Empty()
        {
            if(Top==-1)
                return true;
            else
                return false;
        }

        void Pop()
        {
            if(!Empty())
            {
                S[Top]=NULL;
                Top--;
            }
        }

        elementtype TopElem()
        {
            if(!Empty())
            {
                return S[Top];
            }
            else
                return -1;
        }

        void Makenull()
        {
            while(Top!=-1)
            {
                S[Top]=NULL;
                Top--;
            }
        }
        void Print()
        {
            int i=Top;
            while(i!=-1)
            {
                cout<<S[i]<<endl;
                i--;
            }
        }
};

int main()
{

    Stos *s1 = new Stos();

    cout<<"Czy pusty? :"<<s1->Empty()<<endl;
    cout<<"Wrzucam 1 na stos"<<endl;
    s1->Push(1);
    cout<<"Zwracam top element: "<<s1->TopElem()<<endl;
    cout<<"Czy pusty? :"<<s1->Empty()<<endl;
    cout<<"Usuwam top element!"<<endl;
    s1->Pop();
    cout<<"Czy pusty? :"<<s1->Empty()<<endl;
    cout<<"Wrzucam 2 na stos"<<endl;
    s1->Push(2);
    cout<<"Wrzucam 3 na stos"<<endl;
    s1->Push(3);
    cout<<"Zwracam top element: "<<s1->TopElem()<<endl;
    cout<<"Czyszcze stos!"<<endl;
    s1->Makenull();
    cout<<"Czy pusty? :"<<s1->Empty()<<endl;
    return 0;
}
