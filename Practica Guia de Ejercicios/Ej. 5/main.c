#include <stdio.h>
#include <stdlib.h>

/*
Escribir el programa necesario para calcular y mostrar el cuadrado de un número.
El número debe ser mayor que cero, en caso de error que aparezca el mensaje "ERROR, el número debe ser mayor que cero"
*/
int main()
{
    int nro1;
    int nro2;
    long cuadrado;

    printf("Ingrese el primer numero: ");
    scanf("%d", &nro1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &nro2);

    cuadrado=nro1*nro2;

    if(cuadrado<0)
    {
        printf("Error, el numero debe ser mayor a cero");
    }
    else
    {
        printf("El resultado es: %li", cuadrado);
    }

    return 0;


}
