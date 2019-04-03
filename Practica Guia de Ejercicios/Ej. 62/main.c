#include <stdio.h>
#include <stdlib.h>
/*62.
Leer dos vectores A y B de dimensión 100.
Generar un tercer vector C de 100 elementos donde la
componente C[ i ] sea igual al mínimo valor de A[ i j y B[ i ].
 Imprimir los tres vectores*/
int main(){

    //Uso vectores tamaño 10 y hardcodeo para testear
    int vector1[10]={100,550,2,66,180,49,20,10,6,2};
    int vector2[10]={55,42,108,990,26,33,87,511,20,11};
    int vector3[10];

    for (int i=0 ; i<10 ; i++){

        if(vector1[i]<vector2[i]){
            vector3[i]=vector1[i];
        }else{
            vector3[i]=vector2[i];
        }

    }

    system("cls");

    printf("\tA\tB\tC");
    for(int i=0; i<10 ; i++){

        printf("\n\t%d\t%d\t%d", vector1[i], vector2[i], vector3[i]);

    }



    return 0;
}
