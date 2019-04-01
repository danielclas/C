#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
/*67. Cargar un vector de 20 elementos.
Una vez terminada la carga y por medio de un menú de opciones realizar
lo siguiente:
a- Ingresar un número y mostrar en qué
posición dentro del vector se encuentra
b- Ingresar la posición del vector
y mostrar el número que se encuentra en esa posición
Si la posición es incorrecta
o el número no se encuentra se debe mostrar un mensaje de error.
*/
int main()
{
    float nro[20];
    char rta;
    int i;
    int flagNro=0;
    float j;

    for( i=0 ; i<20 ; i++){
            printf("\nIngrese un numero posicion #%d: ", i+1);
            scanf("%f", &nro[i]);
        }

    system("cls");

    do{
        printf("Opciones: ");
        printf("\n\tA- Ingresar un nro. para averiguar la posicion");
        printf("\n\tB- Ingresar la posicion y mostrar el numero");
        printf("\n\nIngrese una opcion: ");
        rta=getche();
        rta=tolower(rta);
        system("cls");

        switch(rta){

            case 'a':
                printf("Ingrese un numero para buscar: ");
                scanf("%f", &j);
                for(i=0; i<20 ; i++)
                {
                    if(nro[i]==j){
                        printf("\nEl nro. ingresado (%.2f) esta en la posicion %d ", j, i+1);
                        flagNro=1;
                    }
                }
                if(flagNro==0){
                        printf("El nro. ingresado no esta en ningun vector");
                }
                break;
            case 'b':
                printf("Ingrese la posicion en el vector: ");
                scanf("%d", &i);
                if(i<0 && i>19){
                    printf("\nLa posicion ingresada es incorrecta.");
                }else{
                    printf("Posicion #%d, numero: %.2f", i, nro[i-1]);
                }
                /*
                Se muestra i+1 para que el usuario ingresa de la opcion 1 al 20,
                y no de la 0 a la 19.
                */
                break;
            default:
                break;
        }


    }while(rta!='a' && rta!='b');

    printf("\n\nPrograma finalizado");

    return 0;
}
