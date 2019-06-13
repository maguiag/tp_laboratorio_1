#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief  Busca empeado segun id
 *
 * \param pArrayListEmployee *
 * \param id a buscar
 * \return int: indice
 *
 */

static int findEmployeeById(LinkedList *pArrayListEmployee, int id);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
   if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
            retorno=0;
        }
        else
        {
            printf("\nError\n");
        }
    }
return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb"); // read in binary
        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            retorno=0;

        }
        else
        {
            printf("\nError\n");
        }
    }
return retorno;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
   int retorno=0;
   char auxNombre[1024];
   int  auxHorasTrabajadas;
   int auxSueldo;
   Employee* pEmployee;

   pEmployee=employee_new();
   if(pArrayListEmployee!=NULL &&
      !utn_getLetras(auxNombre,50,2,"\nIngrese nombre:  ", "\nError, no valido\n") &&
      !utn_getEntero(&auxHorasTrabajadas,2,"\nIngrese horas:  ","\nError, no valido\n",0,1000) &&
      !utn_getEntero(&auxSueldo,2,"\nIngrese sueldo: ","\nError, no valido\n",0,10000))
      {
          if(!employee_setNombre(pEmployee,auxNombre) &&
             !employee_setHorasTrabajadas(pEmployee,auxHorasTrabajadas) &&
             !employee_setSueldo(pEmployee,auxSueldo) &&
             !employee_setId(pEmployee,-1))
          {
              ll_add(pArrayListEmployee,pEmployee);
              retorno=-1;
          }
      }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char auxNombre[51];
    int auxHorasTrabajas;
    int auxSueldo;
    int indice;
    int id;

    utn_getEntero(&id,2,"\Ingrese Id:  ","\nError, no valido\n",0,1000);
    indice=findEmployeeById(pArrayListEmployee,id);
    Employee* pEmployee=ll_get(pArrayListEmployee,indice);

    if(pEmployee!=NULL &&
            !utn_getLetras(auxNombre,50,2,"\nIngrese nombre:  ", "\nError, no valido\n") &&
            !utn_getEntero(&auxHorasTrabajas,2,"\nIngrese horas:  ","\nError, no valido\n",0,1000) &&
            !utn_getEntero(&auxSueldo,2,"\nIngrese sueldo: ","\nError, no valido\n",0,10000))
    {
        employee_setNombre(pEmployee,auxNombre);
        employee_setHorasTrabajadas(pEmployee,&auxHorasTrabajas);
        employee_setSueldo(pEmployee,&auxSueldo);
        retorno=0;
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int limite;
    int i;
    int auxId;
    int bufferId;

    Employee* pEmployee;
    if(pArrayListEmployee!=NULL &&
       !utn_getEntero(&auxId,2,"\nIgrese Id:  ", "\nError\n",0,9999))
    {
        limite=ll_len(pArrayListEmployee);
        for(i=0;i<limite;i++)
        {
            pEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee,&bufferId);
            if(bufferId==auxId)
            {
                ll_remove(pArrayListEmployee,i);
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int auxId;
    int auxSueldo;
    int auxHorasTrabajadas;
    char auxNombre[1024];

    Employee* pEmployee;
    int  limite=ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        retorno=0;

        for(i=0;i<limite;i++)
        {
            pEmployee=(Employee*)ll_get(pArrayListEmployee,i);

            employee_getId(pEmployee,&auxId);
            employee_getNombre(pEmployee,auxNombre);
            employee_getHorasTrabajadas(pEmployee,&auxHorasTrabajadas);
            employee_getSueldo(pEmployee,&auxSueldo);

            printf("id: %d -Nombre: %s  -Horas: %d  -Sueldo: %d\n ",auxId,
                                                                auxNombre,
                                                                auxHorasTrabajadas,
                                                                auxSueldo);
        }

    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,Employee_criterioName,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile=fopen(path,"w");
    Employee* pEmpleado;
    int i;
    char auxNombre[51];
    int auxHoras;
    int auxId;
    int auxSueldo;
    int limite=ll_len(pArrayListEmployee);

    if(pFile!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&auxId);
            employee_getNombre(pEmpleado,auxNombre);
            employee_getHorasTrabajadas(pEmpleado,&auxHoras);
            employee_getSueldo(pEmpleado,&auxSueldo);

            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
        }
    }
    fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile=fopen(path,"wb");
    Employee* pEmployee;
    int i;
    int limite=ll_len(pArrayListEmployee);

    if(pFile!=NULL)
    {

        for(i=0;i<limite;i++)
        {
            pEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pEmployee,sizeof(Employee),1,pFile);
        }
    }
    fclose(pFile);
    return 1;
}

 findEmployeeById(LinkedList *pArrayListEmployee, int id)
{
    int i;
    int index = -1;
    int auxId;
    Employee *pEmployee;

    int len = ll_len(pArrayListEmployee);
    if (len > 0 && pArrayListEmployee != NULL)
    {
        for (i = 0; i < len; i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee,&auxId);
            if (auxId == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}
