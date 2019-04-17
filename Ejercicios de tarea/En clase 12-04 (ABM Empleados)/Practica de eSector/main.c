#include <stdio.h>
#include <stdlib.h>

#define TAM 3
typedef struct{

    int id;
    char desc[20];

}eSector;

typedef struct{

    int legajo;
    int idSector;

}eEmpleado;

void mostrarSectores(eSector sectores[], int tam);
void cargarEmpleados(eEmpleado lista[], eSector sectores[], int tam);

int main()
{
    eEmpleado lista[TAM];
    eSector sectores[TAM]={{1, "RRHH"},{2, "Contable"},{3, "Ventas"}};

    mostrarSectores(sectores, TAM);
    cargarEmpleados(lista, sectores, TAM);

    for(int i=0 ; i<TAM ; i++){
            for(int j=0 ; j<TAM ; j++){
                if(sectores[j].id==lista[i].idSector){
                    printf("\nLegajo: %d Sector: %s", lista[i].legajo, sectores[j].desc);
                }
            }
    }


    return 0;
}

void mostrarSectores(eSector sectores[], int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d %s", sectores[i].id,sectores[i].desc);
    }

}

void cargarEmpleados(eEmpleado lista[], eSector sectores[], int tam){

    for(int i=0 ; i<tam ; i++){
        printf("\n\nIngrese legajo: ");
        scanf("%d", &lista[i].legajo);

        printf("\nIngrese sector: \n1- RRHH \n2- Contable \n3-Ventas\nOpcion: ");
        scanf("%d", &lista[i].idSector);
    }


}
