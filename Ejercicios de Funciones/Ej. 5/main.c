#include <stdio.h>
#include <stdlib.h>
/*5- Realizar un programa para mostrar en pantalla
un menú de opciones como el siguiente:

1- Ingreso de datos
2- Mostrar
3- Salir
El menú debe ser hecho con una función.
Cuando se elija la opción (dentro de main) se debería llamar
a la función que realice la tarea
correspondiente.
1- Se carga un vector de 30 enteros.
2- Se muestra el vector.
3- Salir del programa.
*/
int menuOpciones();
void cargarVector(int vector[], int tam);
void mostrarVector(int vector[], int tam);
void salirPrograma();

int main()
{
    int rta;
    int vector[10];

    do{
        rta=menuOpciones();

        switch(rta){

        case 1:
            cargarVector(vector, 10);
            system("cls");
            break;
        case 2:
            mostrarVector(vector, 10);
            break;
        case 3:
            salirPrograma();
            break;
        default:
            system("cls");
            break;
        }

    }while(rta!=3);

    return 0;
}

int menuOpciones(){

    int rta;

    printf("\n\t1- Cargar el vector");
    printf("\n\t2- Mostrar el vector");
    printf("\n\t3- Salir");
    printf("\n\nOpcion: ");
    scanf("%d", &rta);

    return rta;

}

void cargarVector(int vector[], int tam){

    int i;

    for(i=0 ; i<tam ; i++){
        printf("Ingrese entero posicion #%d: ", i);
        scanf("%d", &vector[i]);
    }
}

void mostrarVector(int vector[], int tam){

    int i;

    for(i=0 ; i<tam ; i++){
        printf("\nEntero posicion #%d: %d", i, vector[i]);
    }
}

void salirPrograma(){

    printf("\n\nEl programa ha finalizado");
}
