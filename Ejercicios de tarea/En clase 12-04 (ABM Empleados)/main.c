#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define TAM 9
#define TAMSECT 5

typedef struct{

    int dia;
    int mes;
    int anno;

}eFecha;

typedef struct{

    int ID;
    char desc[20];

}eSector;

typedef struct{

    int legajo;
    int idSector;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha ingreso;
    int ocupado;

}eEmpleado;

///FALTAN VALIDACIONES!!

int inicializarEmpleados (eEmpleado vec[], int tam);
void inicializarSectores (eSector sectores[], int tamSect);
int buscarLibre (eEmpleado vec[], int tam);
int buscarEmpleado (eEmpleado vec[], int tam, int legajoABuscar);
void bajaEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void modificarEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void mostrarEmpleado (eEmpleado emp, eSector sectores[], int sector);
void mostrarEmpleados (eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void agregarEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void ordenarParametro(eEmpleado vec[], int tam, int parametro, int orden);
void ordenarEmpleados(eEmpleado vec[], int tam);
void hardCodearEmpleados(eEmpleado vec[], int tam);
void hardCodearSectores(eSector sectores[], int tam);
void informesPorAnnio(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void mostrarSectores(eSector sectores[], int tam);
int elegirSector (eSector sectores[], int tam);
int averiguarSector(eEmpleado emp, eSector sectores[], int tamSect);
void swapearEmp(int i, int j, eEmpleado vec[]);
void seleccionarYMostrarSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void totalEmpPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void sectorMaxEmp(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void sueldoMaxPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void sueldosPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void printEmpPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void cargarSectores(eSector sectores[], int tamSect);
void menuInformes();
int menuOpcion();

int main()
{
    eEmpleado lista[TAM];
    eSector sectores[TAMSECT];
    int rta;

    inicializarEmpleados(lista, TAM);
    inicializarSectores(sectores, TAMSECT);
    //hardCodearSectores(sectores, TAMSECT);
    //hardCodearEmpleados(lista, TAM);

    do{
        system("cls");
        rta=menuOpcion();

        switch(rta){

        case 0:
            cargarSectores(sectores, TAMSECT);
            break;
        case 1:
            agregarEmpleado(lista, sectores, TAM, TAMSECT);
            system("cls");
            break;
        case 2:
            bajaEmpleado(lista, sectores, TAM, TAMSECT);
            break;
        case 3:
            modificarEmpleado(lista, sectores, TAM, TAMSECT);
            break;
        case 4:
            ordenarEmpleados(lista, TAM);
            break;
        case 5:
            mostrarEmpleados(lista, sectores, TAM, TAMSECT);
            break;
        case 6:
            menuInformes(lista, sectores, TAM, TAMSECT);
            break;
        case 7:
            printf("\nEl programa ha finalizado\n");
            system("pause");
            break;
        default:
                system("cls");
        }
    }while(rta!=7);

        return 0;
}

void modificarEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int legajoModificar;
    int indexBuscar;
    int campoModificar;

    if(vec[0].ocupado==0){
        printf("Aun no se han ingresado empleados\n");
        system("pause");
    }else{

        printf("\n\nIngrese el legajo del empleado a modificar: ");
        scanf("%d", &legajoModificar);

        indexBuscar=buscarEmpleado(vec, TAM, legajoModificar);

        if(indexBuscar==-1){
            printf("\nNo existe ninguna empleado con ese legajo\n");
            system("pause");
        }else{
            do{
                system("cls");
                printf("\nEmpleado seleccionado legajo %d", legajoModificar);
                mostrarEmpleado(vec[indexBuscar], sectores, averiguarSector(vec[indexBuscar], sectores, tamSect));
                printf("\n\nIngrese el dato a modificar: ");
                printf("\n\n\t1-Nombre\n\t2-Sueldo\n\t3-Sexo\n\t4-Fecha de Ingreso\n\t5-Sector\n\t6- Terminar modificacion");
                printf("\n\nOpcion: ");
                scanf("%d", &campoModificar);

                switch(campoModificar){
                    case 1:
                        printf("\n\tIngrese nuevo nombre: ");
                        fflush(stdin);
                        gets(vec[indexBuscar].nombre);
                        break;
                    case 2:
                        printf("\n\tIngrese nuevo sueldo: ");
                        scanf("%f", &vec[indexBuscar].sueldo);
                        break;
                    case 3:
                        printf("\n\tIngrese nuevo sexo: ");
                        fflush(stdin);
                        vec[indexBuscar].sexo=tolower(getchar());
                        break;
                    case 4:
                        printf("\n\tIngrese nueva fecha de ingreso: ");
                        printf("\n\tDia: ");
                        scanf("%d", &vec[indexBuscar].ingreso.dia);
                        printf("\tMes: ");
                        scanf("%d", &vec[indexBuscar].ingreso.mes);
                        printf("\tAño: ");
                        scanf("%d", &vec[indexBuscar].ingreso.anno);
                        break;
                    case 5:
                         vec[indexBuscar].idSector=elegirSector(sectores, tamSect);
                        break;
                    case 6:
                        printf("\n\tModificacion terminada\n");
                        system("pause");
                        break;
                    default:
                        system("cls");
                        break;
                }

            }while(campoModificar!=6);

            }
        }
}

void bajaEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int legajoBaja;
    int indexBuscar;
    char confirmoBaja;

    if(vec[0].ocupado==0){
        printf("Aun no se han ingresado empleados\n");
        system("pause");
    }else{
        printf("\nIngrese el legajo a dar de baja: ");
        scanf("%d", &legajoBaja);

        indexBuscar=buscarEmpleado(vec, TAM, legajoBaja);

        if(indexBuscar==-1){
                printf("\nNo existe ningun empleado con ese legajo\n");
                system("pause");
        }else{
            printf("\nEmpleado con legajo %d: ", legajoBaja);
            mostrarEmpleado(vec[indexBuscar], sectores, averiguarSector(vec[indexBuscar], sectores, tamSect));

            printf("\n\nConfirmar la baja de este empleado? S/N: ");
            fflush(stdin);
            confirmoBaja=tolower(getchar());

            if(confirmoBaja=='n'){
                printf("\nBaja de empleado cancelada\n");
                system("pause");
            }else{
                printf("\nBaja de empleado confirmada\n");
                system("pause");
                vec[indexBuscar].ocupado=0;
            }
        }
    }


}

void ordenarEmpleados(eEmpleado vec[], int tam){

    int parametro;
    int orden;

    if(vec[0].ocupado==0){
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }else{
        printf("\nElija un parametro por el cual ordenar: ");
        printf("\n\n\t1- Legajo\n\t2- Sexo\n\t3- Sueldo\n\t4- Nombre\n\t5- Fecha de Ingreso");
        printf("\n\n\tOpcion: ");
        scanf("%d", &parametro);
        printf("\nElija el orden: ");
        printf("\n\t1- Creciente\n\t2- Decreciente");
        printf("\n\n\tOpcion: ");
        scanf("%d", &orden);
    }

    ordenarParametro(vec, TAM, parametro, orden);
}

void swapearEmp(int i, int j, eEmpleado vec[])
{
    eEmpleado auxEmp;

    auxEmp=vec[i];
    vec[i]=vec[j];
    vec[j]=auxEmp;

}
void ordenarParametro(eEmpleado vec[], int tam, int parametro, int orden){


for(int i=0 ; i<tam-1 ; i++){

    for(int j=i+1 ; j<tam ;j++){

    switch(parametro){
        case 1:
            switch(orden){
            case 1:
                  if(vec[i].legajo>vec[j].legajo){
                    ///Legajo creciente
                    swapearEmp(i, j, vec);
                    }
                break;
            case 2:
                  if(vec[i].legajo<vec[j].legajo){
                    ///Legajo decreciente
                    swapearEmp(i, j, vec);
                    }
                break;
                }
            break;
        case 2:
                switch(orden){
            case 1:
                if(vec[i].sexo>vec[j].sexo){
                    ///Sexo creciente
                      swapearEmp(i, j, vec);
                    }
            case 2:
                if(vec[i].sexo<vec[j].sexo){
                    ///Sexo decreciente
                     swapearEmp(i, j, vec);
                    }
                }
                break;
        case 3:
            switch(orden){
                case 1:
                    if(vec[i].sueldo>vec[j].sueldo){
                    ///Sueldo creciente
                        swapearEmp(i, j, vec);
                        }
                break;
            case 2:
                if(vec[i].sueldo<vec[j].sueldo){
                    ///Sueldo decreciente
                       swapearEmp(i, j, vec);
                }
                break;
            }
            break;
        case 4:
            switch(orden){
            case 1:
                if((stricmp(vec[i].nombre, vec[j].nombre)==1)){
                    ///Nombre creciente
                    swapearEmp(i, j, vec);
            }
            break;
            case 2:
            if((stricmp(vec[i].nombre, vec[j].nombre)==-1)){
                ///Nombre decreciente
                    swapearEmp(i, j, vec);
                }
            }
            break;
        case 5:
            switch(orden){
            case 1:
                if(vec[i].ingreso.anno>vec[j].ingreso.anno){
                    ///Ingreso creciente
                    swapearEmp(i, j, vec);
                }else{
                    if(vec[i].ingreso.anno==vec[j].ingreso.anno && vec[i].ingreso.mes>vec[j].ingreso.mes){
                        swapearEmp(i, j, vec);
                    }else{
                        if(vec[i].ingreso.anno==vec[j].ingreso.anno && vec[i].ingreso.mes==vec[j].ingreso.mes && vec[i].ingreso.dia>vec[j].ingreso.dia){
                           swapearEmp(i, j, vec);
                        }
                    }
                }
            break;
            case 2:
                if(vec[i].ingreso.anno<vec[j].ingreso.anno){
                    ///Ingreso creciente
                   swapearEmp(i, j, vec);
                }else{
                    if(vec[i].ingreso.anno==vec[j].ingreso.anno && vec[i].ingreso.mes<vec[j].ingreso.mes){
                       swapearEmp(i, j, vec);
                    }else{
                        if(vec[i].ingreso.anno==vec[j].ingreso.anno && vec[i].ingreso.mes==vec[j].ingreso.mes && vec[i].ingreso.dia<vec[j].ingreso.dia){
                          swapearEmp(i, j, vec);
                        }
                    }
                }
            break;
            }
        }

        }
}
}
void agregarEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int legajo;
    int indexLibre;
    int indexMostrar;

    if(buscarLibre(vec, TAM)==-1){
        printf("\nNo hay lugares libres\n");
        system("pause");
    }else{
        indexLibre=buscarLibre(vec, TAM);
        printf("\nIngrese el legajo: ");
        scanf("%d", &legajo);

        if(buscarEmpleado(vec, TAM, legajo)==-1){
     ///Si buscarEmpleado devuelve -1, entonces el empleado no existe. Pido datos
            vec[indexLibre].legajo=legajo;
            printf("\nLegajo: %d", legajo);
            printf("\nNombre: ");
            fflush(stdin);
            gets(vec[indexLibre].nombre);
            printf("Sueldo: $");
            scanf("%f", &vec[indexLibre].sueldo);
            vec[indexLibre].ocupado=1;
            printf("Sexo: ");
            fflush(stdin);
            vec[indexLibre].sexo=getchar();
            printf("Fecha de ingreso: ");
            printf("\n\tDia: ");
            scanf("%d", &vec[indexLibre].ingreso.dia);
            printf("\tMes: ");
            scanf("%d", &vec[indexLibre].ingreso.mes);
            printf("\tAño: ");
            scanf("%d", &vec[indexLibre].ingreso.anno);
            if(sectores[0].ID==0){
                printf("Aun no se han agregado sectores. Modifique luego");
            }else{
                vec[indexLibre].idSector=elegirSector(sectores, tamSect);
            }

            printf("\nEl empleado ha sido registrado por exito\n");
            system("pause");
        }else{
    ///Si es diferente a -1, entonces existe, y el valor devuelto sera el indice con el que muestro
            printf("\nYa hay un empleado con ese legajo\n");
            indexMostrar=buscarEmpleado(vec, TAM, legajo);
            mostrarEmpleado(vec[indexMostrar], sectores, averiguarSector(vec[indexMostrar], sectores, tamSect));
            printf("\n\n");
            system("pause");
        }
      }

}

