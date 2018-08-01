#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "temas.h"

#include "usuarios.h"

void escucharTema(ArrayList* listaUsuarios,ArrayList* listaTemas,ArrayList* listaEstadisticas)
{
    char nick[20];
    char pass[50];
    int idTema;
    printf("Ingrese Nick: ");
    scanf("%s",nick);
    printf("Ingrese password: ");
    scanf("%s",pass);
    int lenTemas;
    int lenUsuarios,i,j;
    lenUsuarios=al_len(listaUsuarios);
    eUsuarios* auxUsuario;
    eEstadisticas* auxEst;
    eTemas* auxTema;
    for(i=0;i<lenUsuarios;i++)
    {
        auxUsuario=al_get(listaUsuarios,i);

        if(strcmpi(pass,auxUsuario->password)==0)
        {
            lenTemas=al_len(listaTemas);
            tema_MostrarTodos(listaTemas);
            printf("Elija un tema: (ID) ");
            scanf("%d",&idTema);

            for(j=0;j<lenTemas;j++)
            {
                auxTema=al_get(listaTemas,j);
                if(auxTema->id==idTema)
                {
                    auxEst=estadistica_New();
                    auxEst->idTema=idTema;
                    auxEst->idUsuario=auxUsuario->id;
                    al_add(listaEstadisticas,auxEst);
                }
            }

        }
    }

}

int usuario_ordenarPorNombre(void* aux1,void* aux2)
{
    eUsuarios* aux3=(eUsuarios*)aux1;
    eUsuarios* aux4=(eUsuarios*)aux2;
    int retorno;

    retorno=strcmpi(aux3->nombre,aux4->nombre);

    return retorno;

}

void usuario_MostrarTodos(ArrayList* lista)
{
    int len,i;
    eUsuarios* aux;
    int contador=50;
    if(lista!=NULL)
    {
        len=al_len(lista);
        printf("Id  |    Nombre   |    Sexo   |  Pais\n ");
        for(i=0;i<len;i++)
        {
            aux=al_get(lista,i);
            usuario_MostrarUno(aux);

        if(i==contador)
        {
            contador=contador+50;
            system("pause");
            system("cls");
            printf("Id  |    Nombre   |    Sexo   |  Pais\n ");
        }
        }


    }
}

void usuario_MostrarUno(eUsuarios* unUsuario)
{
    printf("%5d  %15s  %5s  %5s\n",unUsuario->id,unUsuario->nombre,unUsuario->sexo,unUsuario->pais);
}

eEstadisticas* estadistica_New()
{
    eEstadisticas* aux=NULL;
    aux=(eEstadisticas*)malloc(sizeof(eEstadisticas));
    if(aux!=NULL)
    {
        return aux;
    }
    return aux;
}

eUsuarios* usuario_New()
{
    eUsuarios* aux=NULL;
    aux=(eUsuarios*)malloc(sizeof(eUsuarios));
    if(aux!=NULL)
    {
        return aux;
    }
    return aux;
}
