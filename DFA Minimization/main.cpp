#include <iostream>
#include <fstream>
using namespace std;
ifstream f("intrare.txt");
ofstream g("iesire.txt");
class AFD{int q,v,z,t;
              int *F;
              int **M;
public:
       AFD()
       {
            cout<<"nr.stari=";f>>q;
            cout<<"cardinal alfabet=";f>>v;
            cout<<"nr. stari finale=";f>>z;
             F=new int [z];
             for(int i=0;i<z;i++)
             {cout<<"Citeste starea=";
                     f>>F[i];}
             M=new int *[q];
             for(int i=0;i<q;i++)
                M[i]=new int [q];
             for(int i=0;i<q;i++)
                for(int j=0;j<v;j++)
                    f>>M[i][j];
        }
        bool finala(int x)
        {

            for (int b=0;b<z;b++)
                if(F[b]==x)
                    return true;
            return false;
        }
        int tranzitie (int x,char c)
        {
            for(int i=0;i<q;i++)
                if(M[x][i]==c)
                    return i;
            return -1;
        }
        void minimizare()
        {
            int **d;
            d=new int *[q];
            for(int i=0;i<q;i++)
                    d[i]=new int [q];
            for(int j=0;j<q;j++)
                for(int i=j+1;i<q;i++)
                    if(finala(i)!=finala(j))
                        d[i][j]=1;
                else
                    d[i][j]=0;

           int ok=1;
           while (ok)
           {
               ok=0;
               for(int i=1;i<q;i++)
                for(int j=0;j<i;j++)
                   for(int k=0;k<v;k++)
                        if(M[i][k]!=-1&&M[j][k]!=-1&&(d[M[i][k]][M[j][k]]==1||d[M[j][k]][M[i][k]]==1)&&d[i][j]==0)
                            d[i][j]=1,ok=1;
           }
           //d[7][2]=d[7][3]=d[7][4]=1;
            int stari=q,k=-1,*s=new int[q];
            for(int i=0;i<q;i++)
                s[i]=-1;
            for(int j=0;j<q;j++)
                {int nr=0;
                if(s[j]==-1)
                    s[j]=++k;
                for(int i=j+1;i<q;i++)
                    if(d[i][j]==0&&s[i]==-1)
                        ++nr,s[i]=s[j];
                if(nr>0)
                    --stari;
                }

            g<<"Numarul de stari: "<<stari<<'\n';
            int finale=z;
            for(int i=0;i<z;i++)
                for(int j=i+1;j<z;j++)
                    if(i!=j&&d[F[i]][F[j]]==d[F[j]][F[i]]&&d[F[i]][F[j]]==0)
                        finale--;
            g<<"Numarul de stari fianle: "<<finale<<'\n';
            for(int i=0;i<q;i++)
                for(int j=0;j<v;j++)
                    if(M[i][j]!=-1)
                        M[i][j]=s[M[i][j]];
            ok=0;
            g<<"Starile finale sunt: ";
            for(int i=0;i<z&&ok<finale;i++)
                {
                    g<<s[F[i]]<<" ";
                    ok++;
                }

            g<<"\nTranzitiile in noul automat sunt: ";
            for(int i=0;i<stari;i++)
                for(int k=0;k<q;k++)
                    if(s[k]==i)
                {
                for(int j=0;j<v;j++)
                    if(M[k][j]!=-1)
                {
                    char y='a'+j;
                    g<<i<<" "<<y<<" "<<M[k][j]<<'\n';
                }
                break;
                }
        /*for(int i=1;i<q;i++)
                {
                    for(int j=0;j<i;j++)
                        g<<d[i][j]<<" ";
                    g<<'\n';
                }
            for(int i=0;i<q;i++)
                g<<s[i]<<" ";*/
        }
};
int main()
{AFD a;
a.minimizare();
return 0;
}
