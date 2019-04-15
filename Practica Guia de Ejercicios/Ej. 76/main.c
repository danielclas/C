#include <stdio.h>
#include <stdlib.h>
#define TAM 2

/**76. Una empresa comercializa 5 artículos en 3 sucursales.
Se debe realizar un programa que presente un menú con las siguientes opciones :
• Carga de datos: se registrará la existencia en depósito informando N° de sucursal, N° de artículo y cantidad
• Venta de artículos: se registran las ventas realizadas informando N° de sucursal, N° de artículo y cantidad vendida.
Se debe verificar que la cantidad vendida no supere la existencia, informando si la venta no se puede realizar por este motivo
• Existencia de mercaderías: listar por pantalla saldos existentes de mercaderías
• Salir del programa**/
typedef struct{

    int sucursal;
    int nroArticulo;
    int cantidad;

}articulos;

int menuOpcion();
void cargarDatos(articulos lista[], int tam);
void ventaArticulos(articulos lista[], int tam);
void mostrar (articulos lista[], int tam, int i);


int main()
{
    articulos lista[TAM];
    int rta, flag1=0;

    do{
        system("cls");
        rta=menuOpcion();
        switch(rta){

            case 1:
                cargarDatos(lista, TAM);
                flag1=1;
                break;
            case 2:
                ventaArticulos(lista, TAM);
                break;
            case 3:
                if(flag1==1){
                    for(int i=0 ; i<TAM ; i++){
                        if(lista[i].nroArticulo){
                          mostrar(lista, TAM, i);
                        }
                    }
                }else{
                printf("\nAun no se han cargado los datos");
                }
                printf("\n");
                system("pause");
                break;
            case 4:
                printf("El programa ha finalizado\n");
                system("pause");
                break;
            default:
                system("cls");
        }

    }while(rta!=4);


    return 0;
}

void cargarDatos(articulos lista[], int tam){

    int sucursalAux;

    printf("Carga de datos");
    for(int i=0 ; i<tam ; i++){

        system("cls");
        printf("\n\tIngrese N° de sucursal: ");
        scanf("%d", &sucursalAux);

        while(sucursalAux<1 || sucursalAux>3){
        printf("\n\tIngrese N° de sucursal valida: ");
        scanf("%d", &sucursalAux);
        }

        lista[i].sucursal=sucursalAux;

        printf("\n\tIngrese N° de articulo: ");
        scanf("%d", &lista[i].nroArticulo);

        printf("\n\tIngrese cantidad: ");
        scanf("%d", &lista[i].cantidad);
    }
}

int menuOpcion(){

    int rta;

    printf("Opciones: ");
    printf("\n\t1- Carga de datos");
    printf("\n\t2- Venta de articulos");
    printf("\n\t3- Existencia de mercaderias");
    printf("\n\t4- Salir");
    printf("\n\nOpcion: ");
    scanf("%d", &rta);

    return rta;
}

void ventaArticulos(articulos lista[], int tam){

    int auxCant, auxSucursal, auxArt, flag1=0;

    system("cls");
    printf("Registro de venta");
    printf("\n\n\tIngrese N° de sucursal: ");
    scanf("%d", &auxSucursal);
    while(auxSucursal<1 || auxSucursal>3){
    printf("\tIngrese N° de sucursal valida: ");
    scanf("%d", &auxSucursal);
    }

    printf("\nArticulos existentes en esta sucursal: ");
    for(int i=0 ; i<tam ; i++){
        if(lista[i].sucursal==auxSucursal){
            mostrar(lista, TAM, i);
            flag1=1;
        }
    }
    if(flag1=0){
        printf("\nNo se ingresaron articulos en esa sucursal");
    }

    printf("\n\tIngrese N° de articulo: ");
    scanf("%d", &auxArt);

    printf("\tIngrese cantidad vendida: ");
    scanf("%d", &auxCant);

    for(int i=0 ; i<tam ; i++){
        if(lista[i].nroArticulo==auxArt && lista[i].sucursal==auxSucursal){
            if(lista[i].cantidad>=auxCant){
             lista[i].cantidad-=auxCant;
            }else{
            printf("\nNo hay stock suficiente para realizar la venta\n");
            system("pause");
            }
        }
    }
}

void mostrar (articulos lista[], int tam, int i){

    printf("\nSucursal: %d\tN° Articulo: %d\tCant. existente: %d", lista[i].sucursal, lista[i].nroArticulo, lista[i].cantidad);

}

