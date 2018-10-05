#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000
#include "arrayEmployees.h"


int main()
{

    char seguir = 's';

    eSector sectores[]=
    {
        {1, "RRHH"},
        {2, "VENTAS"},
        {3, "COMPRAS"},
        {4, "CONTABLE"},
        {5, "SISTEMAS"}
    };

    eEmpleado empleados[TAM];
    inicializarEmpleados(empleados,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(empleados, TAM, sectores, 5);
            break;
        case 2:
            modificarEmpleado(empleados, TAM, sectores, 5);
            break;
        case 3:
            bajaEmpleado(empleados,TAM);
            break;
        case 4:
            mostrarEmpleados(empleados, TAM, sectores, 5);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
           printf("%cError, Reingrese la opcion\n\n",158);
           system("pause");
           break;
        }
    }
    while(seguir == 's');

    return 0;
}
