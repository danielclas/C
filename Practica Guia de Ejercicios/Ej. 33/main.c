#include <stdio.h>
#include <stdlib.h>
/*En un restaurante hay 2 mozos;
 al final del d�a su due�o entrega un plus al mozo que m�s clientes haya atendido,
 ese plus es de 1/3 de lo que factur� cada mozo.
 El proceso termina cuando se ingresa un n�mero de mozo 0
 */

int main()
{
    float mozo1;
    float fact1;
    float mozo2;
    float fact2;
    float plus;

    printf("\nClientes atendidos por mozo 1: ");
    scanf("%f", &mozo1);

    printf("\nFacturado por mozo 1: ");
    scanf("%f", &fact1);

    printf("\nClientes atendidos por mozo 2: ");
    scanf("%f", &mozo2);

    printf("\nFacturado por mozo 2: ");
    scanf("%f", &fact2);

    if(mozo1>mozo2)
    {
        plus=fact1*0.33;
        printf("\nMozo 1 tiene plus. Valor: %.2f", plus);
    }
    else
    {
        if(mozo2>mozo1)
        {
            plus=fact2*0.33;
            printf("\nMozo 2 tiene plus. Valor: %.2f", plus);
        }
        else
        {
            printf("\nCantidad de clientes atendidos es igual");
        }
    }



    return 0;
}
