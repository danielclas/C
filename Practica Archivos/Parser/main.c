#include <stdio.h>
#include <stdlib.h>
typedef struct{

    int id;
    char nombre[40];
    char apellido[40];
    float sueldo;

}eEmpleado;

int main()
{
    FILE* f=fopen("mockaroo.csv", "r");
    int auxInt;
    char auxString[40];
    char auxString2[40];
    char auxString3[40];
    char auxString4[40];
    char buffer[4][40];
    float auxFloat;
    int cant, cont=0;
    eEmpleado* lista=(eEmpleado*) malloc (sizeof(eEmpleado));
    eEmpleado* auxEmpleado;

    if(f==NULL){
        printf("Null");
        exit(1);
    }

    fscanf(f, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("%5s%15s%15s%15s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(f)){

        cant=fscanf(f, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);

       if(cant<4){
            if(feof(f)){
                break;
            }else{
                printf("Problemas para leer el archivo");
                break;
            }
        }

    }


    (lista+cont)->id=atoi(buffer[0]);
    strcpy((lista+cont)->nombre, buffer[1]);
    strcpy((lista+cont)->apellido, buffer[2]);
    (lista+cont)->sueldo=atof(buffer[3]);

    cont++;

    auxEmpleado=(eEmpleado*) realloc(lista, sizeof(eEmpleado)*cont+1);

    if(auxEmpleado!=NULL){
        lista=auxEmpleado;
    }

    for(int i=0; i<cont ; i++){
        printf("%5d%15s%15s%15.2f\n", (lista+i)->id, (lista+i)->nombre, (lista+i)->apellido, (lista+i)->sueldo);
    }

    fclose(f);

    return 0;
}
