#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/

    ///Hardcodeo tres empleados
    Employee* emp1=employee_newParametros("1234", "Juan", "234", "25000");
    Employee* emp2=employee_newParametros("2232", "Julia", "100", "15000");
    Employee* emp3=employee_newParametros("3324", "Juana", "334", "20000");
    Employee* emp4=employee_newParametros("5555", "Sofia", "200", "23000");
    /**

    ESTA MAL EL CONSTRUCTOR



    **/

    ///Muestro la cantidad de elementos dentro de la lista vacia
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    ///Agrego un empleado a la lista
    if(ll_add(listaEmpleados, emp1)==0){
        printf("Se ha agregado el empleado con exito\n");
    }

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_add(listaEmpleados, emp2)==0){
        printf("Se ha agregado el empleado con exito\n");
    }

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_add(listaEmpleados, emp3)==0){
        printf("Se ha agregado el empleado con exito\n");
    }

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_set(listaEmpleados, 1, emp4)==0){
        printf("Se ha agregado el empleado con exito\n");
    }

    if(ll_push(listaEmpleados, 1, emp2)==0){
        printf("Se ha agregado el empleado con exito\n");
    }

    mostrarEmpleado((Employee*)ll_get(listaEmpleados, 1));

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    printf("------------------------------------");

  /*  for(int i=0 ; i<ll_len ; i++){
        mostrarEmpleado((Employee*)ll_get(listaEmpleados, i));
    }

    printf("\n\nOrdeno la lista por sueldo\n\n");

    ll_sort(listaEmpleados, ordenarPorSueldo, 0);

    for(int i=0 ; i<ll_len ; i++){
        mostrarEmpleado((Employee*)ll_get(listaEmpleados, i));
    }

    ll_sort(listaEmpleados, ordenarPorSueldo, 1);

    for(int i=0 ; i<ll_len ; i++){
        //mostrarEmpleado((Employee*)ll_get(listaEmpleados, i));
    }

    ll_sort(listaEmpleados, ordenarPorHoras, 0);

    for(int i=0 ; i<ll_len ; i++){
        //mostrarEmpleado((Employee*)ll_get(listaEmpleados, i));
    }*/

    return 0;
}
