#include <stdio.h>
#include <stdlib.h>
/*
Crear una funcion que ordene de forma creciente o decreciente los nros de un vector.
Y otra que duplique los mismos.
*/
void duplicarVector (int vector[], int tam);
void conseguirEntero (int vector[], int tam);
void mostrarEnteros (int vector[], int tam);
int funcionMenu ();
void ordenarVector(int vector[], int tam, int flag);
//Flag 1 es creciente
//Flag 0 es decreciente


int main()
{

    int enteros[5];
    int rta;

    do{
        system("cls");
        rta=funcionMenu();

        switch(rta){

        case 1:
            conseguirEntero(enteros, 5);
            break;
        case 2:
            mostrarEnteros(enteros, 5);
            printf("\n\n");
            system("pause");
            break;
        case 3:
            duplicarVector(enteros, 5);
            mostrarEnteros(enteros, 5);
            printf("\n\n");
            system("pause");
            break;
        case 4:
            ordenarVector(enteros, 5, 1);
            break;
        case 5:
            ordenarVector(enteros, 5, 0);
            break;
        default:
            system("cls");
            break;

        }


    }while(rta!=6);

    return 0;
}

void duplicarVector(int vector[], int tam){

    int i;

    for(i=0 ; i<tam ; i++){

        vector[i]*=2;
    }

}

int funcionMenu(){

    int rta;

    printf("Opciones: ");
    printf("\t\n\n1- Ingrese 5 enteros");
    printf("\t\n2- Mostrar enteros ingresados");
    printf("\t\n3- Duplicar los enteros");
    printf("\t\nOrdenarlos");
    printf("\t\t\n4- Decreciente");//flag 0
    printf("\t\t\n5- Creciente");//flag 1
    printf("\t\n6- Salir");
    printf("\n\nElija una opcion: ");
    scanf("%d", &rta);

    return rta;
}

void conseguirEntero (int enteros[], int tam){

    int i;

    for(i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese un entero: ");
        scanf("%d", &enteros[i]);
    }

}

void mostrarEnteros(int enteros[], int tam){

    int i;

    for(i=0 ; i<tam ; i++){

        printf("\n\tEntero posicion %d: %d", i, enteros[i]);
    }
}

void ordenarVector(int enteros[], int tam, int flag){

    int i, j, auxInt;

    for(i=0 ; i<tam-1 ; i++){

        for(j=i+1 ; j<tam ; j++){

            if(flag==1){//Creciente

                if(enteros[j]<enteros[i]){

                    auxInt=enteros[i];
                    enteros[i]=enteros[j];
                    enteros[j]=auxInt;
                }
            }else{

                //if(flag==0)
                if(enteros[j]>enteros[i]){

                    auxInt=enteros[i];
                    enteros[i]=enteros[j];
                    enteros[j]=auxInt;
            }
        }
    }

}
}
