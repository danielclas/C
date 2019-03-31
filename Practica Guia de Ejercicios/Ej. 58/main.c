#include <stdio.h>
#include <stdlib.h>
//Leer 10 elementos de un vector de enteros y mostrar su contenido
int main()
{

    int nro[11]={0,5,10,15,20,25,30,35,40,45,50};

    for(int j=0;j<11;j++){
        printf("\nElemento %d: %d", j+1, nro[j]);
    }

    return 0;
}
