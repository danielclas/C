#include <stdio.h>
#include <stdlib.h>
//Ingresar un n�mero entero por consola y efectuar la suma de todos los n�meros que le anteceden, comenzando desde 0 y mostrar el resultado por pantalla


int main()
{
    int numero;
    int suma=0;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    for(;numero>0;numero--)
    {

        suma+=numero;

    }


    printf("La suma es: %d", suma);
    return 0;
}
