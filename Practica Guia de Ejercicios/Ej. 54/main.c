#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
/*Escribir un programa que determine si un año es bisiesto.
Un año es bisiesto si es múltiplo de 4.
Los años múltiplos de 100 no son bisiestos,
 salvo si ellos también son múltiplos de 400 (2000 es bisiesto pero 1900 no)
*/
int main()
{
    int anno;
    char rta;

    do{

        printf("Ingrese un anio: ");
        scanf("%d", &anno);

        if(anno<100)
        {
            if(anno%4==0)
            {
                printf("Anio %d es bisiesto\n", anno);
            }
            else
            {
                printf("Anio %d no es bisiesto\n", anno);
            }
        }
        else
        {
            if(anno%4==0 && (((anno%100==0))&&(anno%400==0)))
           {
               printf("Anio %d es bisiesto\n", anno);
           }
           else
           {
               printf("Anio %d no es bisiesto\n", anno);
           }
        }


        printf("\nPresione s para ingresar otro");
        rta=getche();
        rta=tolower(rta);
        system("cls");

    }while(rta=='s');

    return 0;
}
