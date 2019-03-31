#include <stdio.h>
#include <stdlib.h>
#include "clas.h"

/*Diseñar el programa que le presente al usuario un menú de opciones
 con las cuatro operaciones básicas (suma, resta, multiplicación, división).
 Según la operación elegida ingresará 2 números enteros,
se realizará la misma y se mostrará por pantalla el resultado.
El usuario podrá trabajar en el programa hasta que indique. lo contrario.
Recordar que la división por cera es indeterminada
*/
int main()
{

    int opcion;
    float nro1;
    float nro2;

    do{
        printf("\n\n1- Sumar dos numeros\n");
        printf("2- Resta dos numeros\n");
        printf("3- Multiplicar dos numeros\n");
        printf("4- Dividir dos numeros\n");
        printf("\n\nIngrese una opcion: ");
        scanf("%d", &opcion);

        system("cls");

        printf("Ingrese nro. 1: ");
        scanf("%f", &nro1);

        printf("\nIngrese nro. 2: ");
        scanf("%f", &nro2);

        system("cls");

        switch(opcion){

            case 1:
                printf("\nRestultado de la suma: %.2f", nro1+nro2);
                break;
            case 2:
                printf("\nResultado de la resta: %.2f", nro1-nro2);
                break;
            case 3:
                printf("\nResultado de la multiplicacion: %.2f", nro1*nro2);
                break;
            case 4:
                if(nro2==0)
                {
                    printf("\nNo es posible dividir por 0");
                }
                else{
                   printf("\nResultado de la division: %.2f", nro1/nro2);
                }
                break;
            case 5:
                printf("Programa finalizado");
                break;

        }
    }while(opcion!=5);



    return 0;
}
