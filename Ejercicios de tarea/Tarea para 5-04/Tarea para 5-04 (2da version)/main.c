#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>



/*
Crear una funcion que ordene de forma creciente o decreciente los nros de un vector.
Y otra que duplique los mismos.
*/
void duplicarVector (int vector[], int tam);
void conseguirNotas (int notas[], char *texto, int tam);
void mostrarDatos(char nomApe[][20], int legajos[], int notas[], int notas2[], float promedios[], char sexos[], int tam);
int funcionMenu ();
void ordenarEnteros(int vector[], int vector2[], int vector3[], float promedios[], char sexos[], char nomApe[][20], int tam, int flag);
void ordenarFlotantes(float promedios[], int vector[], int vector2[], int vector3[], char sexos[], char nomApe[][20], int tam, int flag);
void conseguirNomApe (char nomApe[][20], int tam);
void calcularPromedios (float promedios[], int notas[], int notas2[], int tam);
void conseguirSexos (char sexos[], int tam);
void conseguirLegajos(int legajos[], int tam);
//Flag 1 es creciente
//Flag 0 es decreciente

int main()
{

    int legajos[5];
    int notas[5];
    int notas2[5];
    int flag1=0;//Legajos
    int flag2=0;//Notas
    int flag3=0;//Notas2
    int flag4=0;//Sexos
    int flag5=0;//Nom y Ape
    int rta;
    char nomApe[5][20];
    char *texto2[10]={"nota"};
    char *texto3[10]={"nota 2"};
    char sexos[5];
    float promedios[5];

    do{
        system("cls");
        rta=funcionMenu();

        switch(rta){

        case 1:
            if(flag5==1){
                puts("\nYa se han ingresado los sexos\n");
                system("pause");
                break;
            }
            flag5=1;
            conseguirNomApe(nomApe, 5);
            break;
        case 2:
            if(flag4==1){
                puts("\nYa se han ingresado los sexos\n");
                system("pause");
                break;
            }
            flag4=1;
            conseguirSexos(sexos, 5);
            break;
        case 3:
            if(flag1==1){
                puts("\nYa se han ingresado los legajos\n");
                system("pause");
                break;
            }
            flag1=1;
            conseguirLegajos(legajos, 5);
            break;
        case 4:
            if(flag2==1){
                puts("\nYa se han ingresado las notas\n");
                system("pause");
                break;
            }
            conseguirNotas(notas, *texto2, 5);
            flag2=1;
            break;
        case 5:
            if(flag3==1){
                puts("\nYa se han ingresado las notas 2\n");
                system("pause");
                break;
            }
            conseguirNotas(notas2, *texto3, 5);
            flag3=1;
            break;
        case 6:
            if(flag1==1 && flag2==1 && flag3==1){
                calcularPromedios(promedios, notas, notas2, 5);
                mostrarDatos(nomApe, legajos, notas, notas2, promedios, sexos, 5);
            }else{
                puts("Debe ingresar todos los datos antes de poder mostrarlos");
            }
            printf("\n\n");
            system("pause");
            break;
        case 7:
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
        case 8://decreciente
            ordenarEnteros(legajos, notas, notas2, promedios, sexos, nomApe, 5, 0);
            break;
        case 9:
            ordenarEnteros(notas, legajos, notas2, promedios, sexos, nomApe, 5, 0);
            break;
        case 10:
            ordenarEnteros(notas2, notas, legajos, promedios, sexos, nomApe, 5, 0);
            break;
        case 11:
            ordenarFlotantes(promedios, notas2, notas, legajos, sexos, nomApe, 5, 0);
            break;
        case 12://creciente
            ordenarEnteros(legajos, notas, notas2, promedios, sexos, nomApe, 5, 1);
            break;
        case 13://creciente
           ordenarEnteros(notas, legajos, notas2, promedios, sexos, nomApe, 5, 1);
           break;
        case 14://creciente
           ordenarEnteros(notas2, legajos, notas, promedios, sexos, nomApe, 5, 1);
           break;
        case 15:
            ordenarFlotantes(promedios, notas2, notas, legajos, sexos, nomApe, 5, 1);
            break;
        default:
            system("cls");
            break;
        }

    }while(rta!=16);

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
    printf("\n\n\t1- Ingrese nombres y apellidos");
    printf("\n\t2- Ingrese sexos");
    printf("\n\t3- Ingrese legajos");
    printf("\n\t4- Ingrese notas");
    printf("\n\t5- Ingrese notas 2");
    printf("\n\n\t6- Mostrar datos ingresados y promedios");
    printf("\n\t7- Duplicar los datos");
    printf("\n\n\t8- Ordenarlos decreciente por legajo");//flag 0
    printf("\n\t9- Ordenarlos decreciente por nota");//flag 0
    printf("\n\t10- Ordenarlos decreciente por nota 2");//flag 0
    printf("\n\t11- Ordenarlos decreciente por promedio");//flag 0
    printf("\n\n\t20- Ordenarlos creciente por legajo");//flag 1
    printf("\n\t13- Ordenarlos creciente por nota");//flag 1
    printf("\n\t14- Ordenarlos creciente por nota 2");//flag 1
    printf("\n\t15- Ordenarlos creciente por promedio");//flag 1


    printf("\n\n\t16- Salir");
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

void conseguirNotas (int notas[], char *texto, int tam){

    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese %s #%d: ", texto, i);
        scanf("%d", &notas[i]);

         while(notas[i]<1 || notas[i]>10){
            printf("Ingrese %s #%d valido: ", texto, i);
            scanf("%d", &notas[i]);
        }
    }

}

