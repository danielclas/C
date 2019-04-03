#include <stdio.h>
#include <stdlib.h>
/*65.
Realizar un programa que por medio de un menú
de opciones y trabajando con un vector de 50 enteros me
permita:
a-
Cargar el vector
b-
Ordenar el vector
c-
Mostrar el vector
d-
Salir*/
int funcionMenu();
void ordenarEnteros(int enteros[5], int tam);
int main()
{

    int enteros[5];//Uso tamaño 5 para testear
    int rta;


    do{
        rta=funcionMenu();
        system("cls");


        switch(rta){

        case 1:
            printf("Cargar el vector\n");
            for(int i=0 ; i<5 ; i++){
                printf("\tNro. #%d: ", i+1);
                scanf("%d", &enteros[i]);
            }
            system("cls");
            break;
        case 2:
            ordenarEnteros(enteros, 5);
            printf("Vector ordenado\n");
            break;
        case 3:
            printf("Vector: ");
            for(int i=0 ; i<5 ; i++){
                printf("\t\t\n%d", enteros[i]);
            }
            break;
        case 4:
            printf("Programa finalizado\n\n");
            system("pause");
            break;
        default:
            break;
        }

    }while(rta!=4);


    return 0;
}

int funcionMenu(){

    int opcion;

    printf("\n\nOpciones\n");
    printf("\t\n1- Cargar el vector");
    printf("\t\n2- Ordenar el vector");
    printf("\t\n3- Mostrar el vector");
    printf("\t\n4- Salir");
    printf("\t\n\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void ordenarEnteros(int enteros[], int tam){

    int auxInt;

    for(int i=0 ; i<tam-1 ; i++){

        for(int j=i+1 ; j<5 ; j++){

            if(enteros[i]>enteros[j]){

                auxInt=enteros[i];
                enteros[i]=enteros[j];
                enteros[j]=auxInt;

            }
        }

    }



}
