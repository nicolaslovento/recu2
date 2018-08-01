typedef struct
{
    int id;
    char mensaje[10000];
    int likes;
    int idUsuario;
}eMensaje;

void* new_Mensaje();
