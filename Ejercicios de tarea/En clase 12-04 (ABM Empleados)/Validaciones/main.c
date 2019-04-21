#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct{

    int legajo;
    int edad;
    char sexo;
    char nombre[20];

}ePersona;

char getSexo(ePersona gente[]);
int getEdad(ePersona gente[]);
int getLegajo(ePersona gente[]);
int getInt();
void agregarGente(ePersona gente[]);
void mostrarPersona(ePersona gente[]);
void mostrarGente(ePersona gente[]);

int main()
{
    ePersona gente[TAM];

 char auxString[30];
    float auxFloat;
    int largo;
    int auxInt;
    int entero;

    gets(auxString);
    largo=strlen(auxString);
    puts(auxString);

    for(int i=0 ; i<largo ; i++){
        if(isdigit(auxString[i])==1 && auxString[i]=='.'){
            continue;
        }else{
            printf("No es numerico");
            break;
        }
    }



    auxFloat=atof(auxString);
    auxInt=auxFloat;

    if(auxFloat-auxInt!=0){
        printf("No es entero");
    }else{
        puts("ooray");
    }



    return 0;
}

char getSexo(ePersona gente[]){

    char sexo;

    printf("Ingrese sexo: ");
    fflush(stdin);
    sexo=getchar();
    sexo=tolower(sexo);

    while(sexo!='m' && sexo!='f'){
        printf("Error. Ingrese sexo: ");
        fflush(stdin);
        sexo=getchar();
        sexo=tolower(sexo);
    }

    return sexo;
}

int getInt(){

    char auxString[30];
    float auxFloat;
    int largo;
    int auxInt;
    int entero;

    gets(auxString);
    largo=strlen(auxString);
    puts(auxString);

    for(int i=0 ; i<largo ; i++){
        if(isdigit(auxString[i])==1 && auxString[i]=='.'){
            continue;
        }else{
            printf("No es numerico");
            break;
        }
    }



    auxFloat=atof(auxString);
    auxInt=auxFloat;

    if(auxFloat-auxInt!=0){
        printf("No es entero");
    }else{
        puts("ooray");
    }

    return entero;

}
