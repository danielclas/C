#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define TAM 5
/*7- Realizar un programa que permita calcular el promedio
de las 5 notas de un alumno
y las muestre en pantalla con el siguiente formato
Apellido Promedio
XXXX ##,##
Los datos a ingresar son, el nombre y apellido y las 5 notas.
No se sabe la cantidad de alumnos a ingresar, por ello se deberá mostrar en pantalla el mensaje Continúa S/N?
Para resolver el problema usar alguna de las funciones desarrolladas en problemas anteriores.
(La consigna original es 30 pero cambio a 5 notas en total )
*/
void obtenerNotasYNombre(char nomApe[][20], float promedios[], int index);
void calcularPromedios (float sumaNotas, float promedios[], int index);
void mostrarPromedios(char nomApe[][20], float promedios[], int index);

int main(){

    char rta;
    char nomApe[50][20];
    float promedios[50];
    int index=0;

    do{
        obtenerNotasYNombre(nomApe, promedios, index);

        index++;

        printf("\nPresione S para continuar o N para salir");
        rta=getche();
        rta=tolower(rta);

    }while(rta!='n');

    mostrarPromedios(nomApe, promedios, index);

    return 0;
}

void obtenerNotasYNombre(char nomApe[][20], float promedios[], int index){

    char materias[TAM][20]={{"Matematica"},{"Ingles"},{"Fisica"},{"Lengua"},{"Quimica"}};
    float sumaNotas, auxNotas;

    sumaNotas=0;
    system("cls");
    printf("Ingrese el apellido del alumno: ");
    fflush(stdin);
    gets(nomApe[index]);

    for(int i=0 ; i<TAM ; i++){
        printf("\n\tNota de %s: ", materias[i]);
        scanf("%f", &auxNotas);
        sumaNotas+=auxNotas;
    }

    calcularPromedios(sumaNotas, promedios, index);
}

void calcularPromedios(float sumaNotas, float promedios[], int index){

    float promedio=sumaNotas/TAM;
    promedios[index]=promedio;

}

void mostrarPromedios(char nomApe[][20], float promedios[], int index){

    system("cls");
    printf("\tApellido\tPromedio");

    for(int i=index-1 ; i>-1 ; i--){

        printf("\n\t%s\t%.2f", nomApe[i], promedios[i]);
    }

}
