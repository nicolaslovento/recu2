#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

#include "validaciones.h"
#include "cliente.h"

void mostrarUnClientePorId(ArrayList* this)
{
     int id,index;
    Cliente* clienteAux;

    printf("Ingrese id: ");
    scanf(" %d",&id);
    index=getClienteIndexById(this,id);
    if(index>-1)
    {
        clienteAux=al_get(this,index);
        mostrarUnCliente(clienteAux);

    }else
    {
       printf("No se escuentra el id.\n");
    }

}

void modificarCliente(ArrayList* this)
{
    int id,index,opcion;
    Cliente* clienteAux;
    char newNombre[50];
    char newApellido[50];
    char newEmail[50];
    printf("Ingrese id: ");
    scanf(" %d",&id);
    index=getClienteIndexById(this,id);
    if(index>-1)
    {
        clienteAux=al_get(this,index);
        mostrarUnCliente(clienteAux);
        printf("Que desea modificar?..\n1.Nombre.\n2.Apellido.\n3.Email.\nOpcion: ");
        scanf(" %d",&opcion);
        switch(opcion)
        {
        case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(newNombre);
                setNombre(clienteAux,newNombre);
            break;
        case 2:
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                gets(newApellido);
                setApellido(clienteAux,newApellido);
            break;
        case 3:
                printf("Ingrese nuevo email: ");
                fflush(stdin);
                gets(newEmail);
                setEmail(clienteAux,newEmail);
            break;
        default:
            printf("Opcion incorrecta.\n");

            break;

        }

    }else
    {
       printf("No se escuentra el id.\n");
    }


}


int eliminarCliente(ArrayList* this)
{
    int id,index;
    char r;
    Cliente* clienteAux;
    printf("Ingrese id: ");
    scanf(" %d",&id);
    index=getClienteIndexById(this,id);
    if(index>-1)
    {
        clienteAux=al_get(this,index);
        mostrarUnCliente(clienteAux);
        printf("Esta seguro que desea eliminar el cliente? s/n: ");
        r=getche();
        if(r=='s')
        {
            al_remove(this,index);
            printf("\nEl cliente ha sido borrado.\n");

        }else
        {
            printf("\nOperacion cancelada.\n");
        }

    }else
    {
       printf("No se escuentra el id.\n");
    }

}

int mostrarUnCliente(Cliente* clienteAux)
{

    printf("%d %10s %15s   %25s      %s\n ",clienteAux->id,clienteAux->nombre,clienteAux->apellido,clienteAux->email,clienteAux->nacionalidad);
}

int agregarCliente(ArrayList* this)
{
    char nombre[7000];
    char apellido[7000];
    char email[7000];
    char genero[2];
    char profesion[7000];
    char nacionalidad[7000];
    char usuario[7000];
    int id;
    Cliente* clienteAux;
    clienteAux=newEmpleado();


    printf("Ingrese nombre :  ");
    fflush(stdin);
    gets(nombre);
    while(validarString(nombre)==1)
    {
        printf("Ingrese nombre :  ");
        fflush(stdin);
        gets(nombre);
    }
    setNombre(clienteAux,nombre);

    printf("Ingrese apellido :  ");
    fflush(stdin);
    gets(apellido);
    while(validarString(apellido)==1)
    {
        printf("Ingrese apellido nuevamente(solo letras) :  ");
        fflush(stdin);
        gets(apellido);
    }
    setApellido(clienteAux,apellido);

    printf("Ingrese genero [M o F]:  ");
    fflush(stdin);
    gets(genero);
    while(validarString(genero)==1)
    {
        printf("Ingrese genero nuevamente(solo letra)M o F :  ");
        fflush(stdin);
        gets(genero);
    }
    setGenero(clienteAux,genero);

    printf("Ingrese email: ");
    fflush(stdin);
    gets(email);
    setEmail(clienteAux,email);

    printf("Ingrese profesion: ");
    fflush(stdin);
    gets(profesion);
    while(validarString(profesion)==1)
    {
        printf("Ingrese profesion nuevamente:  ");
        fflush(stdin);
        gets(profesion);
    }
    setProfesion(clienteAux,profesion);


    printf("Ingrese usuario: ");
    fflush(stdin);
    gets(usuario);
    setUsuario(clienteAux,usuario);


    printf("Ingrese nacionalidad: ");
    fflush(stdin);
    gets(nacionalidad);
    while(validarString(nacionalidad)==1)
    {
        printf("Ingrese nacionalidad nuevamente:  ");
        fflush(stdin);
        gets(nacionalidad);
    }
    setNacionalidad(clienteAux,nacionalidad);

    setId(clienteAux,getClienteId(this));

    al_add(this,clienteAux);





}


