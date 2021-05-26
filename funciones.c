#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#include "informes.h"


int inicializarAutos(eAuto lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }

    return todoOk;
}

int inicializarTrabajos(eTrabajo trabajos[], int tama){
    int todoOk = 0;
    if(trabajos != NULL && tama > 0)
    {
        for(int i = 0; i < tama; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    else{
        todoOk = 0;
    }

    return todoOk;
}


char menu()
{
    char opcion;

    system ("cls");
    printf("**********LAVADERO DE AUTOS**********\n\n");
    printf("a. Alta auto\n");
    printf("b. Modificar auto\n");
    printf("c. Baja auto\n");
    printf("d. Listar autos\n");
    printf("e. listar Marcas\n");
    printf("f. Listar Colores\n");
    printf("g. Listar Servicios\n");
    printf("h. Alta Trabajo\n");
    printf("i. Listar Trabajos\n");
    printf("j. INFORMES\n");
    printf("k. Salir\n\n");
    printf("Ingrese opcion (a-k): ");
    fflush(stdin);
    scanf("%c", &opcion);

    while(opcion != 'a' && opcion != 'b' &&
          opcion != 'c' && opcion != 'd' &&
          opcion != 'e' && opcion != 'f' &&
          opcion != 'g' && opcion != 'h' &&
          opcion != 'i' && opcion != 'j' &&
           opcion != 'k' ){
        printf("ERROR. Ingrese opcion (a-k): ");
        fflush(stdin);
        scanf("%c", &opcion);
    }

    return opcion;
}


int buscarLibre(eAuto lista[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break; // si no se coloca break, devolveria la ultima ubicacion encontrada vacia
        }
    }
    return indice;
}

int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break; // si no se coloca break, devolveria la ultima ubicacion encontrada vacia
        }
    }
    return indice;
}


void listarMarcas(eMarca marcas[], int tam)
{
    printf("************Lista de Marcas************\n");
    printf("    ID        Marcas\n");
        for (int i = 0;i < tam ;i++ )
        {
            mostrarMarca(marcas[i]);
        }

}

void mostrarMarca(eMarca marca)
{
    printf("    %d      %10s\n", marca.id, marca.descripcion);
}

void listarColores(eColor colores[], int tam)
{
    printf("************Lista de Colores************\n");
    printf("    ID      Color\n");
        for (int i = 0;i < tam ;i++ )
        {
            mostrarColor(colores[i]);
        }

}
void listarClientes(eCliente clientes[], int tam)
{
    printf("************Lista de Clientes************\n");
    printf("    ID      Nombre\n");
        for (int i = 0;i < tam ;i++ )
        {
            mostrarCliente(clientes[i]);
        }

}

void mostrarCliente(eCliente cliente)
{
    printf("    %d      %10s   %c\n", cliente.id, cliente.nombre, cliente.sexo);
}


void mostrarColor(eColor color)
{
    printf("    %d      %10s\n", color.id, color.nombreColor);
}

