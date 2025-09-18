#include "matriz.h"

// Crear matriz dinámica nxm
Matriz* crearMatriz(int filas, int columnas) {
    Matriz* m = (Matriz*)malloc(sizeof(Matriz));
    m->filas = filas;
    m->columnas = columnas;

    m->datos = (int**)malloc(filas * sizeof(int*));
    for(int i=0;i<filas;i++)
        m->datos[i] = (int*)malloc(columnas * sizeof(int));

    return m;
}

// Liberar memoria matriz
void liberarMatriz(Matriz* m) {
    for(int i=0;i<m->filas;i++)
        free(m->datos[i]);
    free(m->datos);
    free(m);
}

// Imprimir matriz
void imprimirMatriz(Matriz* m) {
    for(int i=0;i<m->filas;i++){
        for(int j=0;j<m->columnas;j++)
            printf("%d ", m->datos[i][j]);
        printf("\n");
    }
}

// Sumar matrices
Matriz* sumaMatriz(Matriz* m1, Matriz* m2) {
    if(m1->filas!=m2->filas || m1->columnas!=m2->columnas) {
        printf("Error: dimensiones incompatibles para suma\n");
        return NULL;
    }
    Matriz* res = crearMatriz(m1->filas,m1->columnas);
    for(int i=0;i<m1->filas;i++)
        for(int j=0;j<m1->columnas;j++)
            res->datos[i][j] = m1->datos[i][j] + m2->datos[i][j];
    return res;
}

// Resta
Matriz* restaMatriz(Matriz* m1, Matriz* m2) {
    if(m1->filas!=m2->filas || m1->columnas!=m2->columnas){
        printf("Error: dimensiones incompatibles para resta\n");
        return NULL;
    }
    Matriz* res = crearMatriz(m1->filas,m1->columnas);
    for(int i=0;i<m1->filas;i++)
        for(int j=0;j<m1->columnas;j++)
            res->datos[i][j] = m1->datos[i][j] - m2->datos[i][j];
    return res;
}

// Multiplicación
Matriz* multiplicarMatriz(Matriz* m1,Matriz* m2){
    if(m1->columnas!=m2->filas){
        printf("Error: dimensiones incompatibles para multiplicación\n");
        return NULL;
    }
    Matriz* res = crearMatriz(m1->filas,m2->columnas);
    for(int i=0;i<m1->filas;i++)
        for(int j=0;j<m2->columnas;j++){
            res->datos[i][j]=0;
            for(int k=0;k<m1->columnas;k++)
                res->datos[i][j]+=m1->datos[i][k]*m2->datos[k][j];
        }
    return res;
}

// Cuadrada
int esCuadrada(Matriz* m){
    return m->filas==m->columnas;
}

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
