#include <stdio.h>
#include <stdlib.h>
#define TAM 2
/*De los 40 micros de una empresa de corta distancia se registra :
N° de micro, Recaudación, Km recorridos
La carga se realiza a medida que llegan los micros ala terminal.
Se pide un listado impreso de todos los micros con su recaudación
y los Km. recorridos en toda una jornada de trabajo

*/
//Utilizo 10 micros en total para probar
void cargarMicros (float micros[][10]);
void mostrarMicros (float micros[][10], int tam);
float sumarKMs (float micros[][10], int tam);

int main()
{
    float micros[TAM][10]={{0}};
    float kmTotales;
    int contMicros=0;

    do{
        cargarMicros(micros);
        contMicros++;
    }while(contMicros<10);

    kmTotales=sumarKMs(micros, 10);
    printf("KM recorridos en total: %.2f", kmTotales);


    return 0;
}

void cargarMicros (float micros[][10]){

    int index, auxIndex;

    printf("Nro de micro (1 a 10): ");
    scanf("%d", &auxIndex);

    while(auxIndex<1 || auxIndex>10){
        printf("Error. Nro. de micro (1 a 10): ");
        scanf("%d", &auxIndex);
    }

    index=auxIndex-1;

    printf("\n\tRecaudacion: ");
    scanf("%f", &micros[0][index]);

    printf("\n\tKMs recorridos: ");
    scanf("%f", &micros[1][index]);

    system("cls");

}

void mostrarMicros(float micros[][10], int tam){

    for(int i=0 ; i<tam ; i++){
        printf("Micro #%d: ", i+1);
        printf("\tRecaudacion: $%.2f\tKMs recorridos: %.2f", micros[0][i], micros[1][i]);
    }

}

float sumarKMs (float micros[][10], int tam){

    float kmTotales=0;

    for(int i=0 ; i<tam ; i++){
        kmTotales+=micros[1][i];
    }

    return kmTotales;
}
