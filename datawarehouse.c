#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"
#include "funciones.h"

int ids[] = {50002,50003,50004,50005,50006};
char patentes[5][21] = {"ABC","BCD","FGB","ABC","AVB"};
int idMarcas[] = {1000,1002,1002,1004,1003};
int idColores[] = {1,2,4,4,5};
int modelos[] = {1965,1980,1980,1999,2020};
int idClientes[] = {25,30,32,33,50};

int hardcodearAutos(eAuto lista[], int tam, int cant)
{
    int cantidad = 0;
    if(lista != NULL && tam > 0 && cant > 0 && cant <= tam)
    {
        for (int i = 0;i < cant ;i++ )
        {
            lista[i].id = ids[i];
            strcpy(lista[i].patente, patentes[i]);
            lista[i].idColor = idColores[i];
            lista[i].idMarca = idMarcas[i];
            lista[i].modelo = modelos[i];
            lista[i].isEmpty = 0;
            lista[i].idCliente = idClientes[i];

            cantidad++;
        }
    }
    return cantidad;
}
