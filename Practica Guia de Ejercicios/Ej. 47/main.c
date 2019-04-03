#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*De las 20 participantes de un concurso de belleza
se van registrando de uno en uno los siguientes datos:
Apellido y Nombre, Puntos por inteligencia, Puntos
por Cultura general, Puntos por Belleza.
Se necesita informar por pantalla :
 Apellido y nombre de la concursante de mayor puntaje general,
Puntaje acumulado por todas las participantes en Cultura general,
en Inteligencia y en Belleza
*/
int main()
{
    char apell[30];
    char nombre[30];
    char apellTotalMax[30];
    char nombreTotalMax[30];
    int part;
    float puntosInt;
    float puntosCult;
    float puntosBell;
    float puntosTotal=0;//Para comparar entre participantes y averiguar mayor
    float puntosAcum;//Para mostrar puntajes acumulados por todos los participantes
    float puntosTotalMax;

    for(part=1;part<5;part++)
    {
        printf("--Participante %d--", part);

        printf("\nNombre: ");
        scanf("%s", nombre);

        printf("\nApellido: ");
        scanf("%s", apell);

        printf("\nPuntos inteligencia: ");
        scanf("%f", &puntosInt);

        printf("\nPuntos cultura general: ");
        scanf("%f", &puntosCult);

        printf("\nPuntos bellez: ");
        scanf("%f", &puntosBell);

        puntosTotal=puntosBell+puntosCult+puntosInt;
        puntosAcum+=puntosTotal;

        if(part==1)
        {
            puntosTotalMax=puntosTotal;
            strcpy(nombreTotalMax, nombre);
            strcpy(apellTotalMax, apell);
        }
        else
        {
            if(puntosTotal>puntosTotalMax)
            {
                puntosTotalMax=puntosTotal;
                strcpy(nombreTotalMax, nombre);
                strcpy(apellTotalMax, apell);
            }
        }

        system("cls");

    }

    printf("\nMayor puntaje general: %s %s", nombreTotalMax, apellTotalMax);
    printf("\nPuntaje acumulado por todas las participantes: %.2f", puntosAcum);

    return 0;
}
