#include <stdio.h>
#include <stdlib.h>
//Realizar la tabla de multiplicar de un número entre 0 y 10 de forma que se visualice de la siguiente forma: 4x1= 4 4x2= 8

int main()
{
    float nro;
    int mult;
    float producto;

    printf("Ingrese el numero a multiplicar: ");
    scanf("%f", &nro);

    for(mult=0;mult<11;mult++)
    {
        producto=nro*mult;
        printf("\n%.2f x %d = %.2f", nro, mult, producto);
    }


    return 0;
}
