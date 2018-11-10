#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int NUMERO_PERMUTACIONES;

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

int main(int argc, char const *argv[])
{
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