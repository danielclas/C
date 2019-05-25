#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char marca[50];
    float cc;

}eAuto;

void mostrarAutos(eAuto* lista, int tam);
void mostrarAuto(eAuto* unAuto);

int main()
{
    /*FILE* archivo;
    char caracteres;

    archivo=fopen("archivo.txt", "r");

    if(archivo==NULL){
        printf("El archivo no existe");
        exit(1);
    }

    printf("El archivo existe!\n");
    archivo=fopen("archivo.txt", "w");

    fprintf(archivo, "El archivo existe y anda bien");
    fclose(archivo);

    archivo=fopen("archivo.txt", "r");

    while(!feof(archivo)){
        caracteres=fgetc(archivo);
        printf("%c", caracteres);
    }

    fclose(archivo);

    archivo=fopen("archivo.txt", "a");
    fprintf(archivo, "\nSigue andando bien");
    fclose(archivo);
    archivo=fopen("archivo.txt", "r");

    while(!feof(archivo)){
        caracteres=fgetc(archivo);
        printf("%c", caracteres);
    }*/

    eAuto auto1={1234,"ford",1.6};
    eAuto auto2={1222,"renault",1.8};
    eAuto auto3={5555,"peugeot",1.2};

    eAuto* lista = (eAuto*) malloc(3*sizeof(eAuto));
    FILE* archivo;

    *lista=auto1;
    *(lista+1)=auto2;
    *(lista+2)=auto3;

    archivo=fopen("autos.dat", "wb");

    if(archivo==NULL){
        printf("No pudo crearse el archivo");
        exit(1);
    }

    fwrite(lista, sizeof(eAuto), 3, archivo);
    fclose(archivo);



    //mostrarAutos(lista, 3);

    return 0;
}

void mostrarAutos(eAuto* lista, int tam){

    if(lista!=NULL && tam>0){
        for(int i=0 ; i<tam ; i++){
            mostrarAuto(lista+i);
        }
    }
}

void mostrarAuto(eAuto* unAuto){

    if(unAuto!=NULL){
       printf("\n%d %s %.2f", unAuto->id, unAuto->marca, unAuto->cc);
    }
}
