#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parser.h"
#include "empleados.h"


int parserEmpleados(ArrayList* arrayEmpleados)
{
    FILE* archivo;
    archivo=fopen("data.csv","r");
    eEmpleado* empleadoNew;
    int cant;
    char id[10];
    char nombre[50];
    char sueldo[50];
    char edad[50];
    char profesion[50];
    do
    {

        empleadoNew=new_Empleado();
        cant=fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,sueldo,edad,profesion);
        if(cant==5)
        {

            empleadoNew->id=atoi(id);
            strcpy(empleadoNew->nombre,nombre);
            empleadoNew->sueldo=stringAFloat(sueldo);
            empleadoNew->edad=atoi(edad);
            strcpy(empleadoNew->profesion,profesion);

            al_add(arrayEmpleados,empleadoNew);
        }



    }while(!feof(archivo));

    fclose(archivo);
}

int stringAentero(char* string)
{
    int retorno;
    retorno=atoi(string);
    return retorno;
}

float stringAFloat(char* string)
{
    float retorno;
    retorno=atof(string);
    return retorno;
}

int guardarEmpleados(ArrayList* filtro)
{
    FILE* archivo;
    archivo=fopen("out.csv","w");
    int cant,len,i;
    len=al_len(filtro);
    eEmpleado* unEmpleado;
    for(i=0;i<len;i++)
    {
        unEmpleado=al_get(filtro,i);
        if(unEmpleado!=NULL)
        {
          cant=fprintf(archivo,"%d,%s,%.2f,%d,%s\n",unEmpleado->id,unEmpleado->nombre,unEmpleado->sueldo,unEmpleado->edad,unEmpleado->profesion);
        }


    }

     fclose(archivo);
}