int altaAuto(eAuto lista[], int tam, eColor colores[], int tamcol, eMarca marcas[], int tamarcas, int* nextIdAuto ,int* flag, eCliente clientes[], int tamclientes)
{
    int todoOk = 0;
    eAuto nuevoAuto;
    int indice;

    char patente[21];
    int idMarca;
    int IdColor;
    int modelo;
    int idCliente;

    system("cls");
    printf("     Alta Auto\n\n");

    if(lista != NULL && tam > 0 && colores != NULL && tamcol > 0 && marcas != NULL && tamarcas > 0 && nextIdAuto != NULL && flag != NULL && clientes != NULL && tamclientes > 0 )
    {
        indice = buscarLibre(lista, tam);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            printf("ID del auto a ingresar: %d\n", *nextIdAuto);

            printf("Ingrese patente (max. 20 caracteres): ");
            fflush(stdin);
            gets(patente);
            while(validarPatente(patente) != 1)
            {
                printf("Error. Reingrese patente (max. 20 caracteres):");
                fflush(stdin);
                gets(patente);
            }

            strcpy(nuevoAuto.patente, patente);

            listarMarcas(marcas, tamarcas);

            printf("Ingrese ID Marca (1000/1001/1002/1003/1004): ");
            scanf("%d", &idMarca);
            while(idMarca != 1000 && idMarca != 1001 && idMarca != 1002 && idMarca != 1003 && idMarca != 1004)
            {
                printf("Error.Reingrese ID marca (1000/1001/1002/1003/1004): ");
                scanf("%d", &idMarca);
            }

            nuevoAuto.idMarca = idMarca;

            listarColores(colores, tamcol);

            printf("Ingrese ID Color (1/2/3/4/5): ");
            scanf("%d", &IdColor);
            while(!(IdColor >= 1 && IdColor <= 5))
            {
                printf("Error.Reingrese ID Color (1/2/3/4/5): ");
                scanf("%d", &IdColor);
            }

            nuevoAuto.idColor = IdColor;

            printf("Ingrese modelo (Anio, desde 1950 a 2021): ");
            scanf("%d", &modelo);
            while(!(modelo >=1950 || modelo <= 2021))
            {
                    printf("Error. Reingrese modelo (Anio):");
                    scanf("%d", &modelo);
            }

            nuevoAuto.modelo = modelo;

            // CLIENTES

            listarClientes(clientes, tamclientes);

            printf("Ingrese ID Cliente: ");
            scanf("%d", &idCliente);
            while(!(idCliente >= 25 && idCliente <= 50))
            {
                printf("Error.Reingrese ID Cliente : ");
                scanf("%d", &idCliente);
            }

            nuevoAuto.idCliente = idCliente;

            //-------- fin de ingreso de datos----------//


            nuevoAuto.isEmpty = 0;
            nuevoAuto.id = *nextIdAuto;
            (*nextIdAuto)++;
            lista[indice] = nuevoAuto;

            *flag = 1;
            todoOk = 1;
        }
    }

    return todoOk;
}
/////

