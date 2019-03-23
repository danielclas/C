#include <stdio.h>
#include <stdlib.h>
//Diseñar un programa que imprima y sume la serie de números 3,6,9,12,...,99.

int main()
{
    int numero;

    for(numero=3;numero<100;numero+=3)
    {
        printf("Numero: %d \n", numero);
    }

    return 0;
}
