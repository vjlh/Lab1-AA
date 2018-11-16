#include "definiciones.h"
	
int main(int argc, char const *argv[])
{
	char* conjunto_a_permutar, **todas_las_permutaciones;
	//Lectura del archivo de entrada
	recibirNombreArchivo();
	leerArchivosYGuardarDatos();
	liberarArreglo1(NOMBRE_ARCHIVO);

	//Fuerza bruta
	conjunto_a_permutar = generarConjunto();
	todas_las_permutaciones = bruteForce(conjunto_a_permutar);
	
	//Generando las soluciones
	buscarMinimo(todas_las_permutaciones);

	//Liberando memoria
	liberarArreglo1(conjunto_a_permutar);
	liberarArregloInt(MATRIZ_ADYACENCIA,NUMERO_NODOS);
	liberarArregloChar(todas_las_permutaciones,NUMERO_PERMUTACIONES);
}