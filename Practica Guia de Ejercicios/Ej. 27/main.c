#include <stdio.h>
#include <stdlib.h>

/*
Ingresar por teclado 3 números correspondientes a los lados de
un triángulo. Teniendo en cuenta que la suma de los dos
 lados menores tiene que ser superior al lado mayor para que formen un triángulo, indicar si los números
 indicados forman un triángulo y si lo forman que tipo de triángulo es

*/

//Preguntar por que ingresando valores 100, 99 y 2, el valor medio es 79, o 600-500-10/10-500-600c

int main()
{
    int lado1;
    int lado2;
    int lado3;
    int ladoMayor;
    int ladoMedio;
    int ladoMenor;

    printf("Ingrese el lado 1: ");
    fflush(stdin);
    scanf("%d", &lado1);

    printf("\nIngrese el lado 2: ");
    fflush(stdin);
    scanf("%d", &lado2);

    printf("\nIngrese el lado 3: ");
    fflush(stdin);
    scanf("%d", &lado3);

    if(lado1==lado2 && lado2==lado3)
    {
        printf("\nEl triangulo resultante es equilatero\n");
    }
    else
    {
        if(lado1>lado2 && lado1>lado3)
        {
            ladoMayor=lado1;
        }
        else
        {
            if(lado2>lado3 && lado2>lado1)
            {
                ladoMayor=lado2;
            }
            else
            {
                if(lado3>lado2 && lado3>lado1)
                {
                    ladoMayor=lado3;
                }
            }
        }

        if(lado1<lado2 && lado1<lado3)
        {
            ladoMenor=lado1;
        }
        else
        {
            if(lado2<lado3 && lado2<lado3)
            {
                ladoMenor=lado2;
            }
            else
            {
                if(lado3<lado2 && lado3<lado1)
                {
                   ladoMenor=lado3;
                }
            }
        }

        if(lado1>lado2 && lado1<lado3)
        {
            ladoMedio=lado1;
        }
        else
        {
            if(lado2>lado1 && lado2<lado3)
            {
                ladoMedio=lado2;
            }
            else
            {
                if(lado3>lado2 && lado3<lado1)
                {
                  ladoMedio=lado3;
                }
            }
        }

        if(ladoMedio+ladoMenor>ladoMayor)
        {
            if(lado1!=lado2 && lado2!=lado3)
            {
                printf("\nLos tres lados son diferentes: triangulo escaleno\n");
            }
            else
            {
                printf("\nDos lados son iguales y otro no: triangulo isoceles\n");
            }
        }
        else
        {
            printf("\nNo es un triangulo\n");
        }

    }

    int suma;
    suma=ladoMedio+ladoMenor;

    printf("Mayor %d Menor %d Medio %d", ladoMayor, ladoMenor, ladoMedio);
    printf("suma: %d", suma);//De prueba

    return 0;

}
