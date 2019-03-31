#include <stdio.h>
#include <stdlib.h>
/*66. De los 30 empleados de una fábrica se registra la edad, el sexo y el legajo. Terminado el ingreso se pide conocer:
 La edad promedio de los empleados de la fábrica.
 El legajo y sexo de la persona de mayor edad.
 Cuántas mujeres nacieron en el año 1978.
*/

int main()
{

    int legajo[30];
    int legajoMayor;
    int edad[30];
    int edadSuma=0;
    int edadMayor;
    float edadPromedio;
    int cont1978=0;
    char sexo[30];
    char sexoMayor;

    for(int i=0; i<30 ; i++){

        printf("Ingrese la edad del empleado #%d: ", i+1);
        scanf("%d", &edad[i]);

        printf("\nIngrese el legajo del empleado #%d: ", i+1);
        scanf("%d", &legajo[i]);

        printf("\nIngrese el sexo (f o m) del empleado #%d: ", i+1);
        fflush(stdin);
        scanf("%c", &sexo[i]);

        edadSuma+=edad[i];

        while(sexo[i]!='m' && sexo[i]!='f'){

            printf("\nIngrese sexo valido (f o m) del empleado #%d: ", i+1);
            fflush(stdin);
            scanf("%c", &sexo[i]);
        }

        system("cls");

        if(i==0){
            edadMayor=edad[i];
            legajoMayor=legajo[i];
            sexoMayor=sexo[i];
        }
        else{
            if(edad[i]>edadMayor){
                edadMayor=edad[i];
                legajoMayor=legajo[i];
                sexoMayor=sexo[i];
            }
        }

        if(2019-edad[i]==1978 && sexo[i]=='m'){
            cont1978++;
        }
    }

    edadPromedio=edadSuma/30;

    printf("\nEdad promedio: %.2f", edadPromedio);
    printf("\nMayor edad, legajo #%d, sexo %c", legajoMayor, sexoMayor);
    printf("\nMujeres que nacieron en 1978: %d", cont1978);


    return 0;
}
