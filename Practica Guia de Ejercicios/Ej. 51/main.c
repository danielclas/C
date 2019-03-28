#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

//51. ídem al anterior agregando en el informe fina
//el costo de la empresa en salarios y el salario promedio

int main()
{
    float porHora;
    float horasTrabajadas;
    float semanal;
    float semanalMax;
    float semanalMin;
    float salariosTotal=0;
    float salariosPromedio;
    int legajo;
    int legajoMax;
    int legajoMin;
    int cont=0;
    char rta;

    do
    {
        printf("Numero de legajo: ");
        scanf("%d", &legajo);

        printf("\nTarifa horaria: ");
        scanf("%f", &porHora);

        printf("\nHoras trabajadas: ");
        scanf("%f", &horasTrabajadas);

        semanal=porHora*horasTrabajadas;
        salariosTotal+=semanal;

        if(cont==0)
        {
            semanalMax=semanal;
            semanalMin=semanal;
            legajoMax=legajo;
            legajoMin=legajo;
        }
        else
        {
            if(semanal>semanalMax)
            {
                semanalMax=semanal;
                legajoMax=legajo;
            }
            else
            {
                if(semanal<semanalMin)
                {
                    semanalMin=semanal;
                    legajoMin=legajo;
                }
            }
        }

        cont++;
        system("cls");

        printf("\nSalario semanal de trabajador %d: $%.2f\n", legajo, semanal);

        system("pause");//Para que muestre el total en una pantalla diferente a pregunta siguiente

        printf("\nCalcular otro salario? Presione s, u otra tecla para salir");
        rta=getche();
        rta=tolower(rta);

        system("cls");

    }while(rta=='s');

    salariosPromedio=salariosTotal/cont;

    printf("\nSe calcularon %d sueldos de empleados\n", cont);
    printf("\nSueldo mayor: %.2f || Legajo: %d\n", semanalMax, legajoMax);
    printf("\nSueldo menor: %.2f || Legajo: %d\n", semanalMin, legajoMin);
    printf("\nGasto total en salarios: %.2f\n", salariosTotal);
    printf("\nPromedio de salarios: %.2f\n", salariosPromedio);

    return 0;
}
