#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
/*Diseñar un programa que permita calcular el promedio de un alumno sabiendo que se ingresa por alumno
la nota de 6 materias y su nombre. No se sabe la cantidad de alumnos. Se pide un listado impreso que diga:
NOMBRE DEL ALUMNO: PROMEDIO:

listado de todos los alumnos, o de a uno por vez?
*/

int main()
{
    char nombre[30];
    char rta='s';
    float nota;
    float notaSuma;
    float notaPromedio;
    int materia=1;

    do
    {
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nombre);

        do
        {
            printf("Ingrese la nota de materia %d: ", materia);
            scanf("%f", &nota);

            notaSuma+=nota;

            materia++;

        }while(materia<7);

        materia=1;

        notaPromedio=notaSuma/6;

        system("cls");

        printf("Nombre de alumno: %s", nombre);
        printf("\nPromedio de notas: %.2f", notaPromedio);

        printf("\nDesea ingresar otro alumno? Presione s, u otra tecla para salir");
        rta=getche();
        rta=tolower(rta);

        system("cls");

    }while(rta=='s');

    return 0;
}
