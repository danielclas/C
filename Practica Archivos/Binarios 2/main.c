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
    eAuto* lista = (eAuto*) malloc(3*sizeof(eAuto));
    FILE* archivo;
    int i=0;
    int cant;
    //int contador=0;

    archivo=fopen("autos.dat", "rb");

    if(archivo==NULL){
        printf("No pudo crearse el archivo");
        exit(1);
    }

    while(!feof(archivo)){

        cant=fread(lista+i, sizeof(eAuto), 1, archivo);

        if(cant<1){
            if(feof(archivo)){
                break;
            }else{
                printf("Se produjo un error al leer el archivo");
                break;
            }
        }
        i++;
    }

    fclose(archivo);
    mostrarAutos(lista, i);

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
