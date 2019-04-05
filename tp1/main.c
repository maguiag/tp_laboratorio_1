#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
int main()
{
    char seguir='s';
    int opcion=0;
    int primerNum=0;
    int segundoNum=0;

    while(seguir=='s')
    {
        printf("\n\n Menu de opciones\n");
        printf("\n  1- Ingresar el 1er numero \n", primerNum);
        printf("\n  2- Ingresar el 2do numero \n", segundoNum);
        printf("\n  3- Calcular las siguientes operacione: \n");
        printf("\n      a- Calcular la suma \n");
        printf("\n      b- Calcular la resta \n");
        printf("\n      c- Calcular la division \n");
        printf("\n      d- Calcular la multiplicacion \n");
        printf("\n      e- Calcular el factorial \n");
        printf("\n  4- Salir\n\n");
        scanf("%d",&opcion);

        while(opcion<1 || opcion>5)
        {
            printf("\nError, ingrese una opcion valida\n");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
            case 1:
                printf("\nIngrese el primer numero: \n\n");
                scanf("%d", &primerNum);
                    break;
            case 2:
                printf("\nIngrese el segundo numero: \n\n");
                scanf("%d", &segundoNum);
                    break;
            case 3:
                printf("\na- El resultado de la suma entre %d y %d da: %d\n",primerNum,segundoNum,suma(primerNum,segundoNum));
                printf("\nb- El resultado de la resta entre %d y %d da: %d\n",primerNum,segundoNum,resta(primerNum,segundoNum));
                printf("\nc- El resultado de la division entre %d y %d da: %.2f\n",primerNum,segundoNum,division(primerNum,segundoNum));
                printf("\nd- El resultado de la multiplicacion entre %d y %d da: %d\n",primerNum,segundoNum,multiplicacion(primerNum,segundoNum));
                printf("\ne- El factorial de %d da: %d y el factorial de %d da: %d\n",primerNum,factorial(primerNum),segundoNum,factorial(segundoNum));
                    break;
            case 4:
               seguir = 'n';
                    break;
        }
    }
    return 0;
}

