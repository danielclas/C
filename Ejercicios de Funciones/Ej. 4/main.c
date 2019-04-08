#include <stdio.h>
#include <stdlib.h>
/*4- Cargar un vector de 20 elementos con n�meros reales.
Usar una funci�n para ver la cantidad de
veces que se repite un n�mero en el vector.
La funci�n debe tener el siguiente prototipo
intbuscar(float num)
Donde num es el n�mero a buscar dentro del vector.
La funci�n retorna un int que indica la cantidad
de veces que se encontr� num.
De no encontrarse el n�mero se debe retornar 0 (cero) e informar
desde el main que el n�mero no se encontr�.
*/
int buscar (float vector[], float num);
int main()
{

    float vector[20]={0,22.5,11,10,7,89,4,7,11,2,3,4,55,66,1,22,35,89,22.5, 4};
    float num;

    printf("Ingrese el nro a buscar: ");
    scanf("%f", &num);

    if(buscar(vector, num)==0){
        printf("No se encontro el numero");
    }else{
        printf("El numero se encontro %d cantidad de veces", buscar(vector, num));
    }

    return 0;
}

int buscar (float vector[], float num){

    int i;
    int contBuscar=0;

    for(i=0 ; i<20 ; i++){
        if(num==vector[i]){
            contBuscar++;
        }
    }

    return contBuscar;

}

