#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "funciones.h"
#include "validaciones.h"

int subMenuInformes(){
    int opcion;

    system ("cls");
    printf("**********INFORMES**********\n\n");
    printf("1 - Mostrar autos del color seleccionado por el usuario.\n");
    printf("2 - Mostrar autos de una marca seleccionada.\n");
    printf("3 - Informar el o los autos mas viejos (de 1950 a 2000)\n");
    printf("4 - Mostrar un listado de los autos separados por marca\n");
    printf("5 - Elegir un color y una marca, y contar cuantos autos hay de ese color y de esa marca.\n");
    printf("6 - Mostrar la o las marcas mas elegidas por los clientes\n\n");
    printf("Ingrese opcion (1-6): ");
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 6)
    {
        printf("ERROR. Ingrese opcion (1-6): ");
        scanf("%d", &opcion);
    }

    return opcion;
}


//////////////////////////////////////////////////////////////////////1 - Mostrar autos del color seleccionado por el usuario
int buscarColor(eColor colores[], int tam, int color)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(colores[i].id == color)
        {
            indice = 1;
            break;
        }
    }
    return indice;
}

void autosPorColor(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol, eCliente clientes[], int tamclientes)
{
    int color;
    int flag = 0;

    printf("**********Mostrar autos seleccionados por el usuario**********\n");
    listarColores(colores, tamcol);
    printf("Ingrese ID del Color: ");
    scanf("%d", &color);
    while(buscarColor(colores, tamcol, color) != 1)
    {
        printf("Error. Re-ingrese Color: ");
        scanf("%d", &color);
    }

    printf("         Listado de Autos por color\n");
    printf("ID   Patente    Marca         Color  Modelo  Cliente\n");

    for(int i = 0; i < tam; i++)
    {
        if(autos[i].idColor == color)
        {
            mostrarAuto(autos[i], marcas, tammar, colores, tamcol, clientes, tamclientes);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay Autos que mostrar de ese color.\n");
    }
    printf("\n");
}
/////////////////////////////////////////////////////////////////////////2 - Mostrar autos de una marca seleccionada.
int buscarMarca(eMarca marcas[], int tam, int marca)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(marcas[i].id == marca)
        {
            indice = 1;
            break;
        }
    }
    return indice;
}

void autoPorMarca(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol, eCliente clientes[], int tamclientes)
{
    int marca;
    int flag = 0;

    printf("**********Mostrar autos por marca**********\n");
    listarMarcas(marcas, tammar);
    printf("Ingrese ID de la Marca: ");
    scanf("%d", &marca);
    while(buscarMarca(marcas, tammar, marca) != 1)
    {
        printf("Error. Re-ingrese Marca: ");
        scanf("%d", &marca);
    }

    printf("         Listado de Autos por Marca\n");
    printf("ID   Patente    Marca         Color  Modelo  Cliente\n");

    for(int i = 0; i < tam; i++)
    {
        if(autos[i].idMarca == marca)
        {
            mostrarAuto(autos[i], marcas, tammar, colores, tamcol, clientes, tamclientes);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay Autos que mostrar de esa marca.\n");
    }
    printf("\n");

}

//////////////////////////////////////////////////////////////////////////////////3 - Informar el o los autos mas viejos
void autosMasViejos(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol, eCliente clientes[], int tamclientes){

    int flag = 0;
    printf("**********Autos mas viejos (de 1950 a 2000)**********\n");
    for(int i = 0; i < tam; i++)
    {
        if(autos[i].modelo >= 1950 && autos[i].modelo <= 2000)
        {
            mostrarAuto(autos[i], marcas, tammar, colores, tamcol, clientes, tamclientes);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay Autos viejos que mostrar.\n");
    }
    printf("\n");


}

//////////////////////////////////////////////////////////////////////////////////4 - Mostrar un listado de los autos separados por marca
void autosTodosPorMarca(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol, eCliente clientes[], int tamclientes){

    if(autos != NULL && tam > 0 && marcas != NULL && tammar > 0 && colores != NULL && tamcol > 0 && clientes != NULL && tamclientes > 0){

        printf("****************Autos por marca*****************\n");
        int flag;
        int marca;
        for (int i = 0; i < tammar ;i++ )
        {
            marca = marcas[i].id;
            flag = 0;
            printf("********Autos marca: %s***********\n", marcas[i].descripcion);
            for (int j = 0;j < tam ;j++ )
            {
                if(autos[j].isEmpty == 0 && autos[j].idMarca == marca){
                    mostrarAuto(autos[j], marcas, tammar, colores, tamcol, clientes, tamclientes);
                    flag = 1;
                }
            }
            if(flag == 0){
                printf("No hay autos de esta marca.\n");
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////5 - Elegir un color y una marca, y contar cuantos autos hay de ese color y de esa marca.
void contadorAutos(eAuto autos[], int tam, eMarca marcas[], int tammar, eColor colores[], int tamcol){
    if(autos != NULL && tam > 0 && marcas != NULL && tammar > 0 && colores != NULL && tamcol > 0){

        printf("****************Cantidad de Autos por marca y color*****************\n");
        int flag;
        int marca;
        int color;
        int contador = 0;

        listarMarcas(marcas, tammar);
        printf("Elegir ID marca; \n");
        scanf("%d", &marca);

        listarColores(colores, tamcol);
        printf("Elegir ID Color; \n");
        scanf("%d", &color);

        for (int j = 0;j < tam ;j++ )
        {
            if(autos[j].isEmpty == 0 && autos[j].idMarca == marca && autos[j].idColor == color){
                contador++;
                flag = 1;
            }
        }
        if(flag == 0){
            printf("No hay autos de esta marca y color.\n");
        }else{
            printf("Hay %d autos de ese color y marca\n", contador);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////6 - Mostrar la o las marcas mas elegidas por los clientes
void marcasMasElegidas(eAuto autos[], int tam, eMarca marcas[], int tammar){
if(autos != NULL && tam > 0 && marcas != NULL && tammar > 0){

        printf("****************Mostrar la o las marcas mas elegidas por los clientes*****************\n");

        int contador;
        int totales[tammar];
        int flag = 0;
        int mayor;

        char descMarca[20];

        for (int j = 0; j < tammar; j++ ) // recorro las marcas
        {
            contador = 0;
            for(int i = 0; i < tam ; i++) // recorro los autos
            {
                 if(autos[i].idMarca == marcas[j].id && autos[i].isEmpty == 0)
                {
                    contador++;
                }
            }
            totales[j] = contador;
            //printf("Totales del sector %s: %d\n", marcas[j].descripcion, totales[j]);
        }

        for (int i = 0; i < tammar ; i++ ) // para sacar el mayor
        {
            if(flag == 0 || totales[i] > mayor)
            {
                mayor = totales[i];
                flag = 1;
            }
        }

        for (int i = 0; i < tammar ; i++ ) // en caso de que haya empate
        {
            if(mayor == totales[i])
            {
                if(cargarDescripcionMarca(marcas[i].id, marcas, tammar, descMarca)){
                    printf("La Marca con mas auto es/son: %s\n", descMarca);

                }
            }
        }
    }
}


