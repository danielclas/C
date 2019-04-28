#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char cadena[20];

    printf("Ingrese un entero: ");
    entero=getInt();
    printf("%d", entero);

    //entero=getEdad();
    //printf("%d", entero);


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

    char auxiliar[50];
    int len;
    int flagOK;
    int entero;

    gets(auxiliar);
    fflush(stdin);
    len=strlen(auxiliar);

    do{

        flagOK=1;

        for(int i=0 ; auxiliar[i]!='\0' ; i++){
            if(auxiliar[0]=='-'){
                continue;
            }else{
                if(isdigit(auxiliar[i])!=1 || auxiliar[i]=='.'){
                    flagOK=0;
                    break;
                }
            }
        }


        if(flagOK==1){
            entero=atoi(auxiliar);
        }else{
            printf("Error. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxiliar);
        }

    }while(flagOK==0);

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

    printf("Ingrese edad: ");
    edad=getInt();

    while(edad<0){
        printf("Error. Ingrese nuevamente: ");
        edad=getInt();
    }

    return edad;

}
