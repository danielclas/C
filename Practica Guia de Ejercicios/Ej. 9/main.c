#include <stdio.h>
#include <stdlib.h>
//Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se ingresaron, cuantas "e, i, o, u"


int main()
{
    char letra;
    int contador;
    int contadorA=0;
    int contadorE=0;
    int contadorI=0;
    int contadorO=0;
    int contadorU=0;

    for(contador=0;contador<20;contador++)
    {
        printf("Ingrese un caracter: ");
        fflush(stdin);
        scanf("%c", &letra);

        switch(letra)
        {
         case 'a':
             contadorA++;
             break;
         case 'e':
             contadorE++;
             break;
         case 'i':
             contadorI++;
             break;
         case 'o':
             contadorO++;
             break;
         case 'u':
             contadorU++;
             break;
        }


        system("cls");
    }

    printf("Cantidad de A: %d\n", contadorA);
    printf("Cantidad de E: %d\n", contadorE);
    printf("Cantidad de I: %d\n", contadorI);
    printf("Cantidad de O: %d\n", contadorO);
    printf("Cantidad de U: %d\n", contadorU);


    return 0;
}
