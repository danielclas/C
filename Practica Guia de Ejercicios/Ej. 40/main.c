#include <stdio.h>
#include <stdlib.h>

/*40. Se ingresa por consola la cantidad de agua caída, en milímetros día a día durante un mes. Se pide
determinar el día de mayor lluvia, el de menor y el promedio
*/
int main()
{
    float mmCaidos;
    float mmCaidosTotal=0;
    float mmCaidosMay;
    float mmCaidosMen;
    float mmCaidosProm;
    int dia;
    int diaMayor=1;
    int diaMenor=1;

    for(dia=1;dia<31;dia++)
    {
        printf("\nIngrese mm caidos el dia %d:  ", dia);
        scanf("%f", &mmCaidos);

        while(mmCaidos<0)
        {
            printf("\nIngrese mm caidos el dia %d, mayor a 0:  ", dia);
            scanf("%f", &mmCaidos);
        }

        mmCaidosTotal+=mmCaidos;

        if(dia==1)
        {
            mmCaidosMay=mmCaidos;
            mmCaidosMen=mmCaidos;
            diaMayor=dia;
            diaMenor=dia;
        }
        else
        {
            if(mmCaidos>mmCaidosMay)
            {
                mmCaidosMay=mmCaidos;
                diaMayor=dia;
            }
            else
            {
                if(mmCaidos<mmCaidosMen)
                {
                    mmCaidosMen=mmCaidos;
                    diaMenor=dia;
                }
            }

        }

    }

    mmCaidosProm=mmCaidosTotal/dia;

    printf("Dia de mayor lluvia: %d", diaMayor);
    printf("Dia de menor lluvia: %d", diaMenor);
    printf("Promedio de mm caidos: %.2f", mmCaidosProm);

    return 0;
}
