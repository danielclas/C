#include <stdio.h>
#include <stdlib.h>
/*
En una tienda de artículos para caballeros al final del día se carga en la computadora las boletas que confeccionaron los
 distintos vendedores para saber cuánto fue la comisión del día de cada uno de ellos.
 Los datos que se ingresan (por boleta) son: el número de vendedor y el importe. Cuando no hay más boletas para cargar se ingresa 0.
Teniendo en cuenta que el negocio tiene 3 vendedores y que el porcentaje sobre las ventas es del 5%, indicar cuánto ganó cada vendedor en el día
*/

int main()
{
    int respuesta;
    int importe;
    int vendedor;
    int acumulador1=0;
    int acumulador2=0;
    int acumulador3=0;
    float comision1;
    float comision2;
    float comision3;

    do
    {
        printf("Ingrese el importe de la venta: ");
        fflush(stdin);
        scanf("%d", &importe);

        printf("Ingrese el numero del vendedor 1, 2 o 3 ");
        fflush(stdin);
        scanf("%d", &vendedor);

        while(vendedor!=1 && vendedor!=2 && vendedor!=3)
        {
            printf("Ingrese el numero del vendedor 1, 2 o 3 ");
            fflush(stdin);
            scanf("%d", &vendedor);
        }

        switch(vendedor)
        {
            case 1:
                acumulador1+=importe;
                break;
            case 2:
                acumulador2+=importe;
                break;
            case 3:
                acumulador3+=importe;
                break;
        }


        printf("Para finalizar la carga presione 0");
        scanf("%d", &respuesta);

        system("cls");

    }while(respuesta!=0);

    comision1=acumulador1*0.05;
    comision2=acumulador2*0.05;
    comision3=acumulador3*0.05;

    printf("Comision vendedor 1: %.2f", comision1);
    printf("\nComision vendedor 1: %.2f", comision2);
    printf("\nComision vendedor 1: %.2f", comision3);


    return 0;

}
