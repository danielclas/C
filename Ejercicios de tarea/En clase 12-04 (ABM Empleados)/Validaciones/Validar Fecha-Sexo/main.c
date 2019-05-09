#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int dia;
    int mes;
    int anno;

}eFecha;

int conseguirPositivo(char mensaje[], char mensajeError[]);
char conseguirSexo(char mensaje[], char mensajeError[]);
void conseguirFecha(eFecha fechas[], int index);

int main()
{
    eFecha fechas[5];
    char sexos[5];

    for(int i=4 ; i<5 ; i++){
        conseguirFecha(fechas, i);
        sexos[i]=conseguirSexo("Ingrese sexo: ", "Sexo invalido. Ingrese nuevamente: ");
    }

    for(int i=4 ; i<5 ; i++){
        printf("%02d/%02d/%d", fechas[i].dia, fechas[i].mes, fechas[i].anno);
        printf("%c", sexos[i]);
    }

    return 0;
}

void conseguirFecha(eFecha fecha[], int index){

    int auxDia;
    int auxMes;
    int auxAnno;

    printf("Ingrese la fecha: ");
    auxDia=conseguirPositivo("Dia: ", "Ingrese dia valido: ");

    while(auxDia<1 || auxDia>31){
       auxDia=conseguirPositivo("Ingrese dia valido: ", "Ingrese dia valido: ");
    }

    auxMes=conseguirPositivo("Mes: ", "Ingrese mes valido: ");

    while(auxMes<1 || auxMes>12){
       auxMes=conseguirPositivo("Ingrese mes valido: ", "Ingrese mes valido: ");
    }

    auxAnno=conseguirPositivo("Anno: ", "Ingrese anno valido: ");

    while(auxAnno<1){
       auxAnno=conseguirPositivo("Ingrese anno valido: ", "Ingrese anno valido: ");
    }

    fecha[index].dia=auxDia;
    fecha[index].mes=auxMes;
    fecha[index].anno=auxAnno;
}


int conseguirPositivo(char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;
    int positivo;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);

    do{

        flagOK=1;
        len=strlen(aux);

        for(int i=0 ; i<len ; i++){
            if(isdigit(aux[i])!=1){
                flagOK=0;
            }
        }

        if(flagOK==0){
            printf("\n%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            positivo=atoi(aux);
        }

    }while(flagOK==0);

    return positivo;

}

char conseguirSexo(char mensaje[], char mensajeError[]){

    char auxChar;

    printf("\n%s", mensaje);
    fflush(stdin);
    auxChar=tolower(getchar());

    while(auxChar!='f' && auxChar!='m'){
        printf("\n%s", mensajeError);
        fflush(stdin);
        auxChar=tolower(getchar());
    }

}