int cargarDescripcionMarca(int idMarca, eMarca marcas[], int tam, char desc[])
{
    int todoOk = 0;

    if(idMarca >= 1000 && idMarca <= 1004 && marcas != NULL && tam > 0 && desc != NULL)
    {
        for (int i = 0; i< tam ;i++ )
        {
            if(marcas[i].id == idMarca)
            {
                strcpy(desc, marcas[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

int cargarDescripcionColor(int idColor, eColor colores[], int tam, char color[])
{
    int todoOk = 0;

    if(idColor >= 1 && idColor <= 5 &&colores != NULL && tam > 0 && color != NULL)
    {
        for (int i = 0; i< tam ;i++ )
        {
            if(colores[i].id == idColor)
            {
                strcpy(color, colores[i].nombreColor);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

int cargarDescripcionCliente(int idCliente, eCliente clientes[], int tam, char cliente[])
{
    int todoOk = 0;

    if(idCliente >= 25 && idCliente <= 50 && clientes != NULL && tam > 0 && cliente != NULL)
    {
        for (int i = 0; i< tam ;i++ )
        {
            if(clientes[i].id == idCliente)
            {
                strcpy(cliente, clientes[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamsec, eColor colores[], int tamcol, eCliente clientes[], int tamclientes)
{
    char descripcion[20];
    char color[20];
    char descCliente[20];

    if(cargarDescripcionMarca(unAuto.idMarca, marcas, tamsec, descripcion)
       && cargarDescripcionColor(unAuto.idColor, colores, tamcol, color) && cargarDescripcionCliente(unAuto.idCliente, clientes, tamclientes, descCliente))
    {
        printf("%d  %3s  %10s  %10s  %d   %10s\n",
           unAuto.id,
           unAuto.patente,
           descripcion,
           color,
           unAuto.modelo,
           descCliente
          );
    }
    printf("\n");
}

void mostrarAutos(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol, eCliente clientes[], int tamclientes)
{
    int flag = 0;

    printf("         Listado de Autos\n");
    printf("ID   Patente    Marca         Color  Modelo   Cliente\n");

    for(int i=0; i<tam; i++)
    {
        if(!lista[i].isEmpty) // Si .isEmpty es 0 (osea, tiene un auto), lo niego (paso el valor a 1 para que ingrese al IF)
        {
            mostrarAuto(lista[i], marcas, tamsec, colores, tamcol, clientes, tamclientes);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("        No hay Autos que mostrar.\n");
    }
    printf("\n");
}

int buscarAuto(eAuto lista[], int tam, char patente[])
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if((strcmp(lista[i].patente, patente) == 0) && !lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menuModificar()
{
    int opcion;

    system ("cls");
    printf("Que desea modificar?\n\n");
    printf("1. Color\n");
    printf("2. Modelo\n");
    printf("3. Salir\n");
    printf("\n");
    printf("Ingrese opcion (1-3): ");
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}

int modificarAuto(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol, eCliente clientes[], int tamclientes)
{
    char patente[21];
    int indice;
    int salir = 'n';
    int todoOk = 0;

    system("cls");
    printf("          Modificar Auto\n\n");
    mostrarAutos(lista, tam, marcas, tamsec, colores,tamcol, clientes, tamclientes);
    printf("Ingrese la patente del auto a modificar: ");
    fflush(stdin);
    gets(patente);
    printf("\n");

    indice = buscarAuto(lista, tam, patente);

    if(indice == -1)
    {
        printf("La patente indicada no existe.\n\n");
    }
    else
    {
        printf("El auto a modificar es: \n");
        mostrarAuto(lista[indice], marcas, tamsec, colores, tamcol, clientes, tamclientes);

        if(confirmarSub() == 's')
        {
            do
            {
                switch(menuModificar())
                {
                case 1:
                    listarColores(colores,tamcol);
                    printf("Ingrese Id nuevo Color: ");
                    scanf("%d", &lista[indice].idColor);
                    todoOk = 1;
                    break;
                case 2:
                    printf("Ingrese nuevo modelo (anio): ");
                    scanf("%d", &lista[indice].modelo);
                    todoOk = 1;
                    break;
                case 3:
                    salir = confirmarSub();
                    break;
                default:
                    printf("Opcion invalida!\n");
                    break;
                }
                printf("\n");
                system("pause");
                system("cls");

                if(todoOk == 1)
                {
                    printf("Asi quedo modificado el auto:\n\n");
                    mostrarAuto(lista[indice], marcas, tamsec, colores, tamcol, clientes, tamclientes);

                }
            }
            while(salir == 'n');
        }
    }
    return todoOk;
}

int bajaAuto(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol, eCliente clientes[], int tamclientes)
{
    int bajaExitosa = 0;
    char patente[20];
    int indice;

    system("cls");
    printf("          Baja Auto\n\n");
    mostrarAutos(lista, tam, marcas, tamsec, colores, tamcol, clientes, tamclientes);
    printf("Ingrese la patente del auto a dar de baja: ");
    fflush(stdin);
    gets(patente);
    printf("\n");

    indice = buscarAuto(lista, tam, patente);

    if(indice == -1)
    {
        printf("La patente indicada (%s) no existe.\n\n", patente);
    }
    else
    {
        printf("El Auto a dar de baja es:\n");
        mostrarAuto(lista[indice],marcas, tamsec, colores, tamcol, clientes, tamclientes);

        if(confirmarSub() == 's')
        {
            lista[indice].isEmpty = 1;
            bajaExitosa = 1;

        }
        printf("\n");
    }

    return bajaExitosa;
}


void ordenarAutos(eAuto lista[], int tam, eMarca marcas[], int tammar)
{
    eAuto auxAuto;
    eMarca auxMarca;

     // ORDENO LAS MARCAS POR NOMBRE
    for(int i = 0; i < tammar -1; i++)
    {
        for(int j = i +1; j < tammar; j++)
        {
            if(strcmp(marcas[i].descripcion, marcas[j].descripcion) > 0)
            {
                auxMarca = marcas[i];
                marcas[i] = marcas[j];
                marcas[j] = auxMarca;
            }
        }
    }

    // acomodar los ID de autos ordenados segun el For anterior y segun marca y patente.
    for (int k = 0;k < tam ;k++ )
    {
        for (int m = k+1; m < tam ;m++ )
        {
            for (int l = 0; l < tammar ;l++ )
            {
               if(lista[k].idMarca == marcas[l].id || (lista[k].idMarca == marcas[l].id && strcmp(lista[k].patente,lista[m].patente) < 0))
                {
                    auxAuto = lista[k];
                    lista[k] = lista[l];
                    lista[l] = auxAuto;
                }
            }
        }
    }
}

/////////////////////////////////////////////////// ALTA SERVICIO/////////////////////////

void mostrarServicio(eServicio lavado)
{
    printf("    %d      %10s   %d\n", lavado.id, lavado.descripcion, lavado.precio);
}

void listarServicios(eServicio lavados[], int tam)
{
    printf("************Lista de Servicios************\n");
    printf("    ID      Descripcion   Precio\n");
        for (int i = 0;i < tam ;i++ )
        {
            mostrarServicio(lavados[i]);
        }

}

int altaTrabajo(eTrabajo trabajos[], int tamtraba, eServicio lavados[], int tamserv, eAuto lista[], int tam, eColor colores[], int tamcol, eMarca marcas[], int tamarcas, int* nextIdTrabajo, int* flagTrabajo, eCliente clientes[], int tamclientes)
{
    int todoOk = 0;
    eTrabajo nuevoTrabajo;
    int indice;

    char patente[21];
    int idServicio;
    int idCliente;

    eFecha fecha;
    int cant;

    system("cls");
    printf("     Alta Trabajo\n\n");
    printf("ID: %d\n", *nextIdTrabajo);

    if(trabajos != NULL && tamtraba > 0 && lavados != NULL && tamserv > 0 && lista != NULL && tam > 0 && colores != NULL && tamcol > 0 && marcas != NULL && tamarcas > 0 && nextIdTrabajo != NULL && flagTrabajo != NULL && clientes != NULL && tamclientes > 0)
    {
        indice = buscarLibreTrabajo(trabajos, tamtraba);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            mostrarAutos(lista, tam, marcas, tamarcas, colores, tamcol, clientes, tamclientes);
            printf("Ingrese patente del auto seleccionado: ");
            fflush(stdin);
            gets(patente);
            while(buscarAuto(lista, tam, patente) == -1)
            {
                printf("Error. Reingrese patente:");
                fflush(stdin);
                gets(patente);
            }

            strcpy(nuevoTrabajo.patente, patente);

            listarServicios(lavados, tamserv);

            printf("Ingrese ID Servicio (20000/20001/20002/20003): ");
            scanf("%d", &idServicio);
            while(!(idServicio >= 20000 && idServicio <= 20003))
            {
                printf("Error.Reingrese ID Servicio (20000/20001/20002/20003): ");
                scanf("%d", &idServicio);
            }

            nuevoTrabajo.idServicio = idServicio;

            printf("Ingrese fecha dd/mm/aaaa: ");
            cant = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            while(cant != 3)
            {
                printf("Error. Reingrese fecha dd/mm/aaaa: ");
                cant = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
            }

            nuevoTrabajo.fecha = fecha;

            // CLIENTES

            listarClientes(clientes, tamclientes);

            printf("Ingrese ID Cliente: ");
            scanf("%d", &idCliente);
            while(!(idCliente >= 25 && idCliente <= 50))
            {
                printf("Error.Reingrese ID Cliente : ");
                scanf("%d", &idCliente);
            }

            nuevoTrabajo.idCliente = idCliente;


            //-------- fin de ingreso de datos----------//


            nuevoTrabajo.isEmpty = 0;
            nuevoTrabajo.id = *nextIdTrabajo;
            (*nextIdTrabajo)++;

            trabajos[indice] = nuevoTrabajo;

            *flagTrabajo = 1;
            todoOk = 1;
        }
    }

    return todoOk;
}

void mostrarTrabajo(eTrabajo trabajo, eCliente clientes[], int tamclientes)
{
    char descCliente[20];

    if(cargarDescripcionCliente(trabajo.idCliente, clientes, tamclientes, descCliente)){
        printf("  %d    %s      %d   %d/%d/%d    %10s\n",
               trabajo.id,
               trabajo.patente,
               trabajo.idServicio,
               trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio,
               descCliente
               );
    }

}

void listarTrabajos(eTrabajo trabajos[], int tam, eCliente clientes[], int tamclientes)
{
    printf("************Lista de Trabajos************\n");
    printf("    ID    Patente   IdServicio   Fecha     Cliente\n");
    for (int i = 0;i < tam ;i++ )
    {
       if(!trabajos[i].isEmpty)
        {
            mostrarTrabajo(trabajos[i], clientes, tamclientes);
        }
    }
}


