/* Dado el array de numeros del archivi 'lista.h':
   a. Calcule la suma de todos los numeros del vector.
   b. Calcule el promedio de todas las direcciones de memoria de los numeros del vector. 
   */

#include <stdio.h>
#include <stdlib.h>

int suma(int *lista, int largo) {
    int suma = 0;

    for (int i = 0; i < largo; i++) {
        suma += lista[i];
    }

    return suma;
}

float promedio(int *lista, int largo) {
    
}

int main(void) {
    int lista[] = {52345, 60000, 43125, 32768, 45000, 
                   51234, 58000, 64000, 30000, 65535,
                   40960, 50001, 35000, 60001, 48000,
                   52000, 63000, 65530, 47000, 54000
    };
    int largo = sizeof(lista) / sizeof(lista[0]);

    int resultado = suma(lista, largo);

    printf("\nLa suma de todos los numeros del vector es: %d\n", resultado);

    return 0;
}
