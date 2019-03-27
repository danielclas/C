#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

//De los alumnos de una escuela se registra su apellido y nombre y su altura. Diseñar en un programa que
//indique el nombre del alumno más alto y su altura (sólo uno es el más alto)



int main()
{
    char nombre[30];
    char apell[30];
    char nombreAltMax[30];
    char apellAltMax[30];
    char rta='S';
    float altura;
    float alturaMax;
    int cont=0;

    do
    {

         printf("\nIngrese el nombre del alumno: ");
        scanf("%s", nombre);

        printf("\nIngrese el apellido del alumno: ");
        scanf("%s", apell);

        printf("\nIngrese la altura del alumno: ");
        scanf("%f", &altura);

       if(cont==0)
        {
           //Porque strings no se asignan de la misma manera que enteros, es necesario usar strcpy
            strcpy(nombreAltMax, nombre);
            strcpy(apellAltMax, apell);
            alturaMax=altura;
        }
        else
        {
            if(altura>alturaMax)
            {
                strcpy(nombreAltMax, nombre);
                strcpy(apellAltMax, apell);
                alturaMax=altura;
            }
        }

        cont++;

        printf("\nDesea ingresar otro alumno? Presione s, u otra tecla para finalizar");
        rta=getche();
        rta=toupper(rta);

        system("cls");


    }while(rta=='S');


    printf("\nNombre y apellido del alumno mas alto: %s %s", nombreAltMax, apellAltMax);
    printf("\nAltura del alumno mas alto: %.2f", alturaMax);

    return 0;
}
