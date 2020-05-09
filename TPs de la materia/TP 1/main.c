#include <stdio.h>
#include <stdlib.h>
#include "clas.h"

int main()
{
   float x;//X e Y son las variables a las que el usuario les asginara valor
   float y;
   int flagX=0;//Cambiara a 1 solo cuando a X se le haya asignado un valor a traves de la funcion conseguirNro()
   int flagY=0;//Cambiara a 1 solo cuando a Y se le haya asignado un valor a traves de la funcion conseguirNro()
   int flagOprc=0;
   int flagMostrar=0;//
   /*
   La diferencia entre flagOprc y flagMostrar es que flagOprc es usada para avisarle al usuario mediante un printf que las operaciones fueron calculadas o no.
    Cuando flagOprc sea 1, entonces flagMostrar va a cambiar a 1 y sera enviada a mostrarMenu(), que cambiara los valores de A y B por los
    numeros ingresados.
   */
   int rta;//La respuesta resultante de la opcion que el usuario elija en la funcion mostraMenu()

   do{
    rta=mostrarMenu(flagX, flagY, flagMostrar, x, y);
    switch(rta){
            case 1:
                printf("Ingresar primer operando: ");
                x=conseguirNro();//X sera el valor obtenido por la funcion conseguirNro()
                flagX=1;//Cuando a X se le asigna un valor, la bandera cambia a 1.
                system("cls");
                break;
            case 2:
                printf("Ingresar segundo operando: ");
                y=conseguirNro();//Y sera el valor obtenido por la funcion conseguirNro()
                flagY=1;//Cuando a Y se le asigna un valor, la bandera cambia a 1.
                system("cls");
                break;
            case 3:
               if(flagX==0 || flagY==0){
                    printf("\nPor favor, ingrese ambos operandos antes de hacer las operaciones\n\n");
                    system("pause");
               }//Indica al usuario que si no fueron ingresadas X e Y, no pueden calcularse las operaciones
               else{
                   printf("\nLas operaciones han sido calculadas\n\n");
                   system("pause");
                   flagOprc=1;//Esta bandera se activa cuando las operaciones fueron realizadas. Es local de esta funcion
               }
               system("cls");
                break;
            case 4:
                if(flagOprc==0){
                    printf("\n\nAun no se han realizado las operaciones\n\n");
                    system("pause");
                }//Si las operaciones no fueron realizadas, al seleccionar opcion 4 el usuario es avisado de esto.
                else{
                    flagMostrar=1;
                }//Esta bandera se activa si flagOprc=1, y es enviada a funcionMenu()
                system("cls");
                break;
            case 5:
                system("cls");
                printf("\n\nEl programa ha finalizado.\n\n");
                //Con esta opcion, el usuario sale del programa y es mostrado el mensaje anterior en una pantalla limpia
                break;
            default:
                system("cls");
                break;
        }
    }while(rta!=5);//Solo sale de la iteracion si el usuario elige la opcion 5 (salir)

    return 0;
}



