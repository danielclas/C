#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"


void getIngreso(ePersona gente[], int indice){

    puts("Dia: ");
    gente[indice].ingreso.dia=getDia();
    puts("Mes: ");
    gente[indice].ingreso.mes=getMes();
    puts("Anno: ");
    gente[indice].ingreso.anno=getAnno();

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

        for(int i=0 ; i<len ; i++){
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


int getEdad(){

    int edad;

    printf("Ingrese edad: ");
    fflush(stdin);
    edad=getInt();

    while(edad<0){
        printf("Error. Ingrese nuevamente: ");
        fflush(stdin);
        edad=getInt();
    }

    return edad;

}

int getLegajo(){

    int legajo;

    legajo=getInt();

    while(legajo<0){
        printf("Error. Ingrese nuevamente: ");
        legajo=getInt();
    }

    return legajo;

}

void getNombre(ePersona gente[], int indice){

    char nombre[50];
    int len;
    int flagOK;

    gets(nombre);
    fflush(stdin);
    len=strlen(nombre);

    do{
        flagOK=1;

        for(int i=0 ; i<len ; i++){
            if(isalpha(nombre[i])==0){
                flagOK=0;
                break;
            }
        }

        if(flagOK==0){
            puts("Error. Ingrese nuevamente: ");
            fflush(stdin);
            gets(nombre);
        }

    }while(flagOK==0);

    strcpy(gente[indice].nombre, nombre);

}

int getDia(){

    int dia;

    dia=getInt();

    while(dia<1 || dia>31){
        puts("Error. Ingrese nuevamente: ");
        dia=getInt();
    }

    return dia;

}

int getMes(){

    int mes;

    mes=getInt();

    while(mes<1 || mes>12){
        puts("Error. Ingrese nuevamente: ");
        mes=getInt();
    }

    return mes;
}

int getAnno(){

    int anno;

    anno=getInt();

    while(anno<0){
        puts("Error. Ingrese nuevamente: ");
        anno=getInt();
    }

    return anno;

}

float getSueldo(){

    float sueldo;

    sueldo=getFloat();

    while(sueldo<0){
        puts("Error. Ingrese nuevamente: ");
        sueldo=getFloat();
    }

    return sueldo;

}

float getFloat(){

    char auxiliar[50];
    int len;
    int flagOK;
    float flotante;

    gets(auxiliar);
    fflush(stdin);
    len=strlen(auxiliar);

    do{

        flagOK=1;

        for(int i=0 ; i<len ; i++){
            if(auxiliar[0]=='-' || auxiliar[i]=='.'){
                continue;
            }else{
                if(isdigit(auxiliar[i])!=1){
                    flagOK=0;
                    break;
                }
            }
        }

        if(flagOK==1){
            flotante=atof(auxiliar);
        }else{
            printf("Error. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxiliar);
        }

    }while(flagOK==0);

    return flotante;

}

void agregarPersona(ePersona gente[], int indice){

    printf("Ingrese legajo: ");
    gente[0].legajo=getLegajo();
    printf("Ingrese nombre: ");
    fflush(stdin);
    getNombre(gente, 0);
    printf("Ingrese sueldo: $");
    gente[0].sueldo=getSueldo();
    printf("Ingrese sexo: ");
    fflush(stdin);
    gente[0].sexo=getSexo();
    printf("Ingrese edad: ");
    fflush(stdin);
    gente[0].edad=getEdad();
    printf("Fecha de ingreso: ");
    fflush(stdin);
    getIngreso(gente, 0);

}

void mostrarPersona(ePersona persona){

    printf("Legajo\tNombre\tSueldo\tSexo\tEdad\tIngreso");
    printf("\n%d\t%s\t%.2f\t%c\t%d\t%02d / %02d / %d", persona.legajo, persona.nombre, persona.sueldo, persona.sexo, persona.edad, persona.ingreso.dia, persona.ingreso.mes, persona.ingreso.anno);

}

