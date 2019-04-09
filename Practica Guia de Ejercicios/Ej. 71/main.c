#include <stdio.h>
#include <stdlib.h>
/*71. Una empresa de colectivos tiene 3 líneas de 12 coches cada una.
Por cada viaje el chofer entrega al llegar a fa terminal
una planilla con el número de coche (de 1 a 12) ,
número de línea (de 1 a 3) y la recaudación del viaje.
Las planillas se entregan sin ningún orden.
Se pide informar por pantalla:
La recaudación total por línea de colectivo,
La recaudación total por coche,
La recaudación total general*/

//Pregunta: Como hago para el programa detecte un elemento como 0 si no ingrese ningun dato?
int main()
{

    int coches[2][11]={ {0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0}};
    int recLinea=0;
    int recCoche=0;
    int recTotal=0;
    char rta;
    int i, j;

    do{

        printf("Ingrese nro. de linea: ");
        scanf("%d", &i);

        while(i<0 || i>2){
            printf("Ingrese nro. de linea valido: ");
            scanf("%d", &i);
        }

        printf("Ingrese nro. de coche: ");
        scanf("%d", &j);

        while(j<0 || j>11){
            printf("Ingrese nro. de coche valido: ");
            scanf("%d", &j);
        }

            printf("%d %d", i, j);
        printf("Ingrese recaudacion: ");
        scanf("%d", &coches[i][j]);

        //recLinea[i]+=coches[i][j];

        printf("Para seguir presione s");
        rta=getche();
        rta=tolower(rta);

        system("cls");

    }while(rta=='s');

    printf("Recaudacion por linea: \n");
    for(i=0 ; i<2 ; i++){
            recLinea=0;
        for(int j=0 ; j<11 ; j++){
            recLinea+=coches[i][j];
        }
        printf("Rec linea %d: ", i, recLinea);
    }
    printf("\n\nRecaudacion por coche: \n");
    for(i=0 ; i<2 ; i++){
          for(j=0 ; j<11 ; j++){
            printf("\n\tLinea #%d Coche #%d: $%d", i, j,coches[i][j]);
          }
    }

//    printf("\n\nRecaudacion total: %d", recLinea[0]+recLinea[1]+recLinea[2]);



    return 0;
}
