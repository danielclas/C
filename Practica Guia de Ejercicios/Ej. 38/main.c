#include <stdio.h>
#include <stdlib.h>
/*Se registran de los empleados de una empresa
 Número de legajo, sueldo y sexo (1 femenino y 2 masculino).
 Diseñar en un programa que permita informar cuantas mujeres ganan más de á 500
 y cuantos hombres ganan menos de $ 400

*/
int main()
{
    int legajo;
    float sueldo;
    int sexo;
    int contadorMuj=0;
    int contadorHom=0;
    char respuesta;

    do
    {
        printf("\nIngrese nro. de legajo: ");
        scanf("%d", &legajo);

        printf("\nIngrese sueldo: ");
        scanf("%f", &sueldo);

        printf("\nIngrese sexo. 1 para femenino, 2 para masculino: ");
        scanf("%d", &sexo);

        while(sexo!=1 && sexo!=2)
        {
            printf("\nIngrese sexo valido: ");
            scanf("%d", &sexo);
        }

        if(sexo==1 && sueldo>500)
        {
            contadorMuj++;
        }
        else
        {
            if(sexo==2 && sueldo>400)
            {
                contadorHom++;
            }
        }

        printf("\nPara ingresar otro dato presione s: ");
        respuesta=getch();

        system("cls");

    }while(respuesta=='s');

    printf("Mujeres que ganan mas de 500: %d", contadorMuj);
    printf("\nHombres que ganan mas de 400: %d", contadorHom);

    return 0;
}
