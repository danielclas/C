#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct{

    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int estado;

}eEmpleado;

void inicializarEmpleados(eEmpleado* vec, int tam);
int buscarLibre(eEmpleado* vec, int tam);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo);
void mostrarEmpleados(eEmpleado* vec, int tam);
void mostrarEmpleado(eEmpleado* emp);

int main()
{
    eEmpleado* lista=(eEmpleado*) malloc(sizeof(eEmpleado)*TAM);

    if(lista==NULL){
        printf("No se consiguio memoria");
        system("pause");
        exit(1);
    }

    inicializarEmpleados(lista, TAM);
    printf("Empleados inicializados");


    return 0;
}

void mostrarEmpleados(eEmpleado* vec, int tam){

     if(vec!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            if((vec+i)->estado==1){
                mostrarEmpleado(vec+i);
            }
        }
    }

}

void mostrarEmpleado(eEmpleado* emp){

    if(emp!=NULL){
      printf("%d %s %s %.2f\n", emp->id, emp->nombre, emp->apellido, emp->sueldo);
    }

}

int buscarLibre(eEmpleado* vec, int tam){

    int indice=-1;

    if(vec!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            if((vec+i)->estado==0){
                indice=i;
                break;
            }
        }
    }


    return indice;

}
void inicializarEmpleados(eEmpleado* vec, int tam){

    for(int i=0 ; i<tam ; i++){
        (vec+i)->estado=0;
    }

}

eEmpleado* newEmpleado(){

    eEmpleado* emp=(eEmpleado*) malloc(sizeof(eEmpleado));

    if(emp!=NULL){
        emp->id=0;
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo=0;
        emp->estado=0;
    }

    return emp;

}

eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo){

    eEmpleado* emp=(eEmpleado*) malloc(sizeof(eEmpleado));

    if(emp!=NULL){
        emp->id=id;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo=sueldo;
        emp->estado=1;
    }

    return emp;

}
