#include <stdio.h>
#include <stdlib.h>
/*Leer 20 números enteros positivos.
Mostrar el vector tal como fue ingresado
y luego mostrar el vector ordenado en forma decreciente
*/
int main()
{
    int nro[21]={82,40,15,13,16,88,100,2,0,77,4,81,55,96,23,24,25,27,10,22};

    for(int j=0;j<20;j++){

        printf("\nNumero #%d: %d", j+1, nro[j]);
    }
    printf("\n\nEn orden invertido: \n");
    for(int j=19;j>-1;j--){

        printf("\nNumero #%d: %d", j+1, nro[j]);
    }

    return 0;
}
