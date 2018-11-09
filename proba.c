#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int CONT;
int TAM_LISTA;

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
	/*for (int i = 0; i < largoArray+1; ++i)
	{
		printf("%c - ",listaInsertada[i]);
	}*/
	return listaInsertada;
}

//def inserta_multiple(x, lst):
  //  return [inserta(x, lst, i) for i in range(len(lst) + 1)]

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
	for (int i = 0; i < largoArray+1; ++i)
	{
		printf("[%s]\n",listaDevuelta[i]);		

	}
	return listaDevuelta;

}

/*def permuta(c):
    if len(c) == 0:
        return [[]]
    return sum([inserta_multiple(c[0], s)
                for s in permuta(c[1:])],[])*/

char** permutaciones(char *lista)
{
	if (strlen(lista) == 0)
	{
		return "";
	}
	else
		int insertaMul[][] = insertaMultiple(lista[0],s)
		return 

}

int main(int argc, char const *argv[])
{
	char* xd;
	xd = (char*)malloc(sizeof(char)*3);
	strcpy(xd,"124");
	//char xd[3] = {'1','2','4'};
	//printf("TAMA: %lu\n",strlen(xd));

	insertarMultiple(xd,'m');


	//int tamano; ///Aplica sizeof al array
	//int xd[8] = {1,2,3,4,5,6,7,8};
	//int tamano_lista = sizeof(xd);
    //int tamano_entero = sizeof(int);
    //int cantidad_elem = tamano_lista/tamano_entero;
	//insertarMultiple(31,xd,3);
	//insertarNumero(xd,32,0,3);
	return 0;
}