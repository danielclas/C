#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
/*Dise�ar en un programa que permita registrar de los empleados de una f�brica
(no se sabe cu�ntos) su peso y saber cu�ntos pesan hasta 80 kg. inclusive y cuantos pesan m�s de 80 kg.
*/

int main()
{
    int peso;
    int contadorMas80=0;
    int contadorMenos80=0;
    char respuesta;

    do
    {
        printf("Ingrese el peso: ");
        fflush(stdin);
        scanf("%d", &peso);

        if(peso<=80)
        {
            contadorMenos80++;
        }
        else
        {
            contadorMas80++;
        }

        printf("Para ingresar otro presione s");
        fflush(stdin);
        respuesta=getch();//Comando para que cuando ingreso respuesta, pase a proxima linea sin mostrar lo que ingreso
        respuesta=tolower(respuesta);//Comando para que me tome la S mayuscula como respuesta valida

        system("cls");

    }while(respuesta=='s');


   printf("Pesos menores o iguales a 80: %d\n", contadorMenos80);
   printf("Pesos mayores a 80: %d", contadorMas80);
    return 0;
}
