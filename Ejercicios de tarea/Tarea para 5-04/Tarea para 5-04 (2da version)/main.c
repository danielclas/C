#include <stdio.h>
#include <stdlib.h>
/*
Crear una funcion que ordene de forma creciente o decreciente los nros de un vector.
Y otra que duplique los mismos.
*/
void duplicarVector (int vector[], int tam);
void conseguirEntero (int vector[], char *texto, int tam);
void mostrarEnteros (int vector[], int tam);
int funcionMenu ();
void ordenarEnteros(int vector[], int vector2[], int vector3[], int tam, int flag);
//Flag 1 es creciente
//Flag 0 es decreciente


int main()
{

    int legajos[5];
    int notas[5];
    int notas2[5];
    char *texto[10]={"legajo"};
    char *texto2[10]={"nota"};
    char *texto3[10]={"nota 2"};
    int rta;

    do{
        system("cls");
        rta=funcionMenu();

        switch(rta){

        case 1:
            conseguirEntero(legajos, *texto, 5);
            break;
        case 2:
            conseguirEntero(notas, *texto2, 5);
            break;
        case 3:
            conseguirEntero(notas2, *texto3, 5);
            break;
        case 4:
            mostrarEnteros(legajos, 5);
            printf("\n\n");
            system("pause");
            break;
        case 5:
            duplicarVector(legajos, 5);
            mostrarEnteros(legajos, 5);
            printf("\n\n");
            system("pause");
            break;
        case 6://decreciente
            ordenarEnteros(legajos, notas, notas2, 5, 0);
            break;
        case 7:
            ordenarEnteros(notas, legajos, notas2, 5, 0);
            break;
        case 8:
            ordenarEnteros(notas2, notas, legajos, 5, 0);
            break;
        case 9://creciente
            ordenarEnteros(legajos, notas, notas2, 5, 1);
            break;
        case 10://creciente
           ordenarEnteros(notas, legajos, notas2, 5, 1);
           break;
        case 11://creciente
           ordenarEnteros(notas2, legajos, notas, 5, 1);
           break;
        default:
            system("cls");
            break;
        }

    }while(rta!=12);

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
    printf("\n\n\t1- Ingrese 5 legajos");
    printf("\n\t2- Ingrese 5 notas");
    printf("\n\t3- Ingrese 5 notas 2");
    printf("\n\n\t4- Mostrar enteros ingresados");
    printf("\n\t5- Duplicar los enteros");
    printf("\n\n\t6- Ordenarlos decreciente por legajo");//flag 0
    printf("\n\n\t7- Ordenarlos decreciente por nota");//flag 0
    printf("\n\n\t8- Ordenarlos decreciente por nota 2");//flag 0
    printf("\n\t9- Ordenarlos creciente por legajo");//flag 1
    printf("\n\t10- Ordenarlos creciente por nota");//flag 1
    printf("\n\t11- Ordenarlos creciente por nota 2");//flag 1

    printf("\n\n\t12- Salir");
    printf("\n\nElija una opcion: ");
    scanf("%d", &rta);

    return rta;
}

void conseguirEntero (int enteros[], char *texto, int tam){

    int i;

    for(i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese %s: ", texto);
        scanf("%d", &enteros[i]);
    }

}


void mostrarEnteros(int enteros[], int tam){

    int i;

    for(i=0 ; i<tam ; i++){

        printf("\n\tEntero posicion %d: %d", i, enteros[i]);
    }
}

void ordenarEnteros(int vector[], int vector2[], int vector3[], int tam, int flag){

    int i, j, auxInt;

    for(i=0 ; i<tam-1 ; i++){

        for(j=i+1 ; j<tam ; j++){

            if(flag==1){//Creciente

                if(vector[j]<vector[i]){

                    auxInt=vector[i];
                    vector[i]=vector[j];
                    vector[j]=auxInt;

                    auxInt=vector2[i];
                    vector2[i]=vector2[j];
                    vector2[j]=auxInt;

                    auxInt=vector3[i];
                    vector3[i]=vector3[j];
                    vector3[j]=auxInt;
                }
            }else{

                //if(flag==0)
                if(vector[j]>vector[i]){

                    auxInt=vector[i];
                    vector[i]=vector[j];
                    vector[j]=auxInt;

                    auxInt=vector2[i];
                    vector2[i]=vector2[j];
                    vector2[j]=auxInt;

                    auxInt=vector3[i];
                    vector3[i]=vector3[j];
                    vector3[j]=auxInt;
            }
        }
    }

}
}


