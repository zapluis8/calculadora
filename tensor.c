#include "tensor.h"

// ---------------- Tensores ----------------

// Crear tensor nxm de tamaño profundidad
Tensor* crearTensor(int profundidad,int filas,int columnas){
    Tensor* t=(Tensor*)malloc(sizeof(Tensor));
    t->profundidad = profundidad;
    t->capas=(Matriz**)malloc(profundidad*sizeof(Matriz*));
    for(int i=0;i<profundidad;i++)
        t->capas[i] = crearMatriz(filas,columnas);
    return t;
}

// Liberar tensor
void liberarTensor(Tensor* t){
    for(int i=0;i<t->profundidad;i++)
        liberarMatriz(t->capas[i]);
    free(t->capas);
    free(t);
}

// Imprimir tensor
void imprimirTensor(Tensor* t){
    for(int i=0;i<t->profundidad;i++){
        printf("Capa %d:\n",i+1);
        imprimirMatriz(t->capas[i]);
        printf("\n");
    }
}

