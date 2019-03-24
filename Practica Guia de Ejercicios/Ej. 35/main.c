#include <stdio.h>
#include <stdlib.h>
/*Hacer un que imprima los números de 0 al 100,
controlando las filas y las columnas de forma
tal que se visualicen en pantalla todos a la vez
*/
int main()
{
    int nro;

    for(nro=0;nro<101;nro++)
    {
        printf("%d | ", nro);
    }


    return 0;
}
