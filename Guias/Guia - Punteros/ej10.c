/* Escribe una funcion que reciba un puntero a un array de enteros y su tamaño, 
   y multiplique cada elemento por 2. 
   Luego, llame a esta funcion desde main 
   y muestre los elementos del array antes y despues de la modificacion.
   */

#include <stdio.h>
#include <stdlib.h>

void duplicoElementos(int *arr, int longitud) {
    for (int i = 0; i < longitud; i++) {
        arr[i] = arr[i] * 2;
    }
} 

void mostrarVector(int *vector, int longitud){
    for (int i = 0; i < longitud; i++) {
        printf("%d - ", vector[i]);
    }

    printf("\n");
}

int main() {
    int arr[] = {2,1,3,4,6,8,90,3};
    int longitud = sizeof(arr) /sizeof(arr[0]);

    printf("\nArray antes de modificarlo...\n");
    mostrarVector(arr, longitud);

    printf("\nArray despues de modificarlo...\n");
    duplicoElementos(arr, longitud);
    mostrarVector(arr, longitud);

    return 0;
}
