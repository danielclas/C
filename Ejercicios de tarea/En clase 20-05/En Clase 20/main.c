#include <stdio.h>
#include <stdlib.h>

int main(){

    int* puntero;

    puntero=(int*)malloc(sizeof(int));
    *puntero=5;

    printf("%d", *puntero);

    free(puntero);

    return 0;

}
