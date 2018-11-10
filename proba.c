#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int CONT;
int TAM_LISTA;

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
	//char str;
	int largoArray = strlen(lista);
	listaInsertada = (char*)malloc(sizeof(char)*(largoArray+1));

	//sprintf(&str, "%d", numero);
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

//def inserta_multiple(x, lst):
  //  return [inserta(x, lst, i) for i in range(len(lst) + 1)]

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

	//int listaDevuelta[tamLista+1][tamLista+1];
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
		char **lista_permutaciones; 
		char **lista_IM;

		nueva_lista = (char*)malloc(sizeof(char)*(largo-1));
		
		for (int i = 0; i < largo-1; ++i)
			nueva_lista[i] = lista[i+1];
		
		lista_permutaciones = permutaciones(nueva_lista);
		printf("lista: [%s]\n",lista_permutaciones[0]);

		int largoLP = 1;
		int largoConjunto = strlen(*lista_permutaciones);
		for (int i = largoConjunto ; i > 1 ; --i)
			largoLP = largoLP*i;

		int ax = 0;
		int ax2 = 0;
		int largoListaIM;

		//while(lista_permutaciones[largoLP] != NULL) 
		//	largoLP++;

		int numElem = strlen(lista_permutaciones[0]);
		if (largoLP != 0)
			largoListaIM = (numElem+1)*largoLP;
		else
		{
			largoLP = 1;
			largoListaIM = 1;
		}

		printf("largo lista permutaciones %i\n",largoLP);
		printf("largo lista permutaciones %lu\n",strlen(*lista_permutaciones));
		printf("largo lista elementos %i\n",numElem);
		printf("largo lista inserciones %i\n",largoListaIM);


		lista_IM = (char**)malloc(sizeof(char*)*(largoListaIM));

		while(ax<largoLP)
		{
			printf("pasa?\n");
			char **listaTemp;
			listaTemp = insertarMultiple(lista_permutaciones[ax],lista[0]); 
			for (int i = 0; i < numElem+1; ++i)
			{
				lista_IM[ax2] = listaTemp[i];
				ax2++;
			}
			ax++;
		}
		printf("NUEVA LISTA GENERADA\n\n");
		for (int i = 0; i < largoListaIM; ++i)
		{
			
		printf(" [%s] - ",lista_IM[i]);
			
		}
		printf(" \n\nlargo = %i\n\n",largoLP);

		return lista_IM;	
	}	
}



int main(int argc, char const *argv[])
{
	char* xd, **xd2;
	xd = (char*)malloc(sizeof(char)*4);
	strcpy(xd,"1234");
	//char xd[3] = {'1','2','4'};
	//printf("TAMA: %lu\n",strlen(xd));
	xd2 = permutaciones(xd);
	int lar = strlen(*xd2);
	int j = 0;
	while(xd2[j] != NULL){
		j++;
	}
	
	printf("COMBINACIONES: \n\n");

	for (int i = 0; i < j; ++i)
	{
	printf("[%s]\n",xd2[i]);
	}
	

	//int tamano; ///Aplica sizeof al array
	//int xd[8] = {1,2,3,4,5,6,7,8};
	//int tamano_lista = sizeof(xd);
    //int tamano_entero = sizeof(int);
    //int cantidad_elem = tamano_lista/tamano_entero;
	//insertarMultiple(31,xd,3);
	//insertarNumero(xd,32,0,3);
	return 0;
}