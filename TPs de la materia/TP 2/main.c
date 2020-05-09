#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "clas.h"

#define TAM 1000
#define TAMSEC 10

int main()
{
   eEmployee nomina[TAM];
   eSector sectores[TAMSEC];
   int rta;

   inicializarEmpleados(nomina, TAM);
   inicializarSectores(sectores, TAMSEC);

   do{
        system("cls");
        rta=funcionMenu();
        switch(rta){
            case 0:
                cargarSectores(sectores, TAMSEC);
                break;
            case 1:
                agregarEmpleado(nomina, sectores, TAM, TAMSEC);
                break;
            case 2:
                modificarEmpleado(nomina, sectores, TAM, TAMSEC);
                break;
            case 3:
                bajaEmpleado(nomina, sectores, TAM, TAMSEC);
                break;
            case 4:
                menuInformes(nomina, sectores, TAM, TAMSEC);
                break;
            case 5:
                break;
            default:
                system("cls");
        }
   }while(rta!=5);

    return 0;
}

