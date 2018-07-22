
typedef struct
{
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[2];
    char profesion[256];
    char nacionalidad[256];
    int id;
    char usuario[250];
}Cliente;

void* devolverClientePorId(ArrayList* pArray,int id);
void modificarCliente(ArrayList* this);
void mostrarUnClientePorId(ArrayList* this);
int eliminarCliente(ArrayList* this);
int agregarCliente(ArrayList* this);
int getClienteIndexById(ArrayList* this,int id);
int mostrarUnCliente(Cliente* clienteAux);
int ordenarPorEmail(void* cliente1,void* cliente2);
int ordenarPorNombre(void* cliente1,void* cliente2);
Cliente* newEmpleado();
void listarClientes(ArrayList* this);





int setNombre(Cliente* pCliente,char* newNombre);
int setId(Cliente* pCliente,int id);
int setGenero(Cliente* pCliente,char* genero);
int setProfesion(Cliente* pCliente,char* profesion);
int setNacionalidad(Cliente* pCliente,char* nacionalidad);
int setUsuario(Cliente* pCliente,char* usuario);
int setEmail(Cliente* pCliente,char* email);
int setApellido(Cliente* pCliente,char* apellido);
