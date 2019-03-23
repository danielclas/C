#include <stdio.h>
#include <stdlib.h>

/*
Escribir un programa que realice las siguientes acciones:
 Limpie la pantalla
 Declare 2 variables y les asigne sendos valores
 Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor que cero o "Resultado negativo" si es menor que cero

*/
int main()
{
    int nro1;
    int nro2;
    int resta;

    printf("Ingrese numero 1: ");
    scanf("%d", &nro1);

    printf("Ingrese numero 2: ");
    scanf("%d", &nro2);

    resta=nro1-nro2;

    if(resta==0)
    {
        printf("Resultado: %d", resta);
    }
    else
    {
        if(resta<0)
        {
          printf("Resultado negativo: %d", resta);
        }
        else
        {
            printf("Resultado positivo: %d", resta);
        }

    }

    return 0;
}

//Considero al 0 positivo
