#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "clas.h"

#define TAM 1000
#define TAMSEC 10

int funcionMenu(){

    int rta;

    printf("\n\t----Menu de opciones----");
    printf("\n\n\t0- Cargar sectores");
    printf("\n\t1- Altas");
    printf("\n\t2- Modificar");
    printf("\n\t3- Baja");
    printf("\n\t4- Informar:");
    printf("\n\n\t   1- Listado de empleados ordenados alfabeticamente\n\t   por nombre y sector.");
    printf("\n\t   2- Total y promedio de los salarios,\n\t   y cuantos empleados superan el promedio.");
    printf("\n\n\t5- Salir");
    rta=conseguirPositivo("\n\nOpcion: ", "Ingrese opcion valida: ");

    return rta;
}

void inicializarEmpleados (eEmployee nomina[], int tam){

    //Setea a todos los empleados como vacios al princpio del programa
   for(int i=0 ; i<tam ; i++){
        nomina[i].isEmpty=1;
    }

}

int buscarLibre(eEmployee nomina[], int tam){

    int indexLibre=-1;

    //Recorre array de empleados y devuelve el primer indice vacio. Si no lo hay, devuelve -1
    for(int i=0 ; i<tam ; i++){
        if(nomina[i].isEmpty==1){
            indexLibre=i;
            break;
        }
    }

    return indexLibre;

}

int generarId(){

    //Genera y devuelve un entero que sera usado como id, a partir de un static int seteado al princpio del programa
    static int id=1000;

    id++;

    return id;

}

void conseguirNombre(eEmployee nomina[], int index, char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);
    //Pide al usuario nombre usando mensaje recibido como parametro

    do{

        len=strlen(aux);
        flagOK=1;
        for(int i=0 ; i<len ; i++){
            if(isalpha(aux[i])==0){
               flagOK=0;
            }
        }
        //Recorre la cadena y si algun caracter no es alfabetico, la bandera OK es seteada a 0

        if(flagOK==0){
            printf("%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            strlwr(aux);
            aux[0]=toupper(aux[0]);
            strcpy(nomina[index].name, aux);
        }
        //Si la bandera OK es 0, vuelve a pedir con el mensaje de error. Si no, formatea y asigna al nombre del empleado en el indice recibido

    }while(flagOK==0);

}

void conseguirApellido(eEmployee nomina[], int index, char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);
    //Pide al usuario apellido usando mensaje recibido como parametro

    do{

        len=strlen(aux);
        flagOK=1;
        for(int i=0 ; i<len ; i++){
            if(isalpha(aux[i])==0){
               flagOK=0;
            }
        }
        //Recorre la cadena y si algun caracter no es alfabetico, la bandera OK es seteada a 0

        if(flagOK==0){
            printf("%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            strlwr(aux);
            aux[0]=toupper(aux[0]);
            strcpy(nomina[index].lastName, aux);
        }
        //Si la bandera OK es 0, vuelve a pedir con el mensaje de error. Si no, formatea y asigna al apellido del empleado en el indice recibido

    }while(flagOK==0);

}

void agregarEmpleado(eEmployee nomina[], eSector sectores[], int tam, int tamSec){

    int indexLibre=buscarLibre(nomina, tam);
    int idEmp;

    if(indexLibre==-1){
        printf("\nNo hay lugar en el sistema para otro empleado.\n\n");
        system("pause");
    //Si no hay lugares libres, buscarLibre devuelve -1 y se le informa al usuario
    }else{

        system("cls");
        printf("---Agregar empleado---\n");
        idEmp=generarId();
        nomina[indexLibre].id=idEmp;
        printf("\nID: %d\n", idEmp);
        //Si hay libre, se pediran y asignaran los datos correspondientes al empleado en el indice devuelvo por BuscarLibre

        conseguirNombre(nomina, indexLibre, "Nombre: ", "Error, ingrese nombre valido: ");
        conseguirApellido(nomina, indexLibre, "Apellido: ", "Error, ingrese apellido valido: ");
        nomina[indexLibre].salary=conseguirSalario("Salario: $", "Error, ingrese salario valido: $");
        nomina[indexLibre].sector=elegirSector(sectores, tamSec);
        nomina[indexLibre].isEmpty=0;
        //Setea isEmpty en 0 para modificar al empleado como ocupado

        printf("\nCarga de empleado exitosa, presione una tecla para continuar");
        fflush(stdin);
        getch();

    }

}

