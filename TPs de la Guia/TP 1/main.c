#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
/*En una empresa se ingresan de todos sus trabajadores (no se sabe cuántos)
el nombre del empleado, la tarifa horaria y el número de horas trabajadas semanalmente.
 Realizar la carga de datos correspondiente y además:
a) Calcular e imprimir el salario semanal de cada trabajador
b) Imprimir a cuantos empleados se le calculó el salario semanal
c) Mostrar por pantalla cual es el nombre del empleado de mayor sueldo (con el monto que cobró)
d) Mostrar por pantalla cual es el nombre del empleado de menor sueldo (con el monto que cobró)
e) Calcular el costo de la empresa en salarios y mostrarlo por pantalla
f) Calcular e imprimir el sueldo promedio de la empresa
g) indicar cuantos empleados ganan semanalmente $200 o más y cuantos ganan por debajo de esa cifra
h) Calcular y mostrar el resumen de los datos ingresados en el que conste: Costo de la empresa en salarios - Cantidad de empleados - Sueldo promedio
NOTA: se debe permitir al usuario trabajar en la carga de datos y cálculos correspondientes hasta que él lo decida.
 Se debe validar que la tarifa horaria no supere los $7 ni sea inferior a $3
 El número máximo de horas trabajadas semanalmente por un empleado no puede ser superior a 50.
Puntos a hasta h:
Salario semanal SUELDO
Empleados a los que se calculó el salario: TOTAL-EMPLEADOS
Nombre del empleado con mayor sueldo: MEJOR-EMPLEADO
Monto que cobró MEJOR-SUELDO
Nombre del empleado con menor sueldo: PEOR-EMPLEADO
Monto que cobró: PEOR-SUELDO
Costo de la empresa en salarios: COSTO-SUELDOS
Sueldo promedio de la empresa: SUELDO-PROMEDIO
Empleados que ganan $200 o más MAS-DE200
Empleados que ganan menos de $200 MENOS-DE200
*/
typedef struct{

    char nombre[20];
    float valorHora;
    float horas;
    float sueldo;

}Eempleado;

void conseguirDatos (Eempleado nomina[], int index);
int calcularSueldoMenor(Eempleado nomina[], int index);
int calcularSueldoMayor(Eempleado nomina[], int index);
void mostrarEmpleados(Eempleado nomina[], int index);
float calcularTotalSalarios (Eempleado nomina[], int index);
float calcularPromedio (Eempleado nomina[], int index);
int calcularMas200 (Eempleado nomina[], int index);

int main()
{

    Eempleado nomina[50];
    char rta;
    int index=0, indexMayor, indexMenor, empMas200=0, empMenos200=0;

    do{

        conseguirDatos(nomina, index);

        index++;

        printf("Para ingresar datos de otro empleado, presione s: ");
        rta=getche();
        rta=tolower(rta);

    }while(rta=='s');

    //A) Mostrar salario semanal de cada trabajador
    mostrarEmpleados(nomina, index);
    //B) Cantidad de salarios calculados
    printf("\n\nB) Se le calculo el salario a %d empleados", index);
    //C) Mayor sueldo
    indexMayor=calcularSueldoMayor(nomina, index);
    printf("\n\nC) Mayor sueldo $%.2f, %s", nomina[indexMayor].sueldo, nomina[indexMayor].nombre);
    //D) Menor sueldo
    indexMenor=calcularSueldoMenor(nomina, index);
    printf("\n\nD) Menor sueldo $%.2f, %s", nomina[indexMenor].sueldo, nomina[indexMenor].nombre);
    //E) Costo total salarios
    printf("\n\nE) Total salarios: $%.2f", calcularTotalSalarios(nomina, index));
    //F) Promedio de sueldos
    printf("\n\nF) Promedio de sueldo: $%.2f", calcularPromedio(nomina, index));
    //G)Ganan 200 o mas y menos de 200
    empMas200=calcularMas200(nomina, index);
    if(empMas200==0){
        empMenos200=index-1;
    }else{
        empMenos200=index-empMas200;
    }
    printf("\n\nG) Empleados que ganan $200 o mas: %d", empMas200);
    printf("\nG) Empleados que menos de $200: %d", empMenos200);

    return 0;
}

void conseguirDatos (Eempleado nomina[], int index){

    system("cls");
    printf("Empleado #%d: ", index+1);

    printf("\n\tNombre: ");
    fflush(stdin);
    gets(nomina[index].nombre);

    printf("\tValor por horas: ");
    scanf("%f", &nomina[index].valorHora);

    while(nomina[index].valorHora<3 || nomina[index].valorHora>7){
        printf("\tError. Valor por horas: ");
        scanf("%f", &nomina[index].valorHora);
    }

    printf("\tHoras trabajadas: ");
    scanf("%f", &nomina[index].horas);

    while(nomina[index].horas<0 || nomina[index].horas>50){
        printf("\tError. Horas trabajadas: ");
        scanf("%f", &nomina[index].horas);
    }

    nomina[index].sueldo=nomina[index].horas*nomina[index].valorHora;

}

void mostrarEmpleados(Eempleado nomina[],int  index){

    system("cls");
    printf("A) Salario semanal de cada trabajador\n");
    for(int i=index-1 ; i>-1 ; i--){
        printf("\n\t%s, $%.2f", nomina[i].nombre, nomina[i].sueldo);
    }
}

int calcularSueldoMayor(Eempleado nomina[],int  index){

    int indexMayor=index-1;

    for(int i=index-1 ; i>-1 ; i--){

            if(nomina[i].sueldo>nomina[indexMayor].sueldo){
                indexMayor=i;
            }
    }

    return indexMayor;

}

int calcularSueldoMenor(Eempleado nomina[],int  index){

    int indexMenor=index-1;

    for(int i=index-1 ; i>-1 ; i--){
            if(nomina[i].sueldo<nomina[indexMenor].sueldo){
                indexMenor=i;
            }
    }

    return indexMenor;
}

float calcularTotalSalarios (Eempleado nomina[],int  index){

    float totalSalarios=0;

    for(int i=index-1 ; i>-1 ; i--){
        totalSalarios+=nomina[i].sueldo;
    }

    return totalSalarios;

}

float calcularPromedio (Eempleado nomina[],int  index){

    float totalSalarios;
    float promedio;

    totalSalarios=calcularTotalSalarios(nomina, index);
    promedio=(float)totalSalarios/(index-1);

    return promedio;


}

int calcularMas200 (Eempleado nomina[],int  index){

    int cantMas200=0;

    for(int i=index-1 ; i>-1 ; i--){

        if(nomina[i].sueldo>=200){
            cantMas200++;
        }
    }

    return cantMas200;



}

