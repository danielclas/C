#include <stdio.h>
#include <stdlib.h>
/*
Crear una funcion que ordene de forma creciente o decreciente los nros de un vector.
Y otra que duplique los mismos.
*/
void duplicarVector (int vector[], int tam);
void conseguirEntero (int vector[], char *texto, int tam);
void mostrarDatos(char nomApe[][20], int legajos[], int notas[], int notas2[], float promedios[], char sexos[], int tam);
int funcionMenu ();
void ordenarEnteros(int vector[], int vector2[], int vector3[], int tam, int flag);
void ordenarFlotantes(float vector[], int vector2[], int vector3[], int vector4[], int tam, int flag);
void conseguirNomApe (char nomApe[][20], int tam);
void calcularPromedios (float promedios[], int notas[], int notas2[], int tam);
void conseguirSexos (char sexos[], int tam);
//Flag 1 es creciente
//Flag 0 es decreciente
//Faltarian validaciones de legajos y notas..

int main()
{

    int legajos[5];
    int notas[5];
    int notas2[5];
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int rta;
    char nomApe[5][20];
    char *texto[10]={"legajo"};
    char *texto2[10]={"nota"};
    char *texto3[10]={"nota 2"};
    char sexos[5];
    float promedios[5];

    do{
        system("cls");
        rta=funcionMenu();

        switch(rta){

        case 0:
            conseguirNomApe(nomApe, 5);
            break;
        case 100:
            conseguirSexos(sexos, 5);
            break;
        case 1:
            flag1=1;
            conseguirEntero(legajos, *texto, 5);
            break;
        case 2:
            conseguirEntero(notas, *texto2, 5);
            flag2=1;
            break;
        case 3:
            conseguirEntero(notas2, *texto3, 5);
            flag3=1;
            break;
        case 4:
            if(flag1==1 && flag2==1 && flag3==1){
                calcularPromedios(promedios, notas, notas2, 5);
                mostrarDatos(nomApe, legajos, notas, notas2, promedios, sexos, 5);
            }else{
                puts("Debe ingresar todos los datos antes de poder mostrarlos");
            }
            printf("\n\n");
            system("pause");
            break;
        case 5:
             if(flag1==1 && flag2==1 && flag3==1){
                duplicarVector(legajos, 5);
                duplicarVector(notas, 5);
                duplicarVector(notas2, 5);
                mostrarDatos(nomApe, legajos, notas, notas2, promedios, sexos, 5);
            }else{
                puts("Debe ingresar todos los datos antes de poder duplicarlos y mostrarlos");
            }
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
        case 9:
            ordenarFlotantes(promedios, notas2, notas, legajos, 5, 0);
            break;
        case 10://creciente
            ordenarEnteros(legajos, notas, notas2, 5, 1);
            break;
        case 11://creciente
           ordenarEnteros(notas, legajos, notas2, 5, 1);
           break;
        case 12://creciente
           ordenarEnteros(notas2, legajos, notas, 5, 1);
           break;
        case 13:
            ordenarFlotantes(promedios, notas2, notas, legajos, 5, 1);
            break;
        default:
            system("cls");
            break;
        }

    }while(rta!=14);

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
    printf("\n\n\t0- Ingrese 5 nombres y apellidos");
    printf("\n\n\t100- Ingrese 5 sexos");
    printf("\n\t1- Ingrese 5 legajos");
    printf("\n\t2- Ingrese 5 notas");
    printf("\n\t3- Ingrese 5 notas 2");
    printf("\n\n\t4- Mostrar datos ingresados y promedios");
    printf("\n\t5- Duplicar los datos");
    printf("\n\n\t6- Ordenarlos decreciente por legajo");//flag 0
    printf("\n\t7- Ordenarlos decreciente por nota");//flag 0
    printf("\n\t8- Ordenarlos decreciente por nota 2");//flag 0
    printf("\n\t9- Ordenarlos decreciente por promedio");//flag 0
    printf("\n\n\t10- Ordenarlos creciente por legajo");//flag 1
    printf("\n\t11- Ordenarlos creciente por nota");//flag 1
    printf("\n\t12- Ordenarlos creciente por nota 2");//flag 1
    printf("\n\t13- Ordenarlos creciente por promedio");//flag 1


    printf("\n\n\t14- Salir");
    printf("\n\nElija una opcion: ");
    scanf("%d", &rta);

    return rta;
}

void calcularPromedios (float promedios[], int notas[], int notas2[], int tam){

    for(int i=0; i<tam ; i++){
        promedios[i]=(float)(notas[i]+notas2[i])/2;
    }

}

void conseguirSexos (char sexos[], int tam){

    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese sexo #%d: ", i);
        fflush(stdin);
        sexos[i]=getchar();
        sexos[i]=tolower(sexos[i]);

        while(sexos[i]!='f' && sexos[i]!='m'){
            printf("Ingrese sexo #%d valido:", i);
            fflush(stdin);
            sexos[i]=getchar();
            sexos[i]=tolower(sexos[i]);
        }
    }
}

void conseguirEntero (int enteros[], char *texto, int tam){

    int i;

    for(i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese %s #%d: ", texto, i);
        scanf("%d", &enteros[i]);
    }

}

void conseguirNomApe(char nomApe[][20], int tam){

    for(int i=0 ; i<5 ; i++){
        system("cls");
        printf("Ingrese nombre y apellido #%d: ", i);
        fflush(stdin);
        gets(nomApe[i]);
    }


}
void mostrarDatos(char nomApe[][20], int legajos[], int notas[], int notas2[], float promedios[], char sexos[], int tam){

    printf("\n\tSex\tNom y ape\tLegajos\tNotas\tNotas2\tProm");
    for(int i=0 ; i<tam ; i++){
        printf("\n\t%c\t%s\t%d\t%d\t%d\t%.2f", sexos[i], nomApe[i], legajos[i], notas[i], notas2[i], promedios[i]);
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

void ordenarFlotantes(float vector[], int vector2[], int vector3[], int vector4[], int tam, int flag){

    int i, j, auxInt;
    float auxFloat;

    for(i=0 ; i<tam-1 ; i++){

        for(j=i+1 ; j<tam ; j++){

            if(flag==1){//Creciente

                if(vector[j]<vector[i]){

                    auxFloat=vector[i];
                    vector[i]=vector[j];
                    vector[j]=auxFloat;

                    auxInt=vector2[i];
                    vector2[i]=vector2[j];
                    vector2[j]=auxInt;

                    auxInt=vector3[i];
                    vector3[i]=vector3[j];
                    vector3[j]=auxInt;

                    auxInt=vector4[i];
                    vector4[i]=vector4[j];
                    vector4[j]=auxInt;
                }
            }else{

                //if(flag==0) decreciente
                if(vector[j]>vector[i]){

                    auxFloat=vector[i];
                    vector[i]=vector[j];
                    vector[j]=auxFloat;

                    auxInt=vector2[i];
                    vector2[i]=vector2[j];
                    vector2[j]=auxInt;

                    auxInt=vector3[i];
                    vector3[i]=vector3[j];
                    vector3[j]=auxInt;

                     auxInt=vector4[i];
                    vector4[i]=vector4[j];
                    vector4[j]=auxInt;
            }
        }
    }

}
}

void ordenarPorNombre (char nomApe[][20], char sexos[], int legajos[], int notas[], int notas2[], float promedios[], int tam){






}

void ordenar


