#include <stdio.h>
#include <stdlib.h>
/*69. Se registran de los 50 medicamentos
que existen en una farmacia el código de producto ,
el precio y la cantidad en existencia. Se pide:
a- Listado ordenado por código de producto
b- Código del medicamento de precio más bajo
*/

void ordenarMenAMay (int aOrdenar[], int variable[], int tam);

int main()
{

    //Uso vectores tamaño 5 para testear
    int codigo[5];
    int precio[5];
    int cantidad[5];


    for(int i=0; i<5; i++){

        printf("Medicamento #%d: ", i+1);
        printf("\n\n\tIngrese codigo: ");
        scanf("%d", &codigo[i]);
        printf("\tIngrese precio: ");
        scanf("%d", &precio[i]);
        printf("\tIngrese cantidad: ");
        scanf("%d", &cantidad[i]);
        system("cls");

    }

    ordenarMenAMay(codigo, precio, 5);
    printf("Listado ordenado por codigo de producto\n\n");

    for(int i=0; i<5 ; i++){

        printf("\n%d", codigo[i]);
    }

    ordenarMenAMay(precio, codigo, 5);
    printf("\n\nCodigo del medicamento precio mas bajo: %d", codigo[0]);

    return 0;
}

void ordenarMenAMay (int aOrdenar[], int variable[], int tam){

    int auxInt;

    for(int i=0; i<tam-1 ; i++){

        for(int j=i+1; j<tam; j++){

            if( aOrdenar[i] < aOrdenar[j]){

                auxInt = aOrdenar[i];
                aOrdenar[i] = aOrdenar[j];
                aOrdenar[j] = auxInt;

                auxInt = aOrdenar[i];
                aOrdenar[i] = aOrdenar[j];
                aOrdenar[j] = auxInt;

            }
        }
    }

}
