#include <stdio.h>
#include <stdlib.h>
/*6- Se desean obtener determinados datos de un examen.
 Para ello se carga el nombre y apellido, la
nota y el legajo de 25 alumnos. Se pide:
 Calcular el porcentaje de aprobados usando una función.
 Por medio de una función mostrar
el nombre y apellido y la nota de los que aprobaron
*/
float porcentajeAprobados (int notas[], int tam);
void mostrarAprobados (char nomApe[][20], int notas[], int tam);

int main()
{
    char nomApe[10][20];
    int notas[10];
    int legajos[10];
    int cont=0;
    int i;

    for(i=0 ; i<10 ; i++){
        printf("Ingrese nombre y apellido: ");
        fflush(stdin);
        gets(nomApe[i]);

        printf("Ingrese nota: ");
        scanf("%d", &notas[i]);

        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);
    }

    printf("Porcentaje de aprobados: %.1f%%", porcentajeAprobados(notas, 10));
    printf("\n\n");
    mostrarAprobados(nomApe, notas, 10);

    return 0;
}

float porcentajeAprobados (int notas[], int tam){

    int contAprobados=0, i;
    float porcentaje;

    for(i=0 ; i<tam ; i++){
        if(notas[i]>=7){
            contAprobados++;
        }
    }

    porcentaje=(float)(contAprobados*100)/tam;

    return porcentaje;

}

void mostrarAprobados (char nomApe[][20], int notas[], int tam){

    int i;

    for(i=0 ; i<tam ; i++){
        if(notas[i]>=7){
                printf("\n%s aprobo con %d", nomApe[i], notas[i]);
        }
    }


}

