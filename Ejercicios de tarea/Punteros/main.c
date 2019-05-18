#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{

    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
    eFecha fecha;

}eEmpleado;


void funcionModificar(int **p, int *q);
void mostrarEmpleados(eEmpleado* empleados, int tam);
void mostrarEmpleado(eEmpleado* empleado);
void f1(int vec[], int tam);
void f2(int vec[], int tam);
void f3(int* vec, int tam);
void f4(int* vec, int tam);

int main()
{
    int x=5;
    int y=10;
    int* q;
    int vec[]={5,10,15,20,25};
    char cadena[]="Esto es una cadena";
    char* p;
    eEmpleado lista[]={
    {1234, "Juan", 34000, 'm', {10,5,1999}},
    {1546, "Ana", 10000, 'f', {10,8,1989}},
    {1234, "Maria", 13000, 'f', {1,1,1990}},
    };

    q=&x;
    p=cadena;




    printf("  -  %d %d  -  ", x, y);
    funcionModificar(&q, &y);
    printf("%d  %d  \n", x, y);

    f1(vec, 5);
    printf("\n");
    f2(vec, 5);
    printf("\n");
    f3(vec, 5);
    printf("\n");
    f4(vec, 5);
    printf("\n");

    printf("Empleados: ");
    mostrarEmpleados(lista, 3);



    while(*p != '\0'){
        printf("%c", *p);
        p++;
        ///"Mas un sizeof de *p"
    }

    return 0;
}

void funcionModificar(int **p, int *q){

    **p=10;
    *q=50;

}

void f1(int vec[], int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d-", vec[i]);
    }

}

void f2(int vec[], int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d-", *(vec+i));
    }

}

void f3(int* vec, int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d-", vec[i]);
    }

}

void f4(int* vec, int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d-", *(vec+i));
    }

}

void mostrarEmpleados(eEmpleado* lista, int tam){

    for(int i=0 ; i<tam ; i++){
        mostrarEmpleado(lista+i);
    }

    printf("%s", (*(lista+1)).nombre);

}

void mostrarEmpleado(eEmpleado* empleado){

   printf("\n%d %s %c %.2f %02d/%02d/%d", empleado->legajo, empleado->nombre, empleado->sexo, empleado->sueldo, empleado->fecha.dia, empleado->fecha.mes, empleado->fecha.anio);


}
