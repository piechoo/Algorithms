//Author: Piotr Piechowicz
#include <iostream>

using namespace std;



const int B=65;
typedef char * elementtype;
struct celltype
{
    elementtype element;
    celltype * next;
};
typedef celltype * position;

class dictionary
{
    protected :
        position D[B];//tablica nag³ówków list
    public:
        dictionary()
        {
            for(int i=0;i<B;i++)
            {
                D[i]->next=NULL;
            }
        }
        ~dictionary()
        {
            for(int i=0;i<B;i++)
            {
                while(D[i]!=NULL)
                {
                    position k=D[i];
                    D[i]=k->next;
                    delete k;
                }
            }

        }
    void Makenul()
    {
        for(int i=0;i<B;i++)
            {
                while(D[i]!=NULL)
                {
                    position k=D[i];
                    D[i]=k->next;
                    delete k;
                }
            }
    }
    int H(elementtype x)
    {
        int k=(int)x[0];
        return k%B;
    }
    bool Member(elementtype x)
    {
        int h=H(x);
        position k=D[h];
        while(k!=NULL)
        {
            if(k->element==x)
                return true;
            else
                k=k->next;
        }
        return false;

    }
    void Insert(elementtype x)
    {
        if(!Member(x))
        {
            int h=H(x);
            position n=new celltype;
            n->element=x;
            n->next=D[h];
            D[h]=n;
        }

    }
    void Delete(elementtype x)
    {
        int h=H(x);
        if(D[h]!=NULL)
        {
            position n=D[h];
            while(n->next!=NULL)
            {
                if(n->next->element==x)
                {
                    position k=n->next;
                    n->next=k->next;
                    delete k;
                }
                n=n->next;
            }
        }
    }

};

int main()
{
    dictionary *d1= new dictionary();
    cout<<"cos"<<endl;
    d1->Insert("Ala");
    cout<<d1->Member("Ala")<<endl;
    cout<<d1->H("Ala")<<endl;
    d1->Insert("As");
    cout<<d1->Member("As")<<endl;
    cout<<d1->H("As")<<endl;
    cout<<d1->Member("Ala")<<endl;
    cout<<d1->H("Ala")<<endl;
    d1->Insert("Piechowicz");
    cout<<d1->H("Piechowicz")<<endl;
    cout<<d1->Member("Piechowicz")<<endl;
    d1->Delete("Ala");
    cout<<d1->Member("As")<<endl;
    cout<<d1->Member("Ala")<<endl;
    d1->Makenul();
    cout<<d1->Member("As")<<endl;
    cout<<d1->Member("Piechowicz")<<endl;
    return 0;
}
