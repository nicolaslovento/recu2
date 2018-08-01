#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "letras.h"
#include "parser.h"
int main()
{
    ArrayList* miLista;
    miLista=al_newArrayList();

    ArrayList* miListaFiltrada;
    miListaFiltrada=al_newArrayList();
    int opcion;
    int opcion1;

    while(1)
    {
        printf("1.ALTAS.\n");
        printf("2.COMPLETAR.\n");
        printf("3.COMPROBAR.\n");
        printf("4.GENERAR Y LISTAR.\n");
        printf("INGRESE OPCION: ");
        scanf(" %d",&opcion);


        switch(opcion)
        {
            case 1:
                parserLetras(miLista,"datos.csv");
                mostrarLetras(miLista);
                system("pause");
                system("cls");
            break;
            case 2:
                completarLetras(miLista);
                mostrarLetras(miLista);
                system("pause");
                system("cls");
            break;
            case 3:
                mostrarLetras(miLista);
                comprobarPalabra(miLista);
                system("pause");
                system("cls");
            break;
            case 4:
                scanf("%d",&opcion1);
                switch(opcion1)
                {
                case 1:
                    miListaFiltrada=crearArrayRepetido(miLista);
                    al_sort(miListaFiltrada,ordenarLetras,0);
                    mostrarLetras(miListaFiltrada);
                    system("pause");
                    system("cls");
                break;
                case 2:
                    miListaFiltrada=crearArraySinRepetir(miLista);
                    al_sort(miListaFiltrada,ordenarLetras,1);
                    mostrarLetras(miListaFiltrada);
                    system("pause");
                    system("cls");
                    break;
                }

            break;
            default:
                printf("Opcion incorrecta.");
        }

    }
    return 0;
}
