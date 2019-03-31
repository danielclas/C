#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
/*Un profesor de matemática de un establecimiento educativo
registra de cada alumno N° de legajo y promedio.
Según el promedio desea saber cuántos alumnos aprobaron (promedio mayor o igual a 7),
cuantos rinden en diciembre (promedio menor a 7 y mayor o igual a 4)
 y cuantos rinden examen en marzo (promedio menor a 4).
 Además desea conocer el N° de legajo del alumno con mejor promedio
*/
int main()
{
    int legajo;
    int contAprobaron=0;
    int contDiciembre=0;
    int contMarzo=0;
    int cont=0;
    int legajoMax;
    float promedio;
    float promedioMax;
    char rta;

    do{

        printf("Ingrese el legajo del alumno: ");
        scanf("%d", &legajo);

        printf("\nIngrese el promedio: ");
        scanf("%f", &promedio);

        if(promedio>=7){
            contAprobaron++;
        }
        else{
            if(promedio>=4){
                contDiciembre++;
            }
            else{
                contMarzo++;
            }
        }

        if(cont==0){
            promedioMax=promedio;
            legajoMax=legajo;
        }
        else{
            if(promedio>promedioMax){
                promedioMax=promedio;
                legajoMax=legajo;
            }
        }

        printf("\nIngresar otro alumno? Presione s\n");
        rta=getche();
        rta=tolower(rta);
        cont++;
        system("cls");

    }while(rta=='s');

    printf("\nAprobaron: %d", contAprobaron);
    printf("\nA diciembre: %d", contDiciembre);
    printf("\nA marzo: %d", contMarzo);
    printf("\nLegajo del alumno con mayor promedo: %d", legajoMax);


    return 0;
}
