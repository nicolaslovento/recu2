#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
/**
cargar los datos,guardar en un array los datos que sean primos y mostrarlos
**/
typedef struct{
    int id;
    char nombre[20];
    int numero;

}eNumeros;

void* new_Numero();
int parserEmpleados(ArrayList* );
int funcionQueFiltra(void* eNum);
void listarNumeros(ArrayList* this);

int main()
{
    ArrayList* listaDeNumeros;
    listaDeNumeros=al_newArrayList();
    parserEmpleados(listaDeNumeros);

    listarNumeros(listaDeNumeros);

    ArrayList* listaFiltrada;

    listaFiltrada=al_filter(listaDeNumeros,funcionQueFiltra);

    listarNumeros(listaFiltrada);


    return 0;
}
void listarNumeros(ArrayList* this)
{
    int len,i;
    int contador=50;
    len=al_len(this);
    eNumeros* eNum;
    printf("id |  nombre   |  numero  \n");
    for(i=0;i<len;i++)
    {
        eNum=al_get(this,i);
        if(eNum!=NULL)
        {
           printf("%d    %10s    %10d \n",eNum->id,eNum->nombre,eNum->numero);
        }
    }

}


int funcionQueFiltra(void* eNum)
{
    eNumeros* e1;
    e1=(eNumeros*)eNum;
    int i,contador=0;
    if(e1!=NULL)
    {
        for(i=1;i<=e1->numero;i++)
        {
            if(e1->numero%i==0)
            {
                contador++;
            }
        }

        if(contador==2)
        {
            return 1;
        }

     }

    return 0;
}

void* new_Numero()
{
    eNumeros* newNum=NULL;
    newNum=(eNumeros*)malloc(sizeof(eNumeros));
    if(newNum!=NULL)
    {
        return newNum;
    }
    return newNum;
}


int parserEmpleados(ArrayList* array)
{
    FILE* archivo;
    archivo=fopen("data.csv","r");
    eNumeros* newNum;
    int cant;
    char id[10];
    char nombre[50];
    char numero[50];

    do
    {

        newNum=new_Numero();
        cant=fscanf(archivo,"%[^,],%[^,],%[^\n]",id,nombre,numero);
        if(cant==3)
        {

            newNum->id=atoi(id);
            strcpy(newNum->nombre,nombre);
            newNum->numero=atoi(numero);

            al_add(array,newNum);
        }



    }while(!feof(archivo));

    fclose(archivo);
}
