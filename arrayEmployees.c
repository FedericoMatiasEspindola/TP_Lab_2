#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"


int menu()
{
    int opcion;

    system("cls");
    printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t%c   ABM EMPLEADOS  %c\n",186,186);
    printf("\t%c ESPINDOLA MATIAS %c\n",186,186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf(" 1%cALTA\n",250);
    printf(" 2%cMODIFICACION\n",250);
    printf(" 3%cBAJA\n",250);
    printf(" 4%cINFORMAR\n",250);
    printf(" 5%cSALIR\n\n",250);
    printf("%cINGRESE OPCION: ", 254);
    scanf("%d", &opcion);

    return opcion;
}


void inicializarEmpleados(eEmpleado lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}


void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam)
{
    char descSector[20];

    obtenerSector(sectores, tam, unEmpleado.idSector, descSector);

    printf("%4d  %10s  %10s    %6.2f   %10s\n", unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sueldo, descSector);
}


void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{

    system("cls");
    ordenarEmpleadosXApellido(lista, tam);
    printf(" ID    NOMBRE      APELLIDO      SUELDO      SECTOR\n\n");

    for(int i=0; i < tam; i++)
    {
        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i], sectores, tamSector);
        }
    }
    printf("\n\n");
    printf("-------------------------------------------------------");
    salarios(lista,tam);
    printf("\n\n");
    system("pause");
}


int buscarLibre(eEmpleado lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarEmpleado(eEmpleado lista[], int tam, int idNew)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].id == idNew && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int idSector;

    eEmpleado nuevoEmpleado;

    indice = buscarLibre(lista, tam);

    system("cls");
    printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t%c  ALTA EMPLEADOS  %c\n",186,186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    if( indice == -1)
    {
        printf("NO HAY LUGAR EN EL SISTEMA\n\n");
        system("pause");
    }
    else
    {

            printf("%cINGRESE NOMBRE: ",254);
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("%cINGRESE APELLIDO: ",254);
            fflush(stdin);
            gets(nuevoEmpleado.apellido);

            printf("%cINGRESE SUELDO: ",254);
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            listarSectores(sectores, tamSector);

            printf("\n%cINGRESE SECTOR: ",254);
            scanf("%d", &idSector);

            nuevoEmpleado.idSector = idSector;

            nuevoEmpleado.id = 0+indice;

            nuevoEmpleado.isEmpty = 0;

            lista[indice] = nuevoEmpleado;

        }
}


void bajaEmpleado(eEmpleado lista[], int tam)
{
    int id;
    int indice;
    char seguir;

    system("cls");
    printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t%c  BAJA EMPLEADOS  %c\n",186,186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    printf("%cINGRESE ID: ",254);
    scanf("%d", &id);

    indice = buscarEmpleado(lista, tam, id);

    if( indice == -1)
    {
        printf("NO HAY NINGUN EMPLEADO DE ID %d\n\n", id);
        system("pause");
    }
    else
    {
        printf("\nCONFIRMA BORRADO? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("BORRADO CANCELADA\n\n");
        }
        else

        {
            lista[indice].isEmpty = 1;
            printf("BORRADO EXITOSO\n\n");
        }
        system("pause");
    }

}


void modificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{
    int id;
    int indice;
    char seguir;
    eEmpleado nuevoDatoEmpleado;

    system("cls");
    printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t%cMODIFICAR EMPLEADOS%c\n",186,186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    printf("%cIngrese ID: ",254);
    scanf("%d", &id);

    indice = buscarEmpleado(lista, tam, id);

    if( indice == -1)
    {
        printf("NO HAY NINGUN EMPLEADO DE ID %d\n\n", id);
        system("pause");
    }
    else
    {
        do{
            printf("\nCONFIRMA MODIFICACION? [s|n]: ");
            fflush(stdin);
            scanf("%c", &seguir);
            seguir = tolower(seguir);
        }while(seguir != 's' && seguir != 'n');

        if(seguir == 's')
        {
            do{
                switch(menuModifica())
                {
                    case 1:
                        printf("%cINGRESE NUEVA ID: ",254);
                        scanf("%d" , &nuevoDatoEmpleado.id);
                        lista[indice].id = nuevoDatoEmpleado.id;
                        break;
                    case 2:
                        printf("%cINGRESE NUEVO NOMBRE: ",254);
                        fflush(stdin);
                        gets(nuevoDatoEmpleado.nombre);
                        strcpy(lista[indice].nombre , nuevoDatoEmpleado.nombre);
                        break;
                    case 3:
                        printf("%cINGRESE NUEVO APELLIDO: ",254);
                        fflush(stdin);
                        gets(nuevoDatoEmpleado.apellido);
                        strcpy(lista[indice].apellido , nuevoDatoEmpleado.apellido);
                        break;
                    case 4:
                        printf("%cINGRESE NUEVO SUELDO: ",254);
                        scanf("%f" , &nuevoDatoEmpleado.sueldo);
                        lista[indice].sueldo = nuevoDatoEmpleado.sueldo;
                        break;
                    case 5:
                        listarSectores(sectores, tamSector);
                        printf("%cINGRESE NUEVO SECTOR: ",254);
                        scanf("%d" , &nuevoDatoEmpleado.idSector);
                        lista[indice].idSector = nuevoDatoEmpleado.idSector;
                        break;
                    case 6:
                        seguir='n';
                        break;
                    default:
                        printf("%cERROR, REINGRESE OPCION\n\n",158);
                        system("pause");
                        break;
                }

            }while(seguir != 'n');

            printf("\nMODIFICACION EXITOSA\n\n");
            system("pause");
        }
        else
        {
            printf("\nMODIFICACION CANCELADA\n\n");
            system("pause");
        }

    }

}


void ordenarEmpleadosXApellido(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;

    for(int i=0; i<tam-1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {
            if((strcmp(lista[i].apellido,lista[j].apellido) > 0))
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }

}


void listarSectores(eSector sectores[], int tam)
{
    printf("\n%cSECTORES: \n\n", 254);
    for(int i=0; i< tam; i++)
        {
        printf("%d   %10s\n", sectores[i].id, sectores[i].descripcion);
        }
    printf("\n\n");
}


void obtenerSector(eSector sectores[], int tam, int idSector, char cadena[])
{

    for(int i=0; i < tam; i++)
        {
            if( sectores[i].id == idSector)
            {
                strcpy(cadena, sectores[i].descripcion);
            }
        }

}


int menuModifica()
{
    int opcion;

    system("cls");
    printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t%cMODIFICAR EMPLEADOS%c\n",186,186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf(" 1%cID\n",250);
    printf(" 2%cNOMBRE\n",250);
    printf(" 3%cAPELLIDO\n",250);
    printf(" 4%cSUELDO\n",250);
    printf(" 5%cSECTOR\n",250);
    printf(" 6%cSALIR\n",250);
    printf("\n%cINGRESE OPCION: ",254);
    scanf("%d", &opcion);

    return opcion;
}


int salarios(eEmpleado lista[], int tam)
{
    float suma=0;
    float promedio;
    int i;
    int flag=0;
    int contadorEmpleados=0;
    int contadorSuperanElpromedio=0;

    if(lista!=NULL)
    {
        for( i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                suma = suma + lista[i].sueldo;
                contadorEmpleados ++;
                promedio= suma / contadorEmpleados;
            }
        }


        for( i=0; i<tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].sueldo> promedio)
                {
                    contadorSuperanElpromedio ++;
                }
            }

        }
        printf("\nLa suma de los salarios es: %.2f\n", suma);
        printf("\nEl promedio de los salarios es: %.2f\n", promedio);
        printf("\nLos que superan el salario promedio son: %d\n", contadorSuperanElpromedio);
        flag=1;
    }

    return flag;
}
