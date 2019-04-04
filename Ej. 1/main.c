#include <stdio.h>
#include <stdlib.h>
/*
1- Escribir un programa que por medio de una funcion calcule la superficie
de un rectangulo. El programa continua calculando superficies hasta que se ingresen
ambos lados con valor cero.
*/

int areaRectangulo (int lado1, int lado2);

int main()
{

    int lado1;
    int lado2;

    do{
        printf("Ingrese el lado 1: ");
        scanf("%d", &lado1);

        printf("Ingrese el lado 2: ");
        scanf("%d", &lado2);

        if(lado1==0 && lado2==0){
            break;
        }

        if(lado1==lado2){
            printf("Lado debe ser distinto a lado 1. Ingrese nuevamente: ");
            scanf("%d", &lado2);
        }

        printf("\n\tEl area es: %d\n\n", areaRectangulo(lado1, lado2));
        system("pause");
        system("cls");


    }while(lado1!=0 && lado2!=0);


    printf("\n\nEl programa ha finalizado");

    return 0;
}

int areaRectangulo(int lado1, int lado2){

    return lado1*lado2;

}

