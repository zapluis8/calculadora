#ifndef TENSOR_H
#define TENSOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profundidad; // número de matrices en el tensor
    Matriz **capas;
} Tensor;

// Funciones para tensores
Tensor* crearTensor(int profundidad, int filas, int columnas);
void liberarTensor(Tensor* t);
void imprimirTensor(Tensor* t);

#endif
