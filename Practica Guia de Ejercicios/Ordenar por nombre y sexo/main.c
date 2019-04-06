#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio para practicar funcion que ordene primero por nombre, y despues por sexo y nombre
*/
void ordenarPorNombre (char nombre[][20], char sexos[], int tam);
void ordenarPorNombreYSexo (char nombre[][20], char sexos[], int tam);



int main()
{

    char nombre [][20]={"Juan Perez", "Maria Belen", "Daniel Clas", "Camila Alvarez", "Lucas Lopez"};
    char sexos [5]={'m','f','m','f','m'};

    for(int i=0 ; i<5 ; i++){
        printf("\n%s, %c", nombre[i], sexos[i]);
    }

   ordenarPorNombre(nombre, sexos, 5);

    printf("\n\n------------------\n");
    for(int i=0 ; i<5 ; i++){
        printf("\n%s, %c", nombre[i], sexos[i]);
    }

    ordenarPorNombreYSexo(nombre, sexos, 5);

    printf("\n\n------------------\n");
    for(int i=0 ; i<5 ; i++){
        printf("\n%s, %c", nombre[i], sexos[i]);
    }




    return 0;
}

void ordenarPorNombre (char nombre[][20], char sexos[], int tam){

    //Ordena de manera creciente
    char auxString[10][20];
    char auxChar;

    for(int i=0 ; i<tam-1 ; i++){

        for(int j=i+1 ; j<tam ; j++){

            if(stricmp(nombre[i], nombre[j])==1){

                strcpy(auxString[0], nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxString[0]);

                auxChar=sexos[i];
                sexos[i]=sexos[j];
                sexos[j]=auxChar;

               }
        }
    }
}

void ordenarPorNombreYSexo (char nombre[][20], char sexos[], int tam){

    //Ordena de manera creciente
    char auxString[10][20];
    char auxChar;

    for(int i=0 ; i<tam-1 ; i++){
        for(int j=i+1 ; j<tam ; j++){

            if(sexos[i]==sexos[j]){
                if(stricmp(nombre[i], nombre[j])==1){
                strcpy(auxString[0], nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxString[0]);

                auxChar=sexos[i];
                sexos[i]=sexos[j];
                sexos[j]=auxChar;
               }
            }
        }
    }
}


