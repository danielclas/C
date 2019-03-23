
#include <stdio.h>
#include <stdlib.h>

//10. Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima cuantos impares hay

int main()
{
    int numero;
    int contadorImpares=0;

    for(numero=0;numero<101;numero++)
    {
        if(numero%2!=0)
        {
            contadorImpares++;
            printf("Numero impar: %d\n", numero);
        }
    }

    printf("Cantidad de impares: %d", contadorImpares);

    return 0;
}
