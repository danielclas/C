#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vec;

    vec=(int*)malloc(sizeof(int)*5);

    if(vec==NULL){
        printf("No se consiguio memoria");
        exit(1);
    }

    for(int i=0 ; i<5 ; i++){
        printf("Ingrese un numero: ");
        scanf("%d", vec+i);
    }

    for(int i=0 ; i<5 ; i++){
        printf("%d", *(vec+i));
    }

    free(vec);

    return 0;
}
