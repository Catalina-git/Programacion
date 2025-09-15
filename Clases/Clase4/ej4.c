/* Realizar una funcion que implemente un BubbleSort: 
   
   El BubbleSort es un algoritmo de ordenamiento que funciona de la siguiente manera...
   - Revisando cada elemento del vector que va a ser ordenado con el siguiente, 
     intercambiandolos de posicion si estan en el orden equivocado.
   - Repetir el proceso hasta que no se necesiten mas intercambios.
*/

#include <stdio.h>
#include <stdlib.h>

void intercambio(int *ptr_a, int *ptr_b) { /*"int *a" --> a es un puntero * que apunta a un int --> a es una direccion de memoria
    Para modificar la variable hago "*a" --> eso me dice lo que esta adentro de la direccion de memoria*/
    int aux = *ptr_a; 
    *ptr_a = *ptr_b; /* Lo que tengo en ptr_b, lo pego en ptr_a --> lo leo de derecha a izquierda */
    *ptr_b = aux;
}   

void mostrarVector(int *vector, int longitud){
    for (int i = 0; i < longitud; i++) {
        printf("%d - ", vector[i]);
    }

    printf("\n");
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

int main() {
    int lista[] = {4,3,2,6,7,8};
    int size = sizeof(lista) / sizeof(lista[0]);

    printf("\nLista inicial...\n");
    mostrarVector(lista, size);

    BubbleSort(lista, size);

    printf("\nLista ordenada con BubbleSort...\n");
    mostrarVector(lista, size);

    return 0;
}