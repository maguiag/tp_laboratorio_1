#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define QTY 20

//int menu(int *opcion);
int main()
{
    Employee employees[QTY];
    int opcion=0;
    char auxName[51];
    char auxlastName[51];
    float auxSalary;
    int auxSector;
    int auxId;
    float total;
    float promedio;
    int masQPromedio
    int opcionInforme=0;
    char seguir='s';

    initEmployees(employees,QTY);
 do
     {
        system("clear");
      //  menu(&opcion);
        printf("1- ALTA de un Empleado\n");
        printf("2- MODIFICACION de un Empleado\n");
        printf("3- BAJA de un Empleado\n");
        printf("4- INFORMES\n");
        printf("5- SALIR\n");
        scanf("%d",&opcion);
        switch(opcion)
         {
             case 1:
                addEmployee(employees,QTY,auxId,auxName,auxlastName,auxSalary,auxSector);
             break;
             case 2:
                employee_mostrar(employees,QTY);
                getValidInt("\nIngrese el Id del Empleado a modificar: ","\nError\n",auxId,0,99999999,1);
                modifyEmployee(employees,QTY,auxId);
             break;
             case 3:
                getValidInt("\nIngrese el Id del Empleado a borrar: ","\nError\n",auxId,0,99999999,1);
                removeEmployee(employees,QTY,auxId);
             break;
             case 4:
                 system(clear);
                 printf("1- Orden 2- Salarios");
                 scanf("%d",&opcionInforme);
                 switch(opcionInforme)
                 {
                    case 1:
                        sortEmployees(employees,QTY,0);
                        printEmployees(employees,QTY);
                    break;
                    case  2:
                        promedioSalarios(employees,QTY);
                    break;
                    default:
                    break;
                 }
            case 5:
                seguir='n';
            break;
         }
     }while(seguir=='s');
    return 0;
}