float conseguirSalario(char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;
    int flagPunto;
    float salario;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);
    //Pide al usuario un flotante/salario usando mensaje recibido como parametro

    do{
        flagPunto=0;
        flagOK=1;
        len=strlen(aux);

        for(int i=0 ; i<len ; i++){
            if(isdigit(aux[i])!=1 && aux[i]!='.'){
                flagOK=0;
            }
            if(aux[i]=='.'){
                flagPunto++;
            }
        }
        //Recorre la cadena y si algun caracter no es digito o un punto, la bandera OK es seteada a 0
        //La bandera flagPunto es aumentada en 1 cada vez que un punto es encontrado
        if(flagPunto>1 || flagOK==0){
            printf("\n%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            salario=atof(aux);
        }
        //Si la bandera OK es 0, vuelve a pedir con el mensaje de error. Si no, formatea (pasa a flotante la cadena aux) y devuelve como float


    }while(flagOK==0);

    return salario;

}

int conseguirPositivo(char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;
    int positivo;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);
    //Pide al usuario un flotante/salario usando mensaje recibido como parametro

    do{

        flagOK=1;
        len=strlen(aux);

        for(int i=0 ; i<len ; i++){
            if(isdigit(aux[i])!=1){
                flagOK=0;
            }
        }
        //Recorre la cadena y si algun caracter no es digito, la bandera OK es seteada a 0

        if(flagOK==0){
            printf("\n%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            positivo=atoi(aux);
        }
        //Si la bandera OK es 0, vuelve a pedir con el mensaje de error. Si no, formatea (pasa a entero la cadena aux) y devuelve como int

    }while(flagOK==0);

    return positivo;

}

int elegirSector(eSector sectores[], int tamSec){

    int idSector;
    int sectoresEnUso=0;

    //Recorre array de sectores para averiguar cuantos estan en uso
    for(int i=0 ; i<tamSec ; i++){
        if(sectores[i].id!=0){
            sectoresEnUso++;
        }
    }

    printf("\n\t0- No asignar sector\n");
    mostrarSectores(sectores, tamSec);
    idSector=conseguirPositivo("Elija un sector: ", "Sector invalido. Intente de nuevo: ");
    //Lista sectores y opcion No asignar sector, y pide al usuario que ingrese uno

    while(idSector<0 || idSector>sectoresEnUso){
       idSector=conseguirPositivo("Sector invalido. Intente de nuevo: ", "Sector invalido. Intente de nuevo: ");
    }
    //Si el sector no es valido o no existe, vuelve a pedirlo

    return idSector;

}

void mostrarSectores(eSector sectores[], int tamSec){

    for(int i=0 ; i<tamSec ; i++){
        if(sectores[i].id!=0){
            printf("\n\t%d- %s", sectores[i].id, sectores[i].name);
            printf("\n");
        }
    }

}

void inicializarSectores(eSector sectores[], int tamSec){

    //Recorre array de sectores y muestra id y descripcion de aquellos que esten activos
    for(int i=0 ; i<tamSec ; i++){
        sectores[i].id=0;
        strcpy(sectores[i].name, "Sin sector asignado");
    }

}

void hardCodearSectores(eSector sectores[], int tamSec){

    eSector sectAux[]={{1, "RRHH"},{2, "Ventas"},{3, "Compras"},{4, "Gerencia"},{5, "Calidad"}};

    //Hardcodea con valores validos un array de sectores existente
    for(int i=0 ; i<tamSec ; i++){
        sectores[i]=sectAux[i];
    }

}

