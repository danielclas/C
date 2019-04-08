#include <stdio.h>
#include <stdlib.h>
/*72. Una empresa financiera tiene 100 clientes numerados de 1 a 100.
 Por cada transacción se registra :
N° de cliente
Código de transacción:
1. Depósito
2. Extracción
3. Comisiones deducidas
4. Intereses acreditados
Monto de la operación
No se conoce la cantidad de transacciones que se realizan.
Se desea:
Emitir un listado con la siguiente información:
N° De Cliente Total Depósitos
Total Extracciones Total Comisiones Total Intereses Saldo
El programa pide al usuario los datos de que #cliente quiere conocer
*/
int funcionMenu();
int menuTransacciones();
void recorrerTransacciones(float trans[][101], int j);
float averiguarSaldo (float trans[][101], int j);

int main()
{

    float trans[4][101]={{0}};
    float transAux=0;
    int rta, i, j;

    do{
        system("cls");
        rta=funcionMenu();

       switch(rta){

        case 1:
            printf("Ingrese el nro de cliente 1-100: ");
            scanf("%d", &j);
            i=menuTransacciones();
            printf("Ingrese el monto de la transaccion :");
            scanf("%.2f", &transAux);
            trans[i][j]+=transAux;
            system("cls");
            break;
        case 2:
            printf("Ingrese el nro de cliente para averiguar transacciones: ");
            scanf("%d", &j);
            recorrerTransacciones(trans, j);
            system("pause");
            break;
        case 3:
            printf("\n\nEl programa ha finalizado\n\n");
            break;
        default:
            system("cls");
            break;
       }
    }while(rta!=3);

    return 0;
}

int funcionMenu(){

    int rta;

    printf("Opciones: ");
    printf("\n\t1- Ingresar datos de un cliente");
    printf("\n\t2- Conocer datos de un cliente");
    printf("\n\t3- Salir del programa");
    printf("\n\nIngrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}

int menuTransacciones(){

    int rta;

    printf("Transacciones");
    printf("\n\n\t1- Deposito");
    printf("\n\t2- Extraccion");
    printf("\n\t3- Comisiones deducidas");
    printf("\n\t4- Intereses acreditados");
    printf("\n\nSeleccione: ");
    scanf("%d", &rta);

    return rta;
}

void recorrerTransacciones(float trans[][101], int j){

    printf("\n\nCliente #%d", j);
    printf("\n\n\tTotal depositos: %.2f", trans[1][j]);
    printf("\n\tTotal extracciones: %.2f", trans[2][j]);
    printf("\n\tTotal comisiones deducidas: %.2f", trans[3][j]);
    printf("\n\tTotal intereses acreditados: %.2f", trans[4][j]);
    printf("\n\n\tSaldo: %.2f\n\n", averiguarSaldo(trans, j));

}

float averiguarSaldo (float trans[][101], int j){

    float saldo;

    saldo=trans[1][j]-trans[2][j]-trans[3][j]+trans[4][j];

    return saldo;
}
