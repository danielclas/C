#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>


/*48. Escribir un programa que calcule el salario semanal de cada trabajador
de una empresa dada la tarifa
horaria y el número de horas trabajadas además del nombre
(número de legajo para codificar en C).
Se debe permitir al usuario indicar cuando desea dejar de ingresar datos
49. ídem al anterior pera informando al finalizar
 el ingreso de datos y los cálculos correspondientes) la
cantidad de empleados 3 los que se les calculó el Salario
*/
int main()
{
    float porHora;
    float horasTrabajadas;
    float semanal;
    int legajo;
    int cont=0;
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
        cont++;

        system("cls");

        printf("\nSalario semanal de trabajador %d: $%.2f\n", legajo, semanal);

        system("pause");//Para que muestre el total en una pantalla diferente a pregunta siguiente

        printf("\nCalcular otro salario? Presione s, u otra tecla para salir");
        rta=getche();
        rta=tolower(rta);

        system("cls");

    }while(rta=='s');

    printf("\nSe calcularon %d sueldos de empleados\n", cont);
    return 0;
}
