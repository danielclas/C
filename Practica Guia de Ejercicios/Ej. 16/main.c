#include <stdio.h>
#include <stdlib.h>
//Hacer el programa que nos permita introducir un número por teclado y nos informe si es positivo o negativo

int main()
{
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero<0)
    {
        printf("Numero negativo");
    }
    else
    {
        if(numero>0)
        {
            printf("Numero positivo");
        }
        else
        {
            printf("Numero ingresado: 0");
        }
    }

    return 0;
}
