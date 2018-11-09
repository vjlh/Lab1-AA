#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int CONT;
int TAM_LISTA;

int* insertarNumero(int lista[],int numero,int posicion, int tam)
{
	int *listaInsertada;
	listaInsertada = (int*)malloc(sizeof(int)*(tam+1));
	listaInsertada[posicion] = numero;
	int j = 0;
	for (int i = 0; i < tam; ++i)
	{
		if(i == posicion){
			j++;
			listaInsertada[j] = lista[i];
		}
		else
			listaInsertada[j] = lista[i];
		j++;
	}
	/*for (int i = 0; i < tam+1; ++i)
	{
		printf("%i - ",listaInsertada[i]);
	}*/
	return listaInsertada;
}

//def inserta_multiple(x, lst):
  //  return [inserta(x, lst, i) for i in range(len(lst) + 1)]

int** insertarMultiple(int numero, int lista[], int tamLista)
{
	int **listaDevuelta;
	listaDevuelta = (int**)malloc(sizeof(int*)*(tamLista+1));
	for (int i = 0; i < tamLista+1; ++i)
	{
		listaDevuelta[i] = (int*)malloc(sizeof(int)*(tamLista+1));
	}

	//int listaDevuelta[tamLista+1][tamLista+1];
	for (int i = 0; i < tamLista+1; ++i)
	{
		listaDevuelta[i] = insertarNumero(lista,numero,i,tamLista);
	}
	return listaDevuelta;
	for (int i = 0; i < tamLista+1; ++i)
	{
		printf("[");
		for (int j = 0; j < tamLista+1; ++j)
		{
			printf("%i,",listaDevuelta[i][j]);		
		}
		printf("]\n");

	}

}

/*def permuta(c):
    if len(c) == 0:
        return [[]]
    return sum([inserta_multiple(c[0], s)
                for s in permuta(c[1:])],[])*/

int** permutaciones(int lista[])
{
	CONT++;
	if (CONT == TAM_LISTA)
	{
		int lista[] = {}
		return lista
	}
	else
		
		int insertaMul[][] = insertaMultiple(lista[0],s)
		return 

}

int lenLista(int* lista)
{
	int tamano_lista = sizeof(lista);
	printf("TAML: %d\n",tamano_lista);
    int tamano_entero = sizeof(int);
	printf("TAME: %d\n",tamano_entero);
    int cantidad_elem = tamano_lista/tamano_entero;
    return cantidad_elem;

}

int main(int argc, char const *argv[])
{
	//int* xd;
	//xd = (int*)malloc(sizeof(int)*6);
	int xd[] = {};
	TAM_LISTA = 3;
	int tamano_lista = sizeof(xd);
	printf("TAML: %d\n",tamano_lista);


    printf("La cantidad de elem es: %d\n",lenLista(xd));

	//int tamano; ///Aplica sizeof al array
	//int xd[8] = {1,2,3,4,5,6,7,8};
	//int tamano_lista = sizeof(xd);
    //int tamano_entero = sizeof(int);
    //int cantidad_elem = tamano_lista/tamano_entero;
	//insertarMultiple(31,xd,3);
	//insertarNumero(xd,32,0,3);
	return 0;
}