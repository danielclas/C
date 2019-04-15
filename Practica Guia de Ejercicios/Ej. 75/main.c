#include <stdio.h>
#include <stdlib.h>
#define TAM 5
/**
75. Una fábrica tiene 30 obreros con legajos de 1 a 30.
 Por cada obrero se registran los movimientos
  que intervienen en la liquidación informando:

N° de legajo, Sueldo básico, Bonificación por antigüedad.

Se debe calcular el sueldo neto de cada obrero considerando:
Un descuento por jubilación que representa el 16 % del sueldo básico
Un descuento por obra social que representa el 4,5 % del sueldo básico

Se pide:
Listado como el siguiente:
N° de legajo Sueldo básico Jubilación Obra social Antigüedad Sueldo neto
• Indicar cuál fue el legajo del o los obreros con mayor bonificación de antigüedad y cual fue esa cantidad
• Listado de todos los obreros ordenado por sueldo neto
//Utilizo 5 obreros para testear
//Dado que no aclara, utilizo bonificacion de 2% por año como antigüedad
**/
//ARREGLAR BONIFICACION!
typedef struct{

    int legajo;
    float basico;
    float descJubilacion;
    float descObraSocial;
    float bonificacion;
    float neto;
    int antiguedad;

}eEmpleado;

void calcularNetoYDescuentos(eEmpleado obreros[], int tam);
void obtenerDatos(eEmpleado obreros[], int tam);
void mostrarDatos(eEmpleado obreros[], int tam);
void obtenerYMostrarMaximo(eEmpleado obreros[], int tam);
void ordenarPorSueldo(eEmpleado oberos[], int tam);

int main()
{
    eEmpleado obreros[TAM];

    obtenerDatos(obreros, TAM);
    calcularNetoYDescuentos(obreros, TAM);

    mostrarDatos(obreros, TAM);

    return 0;
}


void obtenerDatos(eEmpleado obreros[], int tam){

     for(int i=0 ; i<tam ; i++){
            printf("|---Sistema de liquidacion---|\n");
            printf("\nObrero #%d\n", i+1);
            printf("\n\tLegajo: ");
            scanf("%d", &obreros[i].legajo);
            printf("\tSueldo basico: $");
            scanf("%f", &obreros[i].basico);
            printf("\tIngrese annos de antiguedad: ");
            scanf("%d", &obreros[i].antiguedad);
            system("cls");
    }

    obtenerYMostrarMaximo(obreros, TAM);
}

void calcularNetoYDescuentos(eEmpleado obreros[], int tam){

    for(int i=0 ; i<tam ; i++){
        obreros[i].descJubilacion=(float)obreros[i].basico*0.16;
        obreros[i].descObraSocial=(float)obreros[i].basico*0.045;
        obreros[i].bonificacion=(float)((obreros[i].antiguedad*2)*obreros[i].basico)/100;
        obreros[i].neto=obreros[i].basico-obreros[i].descObraSocial-obreros[i].descJubilacion+obreros[i].bonificacion;
    }
}

void obtenerYMostrarMaximo(eEmpleado obreros[], int tam){

    int i=0;
    float bonificacionMax;

    bonificacionMax=obreros[i].bonificacion;

    for(i=1; i<tam ; i++){
        if(obreros[i].bonificacion>bonificacionMax){
            bonificacionMax=obreros[i].bonificacion;
        }
    }

    printf("|---Sistema de liquidacion---|\n");
    printf("\n\nLegajo(s) de bonificacion(es) maxima(s): \n");
    for(i=0 ; i<tam ; i++){
        if(obreros[i].bonificacion==bonificacionMax){
            printf("\nLegajo: %d\tBonificacion: $%.2f", obreros[i].legajo, obreros[i].bonificacion);
        }
    }
}

void mostrarDatos(eEmpleado obreros[], int tam){

    printf("\n\nDatos ingresados: \n");
    printf("\nLegajo\tBasico\tJubilacion\tObra social\tAntiguedad\tNeto");
    for(int i=0 ; i<tam ;i++){
    printf("\n%d \t $%.2f \t -$%.2f \t -$%.2f \t $%.2f \t $%.2f \t", obreros[i].legajo, obreros[i].basico, obreros[i].descJubilacion, obreros[i].descObraSocial, obreros[i].bonificacion, obreros[i].neto);
    }
}




