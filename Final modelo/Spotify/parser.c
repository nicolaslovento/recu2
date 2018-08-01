#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "usuarios.h"
#include "temas.h"
#include "parser.h"

int cargarEstadistica(ArrayList* this)
{
    FILE* pArchivo;
    pArchivo=fopen("estadistica.txt","r");

    if(pArchivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    eEstadisticas* auxEst;
    int idTema;
    int idUsuario,cantidad;
    while(!feof(pArchivo))
    {
        cantidad=fscanf(pArchivo,"%d,%d\n",&idTema,&idUsuario);

        if(cantidad!=2)
        {
            if(feof(pArchivo))
            {
                break;
            }
        }

        auxEst=estadistica_New();
        auxEst->idTema=idTema;
        auxEst->idUsuario=idUsuario;
        al_add(this,auxEst);


    }

    fclose(pArchivo);

}

int guardarEstadistica(ArrayList* this)
{
    FILE* pArchivo;
    pArchivo=fopen("estadistica.txt","w");

    if(pArchivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    int len,i;
    len=al_len(this);
    eEstadisticas* auxEst;
    for(i=0;i<len;i++)
    {
        auxEst=al_get(this,i);
        fprintf(pArchivo,"%d,%d\n",auxEst->idTema,auxEst->idUsuario);
    }

    fclose(pArchivo);

}

int cargarTemas(ArrayList* this,char* nombreArchivo)
{
    FILE* pArchivo;
    pArchivo=fopen(nombreArchivo,"r");

    if(pArchivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    eTemas* newTema;
    char id[5];
    char nombre_Tema[50];
    char artista[50];
    int cantidad;

    while(!feof(pArchivo))
    {
        cantidad=fscanf(pArchivo,"%[^,],%[^,],%[^\n]",id,nombre_Tema,artista);
        newTema=tema_New();
        if(cantidad==3)
        {
            newTema->id=atoi(id);
            strcpy(newTema->nombre_Tema,nombre_Tema);
            strcpy(newTema->artista,artista);
            al_add(this,newTema);

        }

    }




    fclose(pArchivo);
}


int cargarUsuarios(ArrayList* this,char* nombreArchivo)
{
    FILE* pArchivo;
    pArchivo=fopen(nombreArchivo,"r");

    if(pArchivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    eUsuarios* newUsuario;
    int cantidad,flag=0;
    char id[5];
    char nombre[40];
    char email[40];
    char sexo[40];
    char pais[40];
    char password[40];
    char ip_Address[50];
    while(!feof(pArchivo))
    {



        cantidad=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,email,sexo,pais,password,ip_Address);
        if(cantidad!=7)
        {
            if(feof(pArchivo))
            {
                break;
            }
        }

            newUsuario=usuario_New();

            newUsuario->id=atoi(id);
            strcpy(newUsuario->nombre,nombre);
            strcpy(newUsuario->email,email);
            strcpy(newUsuario->sexo,sexo);
            strcpy(newUsuario->pais,pais);
            strcpy(newUsuario->password,password);
            strcpy(newUsuario->ip_Adress,ip_Address);
            al_add(this,newUsuario);



    }




    fclose(pArchivo);
}
