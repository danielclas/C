#include <stdio.h>
#include <stdlib.h>
/*
Hacer un programa que simule el funcionamiento de un reloj digital y que permita ponerlo en hora
*/

int main()
{
    int hora;
    int minutos;
    int segundos;
    char respuesta;

    do
    {
        printf("\nIngrese la hora: ");
        scanf("%d", &hora);

        while(hora<0 || hora>24)
        {
            printf("\nIngrese una hora valida: ");
            scanf("%d", &hora);
        }

        printf("\nIngrese los minutos: ");
        scanf("%d", &minutos);

        while(minutos<0 || minutos>59)
        {
            printf("\nIngrese minutos valido: ");
            scanf("%d", &minutos);
        }

        printf("\nIngrese los segundos: ");
        scanf("%d", &segundos);

        while(segundos<0 || segundos>59)
        {
            printf("\nIngrese segundos validos: ");
            scanf("%d", &segundos);
        }

        printf("\nSon las %d:%d:%d\n", hora, minutos, segundos);

        printf("\nPara volver a poner en hora presione s. Para salir presiona otra tecla");
        respuesta=getche();
        respuesta=tolower(respuesta);

        system("cls");


    }while(respuesta=='s');


    return 0;
}
