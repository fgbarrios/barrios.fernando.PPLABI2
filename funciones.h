#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

typedef struct{
    int id;
    char nombreColor[20];
}eColor;

typedef struct{
    int id;
    char patente[21];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
    int idCliente;
}eAuto;

typedef struct{
    int id;
    char descripcion[26];
    int precio;
    int isEmpty;
}eServicio;


typedef struct{
    int id;
    char patente[21];
    int idServicio;
    eFecha fecha;
    int isEmpty;
    int idCliente;
}eTrabajo;

typedef struct{
    int id;
    char nombre[21];
    char sexo;

}eCliente;


#endif // FUNCIONES_H_INCLUDED

/** \brief Inicializa un array poniendo sus campos IsEmpty en 0 (removiendo la basura)
 *
 * \param lista[] eAuto - Array a inicializar
 * \param tam int - tamanio del array a inicializar
 * \return int- Devuelve 0 en caso de no poder hacerlo, 1 si lo pudo hacer.
 *
 */
int inicializarAutos(eAuto lista[], int tam);


/** \brief Inicializa un array poniendo sus campos IsEmpty en 0 (removiendo la basura)
 *
 * \param trabajos[] eTrabajo- Array a inicializar
 * \param tama int - tamanio del array a inicializar
 * \return int- Devuelve 0 en caso de no poder hacerlo, 1 si lo pudo hacer.
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tama);


/** \brief Menu de opciones principal
 *
 * \return char - devuelve la opcion indicada
 *
 */
char menu();



/** \brief Busca el primer indice libre de un array y devuelve su indice
 *
 * \param lista[] eAuto - Array sobre el que trabaja
 * \param tam int - tamanio del array a recorrer
 * \return int - Devuelve -1 en caso de no poder hacerlo; si lo pudo hacer devuelve el indice vacio.
 *
 */
int buscarLibre(eAuto lista[], int tam);


/** \brief Busca el primer indice libre de un array y devuelve su indice
 *
 * \param lista[] eTrabajo- Array sobre el que trabaja
 * \param tam int- tamanio del array a recorrer
 * \return int- Devuelve -1 en caso de no poder hacerlo; si lo pudo hacer devuelve el indice vacio.
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam);



/** \brief Lista todas las marcas del array Marcas
 *
 * \param marcas[] eMarca - indice de marcas a evaluar
 * \param tam int - tamanio del array
 * \return void - llama a "mostrarMarca" para que muestre por pantalla las opciones validas
 *
 */
void listarMarcas(eMarca marcas[], int tam);


/** \brief Muestra 1 marca indicada
 *
 * \param marca eMarca - valor a mostrar por pantalla
 * \return void
 *
 */
void mostrarMarca(eMarca marca);


/** \brief Lista todas las marcas del array Colores
 *
 * \param colores[] eColor - indice de colores a evaluar
 * \param tam int- tamanio del array
 * \return void- llama a "mostrarColor" para que muestre por pantalla las opciones validas
 *
 */
void listarColores(eColor colores[], int tam);


/** \brief Muestra 1 color indicado
 *
 * \param color eColor - valor a mostrar por pantalla
 * \return void
 *
 */
void mostrarColor(eColor color);


/** \brief Alta de un item en el array auto
 *
 * \param lista[] eAuto - array sobre el que se hace la carga
 * \param tam int - - tamanio del array auto
 * \param colores[] eColor - array de Colores
 * \param tamcol int - tamanio del array colores
 * \param marcas[] eMarca- array de Marcas
 * \param tamarcas int- tamanio del array marcas
 * \param nextIdAuto int* - id a asignar a la nueva carga
 * \param flag int* - flag para que no se ingrese a las demas opciones sin antes haber cargado un auto
 * \return int - - Devuelve 0 en caso de no poder hacerlo; si lo pudo hacer devuelve 1.
 *
 */
int altaAuto(eAuto lista[], int tam, eColor colores[], int tamcol, eMarca marcas[], int tamarcas, int* nextIdAuto ,int* flag, eCliente clientes[], int tamclientes);

/////

/** \brief Carga la descripcion de una marca segun su ID.
 *
 * \param idMarca int - ID a cargar
 * \param marcas[] eMarca- array de marcas
 * \param tam int- tamanio del array de marcas
 * \param desc[] char- variable para cargar la descripcion
 * \return int devuelve 1 si lo pudo hacer, 0 si no lo pudo hacer.
 *
 */
int cargarDescripcionMarca(int idMarca, eMarca marcas[], int tam, char desc[]);


/** \brief Carga la descripcion de un color segun su ID.
 *
 * \param idColor int- ID a cargar
 * \param colores[] eColor- array de color
 * \param tam int- tamanio del array de color
 * \param color[] char- variable para cargar la descripcion
 * \return int- devuelve 1 si lo pudo hacer, 0 si no lo pudo hacer.
 *
 */
int cargarDescripcionColor(int idColor, eColor colores[], int tam, char color[]);


/** \brief Muestra un auto por pantalla
 *
 * \param unAuto eAuto - auto a mostrar
 * \param marcas[] eMarca- array de marcas
 * \param tamsec int - tamanio del array de marcas
 * \param colores[] eColor - array de colores
 * \param tamcol int- tamanio del array de colores
 * \return void
 *
 */
void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamsec, eColor colores[], int tamcol, eCliente clientes[], int tamclientes);


