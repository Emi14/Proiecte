#include <stdio.h>
#include <stdlib.h>
int a[5][5],i,j,n,ok;
char s;
void afisare()
{
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
            if(a[i][j]==1)
                printf("X|");
                else
                    if(a[i][j]==0)
                printf("O|");
                else
                    printf(" |");
        printf("\n");
    }
}

void adversar(int n,int x,int y)
{
    int k=!n;
    int i,j,z=0;
    for(i=1;i<=3;i++)
    if(a[i][1]==a[i][2]&&a[i][2]==k&&a[i][3]==-1)
    {a[i][3]=k;z=1;return;}
else
    if(a[i][1]==a[i][3]&&a[i][3]==k&&a[i][2]==-1)
    {a[i][2]=k;z=1;return;}
    else
        if(a[i][2]==a[i][3]&&a[i][3]==k&&a[i][1]==-1)
    {a[i][1]=k;z=1;return;}
    if(z==0)
        for(j=1;j<=3;j++)
        if(a[1][j]==a[2][j]&&a[2][j]==k&&a[3][j]==-1)
        {a[3][j]=k;z=1;return;}
    else
        if(a[1][j]==a[3][j]&&a[3][j]==k&&a[2][j]==-1)
        {a[2][j]=k;z=1;return;}
    else
        if(a[3][j]==a[2][j]&&a[2][j]==k&&a[1][j]==-1)
        {a[1][j]=k;z=1;return;}
    if(z==0)
    {
        if(a[1][1]==a[2][2]&&a[2][2]==k&&a[3][3]==-1)
            {a[3][3]=k;z=1;return;}
        else
            if(a[1][1]==a[3][3]&&a[3][3]==k&&a[2][2]==-1)
            {a[2][2]=k;z=1;return;}
        else
            if(a[2][2]==a[3][3]&&a[3][3]==k&&a[1][1]==-1)
            {a[1][1]=k;z=1;return;}
    }
    if(z==0)
    {
        if(a[1][3]==a[2][2]&&a[2][2]==k&&a[3][1]==-1)
            {a[3][1]=k;z=1;return;}
        else
            if(a[3][1]==a[2][2]&&a[2][2]==k&&a[1][3]==-1)
            {a[1][3]=k;z=1;return;}
        else
            if(a[1][3]==a[3][1]&&a[3][1]==k&&a[2][2]==-1)
            {a[2][2]=k;z=1;return;}
    }


    if(z==0)
    for(i=1;i<=3;i++)
    if(a[i][1]==a[i][2]&&a[i][2]==n&&a[i][3]==-1)
    {a[i][3]=k;z=1;return;}
else
    if(a[i][1]==a[i][3]&&a[i][3]==n&&a[i][2]==-1)
    {a[i][2]=k;z=1;return;}
    else
        if(a[i][2]==a[i][3]&&a[i][3]==n&&a[i][1]==-1)
    {a[i][1]=k;z=1;return;}
    if(z==0)
        for(j=1;j<=3;j++)
        if(a[1][j]==a[2][j]&&a[2][j]==n&&a[3][j]==-1)
        {a[3][j]=k;z=1;return;}
    else
        if(a[1][j]==a[3][j]&&a[3][j]==n&&a[2][j]==-1)
        {a[2][j]=k;z=1;return;}
    else
        if(a[3][j]==a[2][j]&&a[2][j]==n&&a[1][j]==-1)
        {a[1][j]=k;z=1;return;}
    if(z==0)
    {
        if(a[1][1]==a[2][2]&&a[2][2]==n&&a[3][3]==-1)
            {a[3][3]=k;z=1;return;}
        else
            if(a[1][1]==a[3][3]&&a[3][3]==n&&a[2][2]==-1)
            {a[2][2]=k;z=1;return;}
        else
            if(a[2][2]==a[3][3]&&a[3][3]==n&&a[1][1]==-1)
            {a[1][1]=k;z=1;return;}
    }
    if(z==0)
    {
        if(a[1][3]==a[2][2]&&a[2][2]==n&&a[3][1]==-1)
            {a[3][1]=k;z=1;return;}
        else
            if(a[3][1]==a[2][2]&&a[2][2]==n&&a[1][3]==-1)
            {a[1][3]=k;z=1;return;}
        else
            if(a[1][3]==a[3][1]&&a[3][1]==n&&a[2][2]==-1)
            {a[2][2]=k;z=1;return;}
    }
    if(z==0)
    {
        if(a[2][2]==-1)
            {a[2][2]=k;z=1;return;}
        else
            if(a[x][3]==-1)
            {a[x][3]=k;z=1;return;}
        else
            if(a[3][y]==-1)
            {a[3][y]=k;z=1;return;}}
        else
            for(i=1;i<=3;i++)
                for(j=1;j<=3;j++)
                    if(a[i][j]==-1)
        {
            a[i][j]=k;
            z=1;
            return;
            break;
        }
    }
void introducere(int n)
{int x,y;
printf("Introduceti indicele linie si coloanei pe care vreti sa scrieti ");
if(n==1)
    printf("X!\n");
    else
    printf("O!\n");
    scanf("%d%d",&x,&y);
a[x][y]=n;
adversar(n,x,y);
}

