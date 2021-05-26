#include "funciones.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


/** \brief Submenu para los informes
 *
 * \return int - devuelve la opcion seleccionada
 *
 */
int subMenuInformes();
/** \brief Busca los colores (si existe) en el array colores
 *
 * \param colores[] eColor - array de colores
 * \param tam int - tamanio array colores
 * \param color int - id color a buscar
 * \return int - -1 si no lo encuentra, 1 si lo encuentra
 *
 */
int buscarColor(eColor colores[], int tam, int color);
/** \brief - Mostrar autos del color seleccionado por el usuario
 *
 * \param autos[] eAuto-  - array de autos
 * \param tam int - tamanio del array de autos
 * \param marcas[] eMarca  - array de marcas
 * \param tammar int- tamanio del array de marcas
 * \param colores[] eColor- array de colores
 * \param tamcol int- tamanio del array de colores
 * \param clientes[] eCliente- array de clientes
 * \param tamclientes int- tamanio del array de autos
 * \return void
 *
 */
void autosPorColor(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol, eCliente clientes[], int tamclientes);

/** \brief Busca las marcas (si existe) segun ID
 *
 * \param marcas[] eMarca - array de marcas
 * \param tam int- tamanio del array de marcas
 * \param marca int - id a buscar
 * \return int -1 si no lo encuentra, 1 si lo encuentra
 *
 */
int buscarMarca(eMarca marcas[], int tam, int marca);
/** \brief Mostrar autos de una marca seleccionada.
 *
 * \param autos[] eAuto-  - array de autos
 * \param tam int - tamanio del array de autos
 * \param marcas[] eMarca  - array de marcas
 * \param tammar int- tamanio del array de marcas
 * \param colores[] eColor- array de colores
 * \param tamcol int- tamanio del array de colores
 * \param clientes[] eCliente- array de clientes
 * \param tamclientes int- tamanio del array de autos
 * \return void
 *
 */
void autoPorMarca(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol, eCliente clientes[], int tamclientes);

/** \brief Informar el o los autos mas viejos
 *
 * \param autos[] eAuto-  - array de autos
 * \param tam int - tamanio del array de autos
 * \param marcas[] eMarca  - array de marcas
 * \param tammar int- tamanio del array de marcas
 * \param colores[] eColor- array de colores
 * \param tamcol int- tamanio del array de colores
 * \param clientes[] eCliente- array de clientes
 * \param tamclientes int- tamanio del array de autos
 * \return void
 *
 */
void autosMasViejos(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol, eCliente clientes[], int tamclientes);


/** \brief Mostrar un listado de los autos separados por marca
 *
 * \param autos[] eAuto-  - array de autos
 * \param tam int - tamanio del array de autos
 * \param marcas[] eMarca  - array de marcas
 * \param tammar int- tamanio del array de marcas
 * \param colores[] eColor- array de colores
 * \param tamcol int- tamanio del array de colores
 * \param clientes[] eCliente- array de clientes
 * \param tamclientes int- tamanio del array de autos
 * \return void
 *
 */
void autosTodosPorMarca(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol, eCliente clientes[], int tamclientes);

/** \brief Elegir un color y una marca, y contar cuantos autos hay de ese color y de esa marca.
 *
 * \param autos[] eAuto-  - array de autos
 * \param tam int - tamanio del array de autos
 * \param marcas[] eMarca  - array de marcas
 * \param tammar int- tamanio del array de marcas
 * \param colores[] eColor- array de colores
 * \param tamcol int- tamanio del array de colores
 * \return void
 *
 */
void contadorAutos(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol);

/** \brief Mostrar la o las marcas mas elegidas por los clientes
 *
 * \param autos[] eAuto-  - array de autos
 * \param tam int - tamanio del array de autos
 * \param marcas[] eMarca  - array de marcas
 * \param tammar int- tamanio del array de marcas
 * \return void
 *
 */
void marcasMasElegidas(eAuto autos[], int tam, eMarca marcas[], int tammar);
