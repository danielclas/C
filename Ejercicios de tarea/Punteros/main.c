#include <stdio.h>
#include <stdlib.h>


void funcionModificar(int **p, int *q);
void f1(int vec[], int tam);
void f2(int vec[], int tam);
void f3(int* vec, int tam);
void f4(int* vec, int tam);

int main()
{
    int x=5;
    int y=10;
    int* q;
    int vec[]={5,10,15,20,25};

    q=&x;

    printf("  -  %d %d  -  ", x, y);
    funcionModificar(&q, &y);
    printf("%d  %d  \n", x, y);

    f1(vec, 5);
    printf("\n");
    f2(vec, 5);
    printf("\n");
    f3(&vec, 5);
    printf("\n");
    f4(vec, 5);

    return 0;
}

void funcionModificar(int **p, int *q){

    **p=10;
    *q=50;

}

void f1(int vec[], int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d-", vec[i]);
    }

}

void f2(int vec[], int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d-", *(vec+i));
    }

}

void f3(int* vec, int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d-", vec[i]);
    }

}

void f4(int* vec, int tam){

    for(int i=0 ; i<tam ; i++){
        printf("%d-", *(vec+i));
    }

}