int getClienteIndexById(ArrayList* this,int id)
{
    int len,i;
    Cliente* clienteAux;
    len=al_len(this);
    int index=-1;

    for(i=0;i<len;i++)
    {
        clienteAux=al_get(this,i);
        if(clienteAux->id==id)
        {
            index=al_indexOf(this,clienteAux);
        }
    }
    return index;
}


void listarClientes(ArrayList* this)
{
    int len,i;
    int contador=50;
    len=al_len(this);
    Cliente* clienteAux;
    printf("id | nombre   |    apellido     |             email           |    nacionalidad   \n");
    for(i=0;i<len;i++)
    {
        clienteAux=al_get(this,i);
        if(clienteAux!=NULL)
        {
            mostrarUnCliente(clienteAux);
        }

        if(i==contador)
        {
            contador=contador+50;
            printf("Ver de %d a %d..",i+2,contador);
            system("pause");
            system("cls");

        }

    }

}


int ordenarPorEmail(void* cliente1,void* cliente2)
{
    int retorno;
    Cliente* c1=(Cliente*)cliente1;
    Cliente* c2=(Cliente*)cliente2;
    retorno=strcmpi(c1->email,c2->email);
    return retorno;

}


int ordenarPorNombre(void* cliente1,void* cliente2)
{
    int retorno;
    Cliente* c1=(Cliente*)cliente1;
    Cliente* c2=(Cliente*)cliente2;
    retorno=strcmpi(c1->nombre,c2->nombre);
    return retorno;

}

//constructor
Cliente* newEmpleado()
{
    Cliente* puntero;
    puntero=(Cliente*)malloc(sizeof(Cliente));
    return puntero;
}

int getClienteId(ArrayList* this)
{
    int retorno;
    retorno=(this->size)+1;

    return retorno;
}

//FUNCIONES SET Y GET

int setId(Cliente* pCliente,int id)
{
    int retorno=0;
    if(pCliente!=NULL && id>0)
    {
        pCliente->id=id;
        retorno=1;
    }
    return retorno;
}

int setGenero(Cliente* pCliente,char* genero)
{
    int retorno=0;
    if(pCliente!=NULL  )
    {
        strcpy(pCliente->genero,genero);
        retorno=1;
    }
    return retorno;
}

int setProfesion(Cliente* pCliente,char* profesion)
{
    int retorno=0;
    if(pCliente!=NULL && profesion!=NULL)
    {
        strcpy(pCliente->profesion,profesion);
        retorno=1;
    }
    return retorno;
}

int setNacionalidad(Cliente* pCliente,char* nacionalidad)
{
    int retorno=0;
    if(pCliente!=NULL && nacionalidad!=NULL)
    {
        strcpy(pCliente->nacionalidad,nacionalidad);
        retorno=1;
    }
    return retorno;
}


int setUsuario(Cliente* pCliente,char* usuario)
{
    int retorno=0;
    if(pCliente!=NULL && usuario!=NULL)
    {
        strcpy(pCliente->usuario,usuario);
        retorno=1;
    }
    return retorno;
}

int setEmail(Cliente* pCliente,char* email)
{
    int retorno=0;
    if(pCliente!=NULL && email!=NULL)
    {
        strcpy(pCliente->email,email);
        retorno=1;
    }
    return retorno;
}

int setApellido(Cliente* pCliente,char* apellido)
{
    int retorno=0;
    if(pCliente!=NULL && apellido!=NULL)
    {
        strcpy(pCliente->apellido,apellido);
        retorno=1;
    }
    return retorno;
}


int setNombre(Cliente* pCliente,char* nombre)
{
    int retorno=0;
    if(pCliente!=NULL && nombre!=NULL)
    {
        strcpy(pCliente->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
