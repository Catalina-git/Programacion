/* Dado el array de numeros del archivi 'lista.h':
   a. Calcule la suma de todos los numeros del vector.
   b. Calcule el promedio de todas las direcciones de memoria de los numeros del vector. 
   */

#include <stdio.h>
#include <stdlib.h>

int suma(int lista[], int largo) {
    int suma = 0;

    for (int i = 0; i < largo; i++) {
        suma += lista[i];
    }

    return suma;
}

float promedio(int lista[], int largo) {
    uintptr_t suma = 0; /* uintptr_t es un tipo de dato que toma la direccion de memoria y la convierte en un entero */

    for (int i = 0; i < largo; i++) {
        suma += (uintptr_t)lista[i];
    }

    float promedio = suma / largo;

    return promedio; 
}

void mostrarVector(int *vector, int longitud){
    for (int i = 0; i < longitud; i++) {
        printf("%d - ", vector[i]);
    }

    printf("\n");
}

void intercambio(int *ptr_a, int *ptr_b) { /*"int *a" --> a es un puntero * que apunta a un int --> a es una direccion de memoria
    Para modificar la variable hago "*a" --> eso me dice lo que esta adentro de la direccion de memoria*/
    int aux = *ptr_a; 
    *ptr_a = *ptr_b; /* Lo que tengo en ptr_b, lo pego en ptr_a --> lo leo de derecha a izquierda */
    *ptr_b = aux;
}  

void BubbleSort(int *vector, int longitud) {
    for (int j = 0; j < longitud - 1; j++) {
        for (int i = 0; i < longitud - j - 1; i++) {
            if (vector [i] > vector [i + 1]) {
                intercambio(&vector[i], &vector[i + 1]);
            }
        }
    }
}


int main(void) {
    int lista[] = {32, 19, 51, 14};
    int largo = sizeof(lista) / sizeof(lista[0]);

    int sum = suma(lista, largo);

    printf("\nLa suma de todos los numeros del vector es: %d\n", sum);

    float prom = promedio(lista, largo);

    printf("\nEl promedio de todas las direcciones de memoria es: %.3f\n", prom);

    printf("\nLista inicial...\n");
    mostrarVector(lista, largo);

    BubbleSort(lista, largo);

    printf("\nLista ordenada con BubbleSort...\n");
    mostrarVector(lista, largo);


    return 0;
}
