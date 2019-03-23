#include <stdio.h>
#include <stdlib.h>
//Hacer el programa que imprima los números del 100 al 0 en orden decreciente

int main()
{
    int numero;

    for(numero=100;numero>-1;numero--)
    {
        printf("Numero: %d\n", numero);
    }


    return 0;
}
