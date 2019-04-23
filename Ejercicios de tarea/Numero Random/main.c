#include <stdio.h>
#include <stdlib.h>

int main()
{
    char rta=1;

    srand(1000);

    do{


        puts("Ingresar otro? 1=s");
        fflush(stdin);
        getchar(rta);

    }while(rta=='1');

    return 0;
}
