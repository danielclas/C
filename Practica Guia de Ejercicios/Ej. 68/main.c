#include <stdio.h>
#include <stdlib.h>n
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

int main()
{
    int mesas[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Preguntar como inicializar vector por defecto en 0!
    int rta;
    float ventaTotal=0;


    do{
        //system("cls");
        rta=menu();
        switch(rta){

            int i;
            float consumo;

            case 1:
                printf("\n\nEn qué mesa desea ingresar un consumo?: ");
                scanf("%d", &i);
                printf("\n\nIngrese el valor del consumo: ");
                scanf("%f", &consumo);
                if(mesas[i]==0){
                    mesas[i]=consumo;
                }else{
                    mesas[i]+=consumo;
                }
                system("cls");
                break;
            case 2:
                for(i=0 ; i<50 ; i++){

                    if(mesas[i]!=0){
                         ventaTotal+=mesas[i];
                    }
                }
                printf("\n\nVenta total del día: %.2f", &ventaTotal);
                break;
            case 3:
                printf("\n\nLas mesas que no fueron ocupadas son: ");
                for(i=0; i<50; i++){

                    if(mesas[i]==0){

                        printf("\nMesa %d", i);
                    }
                }
                system("cls");

                break;
            case 4:
                break;
            case 5:
                printf("El programa ha finalizado.\n\n");
                break;
            default:
                break;



        }





    }while(rta!='5');


    return 0;
}

int menu ()
{
    int opcion;

    printf("----Opciones----\n\n");

    printf("\t1- Ingresar un consumo");
    printf("\n\t2- Venta total del dia");
    printf("\n\t3- Mesas no ocupadas");
    printf("\n\t4- Listado ordenado de mesas por venta");
    printf("\n\t5- Salir");
    printf("\n\n\t Opcion: ");
    scanf("%d", &opcion);

    return opcion;




}
