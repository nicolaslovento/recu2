#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "empleados.h"


int main()
{
    ArrayList* arrayEmpleados;
    arrayEmpleados=al_newArrayList();
    int len,i;
    parserEmpleados(arrayEmpleados);
    eEmpleado* unEmpleado;
    len=al_len(arrayEmpleados);
    printf("SIN FILTRAR:\n\n");
    for(i=0;i<len;i++)
    {
        unEmpleado=al_get(arrayEmpleados,i);
        mostrarUnEmpleado(unEmpleado);
    }


    printf("\n\n\nDESPUES DEL FILTRO:\n\n");
    ArrayList* filtro;
    filtro=al_Filter(arrayEmpleados,funcionQueFiltra);

    int len2=al_len(filtro);
    for(i=0;i<len2;i++)
    {
        unEmpleado=al_get(filtro,i);
        mostrarUnEmpleado(unEmpleado);
    }


    guardarEmpleados(filtro);

    return 0;
}
