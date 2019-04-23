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
    char cadena[20];

    printf("Ingrese un entero: ");
    entero=getInt();
    puts(entero);



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
