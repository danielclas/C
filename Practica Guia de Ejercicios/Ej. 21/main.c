#include <stdio.h>
#include <stdlib.h>
//Hacer el programa que nos permita contar los m�ltiplos de 3 desde la unidad hasta un n�mero que introducimos por teclado

int main()
{
     int numero;
     int contador=0;

     printf("Ingrese un numero: ");
     scanf("%d", &numero);

    for(;numero>0;numero--)
    {
        if(numero%3==0)
        {
            contador++;
        }

    }

    printf("\nCant. de multiplos: %d", contador);

    return 0;
}
