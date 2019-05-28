#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int numeros[]={3,2,4,5,2,6,5,4,7,1,9,3};
    FILE* f;
    int k=0;

    f=fopen("numeros.txt", "w");

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<4 ; j++){
            if(j==3){
                fprintf(f, "%d\n", numeros[k]);
            }else{
                fprintf(f, "%d,", numeros[k]);
            }
            k++;

        }
    }


    printf("OK");
    return 0;

}
