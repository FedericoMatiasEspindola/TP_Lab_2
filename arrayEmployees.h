typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
}eSector;



/** \brief Imprime menu principal
 *
 * \return int Opcion elegida
 *
 */
int menu();



/** \brief Recorre el array para ver si esta vacia
 *
 * \param lista[] eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado lista[], int tam);



/** \brief Obtiene el primer indice libre del array.
 *
 * \param lista[] eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return int El primer indice disponible
 *
 */
int buscarLibre(eEmpleado lista[], int tam);



/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \param legajo int
 * \return int
 *
 */
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);



/** \brief Pide los datos a ser cargados
 *
 * \param lista[] eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return
 *
 */
void altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector);



/** \brief Busca el ID del empleado y cambia el estado para borrar sus datos
 *
 * \param lista[] eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return
 *
 */
void bajaEmpleado(eEmpleado lista[], int tam);


/** \brief Modifica los datos guardados de los empleados
 *
 * \param lista[] eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return
 *
 */
void modificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector);



/** \brief Compara los nombres y los ordena en orden alfabetico
 *
 * \param lista[] eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return
 *
 */
void ordenarEmpleadosXApellido(eEmpleado lista[], int tam);



/** \brief Imprime los datos guardados del empleado
 *
 * \param eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return
 *
 */
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam);




/** \brief Imprime los datos guardados de los empleados
 *
 * \param eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return
 *
 */
void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector);



void listarSectores(eSector sectores[], int tam);



void obtenerSector(eSector sectores[], int tam, int idSector, char cadena[]);


/** \brief Imprime menu modificador
 *
 * \return int Opcion elegida
 *
 */
int menuModifica();




/** \brief Calcula el promedio de los salarios, la suma de los salarios y los empleados que superan el salario promedio
 *
 * \param lista[] eEmpleado El array se pasa como parametro
 * \param tam int Tamaño del Array
 * \return
 *
 */
int salarios(eEmpleado lista[], int tam);

