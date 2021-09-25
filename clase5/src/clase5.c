/*
 ============================================================================
 Name        : clase5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int menu();
int inicializar(int edades[],float sueldos[],char nombres[][20], int tam);
void cargaAleatoriaVector(int edades[],float sueldos[],char nombres[][20],int tam);
int muestroVector(int edades[], float sueldos[],char nombres[][20],int tam);
float calcularPromedio(int vector[],int tam);

int main(void) {
	setbuf(stdout,NULL);
	char seguir='s';
	int edades[TAM];
	float sueldos[TAM];
	char nombres[TAM][20];


	do {

		printf("Tercer comit\n");
		printf("Segundo comit\n");
		printf("Primer comit\n");
		switch(menu()){
		case 1:
			printf("Usted ha seleccionado la opcion 1-Inicializar\n");
			if( (inicializar(edades,sueldos,nombres,TAM)) ){
				printf("\nVector edades inicializado con exito\n");
			}
			system("pause");
			break;
		case 2:
			printf("Usted ha seleccionado la opcion 2-Cargar\n");
			cargaAleatoriaVector(edades,sueldos,nombres,TAM);

			system("pause");
			break;
		case 3:
			printf("Usted ha seleccionado la opcion 3-Mostrar\n");
			muestroVector(edades,sueldos,nombres,TAM);
            printf("\n");
			system("pause");
			break;
		case 4:
			printf("Usted ha seleccionado la opcion 4-Calcular promedio\n");
			printf("El promedio es %.2f\n\n",calcularPromedio(edades,TAM));
			system("pause");
			break;
		case 5:
			printf("Usted ha seleccionado la opcion 5-Ordenar\n");
			system("pause");
		    break;
		case 6:
			printf("Usted ha seleccionado la opcion 6-Salir\n");
			system("pause");
			seguir='n';
			break;
		default:
			printf("\nOpcion invalida. Reingrese opcion.\n");
			system("Pause");
			break;
		}
	}while(seguir=='s');




	return EXIT_SUCCESS;
}

int menu(){

	int opcion;

	        printf("            **** MENU DE OPCIONES ****\n");
			printf("1- Inicializar\n");
			printf("2- Cargar\n");
			printf("3- Mostrar\n");
			printf("4- Calcular promedio\n");
			printf("5- Ordenar\n");
			printf("6- Salir\n");
			printf("Ingrese opcion (1-6):");
			scanf("%d",&opcion);


	return opcion;
}

int inicializar(int edades[],float sueldos[],char nombres[][20],int tam){

	int todoOk=0;

	if(edades!=NULL && sueldos!=NULL && tam>0){
		for(int i=0; i<tam; i++){
			edades[i]=0;
			sueldos[i]=0;

			todoOk = 1;
		}

	}

	return todoOk;
}

void cargaAleatoriaVector(int edades[],float sueldos[],char nombres[][20],int tam){

	char seguir='s';
	int lugar;

	if(edades!=NULL && sueldos!=NULL && tam>0){

		do{

			printf("Ingrese lugar para guardar el empleado: ");
			scanf("%d",&lugar);


                printf("Ingrese nombre:");
                fflush(stdin);
                fgets(nombres[lugar-1][25],25,stdin);
				printf("Ingrese edad: ");
				scanf("%d", &edades[lugar-1]);
				printf("Ingrese sueldo:");
				scanf("%f", &sueldos[lugar-1]);




           printf("Desea agregar otro empleado? s/n: ");
           fflush(stdin);
           scanf("%c",&seguir);


		}while(seguir!='n');

	}


}

int muestroVector(int edades[],float sueldos[],char nombres[][20], int tam) {

	int todoOk = 0;

	if (edades != NULL && sueldos!=NULL &&  tam > 0) {

        printf("Nombre       Edad       Sueldo\n");
		for (int i = 0; i < tam; i++) {
			printf("%s         %4d        %.2f\n",nombres[i],edades[i],sueldos[i]);

		}



		todoOk = 1;
	}

	return todoOk;
}

float calcularPromedio(int vector[],int tam){

	float promedio;
	int acumulador=0;

	for(int i=0; i<tam; i++){
		acumulador+=vector[i];
	}

	promedio=(float)acumulador/tam;

	return promedio;
}
