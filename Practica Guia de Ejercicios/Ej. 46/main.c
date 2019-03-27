#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

/*No hay 44 ni 45
Del registro de partes meteorológico por cada día se registra la fecha, temperatura máxima y temperatura
mínima. Diseñar en un programa que permita informar : el día más frío y cual fue esa temperatura, el día
más cálido y cual fue esa temperatura
*/

int main()
{
    int mes;
    int mesTempMax;
    int mesTempMin;
    int dia;
    int diaTempMax;
    int diaTempMin;
    int cont=0;
    char rta;
    float temp;
    float tempMax;
    float tempMin;

    do
    {
        printf("Ingrese el dia: ");
        scanf("%d", &dia);

        while(dia<1 || dia>31)
        {
            printf("\nIngrese dia valido: ");
            scanf("%d", &dia);
        }

        printf("\nIngrese el mes: ");
        scanf("%d", &mes);

        while(mes<1 || mes>12)
        {
            printf("\nIngrese mes valido: ");
            scanf("%d", &mes);
        }

        printf("\nIngrese la temperatura: ");
        scanf("%f", &temp);

        if(cont==0)
        {
            tempMax=temp;
            diaTempMax=dia;
            mesTempMax=mes;

            tempMin=temp;
            diaTempMin=dia;
            mesTempMin=mes;
        }
        else
        {
            if(temp>tempMax)
            {
                tempMax=temp;
                diaTempMax=dia;
                mesTempMax=mes;
            }
            else
            {
                if(temp<tempMin)
                {
                    tempMin=temp;
                    diaTempMin=dia;
                    mesTempMin=mes;
                }
            }
        }

        cont++;

        printf("Ingresar otro dato? Presiona s, u otra tecla para salir");
        rta=getche();
        rta=tolower(rta);

        system("cls");

    }while(rta=='s');

    printf("Dia mas calido: %d/%d/2019, temp: %.2f C", diaTempMax, mesTempMax, tempMax);
    printf("\nDia mas frio: %d/%d/2019, temp: %.2f C", diaTempMin, mesTempMin, tempMin);


    return 0;
}
