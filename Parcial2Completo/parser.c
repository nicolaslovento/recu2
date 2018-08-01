#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "letras.h"
#include "parser.h"

int parserLetras(ArrayList* miArray,char* nombreDatos)
{
    FILE* archivo;
    int retorno=0;
    char letra,vocal,consonante;
    char nombre[30];
    int id=1,cant;
    if(miArray!=NULL && strlen(nombreDatos)>0)
    {
        archivo=fopen(nombreDatos,"r");

        if(archivo!=NULL)
        {
            eLetra* letraAux;
            while(!feof(archivo))
            {
                cant=fscanf(archivo,"%c,%[^,],%c,%c\n",&letra,nombre,&vocal,&consonante);

                if(cant==4)
                {
                letraAux=new_Letra();
                setLetra(letraAux,letra);
                setNombre(letraAux,nombre);
                setVocal(letraAux,vocal);
                setConsonante(letraAux,consonante);
                setId(letraAux,id);
                al_add(miArray,letraAux);
                id++;
                retorno=1;

                }

            }

        }

        fclose(archivo);

    }

    return retorno;
}
