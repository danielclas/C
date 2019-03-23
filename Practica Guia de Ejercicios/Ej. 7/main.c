#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

/*
Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado.
*/

int main()
{
    float radio;
    float circunferencia;
    float area;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    circunferencia=2*PI*radio;
    area=PI*(radio*radio);

    printf("\nCircunferencia: %.2f\n", circunferencia);
    printf("Area: %.2f", area);

    return 0;
}
