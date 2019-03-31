/** \brief Recibe dos float y los suma
 *
 * \param nro1 float
 * \param nro2 float
 * \return Devuelve float de la suma de ambos
 *
 */

float sumar (float nro1, float nro2);

/** \brief Recibe dos float y los resta
 *
 * \param nro1 float
 * \param nro2 float
 * \return Devuelve float de la resta entre nro1 y nro2
 *
 */

float restar (float nro1, float nro2);

/** \brief Recibe dos float y los divide
 *
 * \param nro1 float
 * \param nro2 float
 * \return Devuelve float de la division entre ambos
 *
 */

float dividir (float nro1, float nro2);

/** \brief Recibe dos float y los multiplica
 *
 * \param nro1 float
 * \param nro2 float
 * \return Devuelve la multiplicacion de ambos
 *
 */

float multiplicar (float nro1, float nro2);

/** \brief Recibe un float y lo factoriza
 *
 * \param nro1 float
 * \return Devuelve el resultado de la factorizacion
 *
 */

float factorial (float nro1);

/** \brief Reserva espacio en memoria para una nueva persona y la inicializa
 *
 * \param flagX, que indica si fue incluido un valor X
 * \param flagY, que indica si fue incluido un valor Y
 * \param flagMostrar, que decide si mostrar menu por defecto o con los valores ingresados (X e Y)
 * \param nro1 float
 * \param nro2 float
 * \return Devuelve un int de la opcion elegida por el usuario
 *
 */

int mostrarMenu (int flagX, int flagY, int flagMostrar, float nro1, float nro2);

/** \brief Le pide al usuario un nro (float)
 *
 * \return Devuelve un float ingresado por el usuario
 *
 */

float conseguirNro();
