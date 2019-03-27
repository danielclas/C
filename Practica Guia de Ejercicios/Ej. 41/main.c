#include <stdio.h>
#include <stdlib.h>
//Hacer unprograma que imprima el mayor y el menor de una serie de 5 números que vamos introduciendo por teclado

int main()
{
    float nro;
    float max;
    float min;
    int cont=0;

    printf("Ingrese un numero: ");
    scanf("%f", &nro);

    max=nro;
    min=nro;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%f", &nro);

        if(nro>max)
        {
            max=nro;
        }
        else
        {
            if(nro<min)
            {
                min=nro;
            }
        }

        cont++;

    }while(cont<4);

    printf("\nMayor: %.2f", max);
    printf("\nMenor: %.2f", min);

    return 0;
}