void modificarEmpleado(eEmployee nomina[], eSector sectores[], int tam, int tamSec){

    int idModificar;
    int indexModificar;
    int campoModificar;

    if(hayEmpleados(nomina, tam)){
        printf("\nAun no se han ingresado empleados\n\n");
        system("pause");
    //Si hayEmpleados devuelve 1, ningun empleado esta activo, y se informa
    }else{

        mostrarEmpleados(nomina, sectores, tam, tamSec);
        idModificar=conseguirPositivo("\nIngrese el ID del empleado a modificar: ", "ID invalido. Intente nuevamente: ");
        indexModificar=buscarEmpleado(nomina, tam, idModificar);
        //Si hay al menos un empleado activo, lista los mismos y pide al usuario el id de empleado a modificar

        while(indexModificar==-1){
            idModificar=conseguirPositivo("ID invalido. Intente nuevamente: ", "ID invalido. Intente nuevamente: ");
            indexModificar=buscarEmpleado(nomina, tam, idModificar);
        }
        //Si el id a modificar no existe o esta inactivo, indexModificar sera -1
        do{
            system("cls");
            printf("\nEmpleado seleccionado legajo %d", idModificar);
            printf("\n\n%4s %12s %12s %10s %9s", "ID", "Nombre", "Apellido", "Salario","Sector");
            mostrarEmpleado(nomina[indexModificar], sectores, tamSec);
            printf("\n\nCampos: ");
            printf("\n\n\t1-Nombre\n\t2-Apellido\n\t3-Salario\n\t4-Sector\n\t5- Terminar modificacion");
            campoModificar=conseguirPositivo("\nIngrese campo a modificar: ","Error. Ingrese campo valido: ");
            //Si el empleado existe, muestra el empleado existente y pregunta al usuario que campo quiere modificar

                switch(campoModificar){
                    //Segun el campo elegido, se modifica dicho dato a traves de este switch
                    case 1:
                        conseguirNombre(nomina, indexModificar, "Ingrese nuevo nombre: ", "Ingrese nombre valido: ");
                        break;
                    case 2:
                        conseguirApellido(nomina, indexModificar, "Ingrese nuevo apellido: ", "Ingrese apellido valido: ");
                        break;
                    case 3:
                        nomina[indexModificar].salary=conseguirSalario("Ingrese nuevo salario: $", "Ingrese salario valido: $");
                        break;
                    case 4:
                         nomina[indexModificar].sector=elegirSector(sectores, tamSec);
                        break;
                    case 5:
                        printf("\n\tModificacion terminada\n\n");
                        system("pause");
                        break;
                    default:
                        system("cls");
                        break;
                }

            }while(campoModificar!=5);

        }
}

int buscarEmpleado(eEmployee nomina[], int tam, int idABuscar){

    int indexEmpleado=-1;

    //Recibe un id a buscar y recorre el array de empleados, y cuando lo encuentra, sale de la iteracion y lo devuelve como entero
    //Si el id no es encontrado, devuelve -1
    for(int i=0; i<tam ; i++){
        if(nomina[i].id==idABuscar && nomina[i].isEmpty!=1){
            indexEmpleado=i;
            break;
        }
    }

    return indexEmpleado;
}

void mostrarEmpleado(eEmployee empleado, eSector sectores[], int tamSec){

    //Muestra un solo empleado recibido, con su correspondiente sector
    int indexSector=averiguarSector(empleado, sectores, tamSec);

    printf("\n%d %12s %12s %10.2f %9s", empleado.id, empleado.name, empleado.lastName, empleado.salary, sectores[indexSector].name);


}

int averiguarSector(eEmployee empleado, eSector sectores[], int tamSec){

    int indexSector;

    //Recibe un empleado y recorre el array sectores hasta que el id del empleado concuerde con el de el sector en i
    for(int i=0 ; i<tamSec ; i++){
        if(empleado.sector==sectores[i].id){
            indexSector=i;
            break;
        }
    }

    return indexSector;
    //Devuelve el indice del sector encontrado

}

void mostrarEmpleados(eEmployee nomina[], eSector sectores[], int tam, int tamSec){

    //Si no hay empleados existentes o activos, se informa al usuario
    if(hayEmpleados(nomina, tam)){
        printf("Aun no se han ingresado empleados");
    }else{
         printf("\n%4s %12s %12s %10s %9s \n", "ID", "Nombre", "Apellido", "Salario","Sector");
        for(int i=0 ; i<tam ; i++){
            if(nomina[i].isEmpty!=1){
                mostrarEmpleado(nomina[i], sectores, tamSec);
            }
        }
    }
    //Si hay empleados activos, a traves de mostrarEmpleado muestra a todos los elementos del array de empleados
    printf("\n");
}

