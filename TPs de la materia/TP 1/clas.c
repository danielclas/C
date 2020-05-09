#include <stdio.h>
#include <stdlib.h>
#include "clas.h"

int mostrarMenu (int flagX, int flagY, int flagMostrar, float nro1, float nro2)
{
    int opcion;//Opcion que el usuario selecciona del menu
    float x;//Valor de X que recibe de funcion main
    float y;//Valor de Y que recibe de funcion main

    printf("\n------ Menu de opciones -----\n");
    if(flagX==0){
      printf("\n1- Ingresar primer operando. A=X");
    }//Si no se ingreso X, entonces muestra el menu por defecto.
    //Si X fue ingresado, entonces la muestra.
    //El programa decide si mostrarla o no a traves de la bandera recibida desde main.
    else{
        x=nro1;
        printf("\n1- Primer operando: %.2f", x);
    }

    if(flagY==0){
       printf("\n2- Ingresar segundo operando. B=Y");
    }//Si no se ingreso Y, entonces muestra el menu por defecto.
    //Si Y fue ingresado, entonces la muestra.
    //El programa decide si mostrarla o no a traves de la bandera recibida desde main.
    else{
        y=nro2;
        printf("\n2- Segundo operando: %.2f", y);
    }

    //Si ambas X e Y fueron ingresadas, entonces el programa reemplaza esos valores cuando muestra el menu.
    if(flagX==1 && flagY==1){
        printf("\n\n3- Calcular resultados: \n");
        printf("\n\tA) Calcular la suma (%.2f + %.2f)", x, y);
        printf("\n\tB) Calcular la resta (%.2f - %.2f)", x, y);
        printf("\n\tC) Calcular la division (%.2f / %.2f)", x, y);
        printf("\n\tD) Calcular la multiplicacion (%.2f * %.2f)", x, y);
        printf("\n\tD) Calcular los factoriales (%.2f! y %.2f!)", x, y);
    }
    else{//Si ambas no fueron ingresadas, entonces muestra el menu por defecto
        printf("\n\n3- Calcular resultados: \n");
        printf("\n\tA) Calcular la suma (A + B)");
        printf("\n\tB) Calcular la resta (A - B)");
        printf("\n\tC) Calcular la division (A / B)");
        printf("\n\tD) Calcular la multiplicacion (A * B)");
        printf("\n\tD) Calcular los factoriales (A! y B!)");
    }

    /*A traves de flagMostrar, el programa decide si mostrar los resultados calculados o no.
    flagMostrar es recibida de main, y es solo activada si fueron ingresados ambos operandos, y ademas si las operaciones fueron calculadas
    (es decir, que el usuario haya elegido la opcion 3).
    */
    if(flagMostrar==0){
        printf("\n\n4- Informar resultados: \n");
        printf("\n\tA) El resultado de A+B es: r");
        printf("\n\tB) El resultado de A-B es: r");
        printf("\n\tC) El resultado de A/B es: r");
        printf("\n\tD) El resultado de A*B es: r");
        printf("\n\tE) El factorial de A es: r1 y El factorial de B es: r2 ");
    }
    else{
        printf("\n\n4- Informar resultados: \n");
        printf("\n\tA) El resultado de %.2f + %.2f es: %.2f", x, y, sumar(x, y));
        printf("\n\tB) El resultado de %.2f - %.2f es: %.2f", x, y, restar(x, y));

        //Si el numero divisor (y) es 0, el programa informa que no es posible dividir por 0.
        if(y==0){
            printf("\n\tC) No es posible dividir por cero");
        }
        else{
           printf("\n\tC) El resultado de %.2f / %.2f es: %.2f", x, y, dividir(x, y));
        }

        printf("\n\tD) El resultado de %.2f * %.2f es: %.2f", x, y, multiplicar(x, y));

        //Si X o Y son menores a 0, entonces no se calcula el factorial respectivo
        if(x<0){
            printf("\n\tE) No es posible calcular factorial de %.2f (numero negativo)", x);
        }
        else{
            printf("\n\tE) El factorial de %.2f es: %.0lf ", x, factorial(x));
        }

        if(y<0){
            printf("\n\t   No es posible calcular factorial de %.2f (numero negativo)", y);
        }
        else{
            printf("\n\t   El factorial de %.2f es: %.0lf ", y, factorial(y));
        }
    }

    printf("\n\n5- Salir");
    printf("\n\nIngrese una opcion: ");

    scanf("%d", &opcion);

    return opcion;

}

float conseguirNro()
{
    float nro;

    scanf("%f", &nro);

    return nro;
}

float sumar (float nro1, float nro2)
{
    return nro1+nro2;
}

float restar (float nro1, float nro2)
{
    return nro1-nro2;
}

float dividir (float nro1, float nro2)
{

    return nro1/nro2;

}

float multiplicar (float nro1, float nro2)
{
    return nro1*nro2;
}

long double factorial (float nro1)
{
    long double fact;

    fact=nro1;

    if(nro1==0 || nro1==1){
        fact=1;
    }
    else{
        for(nro1-=1;nro1>0;nro1--){
            fact*=nro1;
            }
    }

    return fact;
}
