#include <stdio.h>
#include <stdlib.h>
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

int main(){

    int notas[TAM];
    char nomApe[50][20];
    char promedios[50];
    char rta;

    do{


        printf("Presione S para continuar o N para salir");
        rta=getche();
        rta=tolower(rta);

    }while(rta!='n');

    return 0;




}
