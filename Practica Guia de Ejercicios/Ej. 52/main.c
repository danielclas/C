#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
/*52. En un club se registran de uno en uno los siguientes
datos de sus socios: Número de socio, Apellido y
nombre (N° de socio para codificar en C), Edad,
Tipo de deporte que practica (1 tenis, 2 paddle).

Diseñar en un programa que permita emitir por pantalla
cuantos socios practican tenis y cuantos paddle y el
promedio de edad de los jugadores de cada deporte
*/
int main()
{
    char apell[30];
    char nombre[30];
    char rta;
    int deporte;
    int edad;
    int edadTenis;
    int edadPaddle;
    int nroSocio;//Valido que sea de 10000 a 19999
    int totalTenis=0;
    int totalPaddle=0;
    float promedioTenis;
    float promedioPaddle;

    do{
        printf("Ingrese nro. de socio: ");
        scanf("%d", &nroSocio);

        while(nroSocio<10000 || nroSocio>19999){
            printf("Ingrese nro. de socio valido: ");
            scanf("%d", &nroSocio);
        }

        printf("Ingrese nombre: ");
        scanf("%s", nombre);

        printf("Ingrese apellido: ");
        scanf("%s", apell);

        printf("Ingrese edad: ");
        scanf("%d", &edad);

        while(edad<0){
            printf("Ingrese edad valida: ");
            scanf("%d", &edad);
        }

        printf("Ingrese deporte. 1 para tenis, 2 para paddle: ");
        scanf("%d", &deporte);

        while(deporte!=1 && deporte!=2){
            printf("Ingrese un deporte valido. 1 para tenis, 2 para paddle: ");
            scanf("%d", &deporte);
        }

        if(deporte==1){
            totalTenis++;
            edadTenis+=edad;
        }
        else{
            totalPaddle++;
            edadPaddle+=edad;
        }

        printf("Ingresar otro socio? Presione s, u otra tecla obtener los resultados");
        rta=getche();
        rta=tolower(rta);

        system("cls");

    }while(rta=='s');

    promedioPaddle=edadPaddle/totalPaddle;
    promedioTenis=edadTenis/totalTenis;//Variables total corresponden a contador

    printf("\nCantidad de socios que practican paddle: %d", totalPaddle);
    printf("\nPromedio de edad de jugadores de paddle: %.2f", promedioPaddle);
    printf("\nCantidad de socios que practican tenis: %d", totalTenis);
    printf("\nPromedio de edad de jugadores de tenis: %.2f", promedioTenis);

    return 0;
}