int menuOpcion(){

    int rta;

    printf("\t***ABM Empleado***");
    printf("\n\n\t0- Cargar sectores");
    printf("\n\t1- Alta empleados");
    printf("\n\t2- Baja empleado");
    printf("\n\t3- Modificar empleado");
    printf("\n\t4- Ordenar");
    printf("\n\t5- Listar");
    printf("\n\t6- Informes");
    printf("\n\t7- Salir");
    printf("\n\n\tIngrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}

int inicializarEmpleados(eEmpleado vec[], int tam){

    int result=-1;

    for(int i=0; i<tam ; i++){
        vec[i].ocupado=0;
        vec[i].idSector=0;
        result=0;
    }

    return result;
}

int buscarLibre(eEmpleado vec[], int tam){

    int indexLibre=-1;

    for(int i=0 ; i<tam ; i++){
        if(vec[i].ocupado==0){
            indexLibre=i;
            break;
        }
    }

    return indexLibre;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajoABuscar){

    int indexEmpleado=-1;

    for(int i=0; i<tam ; i++){
        if(vec[i].legajo==legajoABuscar && vec[i].ocupado==1){
            indexEmpleado=i;
            break;
        }
    }

    return indexEmpleado;
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int sector){

        printf("\n\tLegajo: %d\tNombre: %s\tSueldo: %.2f\tSexo: %c", emp.legajo, emp.nombre, emp.sueldo, emp.sexo);
        printf("\n\tIngreso: %02d/%02d/%d\tSector: %s\n", emp.ingreso.dia, emp.ingreso.mes, emp.ingreso.anno, sectores[sector].desc);

}

void mostrarEmpleados(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int flagMostrar=0;

        for(int i=0 ; i<tam ; i++){
            if(vec[i].ocupado==1){
              mostrarEmpleado(vec[i], sectores, averiguarSector(vec[i], sectores, tamSect));
              flagMostrar=1;
            }
        }

        if(flagMostrar==0){
            printf("\nAun no se han ingresado empleados\n");
        }
        printf("\n\n");
        system("pause");
}

int averiguarSector(eEmpleado emp, eSector sectores[], int tamSect){

    int sector;
    for(int j=0 ; j<tamSect ; j++){
        if(emp.idSector==sectores[j].ID){
                sector=j;
        }
    }
    return sector;
}

void hardCodearEmpleados(eEmpleado vec[], int tam){

    eEmpleado empleados[]={
        {1001,1,"Juan",'m',25000,{2,6,1998},1},
        {1002,3,"Maria",'f',30000,{6,4,1996},1},
        {1003,4,"Lucas",'m',15000,{10,12,2002},1},
        {1004,4,"Belen",'f',20000,{7,1,2010},1},
        {1005,5,"Mario",'m',90000,{6,5,2014},1},
        {1006,1,"Juana",'f',20000,{1,7,1999},1},
        {1007,3,"Daniel",'m',9000,{16,5,2014},1},
        {1008,1,"Kevin",'m',70000,{4,5,2010},1},
        {1009,3,"Claudia",'f',120000,{2,5,2000},1}
            };

    for(int i=0 ; i<tam ; i++){
        vec[i]=empleados[i];
    }

}

void informesPorAnnio(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int annio;
    int flagMostrar=0;

    printf("\n\n\tIngrese el anio a comprar: ");
    scanf("%d", &annio);

    for(int i=0 ; i<tam ; i++){
        if(vec[i].ingreso.anno==annio){
            for(int j=0 ; j<tamSect ; j++){
                    if(vec[i].idSector==sectores[j].ID){
                        mostrarEmpleado(vec[i], sectores, j);
                        flagMostrar=1;
                    }
            }
        }
    }

    if(flagMostrar==0){
        printf("\nNingun empleado ingreso en ese anio\n");
    }

    printf("\n\n");
    system("pause");

}

void hardCodearSectores(eSector sectores[], int tam){

    eSector sectAux[]={{1, "RRHH"},{2, "Ventas"},{3, "Compras"},{4, "Gerencia"},{5, "Calidad"}};

    for(int i=0 ; i<tam ; i++){
        sectores[i]=sectAux[i];
    }

}

void mostrarSectores(eSector sectores[], int tam){

    for(int i=0 ; i<tam ; i++){
        if(sectores[i].ID!=0){
            printf("\n\t%d- %s", sectores[i].ID, sectores[i].desc);
            printf("\n");
        }
    }

}

int elegirSector(eSector sectores[], int tam){

    int idSector;

    printf("\nElija un sector: \n");
    printf("\n\t0- No asignar sector\n");
    mostrarSectores(sectores, tam);
    printf("\nOpcion: ");
    scanf("%d", &idSector);

    return idSector;

}

int opcionesInformes(){

    int opcion;

    printf("Informes: ");
    printf("\n\n\t1- Ingrese sector para ver empleados");
    printf("\n\t2- Ver los empleados por sector");
    printf("\n\t3- Total de empleados por sector");
    printf("\n\t4- El/los sectores con mas empleados");
    printf("\n\t5- Datos de los que mas ganan por sector");
    printf("\n\t6- Averiguar ingresos por año");
    printf("\n\t7- Sueldos totales por sector");
    printf("\n\t8- Volver al menu principal");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void menuInformes(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int opcion;

    if(vec[0].ocupado==0){
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }else{
        do{
            system("cls");
            opcion=opcionesInformes();
            switch(opcion){

            case 1:
                seleccionarYMostrarSect(vec, sectores, tam, tamSect);
                system("pause");
                break;
            case 2:
                printEmpPorSect(vec, sectores, tam, tamSect);
                break;
            case 3:
                totalEmpPorSect(vec, sectores, tam, tamSect);
                break;
            case 4:
                sectorMaxEmp(vec, sectores, tam, tamSect);
                break;
            case 5:
                sueldoMaxPorSect(vec, sectores, tam, tamSect);
                break;
            case 6:
                informesPorAnnio(vec, sectores, tam, tamSect);
                break;
            case 7:
                sueldosPorSect(vec, sectores, tam, tamSect);
                break;
            case 8:
                break;
            default:
                system("cls");
            }

        }while(opcion!=8);
    }

}



void seleccionarYMostrarSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int sectorAMostrar;

    sectorAMostrar=elegirSector(sectores, tamSect);

    for(int i=0 ; i<tam ; i++){
        if(sectorAMostrar==vec[i].idSector){
            mostrarEmpleado(vec[i], sectores, sectorAMostrar-1);
        }
    }
}

void printEmpPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    printf("Empleados por sector");
    for(int i=0 ; i<tamSect ; i++){
        printf("\n%s:\n", sectores[i].desc);
        for(int j=0 ; j<tam ; j++){
            if(sectores[i].ID==vec[j].idSector && vec[j].ocupado!=0){
                mostrarEmpleado(vec[j], sectores, i);
            }
        }
    }
    system("pause");
}

void totalEmpPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int cont;

    for(int i=0 ; i<tamSect ; i++){
            cont=0;
        for(int j=0 ; j<tam ; j++){
            if(sectores[i].ID==vec[j].idSector){
                cont++;
            }
        }
    printf("\n%s: %d empleado(s)", sectores[i].desc, cont);
    }
    system("pause");
}

