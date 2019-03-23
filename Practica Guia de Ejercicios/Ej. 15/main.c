#include <stdio.h>
#include <stdlib.h>
//Escribir en y codificar en C un programa que muestre los múltiplos de 6 comprendidos entre 0 y 100

int main()
{
    int numero;

    for(numero=1;numero<101;numero++)
    {
        if(numero%6==0)
        {
            printf("\n%d es multiplo de 6", numero);
        }
    }

    return 0;
}
