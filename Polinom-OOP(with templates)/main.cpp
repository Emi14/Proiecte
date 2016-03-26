#include <iostream>
#include <cmath>
using namespace std;
template <class T>
class polinom;
template <class T>
class pereche;
template <class T>
class polinom_ireductibil;
template <class T> istream &operator>> (istream&o,pereche <T> &x);
template <class T> ostream &operator<< (ostream&o,pereche <T> x);
template <class T>
class pereche
    {
protected:    T coeficient;
    int exponent;
public:  pereche* urm;
    pereche* get_urm(){return urm;}
    int get_e(){return exponent;}
    T get_c(){return coeficient;}
friend istream &operator>> <> (istream&o,pereche <T> &x);
friend ostream &operator<< <> (ostream&o,pereche <T> x);
friend class polinom <T>;
friend class polinom_ireductibil <T>;
    };
template <class T>
istream &operator>> (istream &o,pereche <T> &x)
{
    o>>x.coeficient;
    o>>x.exponent;
    return o;
}
template <class T>
ostream &operator<<(ostream&o,pereche <T> x)
{
    o<<x.coeficient;
    if(x.exponent>1)
        o<<"*X^"<<x.exponent;
    else
        if(x.exponent==1)
        o<<"*X";
    return o;
}

template <class T> istream &operator>> (istream &o,polinom <T> &p);
template <class T> ostream &operator<< (ostream &o, const polinom  <T> p);
template <class T>
class polinom {
 protected:   int elemente;
    pereche <T> *prim;
public:
    polinom <T> ()
    {
        prim=new pereche <T>;
        prim->urm=0;
        prim->exponent=0;
        prim->coeficient=0;
    }
    ~polinom <T> ()
    {
        delete prim;
    }
    void sortare();
     polinom operator+(polinom &p);
    virtual polinom operator-(polinom &p);
    virtual polinom operator*(polinom &p);
    virtual T operator()(T x);
    pereche<T>*  get_p(){return prim;}
friend istream &operator>> <> (istream &o,polinom <T> &p);
friend ostream &operator<< <> (ostream &o,const polinom <T> p);
};
template <class T>
istream &operator>>(istream &o,polinom <T> &p)
{
    pereche <T> *t;
    t=new pereche <T>;
    t->urm=0;
    cout<<"Numarul de monoame ale polinomului:";
    o>>p.elemente;
    for(int i=1;i<=p.elemente;i++)
        {
        if(i==1)
            {
               p.prim=new pereche <T>;
               cout<<"Introduceti coeficientul urmat de exponentul monomului:";
               o>>(*p.prim);
               p.prim->urm=0;
            }
            else
            {
                pereche <T> *q=p.prim;
                while(q->urm!=0)
                    q=q->urm;
                t=new pereche <T>;
                cout<<"Introduceti coeficientul urmat de exponentul monomului:";
                o>>(*t);
                q->urm=t;
                t->urm=0;

            }
        }
        p.sortare();
return o;
}
template <class T>
ostream &operator<< (ostream &o,const polinom <T> p)
{
    pereche <T> *z=new pereche <T>;
    z=p.prim;

    while(z!=0)
    {
        if(z==p.prim)
        o<<(*z);
        else
        {
            if(z->get_c()>0)
                o<<"+"<<(*z);
            else
                o<<(*z);
        }
        z=z->urm;
    }
    o<<"=0\n";

return o;
}
template <class T>
void polinom <T> ::sortare()
{
    if(prim!=0)
    {
        pereche <T> *actual=prim;
        pereche <T> *vechi=0;
        pereche <T> *aux=0;
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
template <class T>
polinom <T>  polinom<T>::operator+(polinom<T> &p)
    {
        polinom <T> a;
        pereche <T> *x,*y,*z;
        a.prim=new pereche <T>;
        a.prim->coeficient=NULL;
        a.prim->exponent=NULL;
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
                pereche <T> *t=new pereche <T>;
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
                pereche <T> *r=new pereche <T>;
                r=prim;
                a.prim=r;
                x=prim->urm;
            }
        else
            if(prim->exponent>p.prim->exponent)
               {
                pereche <T> *r=new pereche <T>;
                r=p.prim;
                a.prim=r;
                y=p.prim->urm;
               }
        else
            {
            pereche <T> *r=new pereche <T>;
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
                pereche <T> *r=new pereche <T>;
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
                pereche <T> *r=new pereche <T>;
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
                pereche <T> *r=new pereche <T>;
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
            pereche <T> *r=new pereche <T>;
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
            pereche <T> *r=new pereche <T>;
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
   pereche <T> *vechi=a.prim;
    while(x!=0)
    {
        if(x->coeficient==0)
        {
            pereche <T> *u=x;
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
    pereche <T> *r=new pereche <T>;
    r->coeficient=0;
    r->exponent=0;
    r->urm=0;
    a.prim=r;
    return a;
        }
    }
    }
template <class T>
    polinom <T> polinom <T>::operator-(polinom <T> &p)
    {
        polinom a;
        pereche <T> *x,*y,*z;
        a.prim=new pereche <T>;
        x=prim;
        y=p.prim;
        if(prim->exponent<p.prim->exponent)
            {
                pereche <T> *r=new pereche <T>;
                r=prim;
                a.prim=r;
                x=prim->urm;
            }
        else
            if(prim->exponent>p.prim->exponent)
               {
                pereche <T> *r=new pereche <T>;
                r=p.prim;
                r->coeficient=r->coeficient*(-1);
                a.prim=r;
                y=p.prim->urm;
               }
        else
            {
            pereche <T> *r=new pereche <T>;
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
                pereche <T> *r=new pereche <T>;
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
                pereche <T> *r=new pereche <T>;
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
                pereche <T> *r=new pereche <T>;
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
            pereche <T> *r=new pereche <T>;
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
            pereche <T> *r=new pereche <T>;
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
   pereche <T> *vechi=a.prim;
    while(x!=0)
    {
        if(x->coeficient==0)
        {
            pereche <T> *u=x;
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
    pereche <T> *r=new pereche <T>;
    r->coeficient=0;
    r->exponent=0;
    r->urm=0;
    a.prim=r;
    return a;
        }
    }
    }
template <class T>
     T polinom <T>::operator()(T t)
     {
         T s=0;
         pereche <T> *x=prim;
         while (x!=0)
            {
                s+=x->coeficient*pow(t,x->exponent);
                x=x->urm;
            }
        return s;
     }
template <class T>
polinom <T> polinom<T>::operator*(polinom <T> &p)
     {
         polinom a;
         T v[100]={0};
         int maxi=-1;
         for(pereche <T> *i=prim;i!=0;i=i->urm)
            for(pereche <T> *j=p.prim;j!=-0;j=j->urm)
                {v[i->exponent+j->exponent]+=i->coeficient*j->coeficient;
                if(i->exponent+j->exponent>maxi)
                    maxi=i->exponent+j->exponent;
                }
        int primul=0;
        pereche <T> *vechi;
        for(int i=0;i<=maxi;i++)
        {
            if(v[i]!=T(0))
            {
                pereche <T> *x;
                x=new pereche <T>;
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
template <class T> istream &operator>> (istream &o,polinom_ireductibil <T> &p);
template <class T> ostream &operator<< (ostream &o, const polinom_ireductibil  <T> &p);
template <class T>
class polinom_ireductibil:public polinom <T>
{
    T min_coef;
    void ciurul (int n,bool v[]);
    void coeficienti (T v[]);

public :
    polinom_ireductibil()
    {
        min_coef=32000;
        polinom<T>::prim=new pereche <T>;
        polinom<T>::prim->coeficient=0;
        polinom<T>::prim->exponent=0;
    }
    ~polinom_ireductibil()
    {

        min_coef=0;
    }
    void Einstein ();
    friend istream &operator>> <> (istream &o,polinom_ireductibil <T> &p);
    friend ostream &operator<< <> (ostream &o,const polinom_ireductibil <T> &p);
};
template <class T>
void polinom_ireductibil <T> ::ciurul(int n,bool v[])
{
    v[1]=false;
    for(int i=2;i<=n;i++)
        v[i]=true;
    for(int i=4;i<=n;i+=2)
        v[i]==false;
    for(int i=3;i<=n;i++)
        if(v[i]==true)
            for(int j=i*2;j<=n;j+=i)
                v[j]=false;

}
template <class T>
void polinom_ireductibil <T> ::coeficienti (T v[])
{
    int k=0;
    pereche<T>*q=polinom<T>::prim;
    while(q!=0)
        {v[k++]=q->coeficient;
        if(v[k-1]<min_coef&&v[k-1]>0)
            min_coef=v[k-1];
        q=q->urm;
        }

}
template <class T>
void polinom_ireductibil <T> ::Einstein()
{
    bool prime [polinom<T>::elemente+6];
    T coef[polinom<T>::elemente+6];
    coeficienti(coef);
    ciurul (min_coef,prime);
    bool ok=false;
    for(int i=2;i<=min_coef&&!ok;i++)
        if(prime[i]==true)
        {
            bool flag=true;
            for(int j=0;j<polinom<T>::elemente-1;j++)
                if(coef[j]%i!=0)
                    flag=false;
            if(coef[polinom<T>::elemente-1]%i==0)
                flag=false;
            if(coef[0]%(i*i)==0)
                flag==false;
            if(flag==true)
                ok=true;
        }
    if(ok==true)
        cout<<"Polinomul este ireductibil!";
    else
        cout<<"Polinomul este reductibil!";
}
template <class T>
istream &operator>>(istream &o,polinom_ireductibil <T> &p)
{
    pereche <T> *t;
    t=new pereche <T>;
    t->urm=0;
    cout<<"Numarul de monoame ale polinomului:";
    o>>p.elemente;
    for(int i=1;i<=p.elemente;i++)
        {
        if(i==1)
            {
               p.prim=new pereche <T>;
               cout<<"Introduceti coeficientul urmat de exponentul monomului:";
               o>>(*p.prim);
               p.prim->urm=0;
            }
            else
            {
                pereche <T> *q=p.prim;
                while(q->urm!=0)
                    q=q->urm;
                t=new pereche <T>;
                cout<<"Introduceti coeficientul urmat de exponentul monomului:";
                o>>(*t);
                q->urm=t;
                t->urm=0;

            }
        }
        p.sortare();
return o;
}
template <class T>
ostream &operator<< (ostream &o,const polinom_ireductibil <T> &p)
{
    pereche <T> *z=new pereche <T>;
    z=p.prim;
    while(z!=0)
    {
        if(z==p.prim)
        o<<(*z);
        else
        {
            if(z->get_c()>0)
                o<<"+"<<(*z);
            else
                o<<(*z);
        }
        z=z->urm;
    }
    o<<"=0\n";

return o;
}
int main()
{polinom_ireductibil <int> q,w;
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
         cout<<"9.Verificati daca primul polinom este ireductibil!\n";
         cout<<"10.Verificati daca al doilea polinom este ireductibil!\n";
         cout<<"11.Iesire!\n";
         cout<<"Optiunea aleasa:";
         int x;
         cin>>x;
         if(x==1)
            cin>>q,cout<<q;
         else
            if(x==2)
                cin>>w,cout<<w;
         else
            if(x==3)
         {
             polinom <int> c;
             c=q-w;
             cout<<c;
         }
         else
            if(x==4)
         {
            polinom <int> d;
            d=w-q;
            cout<<d;
         }
            if(x==5)
         {
             polinom <int> e;
             e=q+w;
             cout<<e;
         }
         else
            if(x==6)
         {
             polinom <int> g;
             g=q*w;
             cout<<g;
         }
         if(x==7)
         {
             int y;
             cout<<"Valoarea x:";
             cin>>y;
             cout<<q(y);
         }
         else
            if(x==8)
         {
             int y;
             cout<<"Valoarea x:";
             cin>>y;
             cout<<w(y);
         }
         else
            if(x==9)
                q.Einstein();
            else
                if(x==10)
                    w.Einstein();
            else
                if(x==11)
                break;

     }
    return 0;
}
