#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "usuarios.h"
#include "mensajes.h"
#include "parser.h"

int parserMensajes(ArrayList* this)
{
    FILE* pArchivo;
    pArchivo=fopen("mensajes.csv","r");
    eMensaje* aux;
    int cant;
    char idMensaje[10];
    char idUsuario[10];
    char likes[20];
    char mensaje[10000];

    do
    {

        aux=new_Mensaje();
        cant=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]",idMensaje,idUsuario,likes,mensaje);
        if(cant==4)
        {

            aux->id=atoi(idMensaje);
            aux->idUsuario=atoi(idUsuario);
            aux->likes=atoi(likes);
            strcpy(aux->mensaje,mensaje);


            al_add(this,aux);
        }



    }while(!feof(pArchivo));

    fclose(pArchivo);
}
