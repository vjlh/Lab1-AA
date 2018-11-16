#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int NUMERO_NODOS;
int** MATRIZ_ADYACENCIA;
int NUMERO_PERMUTACIONES;
char *NOMBRE_ARCHIVO;

void liberarArreglo1(char* arreglo);
void liberarArregloChar(char** arreglo,int largo);
void liberarArregloInt(int** arreglo,int largo);
void printCurrent(char* conjunto,int costo);
char* insertarNumero(char* lista,char numero,int posicion);
char** insertarMultiple(char* lista,char numero);
void buscarMinimo(char** permutadas);
char** bruteForce(char *lista);
void recibirNombreArchivo();
void leerArchivosYGuardarDatos();
char* generarConjunto();