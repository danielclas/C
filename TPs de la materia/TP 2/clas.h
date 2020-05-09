typedef struct{

 int id;
 char name[20];

} eSector;

typedef struct{

 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;

} eEmployee;

/** \brief Muestra opciones del menu principal y consigue respuesta
 *
 * \param numeroUno float
 *
 * \return Regresa un int de la funcion elegida
 *
 */
int funcionMenu ();
/** \brief Recorre array empleados y busca si hay ocupados
 *
 * \param nomina[] eEmployee
 * \param tam int
 *
 * \return Devuelve 1 si vacio, 0 si hay algun empleado
 *
 */
int hayEmpleados(eEmployee nomina[], int tam);
/** \brief Recorre array empleados y asigna 1 a campo isEmpty
 *
 * \param nomina[] eEmployee
 * \param tam int
 *
 * \return void
 *
 */
void inicializarEmpleados (eEmployee nomina[], int tam);
/** \brief Si hay lugar libre, pide al usuario ingresar los datos para dar de alta un empleado
 *
 * \param nomina[] eEmployee
 * \param sectores[] eSector
 * \param tam in
 * \param tamSec int
 *
 * \return void
 *
 */
void agregarEmpleado(eEmployee nomina[], eSector sectores[], int tam, int tamSec);
/** \brief Recorre array de empleados y devuelve indice donde isEmpty==1
 *
 * \param nomina[] eEmployee
 * \param tam int
 *
 * \return entero que indica indice libre en array empleados
 *
 */
int buscarLibre(eEmployee nomina[], int tam);
/** \brief Pide y valida nombre, y lo asigna al elemento indicado en el array de empleados
 *
 * \param nomina[] eEmployee
 * \param index int
 * \param mensaje[] char
 * \param mensajeError[] char
 *
 * \return void
 *
 */
void conseguirNombre(eEmployee nomina[], int index, char mensaje[], char mensajeError[]);
/** \brief Pide y valida apellido, y lo asigna al elemento indicado en el array de empleados
 *
 * \param nomina[] eEmployee
 * \param index int
 * \param mensaje[] char
 * \param mensajeError[] char
 *
 * \return void
 *
 */
void conseguirApellido(eEmployee nomina[], int index, char mensaje[], char mensajeError[]);
/** \brief Genera un id autoincremental a partir de un static int
 *
 * \param
 *
 * \return entero que sera el id del empleado a dar de alta
 *
 */
int generarId();
/** \brief Pide y valida un numero flotante
 *
 * \param mensaje[] char
 * \param mensajeError[] char
 *
 * \return flotante validado
 *
 */
float conseguirSalario(char mensaje[], char mensajeError[]);
/** \brief Lista sectores y pide al usuario que ingrese uno
 *
 * \param sectores[] eSector
 * \param tamSec int
 *
 * \return entero correspondiente a sector elegido por el usuario
 *
 */
int elegirSector(eSector sectores[], int tamSec);
/** \brief Lista sectores ocupados
 *
 * \param sectores[] eSector
 * \param tamSec int
 *
 * \return void
 *
 */
void mostrarSectores(eSector sectores[], int tamSec);
/** \brief Recorre array de sectores y setea a 0 su id
 *
 * \param sectores[] eSector
 * \param tamSec int
 *
 * \return void
 *
 */
void inicializarSectores(eSector sectores[], int tamSec);
/** \brief Inicializa array de sectores con valores validos en los campos
 *
 * \param sectores[] eSector
 * \param tamSec int
 *
 * \return void
 *
 */
void hardCodearSectores(eSector sectores[], int tamSec);
/** \brief Pide id de empleado a modificar y permite ingresar nuevos datos
 *
 * \param nomina[] eEmployee
 * \param sectores[] eSector
 * \param tam in
 * \param tamSec int
 *
 * \return void
 *
 */
void modificarEmpleado(eEmployee nomina[], eSector sectores[], int tam, int tamSec);
/** \brief Recibe un id y lo busca en el array de empleados
 *
 * \param nomina[] eEmployee
 * \param tam int
 * \param idABuscar in
 *
 * \return entero correspondiente al index del empleado si lo encuentra, o -1 si el empleado no existe
 *
 */
int buscarEmpleado(eEmployee nomina[], int tam, int idABuscar);
/** \brief Recibe un elemento del array de empleados y lo muestra
 *
 * \param empleado eEmployee
 * \param sectores[] eSector
 * \param tamSec int
 *
 * \return void
 *
 */
void mostrarEmpleado(eEmployee empleado, eSector sectores[], int tamSec);
/** \brief Lista todos los empleados activos
 *
 * \param nomina[] eEmployee
 * \param sectores[] eSector
 * \param tam in
 * \param tamSec int
 *
 * \return void
 *
 */
void mostrarEmpleados(eEmployee nomina[], eSector sectores[], int tam, int tamSec);
/** \brief Recibe un empleado, recorre array de sectores y devuelve el indice del sector que corresponde a ese empleado
 *
 * \param empleado eEmployee
 * \param sectores[] eSector
 * \param tamSec int
 *
 * \return entero correspondiente al sector de empleado
 *
 */
int averiguarSector(eEmployee empleado, eSector sectores[], int tamSec);
/** \brief Lista empleados y pide al usuario ingresar ID para dar baja logica a ese empleado
 *
 * \param nomina[] eEmployee
 * \param sectores[] eSector
 * \param tam int
 * \param tamSec int
 *
 * \return entero correspondiente al sector de empleado
 *
 */
void bajaEmpleado(eEmployee nomina[], eSector sectores[], int tam, int tamSec);
/** \brief Pide al usuario descripcion para inicializar un sector
 *
 * \param sectores[] eSector
 * \param tamSec int
 *
 * \return void
 *
 */
void cargarSectores(eSector sectores[], int tamSec);
/** \brief Calcula salarios total, promedio y empleados por encima de la media
 *
 * \param nomina[] eEmployee
 * \param tam int
 *
 * \return void
 *
 */
void totalPromedioSalarios(eEmployee nomina[], int tam);
/** \brief Menu que pregunta al usuario a que informa desea ingresar
 *
 * \param nomina[] eEmployee
 * \param sectores[] eSector
 * \param tam int
 * \param tamSec int
 *
 * \return void
 *
 */
void menuInformes(eEmployee nomina[], eSector sectores[], int tam, int tamSec);
/** \brief Inicializa array de empleados con valores validos en los campos
 *
 * \param nomina[] eEmployee
 * \param tam int
 *
 * \return void
 *
 */
void hardCodearEmpleados(eEmployee nomina[], int tam);
/** \brief Recibe mensaje y mensaje de error y pide y valida entero ingresado por el usuario
 *
 * \param mensaje[] char
 * \param mensajeError[] char
 *
 * \return entero validado ingresado por el usuario
 *
 */
int conseguirPositivo(char mensaje[], char mensajeError[]);
/** \brief Recibe arrays de empleados y sectores y los orden primero por sector y luego alfabeticamente
 *
  * \param nomina[] eEmployee
 * \param sectores[] eSector
 * \param tam int
 * \param tamSec int
 *
 * \return void
 *
 */
void ordenarEmpleados(eEmployee nomina[], eSector sectores[], int tam, int tamSec);
