#include <stdio.h>
#include <stdlib.h>
/*64.
Leer 20 números enteros (positivos y negativos) distintos de cero. Mostrar el vector tal como fue ingresado
y luego mostrar los positivos ordenados en forma decreciente y por último mostrar los negativos ordenados
en forma creciente*/

void positivosDecreciente (int positivos[], int tam);
void negativosCreciente (int negativos[], int tam);

int main()
{
    int positivos[20];
    int negativos[20];

    for(int i=0 ; i<20 ; i++){
        printf("Ingrese positivo #%d: ", i+1);
        scanf("%d", &positivos[i]);
        while(positivos[i]<=0){
            printf("Ingrese nro. valido: ");
            scanf("%d", &positivos[i]);
        }
        system("cls");
    }

    for(int i=0 ; i<20 ; i++){
        printf("Ingrese negativo #%d: ", i+1);
        scanf("%d", &negativos[i]);
        while(negativos[i]>=0){
            printf("Ingrese nro. valido: ");
            scanf("%d", &negativos[i]);
        }
        system("cls");
    }

    printf("\tPositivos\tNegativos");
    for(int i=0 ; i<20 ; i++){
        printf("\n\t%d\t%d", positivos[i], negativos[i]);
    }

    positivosDecreciente(positivos, 20);
    negativosCreciente(negativos, 20);

    printf("\n\nPositivos Decreciente\tNegativos Creciente ");
    for(int i=0 ; i<20 ; i++){
        printf("\n\t%d\t\t%d", positivos[i], negativos[i]);
        }


    return 0;
}

void positivosDecreciente (int positivos[], int tam){

    int auxInt;

    for(int i=0 ; i<tam-1 ; i++){

        for(int j=i+1 ; j<tam ; j++){

            if(positivos[i]<positivos[j]){
                auxInt=positivos[i];
                positivos[i]=positivos[j];
                positivos[j]=auxInt;

            }
        }
    }
}

void negativosCreciente (int negativos[], int tam){

    int auxInt;

    for(int i=0 ; i<tam-1 ; i++){

        for(int j=i+1 ; j<tam ; j++){

            if(negativos[i]>negativos[j]){
                auxInt=negativos[i];
                negativos[i]=negativos[j];
                negativos[j]=auxInt;

            }
        }
    }
}
