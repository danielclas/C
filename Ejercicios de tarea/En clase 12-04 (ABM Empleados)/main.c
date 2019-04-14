#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define TAM 3

typedef struct{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;

}eEmpleado;

int inicializarEmpleados (eEmpleado vec[], int tam);
int buscarLibre (eEmpleado vec[], int tam);
int buscarEmpleado (eEmpleado vec[], int tam, int legajoABuscar);
void bajaEmpleado(eEmpleado vec[], int tam);
void modificarEmpleado(eEmpleado vec[], int tam);
void mostrarEmpleado (eEmpleado emp);
void mostrarEmpleados (eEmpleado vec[], int tam);
void agregarEmpleado(eEmpleado vec[], int tam);
void ordenarParametro(eEmpleado vec[], int tam, int parametro, int orden);
void ordenarEmpleados(eEmpleado vec[], int tam);

int menuOpcion();

int main()
{
    eEmpleado lista[TAM];
    int rta;

    inicializarEmpleados(lista, TAM);

    do{
        system("cls");
        rta=menuOpcion();
        switch(rta){

        case 1:
            agregarEmpleado(lista, TAM);
            system("cls");
            break;
        case 2:
            bajaEmpleado(lista, TAM);
            break;
        case 3:
            modificarEmpleado(lista, TAM);
            break;
        case 4:
            ordenarEmpleados(lista, TAM);
            break;
        case 5:
            mostrarEmpleados(lista, TAM);
            break;
        case 6:
            printf("\nEl programa ha finalizado\n");
            system("pause");
            break;
        default:
                system("cls");
        }
    }while(rta!=6);

        return 0;
}

void modificarEmpleado(eEmpleado vec[], int tam){

    int legajoModificar;
    int indexBuscar;
    int campoModificar;

    printf("\n\nIngrese el legajo del empleado a modificar: ");
    scanf("%d", &legajoModificar);

    indexBuscar=buscarEmpleado(vec, TAM, legajoModificar);

    if(indexBuscar==-1){
        printf("\nNo existe ninguna empleado con ese legajo\n");
        system("pause");
    }else{

        do{
            system("cls");
            printf("\nEmpleado seleccionado legajo %d", legajoModificar);
            mostrarEmpleado(vec[indexBuscar]);
            printf("\n\nIngrese el dato a modificar: ");
            printf("\n\n\t1-Nombre\n\t2-Sueldo\n\t3-Sexo\n\t4- Terminar modificacion");
            printf("\n\nOpcion: ");
            scanf("%d", &campoModificar);

            switch(campoModificar){
                case 1:
                    printf("\n\tIngrese nuevo nombre: ");
                    fflush(stdin);
                    gets(vec[indexBuscar].nombre);
                    break;
                case 2:
                    printf("\n\tIngrese nuevo sueldo: ");
                    scanf("%f", &vec[indexBuscar].sueldo);
                    break;
                case 3:
                    printf("\n\tIngrese nuevo sexo: ");
                    fflush(stdin);
                    vec[indexBuscar].sexo=tolower(getchar());
                    break;
                case 4:
                    printf("\n\tModificacion terminada\n");
                    system("pause");
                    break;
                default:
                    system("cls");
                    break;
            }

        }while(campoModificar!=4);

        }
}

void bajaEmpleado(eEmpleado vec[], int tam){

    int legajoBaja;
    int indexBuscar;
    char confirmoBaja;

    printf("\nIngrese el legajo a dar de baja: ");
    scanf("%d", &legajoBaja);

    indexBuscar=buscarEmpleado(vec, TAM, legajoBaja);

    if(indexBuscar==-1){
            printf("\nNo existe ningun empleado con ese legajo\n");
            system("pause");
    }else{
        printf("\nEmpleado con legajo %d: ", legajoBaja);
        mostrarEmpleado(vec[indexBuscar]);

        printf("\n\nConfirmar la baja de este empleado? S/N: ");
        fflush(stdin);
        confirmoBaja=tolower(getchar());

        if(confirmoBaja=='n'){
            printf("\nBaja de empleado cancelada\n");
            system("pause");
        }else{
            printf("\nBaja de empleado confirmada\n");
            system("pause");
            vec[indexBuscar].ocupado=0;
        }

    }



}

void ordenarEmpleados(eEmpleado vec[], int tam){

    int parametro;
    int orden;

    printf("\nElija un parametro por el cual ordenar: ");
    printf("\n\n\t1- Legajo\n\t2- Sexo\n\t3- Sueldo\n\t4- Nombre");
    printf("\n\n\tOpcion: ");
    scanf("%d", &parametro);
    printf("\nElija el orden: ");
    printf("\n\t1- Creciente\n\t2- Decreciente");
    printf("\n\n\tOpcion: ");
    scanf("%d", &orden);

    ordenarParametro(vec, TAM, parametro, orden);
}

