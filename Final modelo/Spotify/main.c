#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "usuarios.h"
#include "temas.h"
#include "parser.h"
int main()
{
    ArrayList* listaUsuarios;
    listaUsuarios=al_newArrayList();
    cargarUsuarios(listaUsuarios,"usuarios.dat");

    ArrayList* listaTemas;
    listaTemas=al_newArrayList();
    cargarTemas(listaTemas,"temas.dat");

    ArrayList* listaEstadisticas;
    listaEstadisticas=al_newArrayList();
    cargarEstadistica(listaEstadisticas);

    int opcion;
    while(1)
    {

    printf("1.Listar usuarios\n2.Listar temas\n3.Escuchar tema\n4.Guardar estadistica\n5.Informar\nOpcion: ");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
            al_sort(listaUsuarios,usuario_ordenarPorNombre,1);
            usuario_MostrarTodos(listaUsuarios);
            system("pause");
            system("cls");
        break;
        case 2:
            al_sort(listaTemas,tema_OrdenarPorArtista,1);
            tema_MostrarTodos(listaTemas);
            system("pause");
            system("cls");
        break;
        case 3:
            escucharTema(listaUsuarios,listaTemas,listaEstadisticas);
            system("pause");
            system("cls");
        break;
        case 4:
            guardarEstadistica(listaEstadisticas);
            system("pause");
            system("cls");
        break;
        case 5:
            temaMasEscuchado(listaTemas,listaEstadisticas);
            system("pause");
            system("cls");
        break;
        default:
        printf("Opcion incorrecta.\n");
        system("pause");

        system("cls");
    }

    }


    return 0;
}
