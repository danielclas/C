#include <stdio.h>
#include <stdlib.h>
/*70. Inicializar a cero una matriz de 6 filas por 5 columnas.
Cargar valores enteros en un elemento determinado,
para lo cual se debe informar número de fila y de columna
y luego ingresar el valor a cargar. Mostrar fa matriz por filas y fuego por columnas.
*/
int main()
{

    int matriz[6][5];

    for(int i=0 ; i<6 ; i++){
        for(int j=0 ; j<5 ; j++){
            printf("Ingrese un entero en posicion fila #%d columna #%d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("#0\t#1\t#2\t#3\t#4\t");
    for(int i=0 ; i<6 ; i++){
            printf("\n");
        for(int j=0 ; j<5 ; j++){
            printf("\t%d", matriz[i][j]);
        }
    }


    return 0;
}
