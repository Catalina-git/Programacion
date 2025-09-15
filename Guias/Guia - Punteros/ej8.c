/* Escriba una funcion que reciba un puntero a un array de enteros y su tamaño, 
   y devuelva la suma de sus elementos. 
   Luego, llama a esta funcion desde main y muestre el resultado.
*/

#include <stdio.h>
#include <stdlib.h>

void suma (int *arr, int longitud) {
    int suma = 0;

    for (int i = 0; i < longitud; i++) {
        suma += arr[i];
    }

    printf("\nLa suma de todos los elementos del array es: %d\n", suma);
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int longitud = sizeof(arr) / sizeof(arr[0]);

    suma(arr, longitud);

    return 0;
}