#include <stdio.h>
#include <stdlib.h>
//Dados 3 números donde el primero y el último son límites de un intervalo, indicar si el tercero pertenece a dicho intervalo
int main()
{
    int nro1;
    int nro2;
    int nro3;

    printf("Ingrese numero 1: ");
    scanf("%d", &nro1);

    printf("Ingrese numero 2: ");
    fflush(stdin);
    scanf("%d", &nro2);

    printf("Ingrese numero 3: ");
    fflush(stdin);
    scanf("%d", &nro3);

    if(nro2>=nro1 && nro2<=nro3)
    {
        printf("Pertenece al intervalo");
    }
    else
    {
        if(nro2<=nro1 && nro2>=nro3)
        {
          printf("Pertenece al intervalo");
        }
        else
        {
            printf("No pertenece al intervalo");
        }

    }


    return 0;
}
