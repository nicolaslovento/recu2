#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "parser.h"





int parserClientes(ArrayList* this,char* nombreArchivo)
{

    FILE* archivo;
    archivo=fopen("data.csv","r");
    int contador;
    contador=0;
    char nombre[7000];
    char apellido[7000];
    char email[7000];
    char genero[2];
    char profesion[7000];
    char nacionalidad[7000];
    char usuario[7000];
    int id;
    int r;


    do
    {
        r=fscanf(archivo,"%d,%[^,],%[^,],%[^,], %[^,] ,%[^,],%[^,],%[^\n]\n",&id,nombre,apellido,email,genero,profesion,usuario,nacionalidad);

            if(r==8)
            {


            Cliente *clienteAux=newEmpleado();

            setNombre(clienteAux,nombre);
            setApellido(clienteAux,apellido);
            setEmail(clienteAux,email);
            setUsuario(clienteAux,usuario);
            setGenero(clienteAux,genero);
            setProfesion(clienteAux,profesion);
            setNacionalidad(clienteAux,nacionalidad);
            setId(clienteAux,id);
            al_add(this,clienteAux);
            contador++;

            }




    }while(!feof(archivo));

    fclose(archivo);
}

int CargarClientesBinario(ArrayList* this)
{
    Cliente* clienteAux;
    FILE* archivo;
    archivo=fopen("data.bin","rb");
    int contador=0,cant;

    while(!feof(archivo))
    {
        clienteAux=newEmpleado();
        cant=fread(clienteAux,sizeof(Cliente),1,archivo);
        if(cant!=1)
        {
            if(feof(archivo))
            {
                break;
            }
        }
        al_add(this,clienteAux);
        contador++;

    }


    printf("Se cargaron %d registros de clientes\n",contador);
    fclose(archivo);
}


int guardarClientesBinario(ArrayList* this)
{
    Cliente* clienteAux;
    FILE* archivo;
    archivo=fopen("data.bin","wb");
    int len,i,contador=0;
    len=al_len(this);

    for(i=0;i<len;i++)
    {
        clienteAux=al_get(this,i);
        if(clienteAux!=NULL)
        {
            fwrite(clienteAux,sizeof(Cliente),1,archivo);
            contador++;
        }
    }
    printf("Se guardaron %d registros de clientes\n",contador);
    fclose(archivo);


}



int guardarClientesTexto(ArrayList* this)
{
    Cliente* clienteAux;
    FILE* archivo;
    archivo=fopen("data.csv","w");
    int len=al_len(this);
    int i;

    for(i=0;i<len;i++)
    {
        clienteAux=al_get(this,i);
        if(clienteAux!=NULL)
        {
        fprintf(archivo,"%d,%s,%s,%s,%s,%s,%s,%s\n",clienteAux->id,clienteAux->nombre,clienteAux->apellido,clienteAux->email,clienteAux->genero,clienteAux->profesion,clienteAux->usuario,clienteAux->nacionalidad);
        }
    }





    fclose(archivo);
}
