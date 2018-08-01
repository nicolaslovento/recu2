typedef struct
{
    int id;
    char nombre[100];
    char email[100];
    char sexo[20];
    char pais[100];
    char password[100];
    char ip_Adress[30];
    int idTema;

}eUsuarios;

typedef struct
{
    int idUsuario;
    int idTema;

}eEstadisticas;

eEstadisticas* estadistica_New();
void escucharTema(ArrayList* listaUsuarios,ArrayList* listaTemas,ArrayList* listaEstadisticas);

int usuario_ordenarPorNombre(void* aux1,void* aux2);
void usuario_MostrarTodos(ArrayList* );
void usuario_MostrarUno(eUsuarios*);
eUsuarios* new_Usuario();
