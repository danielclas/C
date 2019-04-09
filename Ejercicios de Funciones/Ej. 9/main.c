#include <stdio.h>
#include <stdlib.h>
#define TAM 5
/*Se toman de 20 personas el nombre, peso y altura.
Se pide calcular el porcentaje de personas cuyo producto
peso por altura se encuentra entre 50.3 y 80.5.
El peso y la altura deben ser validados por una función.
*/
float porcentajeProducto(float pesos[], float alturas[]);
void pedirPesoYAltura (float pesos[], float alturas[]);

int main()
{
    float pesos[TAM];
    float alturas[TAM];

    pedirPesoYAltura(pesos, alturas);
    printf("Cantidad de gente cuyo producto peso/altura se encuentra entre 50.3 y 80.5: %.2f", porcentajeProducto(pesos, alturas));

    return 0;
}

void pedirPesoYAltura(float pesos[], float alturas[]){

    for(int i=0 ; i<TAM ; i++){
        printf("\nIngrese el peso: ");
        scanf("%f", &pesos[i]);
        printf("Ingrese la altura: ");
        scanf("%f", &alturas[i]);
    }
}

float porcentajeProducto (float pesos[], float alturas[]){

    float porcentaje;
    int contSupera=0;

    for(int i=0 ; i<TAM ; i++){

        if(pesos[i]*alturas[i]>50.3 && pesos[i]*alturas[i]<80.5){
            contSupera++;
        }
    }

    porcentaje=(float)(contSupera*100)/TAM;


    return porcentaje;
}
