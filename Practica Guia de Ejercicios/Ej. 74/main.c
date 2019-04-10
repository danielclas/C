#include <stdio.h>
#include <stdlib.h>
#define TAM 2
De los 40 micros de una empresa de corta distancia se registra :
N° de micro, Recaudación, Km recorridos
La carga se realiza a medida que llegan los micros ala terminal.
Se pide un listado impreso de todos los micros con su recaudación
y los Km. recorridos en toda una jornada de trabajo


//Utilizo 10 micros en total para probar
void cargarMicros (float micros[][10]);
void mostrarMicros (float micros[][10]);
float sumarKMs (float micros[][10]);
int main()
{
    float micros[TAM][10]={{0}};
    int contMicros=0;

    do{

        cargarMicro(micros);

        cont++;

    }while(contMicros<10);


    return 0;
}

void cargarMicro (float micros[][10]){

    int index;

    printf("Nro de micro: ");
    scanf("%d", &index-1);

    printf("Recaudacion: ");
    scanf("%f", &micros[0][index]);

    printf("KMs recorridos: ");
    scanf("%f", &micros[1][index]);

}

void mostrarMicros(float micros[][10]){





}
