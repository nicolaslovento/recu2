#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "usuarios.h"
#include "mensajes.h"

void* new_Mensaje()
{
    eMensaje* aux=NULL;
    aux=(eMensaje*)malloc(sizeof(eMensaje));
    if(aux!=NULL)
    {
        return aux;
    }
    return aux;
}