void ordenarParametro(eEmpleado vec[], int tam, int parametro, int orden){

    eEmpleado auxEmp;

for(int i=0 ; i<tam-1 ; i++){

    for(int j=i+1 ; j<tam ;j++){

    switch(parametro){

        case 1:
            switch(orden){
            case 1:
                  if(vec[i].legajo>vec[j].legajo){
                    ///Legajo creciente
                        auxEmp=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmp;
                    }
                break;
            case 2:
                  if(vec[i].legajo<vec[j].legajo){
                    ///Legajo decreciente
                        auxEmp=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmp;
                    }
                break;
                }
            break;
        case 2:
                switch(orden){
            case 1:
                if(vec[i].sexo>vec[j].sexo){
                    ///Sexo creciente
                        auxEmp=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmp;
                    }
            case 2:
                if(vec[i].sexo<vec[j].sexo){
                    ///Sexo decreciente
                        auxEmp=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmp;
                    }
                }
                break;
        case 3:
            switch(orden){
                case 1:
                    if(vec[i].sueldo>vec[j].sueldo){
                    ///Sueldo creciente
                        auxEmp=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmp;
                        }
                break;
            case 2:
                if(vec[i].sueldo<vec[j].sueldo){
                    ///Sueldo decreciente
                        auxEmp=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmp;
                }
                break;
            }
            break;
        case 4:
            switch(orden){
            case 1:
                if((stricmp(vec[i].nombre, vec[j].nombre)==1)){
                    ///Nombre creciente
                    auxEmp=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmp;
            }
            break;
            case 2:
            if((stricmp(vec[i].nombre, vec[j].nombre)==-1)){
                ///Nombre decreciente
                    auxEmp=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmp;
                }
            }
            break;

        }

        }
}
}
void agregarEmpleado(eEmpleado vec[], int tam){

    int legajo;
    int indexLibre;
    int indexMostrar;

    if(buscarLibre(vec, TAM)==-1){
        printf("\nNo hay lugares libres\n");
        system("pause");
    }else{
        indexLibre=buscarLibre(vec, TAM);
        printf("\nIngrese el legajo: ");
        scanf("%d", &legajo);

        if(buscarEmpleado(vec, TAM, legajo)==-1){
     ///Si buscarEmpleado devuelve -1, entonces el empleado no existe. Pido datos
            vec[indexLibre].legajo=legajo;
            printf("\nLegajo: %d", legajo);
            printf("\nNombre: ");
            fflush(stdin);
            gets(vec[indexLibre].nombre);
            printf("Sueldo: $");
            scanf("%f", &vec[indexLibre].sueldo);
            vec[indexLibre].ocupado=1;
            printf("Sexo: ");
            fflush(stdin);
            vec[indexLibre].sexo=getchar();
            printf("\nEl empleado ha sido registrado por exito\n");
            system("pause");
        }else{
    ///Si es diferente a -1, entonces existe, y el valor devuelto sera el indice con el que muestro
            printf("\nYa hay un empleado con ese legajo\n");
            indexMostrar=buscarEmpleado(vec, TAM, legajo);
            mostrarEmpleado(vec[indexMostrar]);
            printf("\n\n");
            system("pause");
        }
      }

}

int menuOpcion(){

    int rta;

    printf("\t***ABM Empleado***");
    printf("\n\n\t1- Alta empleados");
    printf("\n\t2- Baja empleado");
    printf("\n\t3- Modificar empleado");
    printf("\n\t4- Ordenar");
    printf("\n\t5- Listar");
    printf("\n\t6- Salir");
    printf("\n\n\tIngrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}

int inicializarEmpleados(eEmpleado vec[], int tam){

    int result=-1;

    for(int i=0; i<tam ; i++){
        vec[i].ocupado=0;
        result=0;
    }

    return result;
}

int buscarLibre(eEmpleado vec[], int tam){

    int indexLibre=-1;

    for(int i=0 ; i<tam ; i++){
        if(vec[i].ocupado==0){
            indexLibre=i;
            break;
        }
    }

    return indexLibre;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajoABuscar){

    int indexEmpleado=-1;

    for(int i=0; i<tam ; i++){
        if(vec[i].legajo==legajoABuscar && vec[i].ocupado==1){
            indexEmpleado=i;
            break;
        }
    }

    return indexEmpleado;
}

void mostrarEmpleado(eEmpleado emp){

        printf("\n\n\tLegajo: %d\tNombre: %s\tSueldo: %.2f\tSexo: %c", emp.legajo, emp.nombre, emp.sueldo, emp.sexo);

}

void mostrarEmpleados(eEmpleado vec[], int tam){

    int flagMostrar=0;

        for(int i=0 ; i<tam ; i++){
            if(vec[i].ocupado==1){
              mostrarEmpleado(vec[i]);
              flagMostrar=1;
            }
        }

        if(flagMostrar==0){
            printf("\nAun no se han ingresado empleados\n");
        }
        printf("\n\n");
        system("pause");
}



