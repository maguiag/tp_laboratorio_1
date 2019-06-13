#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[1024];
    char bufferNombre [1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int flagOnce=1;
    int retorno=0;
    Employee* auxEmployee;

   while(!feof(pFile))
    {
        if(flagOnce)//si flag==1- cabecera de archivo
        {
            fscanf(pFile,"%s\n",bufferId);
            flagOnce=0;
            //leo y descarto
        }
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo)==4)
        {
           auxEmployee=employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        }
        if(auxEmployee!=NULL)
        {
            ll_add(pArrayListEmployee,auxEmployee);
            retorno=1;
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
 Employee* pEmpleado;
    do
    {
        pEmpleado=Employee_new();
        fread(pEmpleado,sizeof(Employee),1,pFile);
        ll_add(pArrayListEmployee,pEmpleado);
    }while(!feof(pFile));

    return 1;
}
