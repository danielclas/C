#include <stdio.h>
#include <stdlib.h>
//Calcular y generar los primeros 100 números múltiplos de 5, de 7 y de ambos
int main()
{
    int contadorMult7=0;
    int contadorMult5=0;
    int contadorMultAmbos=0;
    int numero=7;

    printf("Primeros 100 multiplos de 7: \n");

    for(numero=7;contadorMult7<100;numero++)
    {
        if(numero%7==0)
        {
            contadorMult7++;
            printf("%d\n", numero);
        }

    }

    printf("Primeros 100 multiplos de 5: \n");

    for(numero=5;contadorMult5<100;numero++)
    {
        if(numero%5==0)
        {
            contadorMult5++;
            printf("%d\n", numero);
        }
    }

    printf("Primeros 100 multiplos de 7 y de 5: \n");

    for(numero=8;contadorMultAmbos<100;numero++)
    {
        if(numero%5==0 && numero%7==0)
        {
            contadorMultAmbos++;
            printf("%d\n", numero);
        }
    }

    return 0;
}
