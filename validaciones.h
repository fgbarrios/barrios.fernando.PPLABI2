#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED



/** \brief Confirmar salida
 *
 * \return char- Devuelve k para salir
 *
 */
char confirmar();
/** \brief Valida un id
 *
 * \param id int- id a evaludar
 * \return int - 1 si es valido, 0 si no lo es.
 *
 */
int validarId(int id);
/** \brief Valida una patente
 *
 * \param patente[] char - patente a validar
 * \return int- 1 si es valido, 0 si no lo es.
 *
 */
int validarPatente(char patente[]);
/** \brief Confirma salida del submenu
 *
 * \return char- Devuelve s para salir
 *
 */
char confirmarSub();
