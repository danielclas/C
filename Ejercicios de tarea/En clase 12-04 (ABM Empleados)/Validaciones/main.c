#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct{

    int legajo;
    int edad;
    char sexo;
    char nombre[20];

}ePersona;

char getSexo();
int getEdad();
int getLegajo(ePersona gente[]);
int getInt();
void agregarGente(ePersona gente[]);
void mostrarPersona(ePersona gente[]);
void mostrarGente(ePersona gente[]);

int main()
{
    ePersona gente[TAM];
    int rta;
    int entero;

    do{

    entero=getInt();
    puts(entero);


    printf("1 o 2");
    scanf("%d", &rta);

    }while(rta==1);



    return 0;
}

char getSexo(){

    char sexo;

    do{
        printf("Ingrese sexo (F o M): ");
        fflush(stdin);
        sexo=getchar();
        sexo=tolower(sexo);
    }while(sexo!='m' && sexo!='f');

    return sexo;
}

int getInt(){

    char auxString[30];
    float auxFloat;
    int flagInt=0, flagNum=1;
    int largo;
    int entero;

    do{
        printf("Ingrese: ");
        gets(auxString);
        largo=strlen(auxString);
        puts(auxString);

        if(auxString[0]=='.' || auxString[largo-1]=='.'){
            flagNum=0;
        }else{
             for(int i=0 ; i<largo ; i++){
                if(isdigit(auxString[i])==0 && auxString[i]!='.'){
                    flagNum=0;
                    break;
                }
            }
        }

        if(flagNum==1){
            auxFloat=atof(auxString);
            entero=auxFloat;

            if(auxFloat-entero!=0){
                flagInt=1;
            }
        }

    }while(flagInt==0);

    return entero;

}

void agregarGente(ePersona gente[]){

    for(int i=0 ; i<TAM ; i++){
        gente[i].sexo=getSexo();
        gente[i].edad=getEdad();
    }
}

int getEdad(){

    int edad;

    do{
        printf("Ingrese edad: ");
        edad=getInt();
    }while(edad<0);

    return edad;

}
