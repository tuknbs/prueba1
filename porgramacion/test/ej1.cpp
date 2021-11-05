#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 250

struct pacientes{
    char nombre[20];
    char apellido[20];
    char email [20];
    char nombreHijo[20];
    char fechaVacuna[10];
};

struct registro{
    char email[20];
    char mensaje [256];
};

FILE * abrir(const char * archivo, const char * modo);
void leer (pacientes paciente, FILE * archivo);
void buscarFecha(char fecha[10], FILE * agenda, FILE * vacunacion, pacientes paciente);


int main(){

char fecha[10];
pacientes paciente;
FILE * agenda = abrir("agenda.txt", "r");
FILE * vacunacion = abrir ("pacientes.dat", "wb");
printf("Ingrese la fecha deseada (dia/mes/anio)\n");
scanf("%s", fecha);
buscarFecha(fecha, agenda, vacunacion, paciente);





system("pause");
return 0;

}

void buscarFecha(char fecha[10], FILE * agenda, FILE * vacunacion, pacientes paciente){
    char buffer [MAX_BUFFER];
    char mensaje[256];

    while (fgets(buffer, MAX_BUFFER, agenda) != NULL){
        strcpy(paciente.nombre, strtok(buffer, ";"));
        strcpy(paciente.apellido, strtok(NULL, ";"));
        strcpy(paciente.email,strtok(NULL, ";"));
        strcpy(paciente.nombreHijo, strtok(NULL, ";"));
        strcpy(paciente.fechaVacuna, strtok(NULL, ";"));

        if (paciente.fechaVacuna == fecha){
            fwrite(paciente.email, sizeof(char), sizeof(paciente.email), vacunacion);
            strcpy (mensaje, ("Estimado/a %s, el dia de %s deberá vacunar a %s para cumplir con su calendario de vacunacion\n", paciente.nombre, paciente.fechaVacuna, paciente.nombreHijo)) ;
            fwrite(mensaje, sizeof(char), sizeof(mensaje), vacunacion);
        }
        
    }
    

}

FILE * abrir(const char * archivo, const char * modo){
    FILE * file = fopen(archivo, modo);
    return file;
}