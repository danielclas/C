#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>


/*Escribir un programa que calcule el salario semanal
de cada trabajador de una empresa dada la tarifa
horaria y el número de horas trabajadas además del
 nombre (número de legajo para codificar en C). Que significa?
 Se debe permitir al usuario indicar cuando desea dejar de ingresar datos
*/
int main()
{
    float porHora;
    float horasTrabajadas;
    float semanal;
    int legajo;
    char rta;

    do
    {
        printf("Numero de legajo: ");
        scanf("%d", &legajo);

        printf("\nTarifa horaria: ");
        scanf("%f", &porHora);

        printf("\nHoras trabajadas: ");
        scanf("%f", &horasTrabajadas);

        semanal=porHora*horasTrabajadas;

        system("cls");

        printf("\nSalario semanal de trabajador %d: $%.2f\n", legajo, semanal);

        system("pause");//Para que muestre el total en una pantalla diferente a pregunta siguiente

        printf("\nCalcular otro salario? Presione s, u otra tecla para salir");
        rta=getche();
        rta=tolower(rta);

        system("cls");

    }while(rta=='s');

    return 0;
}
