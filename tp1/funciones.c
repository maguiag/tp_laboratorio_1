#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

/** \brief Suma de 2 numeros
 * \param int, int
 * \return Devuelve resultado
 */
int suma (int num1,int num2)
{
    int resultado;
    resultado = num1 + num2;
    return resultado;
}

/** \brief Resta entre 2 numeros
 * \param int, int
 * \return Devuelve resultado
 */
int resta (int num1,int num2)
{
    int resultado;
    resultado = num1 - num2;
    return resultado;
}

/** \brief Divisione entre 2 numeros
 * \param int, int (!=0)
 * \return Devuelve resultado
 */
float division (int num1,int num2)
{
    float resultado;
    if(num2==0)
    {
        printf("Error, no se puede dividir por 0\n");
    }
    else{
        resultado = num1/num2;
        return resultado;
    }
}

/** \brief Multiplicacion de 2 numeros
 * \param int, int
 * \return Devuelve resultado
 */
int multiplicacion (int num1,int num2)
{
    int resultado;
    resultado = num1*num2;
    return resultado;
}

/** \brief Factorial de un numero
 * \param int
 * \return Devuelve resultado
 */
int factorial (int num1)
{
    int i;
    int resultado=1;
    if (num1>0 && num1<12)
    {
        for (i=1;i<=num1;i++)
        {
            resultado*=i;
        }
        return resultado;
    }
    else{
        return -1;
    }
}
