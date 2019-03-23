#include <stdio.h>
#include <stdlib.h>
/*Diseñar el programa necesario para que habiéndose leído
el valor de 2 variables NUM1 y NUM2 se intercambien los valores de las variables,
es decir que el valor que tenía NUM1 ahora lo contenga NUM2 y viceversa
*/

int main()
{
    int num1;
    int num2;

    printf("Ingrese num 1: ");
    scanf("%d", &num1);

    printf("\nIngrese num 1: ");
    scanf("%d", &num2);

    printf("\nNum 1: %d Num 2: %d", num2, num1);



    return 0;
}
