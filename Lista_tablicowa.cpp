//Author: Piotr Piechowicz
#include<stdio.h>
typedef int elementtype, position ;
const int maxlength=10;

struct List
{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l)
{
    return l.last+1;
}

position First(List l)
{
    if(l.last>=0)
    {
    return 0;
    }
    else
        return l.last+1;
}

position Next(position p,List l)
{
    return p+1;
}


position Previous(position p,List l)
{
    if (p>0)
        return p-1;
    else
        return 0;
}



position Locate(elementtype x, List l)
{ //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
    for(int i=0; i<=l.last;i++)
    {
        if(l.elements[i]==x)
            return i;
    }
    return END(l);
}

elementtype Retrieve(position p, List l)
{
    return l.elements[p];
}

bool Insert(int x, position p, List &l)
{
    if(p<=l.last)
    {
        for(int i=l.last;i>=p;i--)
        {
            l.elements[i+1]=l.elements[i];
        }
        l.elements[p]=x;
        l.last++;
        return true;
    }
    else if(p-1>l.last)
        return false;
    else
    {
        l.elements[p]=x;
        l.last++;
        return true;

    }


}
void dupl(List &l)
{
    position i=position(First(l));
    position k=END(l);
    while (i!=k)
	{
        Insert(Retrieve(i,l),END(l),l);

		i=Next(i,l);
	}
}

bool Delete(position p, List &l)
{
    if(p<=l.last)
    {
        for(int i=p;i<l.last;i++)
        {
            l.elements[i]=l.elements[i+1];
        }
        l.elements[l.last]=0;
        l.last--;
    return true;
    }
    else
        return false;
}
void deldup(List &l)
{
    for(int j=0; j<l.last; j++)
    {
        for(int i=j+1; i<=l.last; i++)
        {
            if(l.elements[i]==l.elements[j])
               Delete(i,l);
        }
    }

}
void print(List l)
{
	position i=First(l);

	while (i!=END(l))
	{
		printf ("  %d,", Retrieve(i,l));
		i=Next(i,l);
	}
	printf("\n");

}

using namespace std;

int main()
{
    List l;

    l.last=-1;
    Insert(100,First(l),l);
    print (l);
    for (int i=0; i<3;i++)
        Insert(i,First(l),l);

    print (l);
    Insert (20,Previous(END(l),l) ,l);
    print(l);
    Delete( Locate(20,l),l);
    print(l);
    dupl(l);
    print(l);
    Insert(2,First(l),l);
    print(l);
    deldup(l);
    print(l);
    return 0;
}
