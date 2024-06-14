// Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Constantes
#define NUM_MAT 6
#define CAL_MIN 0
#define CAL_APR 6
#define CAL_MAX 10

// Prototipos
void lecturaDeCalificaciones(void);
void materiasAprobadas(void);
void materiasParaRecursar(void);

// Variables globales
float calificacion[NUM_MAT], promedio;
int i;

const char *materia[NUM_MAT] = {
	"Calculo Diferencial e Integral",
	"Fundamentos de Algebra",
	"Fisica Clasica",
	"Quimica Basica",
	"Fundamentos de Programacion",
	"Humanidades I"
};
	
const char *grupo[NUM_MAT] = {
	"1CV31",
	"1CV32",
	"1CV33",
	"1CV34",
	"1CV35",
	"1CV36"
};

int main(void) {
	
	// Sentencias de ejecucion
	lecturaDeCalificaciones();
	system("cls");
	printf("Promedio general: %.2f", promedio);
	materiasAprobadas();
	materiasParaRecursar();
	
	// Cierre del programa
	printf("\n\n\nPresione cualquier tecla para salir...");
	getch();
	
	//Sentencia de retorno
	return 0;
	
}

void lecturaDeCalificaciones(void) {
	
	// Variables locales
	float suma = 0;
	
	// Sentencias de ejecucion
	for(i=0; i<NUM_MAT; i++) {
		
		// Solicitud y lectura de calificaciones
		do {
			
			printf("\nIngrese la calificacion de %s (%s): ", materia[i], grupo[i]);
			scanf("%f", &calificacion[i]);
			
			if(calificacion[i] < CAL_MIN || calificacion[i] > CAL_MAX) {
				printf("\nCalificacion no valida.\n");
			}
			
		} while(calificacion[i] < CAL_MIN || calificacion[i] > CAL_MAX);
		
		// Actualizacion de promedio
		suma = suma + calificacion[i];
		promedio = suma / (i+1);
		
	}
	
	
}

void materiasAprobadas(void) {
	
	// Sentencias de ejecucion
	printf("\n\n\n***Materias aprobadas***\n");
	
	for(i=0; i<NUM_MAT; i++) {
		
		if(calificacion[i] >= CAL_APR) {
			
			printf("\n   %s (%s)", materia[i], grupo[i]);
			
		}
		
	}
	
}

void materiasParaRecursar(void) {
	
	// Sentencias de ejecucion
	printf("\n\n\n***Materias que debe recursar o presentar ETS***\n");
	
	for(i=0; i<NUM_MAT; i++) {
		
		if(calificacion[i] < CAL_APR) {
			
			printf("\n   %s (%s)", materia[i], grupo[i]);
			
		}
		
	}
	
}