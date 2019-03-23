#include <stdio.h>
#include <stdlib.h>
//Hacer el programa que nos permita introducir un número por teclado y nos informe si es par o impar
int main()
{
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero%2==0)
    {
        printf("Numero par");
    }
    else
    {

        printf("Numero impar");

    }

    return 0;
}
