#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio para practicar funcion que ordene primero por nombre, y despues por sexo y nombre
*/
void ordenarPorNombre (char nombre[][20], int tam);


int main()
{

    char nombre [][20]={"Juan Perez", "Maria Belen", "Daniel Clas", "Pedro Alberto", "Lucas Lopez"};

    for(int i=0 ; i<5 ; i++){
        puts(nombre[i]);
        printf("\n");
    }

    ordenarPorNombre(nombre, 5);

    printf("------------------\n");
    for(int i=0 ; i<5 ; i++){
        puts(nombre[i]);
        printf("\n");
    }



    return 0;
}

void ordenarPorNombre (char nombre[][20], int tam){

    //Ordena de manera creciente
    char auxString[10][20];

    for(int i=0 ; i<tam-1 ; i++){

        for(int j=i+1 ; j<tam ; j++){

            if(stricmp(nombre[i], nombre[j])==1){

                strcpy(auxString[0], nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxString[0]);

               }
        }
    }
}
