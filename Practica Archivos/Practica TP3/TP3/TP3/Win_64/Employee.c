#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Employee.h"


int employee_setId(Employee* this,int id){

    int todoOK=0;

    if(this!=NULL && id>0){
        this->id=id;
        todoOK=1;
    }

    return todoOK;

}

int employee_getId(Employee* this,int* id){

    int todoOK=0;

    if(this!=NULL && id!=NULL){
        *id=this->id;
        todoOK=1;
    }

    return todoOK;
}

int employee_setNombre(Employee* this,char* nombre){

    int todoOK=0;

    if(this!=NULL && nombre!=NULL && strlen(nombre)>3){
        strcpy(this->nombre, nombre);
        todoOK=1;
    }

    return todoOK;


}

int employee_getNombre(Employee* this,char* nombre){

    int todoOK=0;

    if(this!=NULL && nombre!=NULL){
        strcpy(nombre, this->nombre);
        todoOK=1;
    }

    return todoOK;

}
///Nombre !=NULL y mas de tres caracteres

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int todoOK=0;

    if(this!=NULL && horasTrabajadas>0){
        this->horasTrabajadas=horasTrabajadas;
        todoOK=1;
    }

    return todoOK;



}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

    int todoOK=0;

    if(this!=NULL && horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        todoOK=1;
    }

    return todoOK;

}
///Horas y sueldos positivios

int employee_setSueldo(Employee* this,int sueldo){

    int todoOK=0;

    if(this!=NULL && sueldo>0){
        this->sueldo=sueldo;
        todoOK=1;
    }

    return todoOK;


}

int employee_getSueldo(Employee* this,int* sueldo){

    int todoOK=0;

    if(this!=NULL && sueldo!=NULL){
        *sueldo=this->sueldo;
        todoOK=1;
    }

    return todoOK;

}

Employee* employee_new(){

    Employee* this=(Employee*) malloc(sizeof(Employee));

    if(this!=NULL){
        this->id=0;
        strcpy(this->nombre, "");
        this->horasTrabajadas=0;
        this->sueldo=0;
    }

    return this;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

    Employee* this;
    int todoOk=0;


    if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL){
        this=employee_new();
            if(this!=NULL){
                if(employee_setId(this, atoi(idStr)==1)){
                    if(employee_setNombre(this, nombreStr)){
                        if(employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr))){
                            if(employee_setSueldo(this, atoi(sueldoStr))){
                                todoOk=1;
                            }
                        }
                   }
                }
            }
    }


    if(todoOk==0){
        free(this);
        this=NULL;
    }

    return this;

}

void mostrarEmpleado(Employee* emp){

    //if(emp!=NULL)
    printf("%d   %s  %d  %d\n",emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);


}

int ordenarPorSueldo(void* emp1, void* emp2){

    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->sueldo > p2->sueldo){
            retorno=1;
        }else{
            if(p1->sueldo < p2->sueldo){
                retorno=-1;
            }else{
                retorno=0;
            }
        }
    }

    return retorno;

}

int ordenarPorHoras(void* emp1, void* emp2){

    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas){
            retorno=1;
        }else{
            if(p1->horasTrabajadas < p2->horasTrabajadas){
                retorno=-1;
            }else{
                retorno=0;
            }
        }
    }

    return retorno;

}
