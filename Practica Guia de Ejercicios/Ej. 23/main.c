#include <stdio.h>
#include <stdlib.h>
//De 3 números ingresados desde el teclado por el usuario, indicar cuál es el mayor

int main()
{
    int num1;
    int num2;
    int num3;

    printf("Ingrese num 1: ");
    scanf("%d", &num1);

    printf("\nIngrese num 2: ");
    scanf("%d", &num2);

    printf("\nIngrese num 3: ");
    scanf("%d", &num3);

    system("cls");

    if(num1>num2 && num1>num3)
    {
        printf("El mayor es %d", num1);
    }
    else
    {
        if(num2>num3)
        {
            printf("El mayor es %d", num2);
        }
        else
        {
            printf("El mayor es %d", num3);
        }
    }


    return 0;
}
