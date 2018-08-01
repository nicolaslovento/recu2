#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "usuarios.h"
#include "parser.h"
#include "temas.h"




void temaMasEscuchado(ArrayList* listaTemas,ArrayList* listaEst)
{
    int i,j;
    eTemas* auxTema;
    for(i=0;i<al_len(listaTemas);i++)
    {
        auxTema=al_get(listaTemas,i);
        if(auxTema!=NULL)
        {
            auxTema->reproducciones=0;
        }
    }
    eEstadisticas* auxEst;
    for(i=0;i<al_len(listaEst);i++)
    {
        auxEst=al_get(listaEst,i);
        for(j=0;j<al_len(listaTemas);j++)
        {
            auxTema=al_get(listaTemas,j);
            if(auxEst->idTema==auxTema->id)
            {
                auxTema->reproducciones++;
            }
        }
    }
    auxTema=al_get(listaTemas,0);
    int maximoId=auxTema->id;
    int maximo=auxTema->reproducciones;
    for(i=1;i<al_len(listaTemas);i++)
    {
        auxTema=al_get(listaTemas,i);
        if(auxTema!=NULL)
        {
            if(maximo<auxTema->reproducciones)
            {
                maximo=auxTema->reproducciones;
                maximoId=auxTema->id;
            }
        }
    }

    auxTema=al_get(listaTemas,maximoId-1);

    printf("Tema mas escuchado: %s\n",auxTema->nombre_Tema);


}

void tema_OrdenarPorArtista(void* aux1,void* aux2)
{
    eTemas* aux3=(eTemas*)aux1;
    eTemas* aux4=(eTemas*)aux2;
    int retorno;
    if(strcmpi(aux3->artista,aux4->artista)==0)
    {
        retorno=strcmpi(aux3->nombre_Tema,aux4->nombre_Tema);
        return retorno;
    }else
    {
        retorno=strcmpi(aux3->artista,aux4->artista);
    }
    return retorno;

}

void tema_MostrarTodos(ArrayList* lista)
{
    int len,i;
    eTemas* aux;
    int contador=50;
    if(lista!=NULL)
    {
        len=al_len(lista);
        printf("Id    |          Nombre          |                          Artista\n ");
        for(i=0;i<len;i++)
        {
            aux=al_get(lista,i);
            tema_MostrarUno(aux);

        if(i==contador)
        {
            contador=contador+50;
            system("pause");
            system("cls");
            printf("Id  |           Nombre       |                 Artista\n ");
        }
        }


    }
}

eTemas* tema_New()
{
    eTemas* aux=NULL;
    aux=(eTemas*)malloc(sizeof(eTemas));
    if(aux!=NULL)
    {
        return aux;
    }
    return aux;
}

void tema_MostrarUno(eTemas* unTema)
{
    printf("%4d    %-40s %10s\n",unTema->id,unTema->nombre_Tema,unTema->artista);
}
