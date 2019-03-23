#include <stdio.h>
#include <stdlib.h>

//Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y muestre el resultado.

int main()
{
    int base;
    float altura;
    float area;

    printf("Ingrese la base: ");
    scanf("%d", &base);

    printf("Ingrese la altura: ");
    scanf("%f", &altura);

    area=base*(altura/2);

    printf("El area del triangulo es: %f", area);

    return 0;
}