void sectorMaxEmp(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int cont, max;

    for(int i=0 ; i<tamSect ; i++){
            cont=0;
        for(int j=0 ; j<tam ; j++){
            if(sectores[i].ID==vec[j].idSector){
                cont++;
            }
        }
        if(i==0){
            max=cont;
        }else{
            if(cont>max){
            max=cont;
            }
        }
    }

    printf("Sector(es) con mas empleados: \n");
    for(int i=0 ; i<tamSect ; i++){
            cont=0;
        for(int j=0 ; j<tam ; j++){
            if(sectores[i].ID==vec[j].idSector){
                cont++;
            }
        }
        if(cont==max){
            printf("%s\n", sectores[i].desc);
        }
    }

    system("pause");

}

void sueldoMaxPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    float sueldoMax;
    int indexMax;

    for(int i=0 ; i<tamSect ; i++){
        if(sectores[i].ID==0){
            continue;
        }else{
            sueldoMax=0;
            printf("%s, sueldo maximo: ", sectores[i].desc);
            indexMax=-1;
            for(int j=0 ; j<tam ; j++){
                if(vec[j].sueldo>sueldoMax && vec[j].idSector==sectores[i].ID){
                    sueldoMax=vec[j].sueldo;
                    indexMax=j;
                }
            }
            if(indexMax!=-1){
               mostrarEmpleado(vec[indexMax], sectores, i);
            }else{
                printf("\n\tSin empleados asignados\n");
            }
        }
    }
    printf("\n \n");
    system("pause");
}

void inicializarSectores (eSector sectores[], int tamSect){

    for(int i=0; i<tamSect ; i++){
        sectores[i].ID=0;
        strcpy(sectores[i].desc, "Sin sector asignado");
    }

}

void cargarSectores(eSector sectores[], int tamSect){

    char rta;
    int i;

    do{
        for(int j=0 ; j<tamSect ; j++){
            if(sectores[j].ID==0){
                sectores[j].ID=j+1;
                i=j;
                break;
            }
        }

        printf("\nSector %d, ingrese descripcion: ", i+1);
        fflush(stdin);
        gets(sectores[i].desc);
        printf("\nIngresar otro sector? S/N: ");
        rta=getchar();
        rta=tolower(rta);

    }while(rta=='s');

}

void sueldosPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    float acum;

    for (int i=0 ; i<tamSect ; i++){
        acum=0;
        if(sectores[i].ID!=0){
            for(int j=0 ; j<tam ; j++){
                if(vec[j].idSector==sectores[i].ID){
                    acum+=vec[j].sueldo;
                }
            }
        printf("\nSector %s, sueldos totales: %.2f", sectores[i].desc, acum);
        }
    }

    system("pause");


}

