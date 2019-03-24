#include <stdio.h>
#include <stdlib.h>
//Escribir en y codificar en C un programa que muestre los números primos comprendidos entre 0 y 100

int main()
{
    int numero=100;
    int numeroAnterior;
    int contador=0;

    for(numeroAnterior=numero-1;numeroAnterior<=2;numeroAnterior--)
    {
        if(numero%numeroAnterior==0)
        {
            break;
        }



    }

    printf("algo");
    return 0;
}