void conseguirLegajos(int legajos[], int tam){

    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese legajo #%d: ", i);
        scanf("%d", &legajos[i]);

        while(legajos[i]<1000 || legajos[i]>9999){
            printf("Ingrese legajo #%d valido: ", i);
            scanf("%d", &legajos[i]);
        }
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

void ordenarEnteros(int vector[], int vector2[], int vector3[], float promedios[], char sexos[], char nomApe[][20], int tam, int flag){

    int i, j, auxInt;
    float auxFloat;
    char auxChar;
    char auxString[20];

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

                    auxFloat=promedios[i];
                    promedios[i]=promedios[j];
                    promedios[j]=auxFloat;

                    auxChar=sexos[i];
                    sexos[i]=sexos[j];
                    sexos[j]=auxChar;

                    strcpy(auxString, nomApe[i]);
                    strcpy(nomApe[i], nomApe[j]);
                    strcpy(nomApe[j], nomApe[i]);

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

                    auxFloat=promedios[i];
                    promedios[i]=promedios[j];
                    promedios[j]=auxFloat;

                    auxChar=sexos[i];
                    sexos[i]=sexos[j];
                    sexos[j]=auxChar;

                    strcpy(auxString, nomApe[i]);
                    strcpy(nomApe[i], nomApe[j]);
                    strcpy(nomApe[j], nomApe[i]);
            }
        }
    }

}
}

void ordenarFlotantes(float promedios[], int vector[], int vector2[], int vector3[], char sexos[], char nomApe[][20], int tam, int flag){

    int i, j, auxInt;
    float auxFloat;
    char auxChar;
    char auxString[20];

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

                    auxFloat=promedios[i];
                    promedios[i]=promedios[j];
                    promedios[j]=auxFloat;

                    auxChar=sexos[i];
                    sexos[i]=sexos[j];
                    sexos[j]=auxChar;

                    strcpy(auxString, nomApe[i]);
                    strcpy(nomApe[i], nomApe[j]);
                    strcpy(nomApe[j], nomApe[i]);
                }
            }else{

                //if(flag==0) decreciente
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

                    auxFloat=promedios[i];
                    promedios[i]=promedios[j];
                    promedios[j]=auxFloat;

                    auxChar=sexos[i];
                    sexos[i]=sexos[j];
                    sexos[j]=auxChar;

                    strcpy(auxString, nomApe[i]);
                    strcpy(nomApe[i], nomApe[j]);
                    strcpy(nomApe[j], nomApe[i]);
            }
        }
    }

}
}

void ordenarPorNombre (char nomApe[][20], char sexos[], int legajos[], int notas[], int notas2[], float promedios[], int tam){






}



