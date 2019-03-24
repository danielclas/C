#include <stdio.h>
#include <stdlib.h>
/*Introducir una letra por teclado.
Imprimirla cinco veces en filas consecutivas,
pero en cada impresión ir desplazándola 4 columnas a la derecha
*/

int main()
{
    char letra;

    printf("Ingrese una letra: ");
    letra=getche();

    printf("\n%c", letra);
    printf("\n    %c", letra);
    printf("\n        %c", letra);
    printf("\n           %c", letra);
    printf("\n               %c", letra);

    return 0;
}
