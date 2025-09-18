#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int filas;
    int columnas;
    int **datos;
} Matriz;

// Funciones para matrices
Matriz* crearMatriz(int filas, int columnas);
void liberarMatriz(Matriz* m);
void imprimirMatriz(Matriz* m);
Matriz* sumaMatriz(Matriz* m1, Matriz* m2);
Matriz* restaMatriz(Matriz* m1, Matriz* m2);
Matriz* multiplicarMatriz(Matriz* m1, Matriz* m2);
int esCuadrada(Matriz* m);

#endif
