#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleados.h"




int funcionQueFiltra(void* empleadoAux)
{
    eEmpleado* e1=(eEmpleado*)empleadoAux;
    if(empleadoAux!=NULL)
    {
        if(e1->edad>30 && strcmp(e1->profesion,"programador")==0)
        {
            return 1;
        }
    }

    return 0;
}

void* new_Empleado()
{
    eEmpleado* empleado=NULL;
    empleado=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(empleado!=NULL)
    {
        return empleado;
    }
    return empleado;
}

void mostrarUnEmpleado(eEmpleado* empleado)
{
    printf("%d  %s   $%.2f   %d  %s \n",empleado->id,empleado->nombre,empleado->sueldo,empleado->edad,empleado->profesion);
}



int getId(ArrayList* eArray)
{
    int retorno;
    retorno=(eArray->size)+1;
    return retorno;
}


