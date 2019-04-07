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
int main()
{

    int coches[2][11];
    int recLinea;
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

        printf("Ingrese recaudacion: ");
        scanf("%d", &coches[i][j]);

        printf("Para seguir presione s");
        rta=getche();
        rta=tolower(rta);

        system("cls");

    }while(rta=='s');

    printf("Recaudacion total por linea de colectivo: ");
    for(i=0 ; i<3 ; i++){
          recLinea=0;
          for(j=0 ; j<11 ; j++){
             if(coches[i][j]!=NULL){
                recLinea+=coches[i][j];
             }
          }
          printf("\nLinea #%d: $%d", i, recLinea);
    }



    return 0;
}
