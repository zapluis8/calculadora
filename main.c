#include "matriz.h"

int main() {
    // Crear matrices 2x2
    Matriz* m1 = crearMatriz(2,2);
    Matriz* m2 = crearMatriz(2,2);

    // Inicializar
    m1->datos[0][0]=1; m1->datos[0][1]=2;
    m1->datos[1][0]=3; m1->datos[1][1]=4;

    m2->datos[0][0]=5; m2->datos[0][1]=6;
    m2->datos[1][0]=7; m2->datos[1][1]=8;

    printf("Matriz 1:\n"); imprimirMatriz(m1);
    printf("Matriz 2:\n"); imprimirMatriz(m2);

    Matriz* suma = sumaMatriz(m1,m2);
    printf("Suma:\n"); imprimirMatriz(suma);

    Matriz* resta = restaMatriz(m1,m2);
    printf("Resta:\n"); imprimirMatriz(resta);

    Matriz* mult = multiplicarMatriz(m1,m2);
    printf("Multiplicación:\n"); imprimirMatriz(mult);

    Matriz* trans = transpuestaMatriz(m1);
    printf("Transpuesta de Matriz 1:\n"); imprimirMatriz(trans);

    printf("¿Matriz 1 es cuadrada? %s\n", esCuadrada(m1) ? "Sí":"No");

    // Crear tensor 2x2x2
    Tensor* t = crearTensor(2,2,2);
    t->capas[0]->datos[0][0]=1; t->capas[0]->datos[0][1]=2;
    t->capas[0]->datos[1][0]=3; t->capas[0]->datos[1][1]=4;

    t->capas[1]->datos[0][0]=5; t->capas[1]->datos[0][1]=6;
    t->capas[1]->datos[1][0]=7; t->capas[1]->datos[1][1]=8;

    printf("Tensor:\n"); imprimirTensor(t);

    // Liberar memoria
    liberarMatriz(m1); liberarMatriz(m2);
    liberarMatriz(suma); liberarMatriz(resta);
    liberarMatriz(mult); liberarMatriz(trans);
    liberarTensor(t);

    return 0;
}
