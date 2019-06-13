#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidName(char* name);
Employee* employee_new()
{
     Employee* this;
    this=malloc(sizeof(Employee));
return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=employee_new();

    if(!employee_setId(this,atoi(idStr)) &&
       !employee_setNombre(this,nombreStr) &&
       !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) &&
       !employee_setSueldo(this,atoi(sueldoStr)))
    {
        return this;

    }
   employee_delete(this);
    return NULL;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
     int retorno=-1;
     static int proximoId=-1;

     if(this!=NULL && id==-1)
     {
         proximoId++;
         this->id=proximoId;
         retorno=0;
     }
     else if(id>proximoId)
     {
         proximoId=id;
         this->id=proximoId;
         retorno=0;
     }
     return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && !isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {

        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
return retorno;
}

int Employee_criterioName(void* thisA, void* thisB)
{
    int retorno=-1;
    char nameA[200];
    char nameB[200];

    employee_getNombre((Employee*)thisA,nameA);
    employee_getNombre((Employee*)thisB,nameB);

    if(strcmp(nameA,nameB)>0)
    {
        retorno=1;
    }
    if(strcmp(nameA,nameB)<0)
       {
           retorno=-1;
       }
       return retorno;
}

static int isValidName(char* name)
{
    int retorno=-1;
    if(name!=NULL)
    {
        retorno=0;
    }
    return retorno;
}





