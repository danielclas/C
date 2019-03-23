#include <stdio.h>
#include <stdlib.h>
//Hacer el programa que imprima los números pares entre el 1 y el 100

int main()
{
    int numero;

    for(numero=0;numero<101;numero++)
    {
        if(numero%2==0)
        {
            printf("Numero par: %d \n", numero);
        }
    }

    return 0;

}
