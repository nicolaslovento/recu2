#include <string.h>
#include "ctype.h"

int validarString(char* palabra)
{
    int retorno=0;
    int len,i;
    len=strlen(palabra);
    for(i=0;i<len;i++)
    {
        if(isalpha(palabra[i])==0)
        {
        retorno=1;
        break;
        }
    }


    return retorno;
}
