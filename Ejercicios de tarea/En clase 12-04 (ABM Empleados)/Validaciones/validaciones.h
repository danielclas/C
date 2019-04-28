typedef struct{

    int dia;
    int mes;
    int anno;

}eFecha;

typedef struct{

    int legajo;
    int edad;
    float sueldo;
    char sexo;
    char nombre[20];
    eFecha ingreso;


}ePersona;

char getSexo();
int getEdad();
int getLegajo();
int getDia();
int getMes();
int getAnno();
void getIngreso(ePersona gente[], int indice);
void getNombre(ePersona gente[], int indice);
int getInt();
float getFloat();
float getSueldo();
void agregarPersona(ePersona gente[], int indice);
void mostrarPersona(ePersona persona);
