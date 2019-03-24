#include <stdio.h>
#include <stdlib.h>
/*
Por teclado se ingresa el valor hora de un empleado.
 Posteriormente se ingresa el nombre del empleado, la antigüedad y la cantidad de horas trabajadas en el mes.
Se pide calcular el importe a cobrar teniendo en cuenta que el total
resulta de multiplicar el valor hora por la cantidad de horas trabajadas,
hay que sumarle la cantidad de años trabajados multiplicados por $30,
y al total de todas esas operaciones restarle
el 13% en concepto de descuentos. Imprimir el recibo correspondiente
con el nombre, la antigüedad, el valor hora, el total a cobrar en bruto,
el total de descuentos y el valor neto a cobrar

*/
int main()
{
    float valorHora;
    float horasTrabajadas;
    char nombre[30];
    float total;
    float aniosTrabajados;
    float antiguedad;
    float bruto;
    float descuento;
    float neto;

    printf("Ingrese el valor de hora del empleado: ");
    scanf("%f", &valorHora);

    printf("\nIngrese el nombre del empleado: ");
    scanf("%s", nombre);

    printf("\nIngrese la cantidad de horas trabajadas en el mes: ");
    scanf("%f", &horasTrabajadas);

    printf("\nIngrese años trabajados: ");
    scanf("%f", &aniosTrabajados);

    system("cls");

    total=valorHora*horasTrabajadas;
    antiguedad=aniosTrabajados*30;

    bruto=total+antiguedad;
    descuento=bruto*0.13;
    neto=bruto*0.87;

    printf("\nNombre del empleado: %s", nombre);
    printf("\nAnios trabajados: %.1f", aniosTrabajados);
    printf("\nValor por hora: %.2f", valorHora);
    printf("\nTotal a cobrar en bruto: %.2f", bruto);
    printf("\nTotal descuento: %.2f", descuento);
    printf("\nTotal bruto: %.2f", neto);


    return 0;
}
