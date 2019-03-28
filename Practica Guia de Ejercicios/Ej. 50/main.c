#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

/*48. Escribir un programa que calcule el salario semanal
de cada trabajador de una empresa dada la tarifa
horaria y el número de horas trabajadas además del
 nombre (número de legajo para codificar en C). Se
debe permitir al usuario indicar cuando desea dejar
 de ingresar datos
49. ídem al anterior pera informando al finalizar
(el ingreso de datos y los cálculos correspondientes) la
cantidad de empleados 3 los que se les calculó el Salario
50. ídem al anterior agregando en el informe fina
( nombre del empleado (número de legajo para codificar en
C) de mayor salario con el monto del salario correspondiente
 y nombre del empleado (número de legajo
para codificar en C) de menor salario con el monto del salario correspondiente
*/
 //Preguntar "numero de legajo para codificar en C"

int main()
{
    float porHora;
    float horasTrabajadas;
    float semanal;
    float semanalMax;
    float semanalMin;
    int legajo;
    int legajoMax;
    int legajoMin;
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

        if(cont==0)
        {
            semanalMax=semanal;
            semanalMin=semanal;
            legajoMax=legajo;
            legajoMin=legajo;
        }
        else
        {
            if(semanal>semanalMax)
            {
                semanalMax=semanal;
                legajoMax=legajo;
            }
            else
            {
                if(semanal<semanalMin)
                {
                    semanalMin=semanal;
                    legajoMin=legajo;
                }
            }
        }

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
    printf("\nSueldo mayor: %.2f || Legajo: %d", semanalMax, legajoMax);
    printf("\nSueldo menor: %.2f || Legajo: %d", semanalMin, legajoMin);

    return 0;
}