int hayEmpleados(eEmployee nomina[], int tam){

    int empEmpty=1;

    //Recorre array de empleados y si encuentra uno solo activo, deja de iterar y devuelve un 0
    //Si recorrio todo el array y no hay empleados activos, devuelve 1
    //Esta configurado de esta manera para poder utilizar esta funcion como condicion en un if
    for(int i=0 ; i<tam ; i++){
        if(nomina[i].isEmpty!=1){
            empEmpty=0;
            break;
        }
    }

    return empEmpty;
}

void bajaEmpleado(eEmployee nomina[], eSector sectores[], int tam, int tamSec){

    int idBaja;
    int indexBuscar;
    char confirmoBaja;

    //Si no hay empleados, informa al usuario y vuelve al menu anterior
    if(hayEmpleados(nomina, tam)){
        printf("\nAun no se han ingresado empleados\n\n");
        system("pause");
    }else{

        mostrarEmpleados(nomina, sectores, tam, tamSec);
        idBaja=conseguirPositivo("\nIngrese el ID a dar de baja: ", "Error. Ingrese nuevamente: ");

        indexBuscar=buscarEmpleado(nomina, TAM, idBaja);
        //Lista empleados y pide al usuario el id del empleado a dar de baja
        if(indexBuscar==-1){
                printf("\nNo existe ningun empleado con ese ID\n");
                system("pause");
        //Si no lo encuentra, informa al usuario
        }else{
            printf("\nEmpleado con ID %d: ", idBaja);
            printf("\n%4s %12s %12s %10s %9s \n", "ID", "Nombre", "Apellido", "Salario","Sector");
            mostrarEmpleado(nomina[indexBuscar], sectores, averiguarSector(nomina[indexBuscar], sectores, tamSec));
            //Si lo encuentra, muestra el empleado y pregunta si quiere confirmar o no la baja

            printf("\n\nConfirmar la baja de este empleado? S/N: ");
            fflush(stdin);
            confirmoBaja=tolower(getchar());

            //Informa al usuario si la baja fue confirmada o cancelada
            if(confirmoBaja=='n'){
                printf("\nBaja de empleado cancelada\n");
                system("pause");
            }else{
                printf("\nBaja de empleado confirmada\n");
                system("pause");
                nomina[indexBuscar].isEmpty=1;
            }
        }
    }


}

void cargarSectores(eSector sectores[], int tamSec){

    char rta;
    int j;

    //Recibe array sectores y pide los datos para cargarlos
    do{
        if(sectores[tamSec-1].id!=0){
            printf("\nNo hay lugar para mas sectores\n\n");
            system("pause");
            break;
        }//Si el ultimo elemento del array de sectores esta ocupado, lo informa

        for(j=0 ; j<tamSec ; j++){
            if(sectores[j].id==0){
                sectores[j].id=j+1;
                break;
            }
        }//Buscar el primer sector sin ocupar y devuelve el id

        printf("\nSector %d, ingrese descripcion: ", j+1);
        fflush(stdin);
        gets(sectores[j].name);
        printf("\nIngresar otro sector? S/N: ");
        fflush(stdin);
        rta=getchar();
        rta=tolower(rta);
        //Pide la descripcion al usuario, dando el id de forma automatica

    }while(rta=='s');

}

