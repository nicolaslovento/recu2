#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "usuarios.h"
#include "mensajes.h"
#include "parser.h"
int main()
{
    ArrayList* listaUsuarios;
    listaUsuarios=al_newArrayList();

    ArrayList* listaMensajes;
    listaMensajes=al_newArrayList();
    parserMensajes(listaMensajes);
    int opcion;


    while(1)
    {

    printf("1. \n");
    printf("2.  \n");
    printf("3.  \n");
    printf("4.  \n");
    printf("5.  \n");

    printf("Ingrese opcion: ");
    scanf("%d",&opcion);


    switch(opcion)
    {
    case 1:

        system("pause");
        system("cls");
        break;
    case 2:


        system("pause");
        system("cls");
        break;
    case 3:

        system("pause");
        system("cls");
        break;
    case 4:

        system("pause");
        system("cls");
        break;
    case 5:

        system("pause");
        system("cls");
        break;

    default:
        printf("Opcion incorrecta..\n");
        system("pause");
        system("cls");
    }

    }

    return 0;
}
