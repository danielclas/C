#include <stdio.h>
#include <stdlib.h>
/*

En una empresa se carga por teclado los siguientes datos:
 nombre del empleado,
 nacionalidad (A argentino, E -extranjero),
 estudios cursados (1- primaria, 2 - secundario, 3 - universitario)
 y antigüedad.

 Se pide emitir un listado con aquellos empleados que sean extranjeros,
tengan estudios universitarios y tengan una antigüedad igual o mayor a 20 años
 y por último indicar cuantos son y qué porcentaje son respecto del total de empleados de la empresa

*/
int main()
{
    char nombre[30];
    char nacionalidad;
    char respuesta;
    float porcentaje;
    float antiguedad;
    int estudios;
    int contadorEmpleados=0;
    int contadorEnunciado=0;

    do
    {
        printf("Ingrese el nombre del empleado: ");
        scanf("%s", nombre);

        printf("\nNacionalidad: Ingrese A para argentino y E para extranjero");
        nacionalidad=getche();
        nacionalidad=toupper(nacionalidad);

        while(nacionalidad!='A' && nacionalidad!='E')
        {
            printf("\nNacionalidad: Ingrese A para argentino y E para extranjero");
            nacionalidad=getche();
            nacionalidad=toupper(nacionalidad);
        }

        printf("\nIngrese estudios cursados. 1 para primario, 2 para secundario y 3 para universitario");
        scanf("%d", &estudios);

        while(estudios!=1 && estudios!=2 && estudios!=3)
        {
            printf("\nIngrese estudios cursados. 1 para primario, 2 para secundario y 3 para universitario");
            scanf("%d", &estudios);
        }

        printf("\nIngrese la antiguedad: ");
        scanf("%f", &antiguedad);

        if(estudios==3 && antiguedad>=20 && nacionalidad=='E')
        {
            contadorEnunciado++;
        }

        contadorEmpleados++;


        printf("\nIngresar otro dato? Presione s");
        respuesta=getche();
        respuesta=tolower(respuesta);

        system("cls");

    }while(respuesta=='s');


    //En lugar de listado solo muestro cuantos cumplea las condiciones

    porcentaje=(contadorEnunciado*100)/contadorEmpleados;

    printf("\nCantidad de empleados que son Extranjeros, universitarios, antiguedad mas de 20: %d", contadorEnunciado);
    printf("\nPorcentaje del total de empleados: %.2f", porcentaje);



    return 0;
}
