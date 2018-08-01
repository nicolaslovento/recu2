typedef struct{

    int id;
    char letra;
    char nombre[21];
    char vocal;
    char consonante;

}eLetra;
int ordenarLetras(void* aux1,void* aux2);

ArrayList* crearArrayRepetido(ArrayList* this);
void comprobarPalabra(ArrayList* miLista);
int comprobarVocaloConsonante(char );
void completarLetras(ArrayList* miArray);
void mostrarLetras(ArrayList* miArray);
void mostrarUnaLetra(eLetra* letraAux);
eLetra* new_Letra();
void setId(eLetra* miLetra,int id);
void setLetra(eLetra* miLetra,char letra);
void setVocal(eLetra* miLetra,char vocal);
void setConsonante(eLetra* miLetra,char consonante);
void setNombre(eLetra* miLetra,char* nombre);
