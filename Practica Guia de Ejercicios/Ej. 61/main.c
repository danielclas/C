#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
/*Una persona desea saber en qué día del mes realizó
más gastos en compras, para ello
ingresa por teclado día a día lo que gastó por día,
 cargando un vector definido en memoria.
 Puede haber varias o ninguna compra para un determinado día. Informar cual fue el día de mayor gasto
*/

int main()
{
    float gasto;//Se sobreescribe cada vez que el usuario ingresa un gasto
    float gastoDiario;//Acumulador de los gastos de ese dia
    float gastoDia[31];//Guarda los gastos de los 31 dias
    float gastoMax;//Gasto diario max
    int gastoMaxDia;//Dia del gasto diario max
    char rta;

    for(int dia=0;dia<30;dia++){

            gastoDiario=0;
            do{
                printf("Ingrese el gasto del dia %d: ", dia+1);
                scanf("%f", &gasto);

                gastoDiario+=gasto;

                printf("\nIngresar otro gasto para dia %d? Presione s", dia+1);
                rta=getche();
                rta=tolower(rta);
                system("cls");

            }while(rta=='s');

            gastoDia[dia]=gastoDiario;

            if(dia==0){
                gastoMax=gastoDiario;
                gastoMaxDia=dia;
            }else{
                if(gastoDiario>gastoMax){
                    gastoMax=gastoDiario;
                    gastoMaxDia=dia;
                }
            }

    }

    printf("\nDia de mayor gasto: %d", gastoMaxDia+1);
    printf("\nEl gasto fue de: %.2f\n", gastoMax);




    return 0;
}
