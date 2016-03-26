#include <iostream>
#include<fstream>
#include <cmath>
using namespace std;
ifstream f("fisier.in");
ofstream g("fisier.out");
class polinom;
class pereche {
    double coeficient;
    int exponent;
    pereche* urm;
public:
    pereche()
    {
        urm=0;
    }
    pereche(pereche &y)
    {
        coeficient=y.coeficient;
        exponent=y.exponent;
        urm=y.urm;
    }

    pereche* get_urm(){return urm;}
    int get_e(){return exponent;}
    double get_c(){return coeficient;}
friend ifstream &operator>>(ifstream&o,pereche &x);
friend istream &operator>>(istream&o,pereche &x);
friend ofstream &operator<<(ofstream&o,pereche x);
friend ostream &operator<<(ostream&o,pereche x);
friend istream &operator>>(istream &o,polinom &p);
friend class polinom;
};
ifstream &operator>>(ifstream&o,pereche &x)
{
    o>>x.coeficient>>x.exponent;
    return o;
}
istream &operator>>(istream&o,pereche &x)
{
    o>>x.coeficient>>x.exponent;
    return o;
}
ofstream &operator<<(ofstream&o,pereche x)
{
    o<<x.coeficient;
    if(x.exponent>1)
        o<<"*X^"<<x.exponent;
    else
        if(x.exponent==1)
        o<<"*X";
    return o;
}
ostream &operator<<(ostream&o,pereche x)
{
    o<<x.coeficient;
    if(x.exponent>1)
        o<<"*X^"<<x.exponent;
    else
        if(x.exponent==1)
        o<<"*X";
    return o;
}
class polinom {
    int elemente;
    pereche *prim;
public:
    polinom()
    {
        prim=new pereche;
    }
    polinom(polinom &y)
    {
        elemente=y.elemente;
        prim=y.prim;
    }
    void sortare();
    polinom operator+(polinom p);
    polinom operator-(polinom p);
    polinom operator*(polinom p);
    double operator()(double x);
friend istream &operator>>(istream &o,polinom &p);
friend ostream &operator<<(ostream &o,polinom p);
};
istream &operator>>(istream &o,polinom &p)
{
    pereche *t;
    t=new pereche;
    t->urm=0;
    cout<<"Numarul de monoame ale polinomului:";
    o>>p.elemente;
    for(int i=1;i<=p.elemente;i++)
        {
        if(i==1)
            {
               p.prim=new pereche;
               cout<<"Introduceti coeficientul urmat de exponentul monomului:";
               o>>(*p.prim);
            }
            else
            {
                pereche *q=p.prim;
                while(q->get_urm()!=0)
                    q=q->get_urm();
                t=new pereche;
                cout<<"Introduceti coeficientul urmat de exponentul monomului:";
                o>>(*t);
                q->urm=t;
                t->urm=0;

            }
        }
        p.sortare();
return o;
}
ostream &operator<<(ostream &o,polinom p)
{
    pereche *q;
    q=p.prim;
    while(q!=0)
    {
        if(q==p.prim)
        o<<(*q);
        else
        {
            if(q->get_c()>0)
                o<<"+"<<(*q);
            else
                o<<(*q);
        }
        q=q->get_urm();
    }
    o<<"=0\n";
return o;
}
void polinom::sortare()
{
    if(prim!=0)
    {
        pereche *actual=prim;
        pereche *vechi=0;
        pereche *aux=0;
        bool sortat=false;
        for(int i=1;i<=elemente;i++)
        {
            while(actual->urm!=0)
            {
                aux=actual->urm;
                if(actual->exponent>aux->exponent)
                {
                    actual->urm=aux->urm;
                    aux->urm=actual;
                    sortat=true;
                    if(vechi!=0)
                        vechi->urm=aux;
                    vechi=aux;
                    if(prim==actual)
                        prim=aux;

                }
                else
                {
                    vechi=actual;
                    actual=actual->urm;
                }
            }
            if(sortat==true)
            {
                vechi=0;
                actual=prim;
                sortat=false;
            }
            else
                break;
        }
    }
}
    polinom polinom::operator+(polinom p)
    {
        polinom a;
        pereche *x,*y,*z;
        a.prim=new pereche;
        x=prim;
        y=p.prim;
        if(elemente==p.elemente&&elemente==1)
        {
            if(prim->exponent==p.prim->exponent)
            {
                a.prim->exponent=prim->exponent;
                a.prim->coeficient=prim->coeficient+p.prim->coeficient;
            }
            else
            {
                a.prim->exponent=prim->exponent;
                a.prim->coeficient=prim->coeficient;
                pereche *t=new pereche;
                t->coeficient=p.prim->coeficient;
                t->exponent=p.prim->exponent;
                t->urm=0;
                a.prim->urm=t;
                a.elemente=2;
            }
        }
        else
            {if(prim->exponent<p.prim->exponent)
            {
                pereche *r=new pereche;
                r=prim;
                a.prim=r;
                x=prim->urm;
            }
        else
            if(prim->exponent>p.prim->exponent)
               {
                pereche *r=new pereche;
                r=p.prim;
                a.prim=r;
                y=p.prim->urm;
               }
        else
            {
            pereche *r=new pereche;
            r->coeficient=p.prim->coeficient+prim->coeficient;
            r->exponent=prim->exponent;
            a.prim=r;
            y=p.prim->urm;
            x=prim->urm;
            }
        a.elemente=1;
        z=a.prim;
        while(x!=0&&y!=0)
        {
            if(x->exponent<y->exponent)
            {
                pereche *r=new pereche;
                r->coeficient=x->coeficient;
                r->exponent=x->exponent;
                r->urm=0;
                z->urm=r;
                z=r;
                a.elemente++;
                x=x->urm;
            }
            else
                if(x->exponent>y->exponent)
            {
                pereche *r=new pereche;
                r->coeficient=y->coeficient;
                r->exponent=y->exponent;
                r->urm=0;
                z->urm=r;
                z=r;
                a.elemente++;
                y=y->urm;
            }
            else
            {
                pereche *r=new pereche;
                r->coeficient=y->coeficient+x->coeficient;
                r->exponent=x->exponent;
                r->urm=0;
                z->urm=r;
                z=r;
                a.elemente++;
                y=y->urm;
                x=x->urm;
            }
        }
        while(x!=0)
        {
            pereche *r=new pereche;
            r->coeficient=x->coeficient;
            r->exponent=x->exponent;
            r->urm=0;
            z->urm=r;
            z=r;
            a.elemente++;
            x=x->urm;
        }
        while(y!=0)
        {
            pereche *r=new pereche;
            r->coeficient=y->coeficient;
            r->exponent=y->exponent;
            r->urm=0;
            z->urm=r;
            z=r;
            a.elemente++;
            y=y->urm;
        }
            }
     if(a.elemente>1)
   {while(a.prim!=0&&a.prim->coeficient==0)
        a.prim=a.prim->urm;
    if(a.prim!=0)
   x=a.prim->urm;
   else
    x=0;
   pereche *vechi=a.prim;
    while(x!=0)
    {
        if(x->coeficient==0)
        {
            pereche *u=x;
            vechi->urm=x->urm;
            vechi=vechi->urm;
            if(vechi!=0)
            x=vechi->urm;
            else
                x=0;
            delete u;
            a.elemente--;
        }
        else
        {vechi=x;
        x=x->urm;
        }
    }
    if(a.elemente>=0)
    {a.sortare();
    return a;
    }
    else
    {
    a.prim=0;
    a.prim->coeficient=0;
    a.prim->exponent=0;
    return a;
    }
   }
    else
    {
        if(a.prim->coeficient==0)
        {
    a.prim=0;
    pereche *r=new pereche;
    r->coeficient=0;
    r->exponent=0;
    r->urm=0;
    a.prim=r;
    return a;
        }
    }
    }


    polinom polinom::operator-(polinom p)
    {
        polinom a;
        pereche *x,*y,*z;
        a.prim=new pereche;
        x=prim;
        y=p.prim;
        if(prim->exponent<p.prim->exponent)
            {
                pereche *r=new pereche;
                r=prim;
                a.prim=r;
                x=prim->urm;
            }
        else
            if(prim->exponent>p.prim->exponent)
               {
                pereche *r=new pereche;
                r=p.prim;
                r->coeficient=r->coeficient*(-1);
                a.prim=r;
                y=p.prim->urm;
               }
        else
            {
            pereche *r=new pereche;
            r->coeficient=prim->coeficient-p.prim->coeficient;
            r->exponent=prim->exponent;
            a.prim=r;
            y=p.prim->urm;
            x=prim->urm;
            }
        a.elemente=1;
        z=a.prim;
        while(x!=0&&y!=0)
        {
            if(x->exponent<y->exponent)
            {
                pereche *r=new pereche;
                r->coeficient=x->coeficient;
                r->exponent=x->exponent;
                r->urm=0;
                z->urm=r;
                z=r;
                a.elemente++;
                x=x->urm;
            }
            else
                if(x->exponent>y->exponent)
            {
                pereche *r=new pereche;
                r->coeficient=y->coeficient*(-1);
                r->exponent=y->exponent;
                r->urm=0;
                z->urm=r;
                z=r;
                a.elemente++;
                y=y->urm;
            }
            else
            {
                pereche *r=new pereche;
                r->coeficient=x->coeficient-y->coeficient;
                r->exponent=x->exponent;
                r->urm=0;
                z->urm=r;
                z=r;
                a.elemente++;
                y=y->urm;
                x=x->urm;
            }
        }
        while(x!=0)
        {
            pereche *r=new pereche;
            r->coeficient=x->coeficient;
            r->exponent=x->exponent;
            r->urm=0;
            z->urm=r;
            z=r;
            a.elemente++;
            x=x->urm;
        }
        while(y!=0)
        {
            pereche *r=new pereche;
            r->coeficient=y->coeficient*(-1);
            r->exponent=y->exponent;
            r->urm=0;
            z->urm=r;
            z=r;
            a.elemente++;
            y=y->urm;
        }
        if(a.elemente>1)
   {while(a.prim!=0&&a.prim->coeficient==0)
        a.prim=a.prim->urm;
    if(a.prim!=0)
   x=a.prim->urm;
   else
    x=0;
   pereche *vechi=a.prim;
    while(x!=0)
    {
        if(x->coeficient==0)
        {
            pereche *u=x;
            vechi->urm=x->urm;
            vechi=vechi->urm;
            if(vechi!=0)
            x=vechi->urm;
            else
                x=0;
            delete u;
            a.elemente--;
        }
        else
        {vechi=x;
        x=x->urm;
        }
    }
    if(a.elemente>=0)
    {a.sortare();
    return a;
    }
    else
    {
    a.prim=0;
    a.prim->coeficient=0;
    a.prim->exponent=0;
    return a;
    }
    }
    else
    {
        if(a.prim->coeficient==0)
        {
    a.prim=0;
    pereche *r=new pereche;
    r->coeficient=0;
    r->exponent=0;
    r->urm=0;
    a.prim=r;
    return a;
        }
    }
    }

     double polinom::operator()(double t)
     {
         double s=0;
         pereche *x=prim;
         while (x!=0)
            {
                s+=x->coeficient*pow(t,x->exponent);
                x=x->urm;
            }
        return s;
     }

     polinom polinom::operator*(polinom p)
     {
         polinom a;
         double v[100]={0};
         int maxi=-1;
         for(pereche *i=prim;i!=0;i=i->urm)
            for(pereche *j=p.prim;j!=-0;j=j->urm)
                {v[i->exponent+j->exponent]+=i->coeficient*j->coeficient;
                if(i->exponent+j->exponent>maxi)
                    maxi=i->exponent+j->exponent;
                }
        int primul=0;
        pereche *vechi;
        for(int i=0;i<=maxi;i++)
        {
            if(v[i]!=double(0))
            {
                pereche *x;
                x=new pereche;
                x->coeficient=v[i];
                x->exponent=i;
                x->urm=0;
                if(primul==0)
                {
                    a.prim=x;
                    vechi=x;
                    primul++;
                }
                else
                   {
                       vechi->urm=x;
                       vechi=x;
                   }
            }
        }
        return a;
     }

