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
int masQPromedio;
char seguir='s';

initEmployees(employees,QTY);
employee_altaForzada(employees,QTY,"Jose","Gomez",35000,1);
employee_altaForzada(employees,QTY,"Juan","Perez",40000,2);
employee_altaForzada(employees,QTY,"Ana","Mena",60000,1);
employee_altaForzada(employees,QTY,"Maria","Paz",60000,2);
 do
     {
        //system("clear");
      //  menu(&opcion);
        printf("1- ALTA de un Empleado\n");
        printf("2- MODIFICACION de un Empleado\n");
        printf("3- BAJA de un Empleado\n");
        printf("4- INFORMES: 1) Orden 2) Salario\n");
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
                sortEmployees(employees,QTY,0);
                printEmployees(employees,QTY);
                promedioSalarios(employees,QTY);
             break;
            case 5:
                seguir='n';
            break;
         }
     }while(seguir=='s');
    return 0;
}

