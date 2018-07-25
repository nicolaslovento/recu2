#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "ctype.h"


typedef struct
{
    int id;
    char nombre[20];
    int edad;
}ePersona;

ePersona* new_Persona();
int cargarDesdeArchivoTexto(ArrayList* lista);
int funcionQueFiltra(void* aux);
int validarEntero(int );

int main()
{
    ArrayList* lista;
    ePersona* miPer;
    lista=al_newArrayList();
    cargarDesdeArchivoTexto(lista);
    int i;
    for(i=0;i<al_len(lista);i++)
    {
        miPer=al_get(lista,i);
        if(i==0)
        {
            printf("ID     NOMBRE        EDAD   \n");
        }
       if(miPer!=NULL)
       {
        printf("%d  %10s %10d\n",miPer->id,miPer->nombre,miPer->edad);
        }

    }

    ArrayList* lista2;

    lista2=al_filter(lista,funcionQueFiltra);

    for(i=0;i<al_len(lista2);i++)
    {
        miPer=al_get(lista2,i);
        if(i==0)
        {
            printf("\n\nID     NOMBRE        EDAD   \n");
        }
       if(miPer!=NULL)
       {
        printf("%d  %10s %10d\n",miPer->id,miPer->nombre,miPer->edad);
        }
    }


    int numero;
    printf("Ingrese numero: ");
    scanf("%d",&numero);
    while(validarEntero(numero)==0)
    {
        printf("Reingrese numero: ");
        scanf(" %d",&numero);
    }


    return 0;
}


int validarEntero(int entero)
{



    return 0;
}

ePersona* new_Persona()
{
    ePersona* aux=NULL;
    aux=(ePersona*)malloc(sizeof(ePersona));
    if(aux!=NULL)
    {
        return aux;
    }

    return aux;
}


int cargarDesdeArchivoTexto(ArrayList* lista)
{
    int retorno=1;
    FILE* archivo;
    char id[10];
    char nombre[50];
    char edad[30];
    int cant;
    ePersona* persona;
    if(lista!=NULL)
    {
        archivo=fopen("data.csv","r");

        if(archivo!=NULL)
        {
            while(!feof(archivo))
            {
                cant=fscanf(archivo,"%[^,],%[^,],%[^\n]\n",id,nombre,edad);
                if(cant==3)
                {
                    persona=new_Persona();
                    persona->id=atoi(id);
                    persona->edad=atoi(edad);
                    strcpy(persona->nombre,nombre);
                    al_add(lista,persona);
                }
            }
        }
    }

    fclose(archivo);

    return retorno;
}



int funcionQueFiltra(void* aux)
{
    ePersona* puntero;
    puntero=(ePersona*)aux;
    if(puntero!=NULL)
    {
        if(puntero->edad<25)
        {
            return 1;
        }
    }

    return 0;
}