int main()
{
    polinom q,w;
     while(1)
         {

         cout<<"\n1.Citire primul polinom!\n";
         cout<<"2.Citire al doilea polinom!\n";
         cout<<"3.Diferenta dintre primul si al doilea polinom!\n";
         cout<<"4.Diferenta dintre al doilea si primul polinom!\n";
         cout<<"5.Suma celor doua polinoame!\n";
         cout<<"6.Produs celor doua polinoame!\n";
         cout<<"7.Valoarea primului polinom in punctul x!\n";
         cout<<"8.Valoarea celui de-al doilea polinom in punctul x!\n";
         cout<<"9.Iesire!\n";
         cout<<"Optiunea aleasa:";
         int x;
         cin>>x;
         if(x==1)
            cin>>q;
         else
            if(x==2)
                cin>>w;
         else
            if(x==3)
         {
             polinom c;
             c=q-w;
             cout<<c;
         }
         else
            if(x==4)
         {
            polinom d;
            d=w-q;
            cout<<d;
         }
            if(x==5)
         {
             polinom e;
             e=q+w;
             cout<<e;
         }
         else
            if(x==6)
         {
             polinom g;
             g=q*w;
             cout<<g;
         }
         if(x==7)
         {
             double y;
             cout<<"Valoarea x:";
             cin>>y;
             cout<<q(y);
         }
         else
            if(x==8)
         {
             double y;
             cout<<"Valoarea x:";
             cin>>y;
             cout<<w(y);
         }
         else
            if(x==9)
            break ;

     }
    return 0;
}
