#include <stdio.h>
#include <stdlib.h>

//Diseñar en un programa que permita ingresar 10 números, ninguno de ellos igual a cero. Se pide sumar los positivos, obtener el producto de los negativos y luego mostrar ambos resultados
int main()
{
    int numero;
    int contador;
    int suma=0;
    int producto=1;

    for(contador=0;contador<10;contador++)
    {
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%d", &numero);

        while(numero==0)
        {
            printf("Ingrese un numero valido: ");
            fflush(stdin);
            scanf("%d", &numero);
        }

        if(numero>0)
        {
            suma+=numero;
        }
        else
        {
            producto*=numero;
        }

        system("cls");

    }

    printf("Suma positivos: %d\n", suma);

    if(producto==1)
    {
        printf("No se ingresaron negativos");
    }
    else
    {
       printf("Producto de negativos: %d\n", producto);
    }

    return 0;
}
