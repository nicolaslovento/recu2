#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "mensajes.h"
#include "usuarios.h"

void* new_Usuario()
{
    eUsuario* aux=NULL;
    aux=(eUsuario*)malloc(sizeof(eUsuario));
    if(aux!=NULL)
    {
        return aux;
    }
    return aux;
}
