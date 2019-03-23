#include <stdio.h>
#include <stdlib.h>

//Ingresar 5 números y calcular su media

int main()
{
    int numero;
    int acumulador=0;
    int contador;
    float promedio;

    for(contador=0;contador<5;contador++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        acumulador+=numero;
    }

    promedio=acumulador/contador;

    printf("Promedio: %.2f", promedio);
    return 0;
}
