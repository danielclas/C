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
//void imprmirEmpleado();
void imprimirEmpleados(eEmpleado* vec, int tam);
int menu();
void altaEmpleado(eEmpleado* vec, int tam);
void guardarEmpleadosBinario(eEmpleado* vec, int tam);

int main()
{
    eEmpleado* lista=(eEmpleado*) malloc(sizeof(eEmpleado)*TAM);
    int rta;

    if(lista==NULL){
        printf("No se consiguio memoria");
        system("pause");
        exit(1);
    }

    inicializarEmpleados(lista, TAM);
    printf("Empleados inicializados");

    do{
        system("cls");
        switch(rta=menu()){
            case 1:
                cargarEmpleados(lista, TAM);
                system("pause");
                break;
            case 2:
                altaEmpleado(lista, TAM);
                break;
            case 3:
                mostrarEmpleados(lista, TAM);
                system("pause");
                break;
            case 4:
                guardarEmpleadosBinario(lista, TAM);
                system("pause");
                break;
            case 5:
                imprimirEmpleados(lista, TAM);
                system("pause");
                break;
            default:
                system("cls");
        }
    }while(rta!=6);

    free(lista);

    return 0;
}

int menu(){

    int rta;

    printf("Menu de opciones\n\n1-Cargar empleados\n2-Alta de empleados\n3- Listar empleados\n4- Guardar Empleados Binario\n5- Imprimir empleados\n6-Salir\n\nOpcion: ");

    scanf("%d", &rta);

    return rta;

}

void altaEmpleado(eEmpleado* vec, int tam){

    int indice=buscarLibre(vec, tam);
    int auxInt;
    char auxString[20];
    char auxString2[20];
    float auxFloat;


    if(indice==-1){
        printf("No hay lugar");
    }else{

        printf("Ingrese ID: ");
        scanf("%d", &auxInt);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        scanf("%s", auxString);
        printf("\nIngrese apellido: ");
        fflush(stdin);
        scanf("%s", auxString2);
        printf("\nIngrese sueldo: ");
        scanf("%f", &auxFloat);

        eEmpleado* nuevoEmpleado=newEmpleadoParam(auxInt, auxString, auxString2, auxFloat);

        if(nuevoEmpleado!=NULL){
            *(vec+indice)=*nuevoEmpleado;
        }

        free(nuevoEmpleado);
    }

}
void mostrarEmpleados(eEmpleado* vec, int tam){

     if(vec!=NULL && tam>0){
        printf("ID Nombre Apellido Sueldo\n\n");
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
void imprimirEmpleados(eEmpleado* vec, int tam){

    FILE* f;

    if(vec!=NULL && tam>0){

        f=fopen("./listaEmpleados.txt", "w");

        if(f!=NULL){
            fprintf(f, "ID Nombre Apellido Sueldo\n\n");
            for(int i=0;i<tam;i++){
                if((vec+i)->estado==1){
                    fprintf(f,"%d %s %s %.2f", (vec+i)->id, (vec+i)->nombre, (vec+i)->apellido, (vec+i)->sueldo);
                }
            }
        }
        fprintf(f, "\n\n");
        fclose(f);
    }
}

void guardarEmpleadosBinario(eEmpleado* vec, int tam){

    FILE* f;

    if(vec!=NULL && tam>0){

        f=fopen("./empleados.bin", "wb");

        if(f!=NULL){
            for(int i=0;i<tam;i++){
                if((vec+i)->estado==1){
                    fwrite((vec+i), sizeof(eEmpleado), 1, f);
                }
            }
        }

        fclose(f);
    }
}


/*void imprmirEmpleado(){

    if(emp!=NULL){
      printf("%d %s %s %.2f\n", emp->id, emp->nombre, emp->apellido, emp->sueldo);
    }



}*/

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

void cargarEmpleados(eEmpleado* vec, int tam){

    int indice;
    /*int auxInt;
    char auxString[20];
    char auxString2[20];
    float auxFloat;*/
    FILE* f;
    int cant;

    f=fopen("./empleados.bin", "rb");

    while(!feof(f)){

        indice=buscarLibre(vec, tam);
        cant=fread((vec+indice), sizeof(eEmpleado), 1, f);

        if(feof(f)){
            break;
        }
    }

    fclose(f);

}
