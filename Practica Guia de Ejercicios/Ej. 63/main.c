#include <stdio.h>
#include <stdlib.h>
/*De los 100 empleados de una fábrica se registra:
número de legajo (coincide con el número de índice),
edad y salario.
Se pide: Ingresar los datos correlativamente,
Calcular la edad promedio informando número de legajo
de los empleados cuya edad supere el promedio.
*/
int main()
{
    int legajo[100];
    int edad[100];
    int edadSuma=0;
    float edadPromedio;
    float salario;

    //Inicializo i=90 para probar ejercicio mas facilmente

    for(int i=90 ; i<100 ; i++){

            legajo[i]=i+1;//Para que el elemento 0 sea el legajo 1

            printf("\nLegajo #%d. Ingrese edad: ", legajo[i]);
            scanf("%d", &edad[i]);

            edadSuma+=edad[i];//Calculo suma de todas las edades para luego sacar promedio

            printf("\nIngrese salario: ");
            scanf("%f", &salario);

            system("cls");


    }

    edadPromedio=edadSuma/10;

    for(int i=90; i<100; i++){

        if(edad[i]>edadPromedio){
            printf("\nLegajo %d supera el promedio. Edad: %d", legajo[i], edad[i]);
        }
    }


    return 0;
}
