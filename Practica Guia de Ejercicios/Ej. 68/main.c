#include <stdio.h>
#include <stdlib.h>
/*68. Un restaurante que dispone de 50 mesas,
 necesita llevar cuenta de las ventas diarias.
Para ello cada vez que una mesa es ocupada
se registra el número de mesa y el valor de lo que van consumiendo.
Una vez que se cierra el local se deben obtener los siguientes resultados

a- Ingresar un consumo
b- Venta total del día
c- Indicar cuales fueron las mesas que no se ocuparon en todo el día.
d- Listado ordenado por venta que muestre Nro de mesa Venta
*/
int menu ();
void ordenarVentas(float mesas[], int tam);

int main()
{
    float mesas[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Preguntar como inicializar vector por defecto en 0!
    int rta;
    float ventaTotal=0;


    do{

        rta=menu();
        switch(rta){

            int i;
            float consumo;

            case 1:
                system("cls");
                printf("\n\nEn qué mesa desea ingresar un consumo?: ");
                scanf("%d", &i);
                printf("\n\nIngrese el valor del consumo: ");
                scanf("%f", &consumo);
                if(mesas[i]==0){
                    mesas[i]=consumo;
                }else{
                    mesas[i]+=consumo;
                }
                printf("\n\n\n");
                system("pause");
                system("cls");
                break;
            case 2:
                for(i=0 ; i<50 ; i++){

                    if(mesas[i]!=0){
                         ventaTotal+=mesas[i];
                    }
                }
                printf("\n\nVenta total del día: %.2f", ventaTotal);
                printf("\n\n\n");
                system("pause");
                system("cls");
                break;
            case 3:
                printf("\n\nLas mesas que no fueron ocupadas son: \n");
                for(i=0; i<50; i++){

                    if(mesas[i]==0){

                        printf("\nMesa %d", i);
                    }
                }
                printf("\n\n\n");
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                ordenarVentas(mesas, 50);
                printf("Listado ordenado: ");
                printf("\n\nMesa || Ventas\n");
                for(i=0; i<50; i++)
                {
                    printf("\n   %d     %.2f", i, mesas[i]);
                }
                printf("\n\n\n");
                system("pause");
                system("cls");
                break;
            case 5:
                printf("El programa ha finalizado.\n\n");
                printf("\n\n\n");
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                break;
        }

    }while(rta!='5');

    return 0;
}

int menu ()
{
    int opcion;

    printf("\n\n----Opciones----\n\n");

    printf("\t1- Ingresar un consumo");
    printf("\n\t2- Venta total del dia");
    printf("\n\t3- Mesas no ocupadas");
    printf("\n\t4- Listado ordenado de mesas por venta");
    printf("\n\t5- Salir");
    printf("\n\n\t Opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void ordenarVentas (float mesas[], int tam){

    float auxFloat;

    for(int i=0; i<tam-1 ; i++){

        for(int j=1; j<tam; j++){

            if( mesas[i] < mesas[j]){

                auxFloat = mesas[i];
                mesas[i] = mesas[j];
                mesas[j] = auxFloat;
            }

        }
    }

}
