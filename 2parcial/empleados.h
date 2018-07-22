
typedef struct
{
    int id;
    char nombre[30];
    float sueldo;
    int edad;
    char profesion[30];

}eEmpleado;



void* new_Empleado();
void mostrarUnEmpleado(eEmpleado* empleado);
int getId(ArrayList* eArray);
int funcionQueFiltra(void* empleadoAux);
