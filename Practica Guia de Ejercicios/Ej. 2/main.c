#include <stdio.h>
#include <stdlib.h>
//Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado

int main()
{
    int nro1;
    int nro2;
    int suma;

    printf("Ingrese nro 1: ");
    scanf("%d", &nro1);

    printf("Ingrese nro 2: ");
    scanf("%d", &nro2);

    suma=nro1+nro2;

    printf("La suma es: %d", suma);

    return 0;
}
