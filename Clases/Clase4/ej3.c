/* 1 - Implementar una función en C para imprimir los elementos de un vector de enteros.
   2 - Implementar un algoritmo de ordenamiento simple en C.

    Define una función llamada EasySort que reciba dos parámetros:
    Un puntero a un array de enteros (vector).
    Un entero que representa la longitud del array (longitud).

    La función debe:
    -Crear un array temporal para almacenar los elementos ordenados.
    -Recorrer el array original y copiar los elementos en el array temporal en orden creciente.
    es decir, iterativamente, encuentra el mínimo de los elementos restantes y se coloca en
    la siguiente posición del array temporal.
    -Finalmente, copiar los elementos del array temporal de vuelta al array original.
*/

#include <stdio.h>
#include <stdlib.h>

void mostrarVector(int *vector, int longitud){
    for (int i = 0; i < longitud; i++) {
        printf("%d - ", vector[i]);
    }

    printf("\n");
}

void EasySort(int *vector, int longitud) {
    int aux[longitud];
    int min = vector[0];
    int last_min = 0;

    for (int i = 0; i < longitud; i++) {
        min = 65536;
        for(int j = 0; j < longitud; j++) {
            if ((vector[j] < min) && (vector[j] > last_min)) {
                min = vector[j];
            }
        }

        aux[i] = min;
        last_min = min;
    }

    for (int i = 0; i < longitud; i++) {
        vector[i] = aux[i];
    }
}

int main() {
    int lista[] = {4,3,2,6,7,8};
    int size = sizeof(lista) / sizeof(lista[0]);

    printf("\nLista inicial...\n");
    mostrarVector(lista, size);

    EasySort(lista, size);

    printf("\nLista ordenada con EasySort...\n");
    mostrarVector(lista, size);

    return 0;    
}