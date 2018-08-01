#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "parser.h"
#include "letras.h"

ArrayList* crearArraySinRepetir(ArrayList* this)
{
    ArrayList* filtrada;
    filtrada=al_newArrayList();
    int i,j;
    eLetra* aux1;
    eLetra* aux2;
    int len1;
    int contador=0;
    len1=al_len(this);
    for(i=0;i<len1;i++)
    {

        aux1=al_get(this,i);

        for(j=1;j<len1;j++)
        {
            aux2=al_get(this,j);
            if(i!=j)
            {

                if(aux1->letra==aux2->letra)
                {
                    break;


                }

            }

            if(j==len1-1)
            {
                 al_add(filtrada,aux1);
            }
        }
}


    return filtrada;

}


int ordenarLetras(void* aux1,void* aux2)
{
    eLetra* letra1=(eLetra*)aux1;
    eLetra* letra2=(eLetra*)aux2;
    int retorno=1;

    if(letra1->letra<letra2->letra)
    {
        return -1;
    }else
    {
        if(letra1->letra==letra2->letra)
        {
            return 0;
        }
    }

    return retorno;

}

ArrayList* crearArrayRepetido(ArrayList* this)
{
    ArrayList* filtrada;
    filtrada=al_newArrayList();
    int i,j;
    eLetra* aux1;
    eLetra* aux2;
    int len1;
    len1=al_len(this);
    for(i=0;i<len1;i++)
    {

        aux1=al_get(this,i);

        for(j=1;j<len1;j++)
        {
            aux2=al_get(this,j);
            if(i!=j)
            {

                if(aux1->letra==aux2->letra)
                {
                al_add(filtrada,aux1);
                j=0;
                break;

                }

            }


        }
        continue;
    }


    return filtrada;

}

void comprobarPalabra(ArrayList* miLista)
{
    char palabra[30];

    int len,i=0,k=0,j=0;
    eLetra* letraAux;
    printf("Ingrese palabra: ");
    fflush(stdin);
    gets(palabra);
    len=strlen(palabra);
    int indexHallado[len];
    int flag=0;
    int contador=0;
    if(len>0)
    {
        for(i=0;i<al_len(miLista);i++)
        {
            letraAux=al_get(miLista,i);
            if(letraAux!=NULL)
            {
                if(palabra[j]==letraAux->letra)
                {
                        flag=0;
                        for(k=0;k<len;k++)
                        {
                        if(indexHallado[k]==letraAux->id)
                        {
                            flag=1;
                            i=i+1;
                        }
                        }
                        if(flag!=1)
                        {

                        indexHallado[j]=letraAux->id;
                        contador++;
                        j++;
                        i=0;
                        printf("%d-",letraAux->id);


                        }
                    }




                }
            }
        }


    if(contador<len)
    {
        printf("No existen las letras suficientes para completar la palabra..\n");
    }else
    {
        printf("Existen las letras suficientes para completar la palabra..\n");
    }
}


int comprobarVocaloConsonante(char aux)
{

    if(aux=='a' || aux=='e' || aux=='i' || aux=='o' || aux=='u')
    {
        return 1;
    }

    return 0;
}


void completarLetras(ArrayList* miArray)
{
    int len,i;
    char aux;
    len=al_len(miArray);
    eLetra* letraAux;
    for(i=0;i<len;i++)
    {
        letraAux=al_get(miArray,i);

        if(letraAux!=NULL )
        {
            aux=tolower(letraAux->letra);
            if(comprobarVocaloConsonante(aux)==1)
            {
                setVocal(letraAux,'1');
            }else
            {
                setConsonante(letraAux,'1');
            }
        }
    }
}


void mostrarLetras(ArrayList* miArray)
{
    int len,i;
    len=al_len(miArray);
    eLetra* letraAux;
    printf("ID  |  letra  |     nombre    |  vocal  |  consonante  \n");
    for(i=0;i<len;i++)
    {

        letraAux=al_get(miArray,i);
        if(letraAux!=NULL)
        {
            mostrarUnaLetra(letraAux);
        }
    }

}

void mostrarUnaLetra(eLetra* letraAux)
{
    printf("%3d  %5c  %15s   %5c      %5c\n",letraAux->id,letraAux->letra,letraAux->nombre,letraAux->vocal,letraAux->consonante);
}

















eLetra* new_Letra()
{
    eLetra* letraAux=NULL;
    letraAux=(eLetra*)malloc(sizeof(eLetra));
    if(letraAux!=NULL)
    {
        return letraAux;
    }
        return letraAux;

}

void setId(eLetra* miLetra,int id)
{
    miLetra->id=id;
}

void setLetra(eLetra* miLetra,char letra)
{
    miLetra->letra=letra;
}

void setVocal(eLetra* miLetra,char vocal)
{
    miLetra->vocal=vocal;
}

void setConsonante(eLetra* miLetra,char consonante)
{
        miLetra->consonante=consonante;
}

void setNombre(eLetra* miLetra,char* nombre)
{
    strcpy(miLetra->nombre,nombre);
}
