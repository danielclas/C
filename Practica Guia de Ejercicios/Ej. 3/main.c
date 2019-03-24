#include <stdio.h>
#include <stdlib.h>
/*
Escribir un programa que realice las siguientes acciones
 Limpie la pantalla
 Asigne a 2 variables numero1 y numero2 valores distintos de cero
 Efectúe el producto de dichas variables
 Muestre el resultado pos pantalla
 Obtenga el cuadrado de numero1 y lo muestre par pantalla

*/
int main()
{

    int nro1;
    int nro2;
    int producto;
    int cuadrado;

    printf("Ingrese nro 1: ");
    scanf("%d", &nro1);

    printf("Ingrese nro 2: ");
    scanf("%d", &nro2);

    system("cls");

    producto=nro1*nro2;
    cuadrado=nro1*nro1;

    printf("\nEl producto de los numeros ingresados es: %d\n", producto);
    printf("El cuadrado del primer numero es: %d\n", cuadrado);

    return 0;

}