/** \brief Trabaja con la funcion "mostrarAutos", eligiendo los parametros a mostrar por pantalla
 *
 * \param lista[] eAuto - array de autos
 * \param tam int- tamanio del array de autos
 * \param marcas[] eMarca- array de marcas
 * \param tamsec int - tamanio del array de marcas
 * \param colores[] eColor - array de colores
 * \param tamcol int- tamanio del array de colores
 * \return void
 *
 */
void mostrarAutos(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol, eCliente clientes[], int tamclientes);


/** \brief Busca un item del array de autos segun su patente
 *
 * \param lista[] eAuto- array sobre el cual hace la busqueda
 * \param tam int - tamnio del array
 * \param patente[] char - patente a buscar
 * \return int - devuelve el indice del array si lo encontro, -1 si no lo pudo hacer.
 *
 */
int buscarAuto(eAuto lista[], int tam, char patente[]);


/** \brief - Modificar un auto ingresado
 *
 * \param lista[] eAuto - array de autos
 * \param tam int- tamanio del array de autos
 * \param marcas[] eMarca- array de marcas
 * \param tamsec int - tamanio del array de marcas
 * \param colores[] eColor - array de colores
 * \param tamcol int- tamanio del array de colores
 * \return int- devuelve 1 si lo pudo hacer, 0 si no lo pudo hacer.
 *
 */
int modificarAuto(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol, eCliente clientes[], int tamclientes);


/** \brief Baja logica de un auto (cambia el valor de isEmpty)
 *
 * \param lista[] eAuto - array de autos
 * \param tam int- tamanio del array de autos
 * \param marcas[] eMarca- array de marcas
 * \param tamsec int - tamanio del array de marcas
 * \param colores[] eColor - array de colores
 * \param tamcol int- tamanio del array de colores
 * \return int- devuelve 1 si lo pudo hacer, 0 si no lo pudo hacer.
 *
 */
int bajaAuto(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol, eCliente clientes[], int tamclientes);


/** \brief Ordena los autos ingresados por marca y patente
 *
 * \param lista[] eAuto - array de autos
 * \param tam int- tamanio del array de autos
 * \param marcas[] eMarca- array de marcas
 * \param tammar int - tamanio del array de marcas
 * \return void
 *
 */
void ordenarAutos(eAuto lista[], int tam, eMarca marcas[], int tammar);

/////////////////////////////////////////////////// ALTA SERVICIO/////////////////////////

/** \brief Muestra los servicios indicados enviados por la funcion "mostrarServicios"
 *
 * \param lavado eServicio - servicio a mostrar por pantalla
 * \return void
 *
 */
void mostrarServicio(eServicio lavado);

/** \brief Lista los servicios a mostrar por pantalla
 *
 * \param lavados[] eServicio - array del servicio
 * \param tam int - tamanio del array
 * \return void
 *
 */
void listarServicios(eServicio lavados[], int tam);

/** \brief
 *
 * \param trabajos[] eTrabajo - array de trabajos sobre el que se va a realizar la carga
 * \param tamtraba int - tamnio del array de trabajos
 * \param lavados[] eServicio - array de servicios
 * \param tamserv int - tamanio del array servicios
  * \param lista[] eAuto - array de autos
 * \param tam int - - tamanio del array auto
 * \param colores[] eColor - array de Colores
 * \param tamcol int - tamanio del array colores
 * \param marcas[] eMarca- array de Marcas
 * \param tamarcas int- tamanio del array marcas
 * \param nextIdTrabajo int* - ID a asignar al siguiente trabajo
 * \param flagTrabajo int*- Flag para evitar que el usuario liste los trabajos sin antes ingresar uno
 * \return int- devuelve 1 si lo pudo hacer, 0 si no lo pudo hacer.
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamtraba, eServicio lavados[], int tamserv, eAuto lista[], int tam, eColor colores[], int tamcol, eMarca marcas[], int tamarcas, int* nextIdTrabajo, int* flagTrabajo, eCliente clientes[], int tamclientes);
/** \brief Muestra un trabajo indicado
 *
 * \param trabajo eTrabajo - trabajo a mostrar por pantalla
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eCliente clientes[], int tamclientes);
/** \brief Lista un array de trabajos
 *
 * \param trabajos[] eTrabajo - array de trabajos
 * \param tam int - tamanio  de array de trabajos
 * \param clientes[] eCliente- array de clientes
 * \param tamclientes int- tamanio  de array de clientes
 * \return void
 *
 */
void listarTrabajos(eTrabajo trabajos[], int tam, eCliente clientes[], int tamclientes);

/** \brief Carga la descripcion de un color
 *
 * \param idColor int- id del color a cargar
 * \param colores[] eColor - array de colores
 * \param tam int - tamanio del array de colores
 * \param color[] char - variable en donde se guarda la descripcion
 * \return int devuelve 0 si no lo pudo hacer, 1 si lo pudo hacer
 *
 */
int cargarDescripcionColor(int idColor, eColor colores[], int tam, char color[]);

/** \brief Muestra por pantalla el item solicitado
 *
 * \param cliente eCliente - cliente a mostrar
 * \return void
 *
 */
void mostrarCliente(eCliente cliente);
/** \brief Listar los clientes
 *
 * \param clientes[] eCliente - array de clientes
 * \param tam int - tamanio del array de clientes
 * \return void
 *
 */
void listarClientes(eCliente clientes[], int tam);
