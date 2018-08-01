typedef struct
{
    int id;
    char nombre_Tema[50];
    char artista[50];
    int reproducciones;
 }eTemas;
void tema_OrdenarPorArtista(void* aux1,void* aux2);
void tema_MostrarTodos(ArrayList* lista);
void tema_MostrarUno(eTemas* unTema);
eTemas* tema_New();