void verificare(int n)
{
        int k=!n;
        for(j=1;j<=3;j++)
        if(a[1][j]==n&&a[2][j]==n&&a[3][j]==n)
            {printf("Felicitari,ai castigat!\n");ok=0;return;}
        for(i=1;i<=3;i++)
            if(a[i][2]==n&&a[i][1]==n&&a[i][3]==n)
            {printf("Felicitari,ai castigat!\n");ok=0;return ;}
        if(a[1][1]==n&&a[2][2]==n&&a[3][3]==n)
            {printf("Felicitari,ai castigat!\n");ok=0;return ;}
        if(a[1][3]==n&&a[2][2]==n&&a[3][1]==n)
            {printf("Felicitari,ai castigat!\n");ok=0;return ;}

        for(j=1;j<=3;j++)
        if(a[1][j]==k&&a[2][j]==k&&a[3][j]==k)
            {printf("Din pacate ai pierdut!\n");ok=0;}
             for(i=1;i<=3;i++)
            if(a[i][2]==k&&a[i][1]==k&&a[i][3]==k)
                {printf("Din pacate ai pierdut!\n");ok=0;}
        if(a[1][1]==k&&a[2][2]==k&&a[3][3]==k)
             {printf("Din pacate ai pierdut!\n");ok=0;}
        if(a[1][3]==k&&a[2][2]==k&&a[3][1]==k)
             {printf("Din pacate ai pierdut!\n");ok=0;}
}
void verificare_multi(int n)
{
        int k=!n;
        for(j=1;j<=3;j++)
        if(a[1][j]==n&&a[2][j]==n&&a[3][j]==n)
            {printf("Jucatorul numarul 1 a castigat!\n");ok=0;return;}
        for(i=1;i<=3;i++)
            if(a[i][2]==n&&a[i][1]==n&&a[i][3]==n)
            {printf("Jucatorul numarul 1 a castigat!\n");ok=0;return ;}
        if(a[1][1]==n&&a[2][2]==n&&a[3][3]==n)
            {printf("Jucatorul numarul 1 a castigat!\n");ok=0;return ;}
        if(a[1][3]==n&&a[2][2]==n&&a[3][1]==n)
            {printf("Jucatorul numarul 1 a castigat!\n");ok=0;return ;}

        for(j=1;j<=3;j++)
        if(a[1][j]==k&&a[2][j]==k&&a[3][j]==k)
            {printf("Jucatorul numarul 2 a castigat!\n");ok=0;}
             for(i=1;i<=3;i++)
            if(a[i][2]==k&&a[i][1]==k&&a[i][3]==k)
                {printf("Jucatorul numarul 2 a castigat!\n");ok=0;}
        if(a[1][1]==k&&a[2][2]==k&&a[3][3]==k)
             {printf("Jucatorul numarul 2 a castigat!\n");ok=0;}
        if(a[1][3]==k&&a[2][2]==k&&a[3][1]==k)
             {printf("Jucatorul numarul 2 a castigat!\n");ok=0;}
}
void introducere_multi(int n)
{int x,y;
printf("Jucatorul numarul 1!!Introduceti indicele linie si coloanei pe care vreti sa scrieti ");
if(n==1)
    printf("X!\n");
    else
    printf("O!\n");
    scanf("%d%d",&x,&y);
a[x][y]=n;
afisare();
verificare_multi(n);
if (ok==0)
return;
else
printf("Jucatorul numarul 2!!Introduceti indicele linie si coloanei pe care vreti sa scrieti ");
if(!n==1)
    printf("X!\n");
    else
    printf("O!\n");
    scanf("%d%d",&x,&y);
a[x][y]=!n;
}
void joc()
{
    introducere(n);
    afisare();
    verificare(n);
}
void repetare()
{   int t=0;
    while(1)
        {joc();t++;
        if(ok==0)
            break;
            else
                if(t==5)
            {printf("Egalitate!\n");
            break;
            }
        }
}
void joc_multi()
{
    introducere_multi(n);
    afisare();
    verificare_multi(n);
}
void repetare_multi()
{   int t=0;
    while(1)
        {joc_multi();t++;
        if(ok==0)
            break;
            else
                if(t==5)
            {printf("Egalitate!\n");
            break;
            }
        }
}
void multi()
{
    printf("Jucatorul numarul 1,pentru a juca cu 'X' apasati tasta 1,iar pentru a juca cu 'O' apasati tasta 0!\n");
    scanf("%d",&n);
    if(n==1)
        printf("Jucatorul numarul 2,va juca cu 'O'\n");
    else
        printf("Jucatorul numarul 2,va juca cu 'X'\n");

}
void meniu()
{int x=1;
    while(x)
    {for(i=0;i<=4;i++)
    for(j=0;j<=4;j++)
        a[i][j]=-1;
int p;
printf("Pentru a juca impotriva calculatorului apasati 1,iar pentru a juca impotriva unui prieten apasati 2!\n");
scanf("%d",&p);
if(p==1)
{printf("Pentru a juca cu 'X' apasati tasta 1,iar pentru a juca cu 'O' apasati tasta 0!\n");
scanf("%d",&n);
ok=1;
repetare();
printf("Pentru un joc nou apasati tasta 1,pentru a iesi apasati tasta 0!\n");
scanf("%d",&x);
    }
    else
        {multi();
        ok=1;
        repetare_multi();
        printf("Pentru un joc nou apasati tasta 1,pentru a iesi apasati tasta 0!\n");
scanf("%d",&x);
        }
}
}
int main()
{
    meniu();
return 0;
}
