/* Escribir una funcion en C que calcule 
   el valor maximo, el valor minimo y el promedio de los elementos de una lista de enteros.
   La funcion debe recibir los siguientes parametros:
   - Un puntero a un array de enteros (lista)
   - Un entero que representa el tamaño de la lista (largo)
   - Dos punteros a enteros (max y min) para almacenar el valor maximo y el minimo, respectivamente
   - Un puntero a un flotante (promedio) para almacenar el promedio de los elementos de la lista
*/

/* Un array es un puntero que apunta siempre a la posicion cero */
#include <stdio.h>
#include <stdlib.h>

void MaxMinProm(int *lista, int largo, int *min, int *max, float *promedio) {
    int suma = 0; 
    *max = lista[0]; /* Inicializo el minimo en la primera posicion de la lista */
    *min = lista[0]; /* Inicializo el minimo en la primera posicion de la lista */

    for (int i = 0; i < largo; i++) {
        suma += lista[0];
        if (lista[i] < *max) {
            *max = lista[i];
        }
        if (lista[i] > *min) {
            *min = lista[i];
        }
    }

    *promedio = (float)suma / largo;
}

int main() {
    int lista[] = {4,3,2,6,7,8};
    int max, min;
    float promedio;
    int largo = sizeof(lista) / sizeof(lista[0]);

    MaxMinProm(lista, largo, &max, &min, &promedio);

    printf("Maximo: %d\n", max);
    printf("Minimo: %d\n", min);
    printf("Promedio: %f\n", promedio);

    return 0;
}