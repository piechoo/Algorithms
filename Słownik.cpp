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
            //cout<<"kosn"<<endl;
            for(int i=0;i<B;i++)
            {
                D[i]=NULL;
            }
        }
        ~dictionary()
        {
            position k;
            for(int i=0;i<B;i++)
            {
                while(D[i]!=NULL)
                {
                    k=D[i];
                    D[i]=k->next;
                    delete k;
                }
            }

        }
    void Makenul()
    {
        position k;
        for(int i=0;i<B;i++)
            {
                while(D[i]!=NULL)
                {
                    k=D[i];
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
        position k;

        if(D[h]!=NULL)
        {

            position n=D[h];
            position z;
            //cout<<x<<endl;
            if(n->element==x)
                {
                    //cout<<"ten ele"<<endl;
                    n=NULL;
                }
            while(n->next!=NULL)
            {
                z=n->next;

                if(z->element==x)
                {

                    k=n->next;
                    n->next=k->next;
                    delete k;
                    break;
                }
                n=n->next;
            }
        }
    }

};

int main()
{
    dictionary *d1= new dictionary();
    //cout<<"cos"<<endl;
    //char* k="aos";
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
    //d1->H();
    //cout<<d1->H(k);
    //cout << "Hello world!" << endl;
    return 0;
}
