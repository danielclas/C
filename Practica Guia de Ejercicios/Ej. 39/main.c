#include <stdio.h>
#include <stdlib.h>

//39. Diseñar un programa que lea 4 números e imprima el mayor de los cuatro

int main()
{
    float nro;
    float mayor;

    int cont=0;

    do
    {
        printf("\nIngrese un numero: ");
        scanf("%f" , &nro);
        cont++;

        if(cont==0)
        {
            mayor=nro;
        }
        else
        {
            if(nro>mayor)
            {
                mayor=nro;
            }
        }

    }while(cont<4);

    printf("\nEl mayor es: %.2f", mayor);

    return 0;
}
