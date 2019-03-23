#include <stdio.h>
#include <stdlib.h>
//Hacer el programa que imprima todos los números naturales que hay desde la unidad hasta un número que introducimos por teclado

int main()
{
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    for(;numero>0;numero--)
    {
        printf("Numero: %d\n", numero);
    }


    return 0;
}
