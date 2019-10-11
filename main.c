#include <stdio.h>
#include <stdlib.h>
#define n 100
typedef struct
{
    char Nombre[30];
    int Edad;
    char Sexo;
    char Carrera;
}TDatos;

typedef struct
{
    TDatos Nodos[n];
    int Adyacencias[n][n];
    int Vertice;
}TGrafos;

int main()
{
    printf("Hello world!\n");
    return 0;
}

void InicializarG(TGrafos *G)
{
    G->Vertice =0;
}

int AgregarNodo(TGrafos *G,TDatos D) //Un 0 = no se puede agregar; Un 1 = si se pudo agregar.
{
    int i;
    if(G->Vertice==n)
    {
       return(0);
    }
    G->Nodos[G->Vertice]=D;
    for(i=0;i<= G->Vertice;i++)
    {
        G->Adyacencias[G->Vertice][i]=0;
        G->Adyacencias[i][G->Vertice]=0;
    }
    G->Vertice ++;
    return(1);
}

int AgregarArista(TDatos D1,TDatos D2,TGrafos *G) // Regresa un 0 si no pudo agregarla y regresa un 1 si consiguio agregar la arista.
{
    int V1=-1, V2=-1;
    int i;
    for(i=0;i<G->Vertice;i++)
    {
        if(G->Nodos[i]==D1)
        {
            V1=i;
        }
        if(G->Nodos[i]==D2)
        {
            V2=i;
        }
    }
    if(V1==-1 || V2==-1)
    {
        return(0);
    }
    G->Adyacencias[V1][V2]=1; //Coloca un 1 en la cordenada.
    Return(1);
}

int EliminarArista(TGrafos *G,TDatos V1,TDatos V2) //Regresa un 1 si pudo eliminarla, regresa un 0 si no pudo eliminarla.
{
    int a=-1, b=-1;
    int i;
    for(i=0;i<G->Vertice;i++)
    {
        if(G->Nodos[i]==V1)
        {
            a=i;
        }
        if(G->Nodos[i]==V2)
        {
            b=i;
        }
    }
    if(a==-1 || b== -1)
    {
        return(0);
    }
    G->Adyacencias[a][b]=0;
    return(1);
}

int EliminarNodo(TGrafos *G,TDatos V)
{
    int i,j;
    for(i=0;i<G->Vertice && G->Nodos[i]!=V;i++);
    if(i==N)
    {
        return(0);
    }
    int Ren,Col;
    for(Ren=i;Ren<G->Vertice-1;Ren++) //Ciclos para recorrer los RENGLONES.
    {
        for(Col=0;Col<G->Vertice;Col++)
        {
            G->Adyacencias[Ren][Col]=G->Adyacencias[Ren+1][Col];
            G->Adyacencias[Col][Ren]=G->Adyacencias[Col][Ren+1];
        }
    }
    for(Ren=i;Ren<G->Vertice-1;Ren++)//Ciclos para recorrer las COLUMNAS.
    {
        for(Col=0;Col<G->Vertice;Col++)
        {
            G->Adyacencias[Ren][Col]=G->Adyacencias[Ren][Col+1];
            G->Adyacencias[Ren][Col]=G->Adyacencias[Col+1][Ren];
        }
    }
    G->Vertice--;
    return(0);
}
