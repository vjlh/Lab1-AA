#include "definiciones.h"
//FUNCIONES PARA LIBERAR MEMORIA
void liberarArreglo1(char* arreglo)
{
	free(arreglo);
}

void liberarArregloChar(char** arreglo,int largo)
{
	for (int i = 0; i < largo; ++i)
	{
		free(arreglo[i]);
	}
	free(arreglo);
}
void liberarArregloInt(int** arreglo,int largo)
{
	for (int i = 0; i < largo; ++i)
	{
		free(arreglo[i]);
	}
	free(arreglo);
}

void printCurrent(char* conjunto,int costo){
	#ifdef DEBUG
	
	printf("enter para continuar...\n");
	while(getchar() != '\n');
	
	printf("\nCamino: 0 - ");
	for (int i = 0; i < strlen(conjunto); ++i)
		printf("%c - ",conjunto[i]);
	printf("0\nCon un costo de : %i\n",costo);
	
	#endif
}

//FUNCIONES DE INSERCIÓN DE UN ELEMENTO EN UN ARREGLO
char* insertarNumero(char* lista,char numero,int posicion)
{
	char *listaInsertada;
	int largoArray = strlen(lista);
	listaInsertada = (char*)malloc(sizeof(char)*(largoArray+1));

	listaInsertada[posicion] = numero;

	int j = 0;
	for (int i = 0; i < largoArray; ++i)
	{
		if(i == posicion){
			j++;
			listaInsertada[j] = lista[i];
		}
		else
			listaInsertada[j] = lista[i];
		j++;
	}
	return listaInsertada;
}

char** insertarMultiple(char* lista,char numero)
{
	char **listaDevuelta;
	int largoArray = strlen(lista);
	listaDevuelta = (char**)malloc(sizeof(char*)*(largoArray+1));

	for (int i = 0; i < largoArray+1; ++i)
	{
		listaDevuelta[i] = (char*)malloc(sizeof(char)*(largoArray+1));
		listaDevuelta[i] = insertarNumero(lista,numero,i);
	}

	return listaDevuelta;
}

//FUNCION QUE DADO UN CONJUNTO DE POSIBLES SOLUCIONES, ENCUENTRA LA QUE TIENE EL COSTO MINIMO
void buscarMinimo(char** permutadas)
{
	FILE* archivo_salida;
	int numNodos = strlen(permutadas[0]);
	int minimo = 12345678;
	int indice = -1;

	for (int i = 0; i < NUMERO_PERMUTACIONES; ++i)
	{
		int costo = 0;
		for (int j = 0; j < NUMERO_NODOS-1; ++j)
		{
			int n1 = permutadas[i][j] - '0' - 1;
			int n2 = permutadas[i][j+1] - '0' - 1;
			costo = costo + MATRIZ_ADYACENCIA[n1][n2];
		}
		printCurrent(permutadas[i],costo);
		if (costo < minimo)
		{
			minimo = costo;
			indice = i;
		}
	}
	minimo = minimo + 2; //Se le suma 2 por el costo de ir a la capital y volver a esta

	archivo_salida = fopen("salida.out","w");
	fprintf(archivo_salida,"Costo mínimo: %i \n\n0 - ",minimo);

	for (int i = 0; i < numNodos; ++i)
		fprintf(archivo_salida,"%c - ",permutadas[indice][i]);

	fprintf(archivo_salida,"0");
	fclose(archivo_salida);
	printf("\nEl programa ha terminado...\n");

}

//FUNCIÓN DE FUERZA BRUTA, QUE GENERA UN CONJUNTO CON TODAS LAS POSIBLES SOLUCIONES
char** bruteForce(char *lista)
{
	int largo = strlen(lista);
	if (largo == 0)
	{
		char** empty;
		empty = (char**)malloc(sizeof(char*)*1);
		empty[0] = "";
		return empty;

	}
	else
	{
		char  *nueva_lista; //Lista desde 1:n elementos de lista
		char **lista_permutaciones, **lista_permuFinal; 
		int largoListaPerm, largoConjuntos, permutacionesTotales, i, j;

		nueva_lista = (char*)malloc(sizeof(char)*(largo-1));
		
		for (i = 0; i < largo-1; ++i)
			nueva_lista[i] = lista[i+1];
		
		lista_permutaciones = bruteForce(nueva_lista);

		largoListaPerm = 1;
		largoConjuntos = strlen(*lista_permutaciones);
		
		for (i = largoConjuntos ; i > 1 ; --i)
			largoListaPerm = largoListaPerm*i;

		j = 0;

		permutacionesTotales = (largoConjuntos+1)*largoListaPerm;

		lista_permuFinal = (char**)malloc(sizeof(char*)*(permutacionesTotales));

		for (i = 0; i < largoListaPerm; ++i)
		{
			char **listaTemp;
			listaTemp = insertarMultiple(lista_permutaciones[i],lista[0]); 
			for (int i = 0; i < largoConjuntos+1; ++i)
			{
				lista_permuFinal[j] = listaTemp[i];
				j++;
			}
		}

		NUMERO_PERMUTACIONES = permutacionesTotales;
		return lista_permuFinal;	
	}	
}

