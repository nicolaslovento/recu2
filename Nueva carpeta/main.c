#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/


int main()
{
    FILE* archivo;
    ArrayList* pArrayEmpleados;
    pArrayEmpleados = al_newArrayList();
    Cliente* Cliente;
    int opcion;


    while(1)
    {

    printf("1. Cargar datos desde data.csv \n");
    printf("2. Listar Clientes \n");
    printf("3. Ordenar por nombre y apellido \n");
    printf("4. Ordenar por mail \n");
    printf("5. Agregar un Cliente \n");
    printf("6. Elimina un Cliente \n");
    printf("7. Modificar Cliente (Nombre, Apellido y Mail) \n");
    printf("8. Listar un cliente por id.\n");
    printf("9. Guardar datos en data.csv \n");
    printf("10. Guardar datos en data.bin \n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);


    switch(opcion)
    {
    case 1:
        parserClientes(pArrayEmpleados,"data.csv");
        system("pause");
        system("cls");
        break;
    case 2:

        listarClientes(pArrayEmpleados);
        system("pause");
        system("cls");
        break;
    case 3:
        al_sort(pArrayEmpleados,ordenarPorNombre,1);
        system("pause");
        system("cls");
        break;
    case 4:
        al_sort(pArrayEmpleados,ordenarPorEmail,1);
        system("pause");
        system("cls");
        break;
    case 5:
        agregarCliente(pArrayEmpleados);
        system("pause");
        system("cls");
        break;
    case 6:
        eliminarCliente(pArrayEmpleados);
        system("pause");
        system("cls");
        break;
    case 7:
        modificarCliente(pArrayEmpleados);
        system("pause");
        system("cls");
        break;
    case 8:
        mostrarUnClientePorId(pArrayEmpleados);
        system("pause");
        system("cls");
        break;
    case 9:
        guardarClientesTexto(pArrayEmpleados);
        system("pause");
        system("cls");
        break;
    case 10:
        guardarClientesBinario(pArrayEmpleados);
        system("pause");
        system("cls");
        break;
    case 11:
        CargarClientesBinario(pArrayEmpleados);
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
