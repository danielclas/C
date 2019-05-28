#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f=fopen("numeros.txt", "r");
    int num1, num2, num3, num4, cant;

    if(f==NULL){
        printf("Null");
        exit(1);
    }

    while(!feof(f)){

        cant=fscanf(f, "%d,%d,%d,%d\n", &num1, &num2, &num3, &num4);
        printf("%d,%d,%d,%d\n", num1, num2, num3, num4);

        if(cant<4){
            if(feof(f)){
                break;
            }else{
                printf("Problemas para leer el archivo");
            }
        }
    }

    fclose(f);

    return 0;
}
