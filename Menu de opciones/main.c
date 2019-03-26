#include <stdio.h>
#include <stdlib.h>

int mostrarMenu();

int main()
{
    char seguir ='s';

    do
    {
        switch(mostrarMenu())
        {
        case 1:
            printf("Opcion alta\n");
            //Llamo a la funcion
            break;
        case 2:
            printf("Opcion baja\n");
            break;
        case 3:
            printf("Opcion modificacion\n");
            break;
        case 4:
            printf("Opcion informes\n");
            break;
        case 5:
            printf("Opcion salir\n");
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        system("pause");

    }
    while(seguir=='s');

    printf("Hello world!\n");
    return 0;
}

int mostrarMenu()
{
    int opcion;

    system("cls");

    printf("*** Menu de Opciones ***\n\n");

    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificacion\n");
    printf("4- Informes\n");
    printf("5- Salir\n");
    printf("\nIngrese opcion: ");

    //Agregar validaciones


    scanf("%d", &opcion);

    return opcion;
}
