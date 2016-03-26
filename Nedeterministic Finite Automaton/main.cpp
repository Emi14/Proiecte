#include <iostream>
#include<fstream>
#include<map>
using namespace std;
ifstream fin("fisier.txt");
class NFA {
int initiala,finale,stari,tran,cuvinte;
int *f;
public :multimap <pair <int,int>,char>t;
public:
    void stari_finale();
    void tranzitii();
    void rezolvare();
};
void NFA::stari_finale()
{
    //ifstream fin(fisier);
    fin>>finale;
    f=new int[finale+1];
    for(int i=1;i<=finale;i++)
        fin>>f[i];
}

void NFA::tranzitii() //char *fisier
{
    //ifstream fin(fisier);
    fin>>tran;
    for(int i=1;i<=tran;i++)
    {
        int x,y;
        char c2;
        fin>>x>>y>>c2;
        t.insert(make_pair(make_pair(x,y),c2));
    }
}

void NFA::rezolvare()
{
    fin>>stari>>initiala;
    //stari_finale();
    //tranzitii();
    fin>>cuvinte;
    for(int i=1;i<=cuvinte;i++)
    {
        int l;
        fin>>l;
        char *cuv=new char[l+1];
        fin.get();
        fin.getline(cuv,l+1);
        int *c=new int[stari+10],nr=1;
        c[1]=initiala;
        for(int j=0;j<l;j++)
        {
            int *c1=new int[stari+10];
            int n=0;
            for(int k=1;k<=nr;k++)
                for(int z=0;z<=stari;z++)
                if(t.find(make_pair(c[k],z))!=t.end())
                {std::multimap<pair<int,int>,char>::iterator it;
                for (it=t.equal_range(make_pair(c[k],z)).first; it!=t.equal_range(make_pair(c[k],z)).second; ++it)
                        if(it->second==cuv[j])
                            n++,c1[n]=z;
                }
            for(int k=1;k<=n;k++)
                c[k]=c1[k];
            nr=n;
           delete []c1;
        }
        for(int j=1;j<=nr;j++)
            {for(int k=1;k<=finale;k++)
                if(c[j]==f[k])
        {
            cout<<"Cuvantul "<<cuv<<" este acceptat!\n";
            nr=-1;
            break;
        }
        if(nr==-1)
            break;
            }
        if(nr!=-1)
        cout<<"Cuvantul "<<cuv<<" nu este acceptat!\n";
        delete []c;
        delete []cuv;
    }

}

int main()
{
    NFA test;
    test.tranzitii();
    test.stari_finale();
    test.rezolvare();
    //test.stari_finale(); //"fisier.txt"
   /* for(int i=1;i<=test.finale;i++)
        cout<<test.f[i];
    cout<<'\n';*/
    //test.tranzitii();
   /* for (const auto &pair : test.t)
    std::cout << pair.first.first << "," << pair.first.second << ": " << pair.second << '\n';*/

    return 0;
}