void totalPromedioSalarios(eEmployee nomina[], int tam){

    float salariosTotal=0;
    int cantidadSalarios=0;
    float promedioSalarios;
    int contadorSuperan=0;

    //Si no hay empleados activos, informa
    if(hayEmpleados(nomina, tam)){
        printf("\nAun no se han ingresado empleados");
    }else{

        for(int i=0 ; i<tam ; i++){
            if(nomina[i].isEmpty!=1){
                salariosTotal+=nomina[i].salary;
                cantidadSalarios++;
            }
        }
        //Recorre array de empleados y suma los salarios de los que esten activos

        promedioSalarios=(float)salariosTotal/cantidadSalarios;

        printf("\nTotal de salarios: $%.2f\n", salariosTotal);
        printf("\nPromedio de salarios: $%.2f\n", promedioSalarios);
        //Recorre empleados y cuentan aquellos que superen al promedio calculado
        for(int i=0 ; i<tam ; i++){
            if(nomina[i].isEmpty!=1 && nomina[i].salary>promedioSalarios)
                contadorSuperan++;
        }

        //Muestra cuantos superaron el promedio
        printf("\nEmpleados que superan el promedio: %d\n\n", contadorSuperan);
        system("pause");
    }
}

void menuInformes(eEmployee nomina[], eSector sectores[], int tam, int tamSec){

    int rta;

    //Si no hay empleados, informa
    if(hayEmpleados(nomina, tam)){
        printf("\nAun no se han ingresado empleados.\n\n");
        system("pause");
    }else{
        do{
            //Si hay empleados activos, pregunta al usuario a que informe desea acceder
            system("cls");
            printf("Informes: ");
            printf("\n\n\t1- Listado de empleados ordenados alfabeticamente\n\t   por nombre y sector");
            printf("\n\n\t2- Total y promedio de los salarios,\n\t   y cuantos empleados superan el promedio.");
            printf("\n\n\t3-Volver al menu principal");
            printf("\n\nOpcion: ");
            scanf("%d", &rta);

            switch(rta){
                //Llama a la funcion correspondiente segun el informe requerido por el usuario
                case 1:
                    ordenarEmpleados(nomina, sectores, tam, tamSec);
                    mostrarEmpleados(nomina, sectores, tam, tamSec);
                    system("pause");
                    break;
                case 2:
                    totalPromedioSalarios(nomina, tam);
                    break;
                case 3:
                    break;
                default:
                    system("cls");
            }

        }while(rta!=3);
    }

}


void ordenarEmpleados(eEmployee nomina[], eSector sectores[], int tam, int tamSec){

    eEmployee auxEmp;

    //Mediante burbujeo, ordena los empleados por sus respectivos sectores

    for(int i=0 ; i<tam-1 ; i++){
        for(int j=i+1 ; j<tam ; j++){
            if(nomina[i].sector>nomina[j].sector){
                auxEmp=nomina[i];
                nomina[i]=nomina[j];
                nomina[j]=auxEmp;
            }
        }
    }

    //Una vez ordenados por sector, los ordena por nombre de manera alfabetica, y si son iguales, por apellido
    for(int i=0 ; i<tam-1 ; i++){
        for(int j=i+1 ; j<tam ; j++){
            if(nomina[i].sector==nomina[j].sector && stricmp(nomina[i].name, nomina[j].name)==1){
                auxEmp=nomina[i];
                nomina[i]=nomina[j];
                nomina[j]=auxEmp;
            }else{
                if(nomina[i].sector==nomina[j].sector && stricmp(nomina[i].name, nomina[j].name)==0){
                    if(stricmp(nomina[i].lastName, nomina[j].lastName)==1){
                        auxEmp=nomina[i];
                        nomina[i]=nomina[j];
                        nomina[j]=auxEmp;
                    }
                }
            }
        }
    }

}

void hardCodearEmpleados(eEmployee nomina[], int tam){

    //Funcion para cargar al array de empleados con datos validos

    eEmployee empleados[]={
        {1001,"Juan","Perez",25000,1,0},
        {1002,"Maria","Luces",30000,2,0},
        {1003,"Lucas","Messi",15000,3,0},
        {1004,"Belen","Curcio",20000,1,0},
        {1005,"Mario","Beliz",90000,2,0},
        {1006,"Juana","De arco",20000,3,0},
        {1007,"Daniel","Yo",9000,1,0},
        {1008,"Kevin","Clas",70000,2,0},
        {1009,"Claudia","Ella",120000,3,0}
            };

    for(int i=0 ; i<tam ; i++){
        nomina[i]=empleados[i];
    }

}