//FUNCIONES DE LECTURA Y ALMACENAMIENTO DE LOS DATOS DEL ARCHIVO DE ENTRADA
void recibirNombreArchivo() 
{
	FILE* archivo; //
	NOMBRE_ARCHIVO = (char*)malloc(sizeof(char)*25);//Estas variables globales definidas en las definiciones
	printf("Para comenzar primero se necesita el nombre de sus dos archivos de entrada junto a su formato\n");
	printf("Por ejemplo 'entrada1.txt' o prueba1.txt\n\nRecuerde que el primero es el que contiene las instrucciones y el segundo las lineas de control\n");
	do
	{
		printf("\nIngrese el nombre del archivo solicitado: ");
		scanf("%s",NOMBRE_ARCHIVO);
		while(getchar()!='\n');
		archivo = fopen(NOMBRE_ARCHIVO,"r");
		
		if (archivo == NULL) 
			printf("No se encuentra archivo con ese nombre, intente nuevamente\n");
		
	} while (archivo == NULL);
	fclose(archivo);
}


void leerArchivosYGuardarDatos()		//Esta funcion se encarga del proceso de lectura y obtencion de los datos del archivo
{										//primero cuenta cuantas lineas tiene el archivo	
	FILE* archivo_nodos;		//hecho esto, pasa todas las instrucciones que están en el archivo
	int nodo1, nodo2, costo, aux2, i, largo;	//y los registros o direcciones de memoria involucrados en ella
	char buffer[100],buffer2[100],*valor1,*valor2, *valor3;
										//La función no retorna nada ya que todo lo que va modificando son punteros
	archivo_nodos = fopen(NOMBRE_ARCHIVO,"r");
	fgets(buffer,3,archivo_nodos);
	
	NUMERO_NODOS = atoi(buffer);
	MATRIZ_ADYACENCIA = (int**)malloc(sizeof(int*)*NUMERO_NODOS);
	
	for (int i = 0; i < NUMERO_NODOS; ++i)
	{
		MATRIZ_ADYACENCIA[i] = (int*)malloc(sizeof(int)*NUMERO_NODOS);

		for (int j = 0; j < NUMERO_NODOS; ++j)
			MATRIZ_ADYACENCIA[i][j] = 0;
	}

	while (!feof(archivo_nodos))
	{
		memset(buffer,0, 100);
		memset(buffer2,0, 100);
		aux2 = 1;
		fscanf(archivo_nodos," %119[^\n]",buffer);
		largo = strlen(buffer);

		for (i = 0; i < largo; ++i)
			if (buffer[i] == ' ')
				aux2++;

		if (buffer[0] != '\0' && aux2 != largo && buffer[0] != '\n'&& buffer[0])
		{	
			for (i = 0; i < largo; ++i)
				if (buffer[i] != ' ')
					break;

			strncpy(buffer2,buffer+i,largo-i);
	
			valor1 = strtok(buffer2," ");
			nodo1 = atoi(valor1)-1;

			valor2 = strtok(NULL," ");
			nodo2 = atoi(valor2)-1;

			valor3 = strtok(NULL," ");
			costo = atoi(valor3);

			MATRIZ_ADYACENCIA[nodo1][nodo2] = costo;
			MATRIZ_ADYACENCIA[nodo2][nodo1] = costo;

		}	
		fgetc(archivo_nodos);
		if (feof(archivo_nodos))
			break;	
	}
	fclose(archivo_nodos);
}
//FUNCION QUE GENERA EL CONJUNTO DE NODOS A PERMUTAR
char* generarConjunto()
{

	char *conjunto;
	conjunto = (char*)malloc(sizeof(char)*NUMERO_NODOS);
	for (int i = 1; i < NUMERO_NODOS+1; ++i)
	{
		char nodo = i+'0';
		conjunto[i-1] = nodo;

	}
	return conjunto;
}
