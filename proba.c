#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int NUMERO_PERMUTACIONES;
char *NOMBRE_ARCHIVO;
int** MATRIZ_ADYACENCIA


void liberarArreglo1(char* arreglo)
{
	free(arreglo);
}

void liberarArreglo2(char** arreglo,int largo)
{
	for (int i = 0; i < largo; ++i)
	{
		free(arreglo[i]);
	}
	free(arreglo);
}
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

char** concatenarVacia(char** l1)
{
	char **contatenada;	
	char* empty = "";

	int i = 0;
	int largoTotal = 0;

	while (l1[i] != NULL)
	{
		largoTotal++;
		i++;
	}
	
	contatenada = (char**)malloc(sizeof(char*)*(largoTotal+1));

	for (int i = 0; i < largoTotal; ++i)
		contatenada[i] = l1[i];
	contatenada[largoTotal] = empty;

	return contatenada;
}

char** insertarMultiple(char* lista,char numero)
{
	char **listaDevuelta;
	int largoArray = strlen(lista);
	listaDevuelta = (char**)malloc(sizeof(char*)*(largoArray+1));
	for (int i = 0; i < largoArray+1; ++i)
	{
		listaDevuelta[i] = (char*)malloc(sizeof(char)*(largoArray+1));
	}

	for (int i = 0; i < largoArray+1; ++i)
	{
		listaDevuelta[i] = insertarNumero(lista,numero,i);
	}
	
	return listaDevuelta;

}

char** permutaciones(char *lista)
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
		char **lista_permutaciones, **lista_IM; 
		int largoListaPerm, largoConjuntos, largoListaIM, i, j ;

		nueva_lista = (char*)malloc(sizeof(char)*(largo-1));
		
		for (i = 0; i < largo-1; ++i)
			nueva_lista[i] = lista[i+1];
		
		lista_permutaciones = permutaciones(nueva_lista);

		largoListaPerm = 1;
		largoConjuntos = strlen(*lista_permutaciones);
		
		for (i = largoConjuntos ; i > 1 ; --i)
			largoListaPerm = largoListaPerm*i;

		j = 0;

		largoListaIM = (largoConjuntos+1)*largoListaPerm;

		lista_IM = (char**)malloc(sizeof(char*)*(largoListaIM));

		for (i = 0; i < largoListaPerm; ++i)
		{
			char **listaTemp;
			listaTemp = insertarMultiple(lista_permutaciones[i],lista[0]); 
			for (int i = 0; i < largoConjuntos+1; ++i)
			{
				lista_IM[j] = listaTemp[i];
				j++;
			}
		}

		NUMERO_PERMUTACIONES = largoListaIM;
		return lista_IM;	
	}	
}

void recibirNombreArchivo() 
{ //Esta función es la que se encarga de pedirle al usuario el nombre de cada uno de los archivos de entrada
	FILE* arch; //Almacenandolos en NOMBRE_ARCHIVO_1 y NOMBRE_ARCHIVO_2 respectivamente, siendo
	NOMBRE_ARCHIVO = (char*)malloc(sizeof(char)*25);//Estas variables globales definidas en las definiciones
	printf("Para comenzar primero se necesita el nombre de sus dos archivos de entrada junto a su formato\n");
	printf("Por ejemplo 'entrada1.txt' o prueba1.txt\n\nRecuerde que el primero es el que contiene las instrucciones y el segundo las lineas de control\n");
	do
	{
		printf("\nIngrese el nombre del primer archivo solicitado: ");
		scanf("%s",NOMBRE_ARCHIVO);
		while(getchar()!='\n');
		arch = fopen(NOMBRE_ARCHIVO,"r");
		
		if (arch == NULL) 
			printf("No se encuentra archivo con ese nombre, intente nuevamente\n");
		
	} while (arch == NULL);
	fclose(arch);
}


void leerArchivosYGuardarDatos()		//Esta funcion se encarga del proceso de lectura y obtencion de los datos del archivo
{										//primero cuenta cuantas lineas tiene el archivo	
	FILE* archivo_nodos;		//hecho esto, pasa todas las instrucciones que están en el archivo
	int nodo1, nodo2, costo, aux2, i, largo;	//y los registros o direcciones de memoria involucrados en ella
	char buffer[100],buffer2[100],*valor1,*valor2, *valor3;
										//La función no retorna nada ya que todo lo que va modificando son punteros
	archivo_nodos = fopen(NOMBRE_ARCHIVO,"r");
	fgets(buffer,3,archivo_nodos);
	
	int nodos = atoi(buffer);
	printf("NODOS: %i\n",nodos);
	MATRIZ_ADYACENCIA = (int**)malloc(sizeof(int*)*nodos)
	
	for (int i = 0; i < nodos; ++i)
	{
		MATRIZ_ADYACENCIA[i] = (int*)malloc(sizeof(int)*nodos);

		for (int j = 0; j < nodos; ++j)
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
			printf("%s %s %s\n",valor1,valor2,valor3);

			MATRIZ_ADYACENCIA[nodo1][nodo2] = costo;
			MATRIZ_ADYACENCIA[nodo2][nodo1] = costo;

		}	
		fgetc(archivo_nodos);
		if (feof(archivo_nodos))
			break;	
	}
	fclose(archivo_nodos);
	for (int i = 0; i < nodos; ++i)
	{
		for (int j = 0; j < nodos; ++j)
		{
			printf(" |%i|  ",MATRIZ_ADYACENCIA[i][j]);
		}
		printf("\n");	
	}
}


int main(int argc, char const *argv[])
{
	recibirNombreArchivo();
	leerArchivosYGuardarDatos();

	liberarArreglo1(NOMBRE_ARCHIVO);

	char* xd, **xd2;
	xd = (char*)malloc(sizeof(char)*4);
	strcpy(xd,"1234");
	xd2 = permutaciones(xd);
	
	printf("EL NUMERO DE PERMUTACIONES ES: %i \n\n",NUMERO_PERMUTACIONES);

	for (int i = 0; i < NUMERO_PERMUTACIONES; ++i)
		printf(" [%s] ",xd2[i]);
	printf("\n");

	liberarArreglo1(xd);
	liberarArreglo2(xd2,NUMERO_PERMUTACIONES);
}