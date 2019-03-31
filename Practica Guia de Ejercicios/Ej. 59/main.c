#include <stdio.h>
#include <stdlib.h>
//Leer 20 números enteros positivos, indicar cuál es el mayor y en qué orden fue leído (a que elemento pertenece). Mostrar el vector completo

int main()
{
    int nro[21]={0,55,220,11,33,68,59,54,12,35,69,56,12,15,13,11,10,1,7,9};
    int max;
    int maxJ;

    for(int j=0;j<20;j++){

        if(j==0){
            max=nro[0];
            maxJ=1;
        }
        else{
            if(nro[j]>max){
                max=nro[j];
                maxJ=j;
            }
        }
        printf("\nElemento %d: %d", j+1, nro[j]);
    }

    printf("\n\nElemento mas grande #%d: %d\n\n", maxJ+1, max);

    return 0;
}
