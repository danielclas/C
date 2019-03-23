#include <stdio.h>
#include <stdlib.h>
//Ingresar un número entero por consola y efectuar la suma de todos los números que le anteceden, comenzando desde 0 y mostrar el resultado por pantalla


int main()
{
    int numero;
    int suma=0;
    char respuesta='s';

    do
    {
        printf("Ingrese un numero entero: ");
        fflush(stdin);
        scanf("%d", &numero);

        suma+=numero;

        printf("Presione s para ingresar otro numero o cualquier tecla para salir: ");
        fflush(stdin);
        scanf("%c", &respuesta);

        system("cls");

    }while(respuesta=='s');


    printf("La suma es: %d", suma);
    return 0;
}
