#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Hacer el programa ante la pregunta desea continuar sólo nos permita introducir como respuesta 'S' o'N'
int main()
{
    char respuesta;

    do
    {
        printf("\nDesea continuar? Presione S o N: ");
        fflush(stdin);
        respuesta=getche();

        while(respuesta!='S' && respuesta!='N')
        {
            printf("\n Ingrese una respuesta valida S o N: ");
            fflush(stdin);
            respuesta=getche();
        }

        //system("cls");

    }while(respuesta=='S');

    return 0;
}

