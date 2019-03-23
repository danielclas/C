#include <stdio.h>
#include <stdlib.h>
//De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero


int main()
{
    int nro;
    int contadorMayores=0;
    int contadorMenores=0;
    int contador;

    for(contador=0;contador<10;contador++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &nro);

        if(nro<0)
        {
            contadorMenores++;
        }
        else
        {
            if(nro>0)
            {
                contadorMayores++;
            }
        }
    }

    printf("\nNros positivos: %d\n", contadorMayores);
    printf("Nros negativos: %d\n", contadorMenores);

    return 0;
}
