#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Realizar un programa que lea numeros enteros hasta que se indique
por medio del mensaje CONTINUA? S/N que finaliza el ingreso de datos.
Obtener la suma de los numeros ingresado.
Por medio de una funcion se debe validar el ingreso de opciones.
El prototipo de la funcion es int validaS_N(void)

A la funcion no le ingresan valores, se lee desde el teclado el caracter
y si es uno de los correctos retorna un valor que sera:

    Verdadero si ingreso la letra S
    Falso si ingreso la letra N
Caso contrario  se pide el reingreso del dato hasta que el mismo sea valido.
*/

int validaS_N (void);

int main()
{
    int rta;
    int entero;
    int sumaEnteros=0;

    do{
        printf("Ingrese el entero: ");
        scanf("%d", &entero);

        sumaEnteros+=entero;

        printf("Desea ingresar otro entero? Presione S o N: ");
        rta=validaS_N();

        system("cls");

    }while(rta==1);

    printf("La suma es: %d", sumaEnteros);
    printf("\nPrograma finalizado");


    return 0;
}

int validaS_N (void){

    int rta;
    char respuesta;

    do{
        scanf("%c", &respuesta);
        respuesta=toupper(respuesta);

    }while(respuesta!='S' && respuesta!='N');


    if(respuesta=='S'){
        rta=1;
    }else{
            if(respuesta=='N'){
                rta=0;
            }
    }



    return rta;


}
