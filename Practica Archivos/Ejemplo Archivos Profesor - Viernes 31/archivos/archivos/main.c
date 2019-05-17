#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int estado;
} eEmpleado;

///Ya no se usa void inicializarEmpleados(eEmpleado** vec, int size);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo);
///Ya no se usa int buscarLibre(eEmpleado** vec, int size);
void mostrarEmpleados(eEmpleado** vec, int size);
void mostrarEmpleado(eEmpleado* emp);
int menu();
int altaEmpleado(eEmpleado** vec, int size);
void guardarEmpleadosBinario(eEmpleado** vec, int size);
void cargarEmpleados(eEmpleado** vec, int size);
void imprimirEmpleados(eEmpleado** vec, int tam);
int agrandarLista(eEmpleado** vec, int size);

int main()
{
    int size=0;
    char seguir = 's';
    ///eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado)* TAM);
    ///En lugar de pedir lugares para TAM empleados, pido lugar para
    ///TAM punteros a empleados
    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*));
    ///Lista pasa a ser puntero a puntero


    if( lista == NULL)
    {
        printf("No se consiguio memoria");
        system("Pause");
        exit(EXIT_FAILURE);
    }

    ///No inicializo porque ya notengoempleados inicializarEmpleados(lista, TAM);
    ///Size tendra dos usos: cant de elementos y indice del primer lugar libre

    printf("Empleados inicializados\n\n");

    do
    {
        switch(menu())
        {

        case 1:
            cargarEmpleados(lista, size);
            system("pause");
            break;
        case 2:
            if(altaEmpleado(lista, size)==1){
                size++;
                if(agrandarLista(lista, size)==1){
                    printf("Alta exitosa");
                }
            }
            system("pause");
            break;
        case 3:
            mostrarEmpleados(lista, size);
            system("pause");
            break;
        case 4:
            guardarEmpleadosBinario(lista, size);
            system("pause");
            break;
        case 5:
            imprimirEmpleados(lista, size);
            system("pause");
            break;
        case 6:
            printf("Opcion 6\n");
            system("pause");
            seguir = 'n';
            break;


        }


    }
    while( seguir == 's');

    free(lista);

    return 0;
}

int inicializarEmpleados(eEmpleado* vec, int tam)
{

    for(int i=0; i < tam; i++)
    {
        (vec + i)->estado = 0;
    }
}

int agrandarLista(eEmpleado** vec, int size){

    int todoOK=0;
    eEmpleado** aux;

    aux =(eEmpleado**) realloc(vec, sizeof(eEmpleado*)*(size+1));

    if(aux!=NULL){
        vec=aux;
        todoOK=1;
    }

    return todoOK;

}

eEmpleado* newEmpleado()
{

    eEmpleado* emp = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(emp != NULL)
    {
        emp->id = 0;
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo = 0;
        emp->estado = 0;
    }
    return emp;
}

eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo)
{

    eEmpleado* emp = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(emp != NULL)
    {
        emp->id = id;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo = sueldo;
        emp->estado = 1;
    }
    return emp;
}

int buscarLibre(eEmpleado* vec, int tam)
{
    int indice = -1;

    if( vec != NULL && tam >0)
    {
        for(int i=0; i < tam; i++)
        {
            if( (vec + i)->estado == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void mostrarEmpleados(eEmpleado** vec, int size)
{

    if( vec != NULL && size >0)
    {
        printf("Id  Nombre  Apellido  Sueldo\n\n");
        for(int i=0; i < size; i++)
        {
            if( (*(vec + i))->estado == 1)
            {
                mostrarEmpleado(*(vec + i));
            }
        }
    }

}

void mostrarEmpleado(eEmpleado* emp)
{

    if( emp != NULL)
    {
        printf("%d %s %s %.2f\n", emp->id, emp->nombre, emp->apellido, emp->sueldo);
    }

}


int menu()
{

    int opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1_ Cargar empleados\n");
    printf("2_ Alta empleado\n");
    printf("3_ Listar empleados\n");
    printf("4_ Guardar empleados archivo\n");
    printf("5_ Imprimir empleados\n");
    printf("6_ Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int altaEmpleado(eEmpleado** vec, int size)
{
    int todoOK=0;
    //int indice;
    int auxInt;
    char auxCad[20];
    char auxCad2[20];
    float auxFloat;

    ///indice = buscarLibre(vec, tam);

    /*if( indice == -1)
    {
        printf("No hay lugar\n");
    }
    else
    {*/

        printf("Ingrese id: ");
        scanf("%d", &auxInt);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxCad);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxCad2);

        printf("Ingrese sueldo: ");
        scanf("%f", &auxFloat);

        eEmpleado* nuevoEmpleado = newEmpleadoParam(auxInt, auxCad, auxCad2, auxFloat);

        if(nuevoEmpleado != NULL)
        {
            *(vec + size) = nuevoEmpleado;
            todoOK=1;
            ///free(nuevoEmpleado);
        }
    //}

    return todoOK;
}

void imprimirEmpleados(eEmpleado** vec, int size)
{
    FILE* f;

    if( vec != NULL && size >0)
    {
        f = fopen("./listaEmpleados.txt", "w");
        if(f != NULL)
        {
            fprintf(f,"Id  Nombre  Apellido  Sueldo\n\n");
            for(int i=0; i < size; i++)
            {
                if( (*(vec + i))->estado == 1)
                {
                    fprintf(f,"%d %s %s %.2f\n", (*(vec + i))->id, (*(vec + i))->nombre, (*(vec + i))->apellido, (*(vec + i))->sueldo);
                }
            }
            fprintf(f,"\n\n");
        }
        fclose(f);
    }
}

void guardarEmpleadosBinario(eEmpleado** vec, int size)
{
    FILE* f;

    if( vec != NULL && size >0)
    {
        f = fopen("./empleados.bin", "wb");
        if(f != NULL)
        {

            for(int i=0; i < size; i++)
            {
                if( (*(vec + i))->estado == 1)
                {
                    fwrite( (vec+ i), sizeof(eEmpleado), 1, f);
                }
            }

        }
        fclose(f);
    }
}


void cargarEmpleados(eEmpleado** vec, int size)
{
    int indice;
    FILE* f;
    int cant;

    f = fopen("./empleados.bin", "rb");

    while( !feof(f))
    {

        indice = buscarLibre(vec, size);

        cant = fread( (vec + indice), sizeof(eEmpleado), 1, f);

     if( cant < 1){
        if(feof(f)){

            break;
        }
        else{
            printf("Problemas para leer el archivo");
        }
       }
    }

    fclose(f);
}




