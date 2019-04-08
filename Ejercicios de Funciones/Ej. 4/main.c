#include <stdio.h>
#include <stdlib.h>
/*4- Cargar un vector de 20 elementos con números reales.
Usar una función para ver la cantidad de
veces que se repite un número en el vector.
La función debe tener el siguiente prototipo
intbuscar(float num)
Donde num es el número a buscar dentro del vector.
La función retorna un int que indica la cantidad
de veces que se encontró num.
De no encontrarse el número se debe retornar 0 (cero) e informar
desde el main que el número no se encontró.
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

