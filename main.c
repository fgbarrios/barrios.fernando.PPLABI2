#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"
#include "datawarehouse.h"
#include "informes.h"


#define TAMMAR 5
#define TAMCOL 5
#define TAMSERV 4
#define TAMAUTO 5
#define TAMTRABA 5
#define TAMCLIENTES 5

int main()
{
    int nextIdAuto = 100;
    int nextIdTrabajo = 200000;
    int flag = 1;
    int flagTrabajo = 0;

    eMarca marcas[TAMMAR] = {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
        };
    eColor colores[TAMCOL] = {
        {1, "Negro"},
        {2, "Blanco"},
        {3, "Gris"},
        {4, "Rojo"},
        {5, "Azul"}
        };
    eServicio lavados[TAMSERV] = {
        {20000,"Lavado", 250},
        {20001,"Pulido", 300},
        {20002,"Encerado", 400},
        {20003,"Completo", 600}
    };

    eCliente clientes[TAMCLIENTES] = {
    {25,"Fernando",'m'},
    {30,"Alexis",'m'},
    {32,"Julian",'m'},
    {33,"Fernanda",'f'},
    {50,"Valentina",'f'},
    };

    eAuto autos[TAMAUTO];
    eTrabajo trabajos[TAMTRABA];

    inicializarAutos(autos, TAMAUTO);
    inicializarTrabajos(trabajos,TAMTRABA);

    ////////////////////////////// HARDCODEO DE PRUEBA
    hardcodearAutos(autos, 5, 5);
    ////////////////////////////////////////

    char salir = 'z';

    while(salir == 'z')
    {
        switch(menu())
        {
        case 'a': // ALTA AUTO
            if(altaAuto(autos,TAMAUTO,colores, TAMCOL, marcas, TAMMAR, &nextIdAuto, &flag, clientes, TAMCLIENTES))
            {
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            break;

        case 'b': // MODIFICAR AUTO
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                modificarAuto(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL, clientes, TAMCLIENTES);
            }
            break;

        case 'c': // BAJA AUTO
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                bajaAuto(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL, clientes, TAMCLIENTES);
            }
            break;

        case 'd': // LISTAR AUTOS
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                system("cls");
                ordenarAutos(autos, TAMAUTO, marcas, TAMMAR);
                mostrarAutos(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL, clientes, TAMCLIENTES);
            }
            break;

        case 'e': // LISTAR MARCAS
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                system("cls");
                listarMarcas(marcas, TAMMAR);
            }
            break;

        case 'f': // LISTAR COLORES
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                system("cls");
                listarColores(colores, TAMCOL);
            }
            break;

        case 'g': // LISTAR SERVICIOS
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                system("cls");
                listarServicios(lavados, TAMSERV);
            }
            break;

       case 'h': // ALTA TRABAJO
            if(flag == 0){
                printf("Primero debe realizar un alta de un auto.\n\n");
            }
            else
            {
                altaTrabajo(trabajos, TAMTRABA, lavados, TAMSERV, autos, TAMAUTO, colores, TAMCOL, marcas, TAMMAR, &nextIdTrabajo, &flagTrabajo, clientes, TAMCLIENTES);
            }
            break;

       case 'i': // LISTAR TRABAJOS

            if(flagTrabajo == 0 && flag == 0)
            {
                printf("Primero debe dar de alta un Trabajo\n");
            }else{
                system("cls");
                listarTrabajos(trabajos, TAMTRABA, clientes, TAMCLIENTES);
            }
            break;

        case 'j': // INFORMES
            if(flag == 0)
            {
                printf("Primero debe dar de alta un Auto\n");
            }else{

                switch (subMenuInformes())
                {
                    case 1:
                        system("cls");
                        autosPorColor(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL, clientes, TAMCLIENTES);
                    break;
                    case 2:
                        system("cls");
                        autoPorMarca(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL, clientes, TAMCLIENTES);
                    break;
                    case 3:
                        system("cls");
                        autosMasViejos(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL, clientes, TAMCLIENTES);
                    break;
                    case 4:
                        system("cls");
                        autosTodosPorMarca(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL, clientes, TAMCLIENTES);

                    break;
                    case 5:
                        system("cls");
                        contadorAutos(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL);

                    break;
                    case 6:
                        system("cls");
                        marcasMasElegidas(autos, TAMAUTO, marcas, TAMMAR);
                    break;

                    default:
                        printf("Ingrese una opcion correcta.\n");
                    break;
                }
            }
            break;

        case 'k':
            salir = confirmar();
            break;

        default:
            printf("Opcion invalida!\n");
            break;
        }
        system("pause");
    }

    return 0;
}
