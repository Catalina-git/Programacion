/* Escribe una funcion que reciba un puntero a un array de enteros y su tamaño, 
   y devuelva un puntero al elemento de mayor valor en el array. 
   Luego, llame a esta funcion desde main y muestre el valor del elemento de mayor valor. 
*/

#include <stdio.h>
#include <stdlib.h>

int* mayor(int *arr, int longitud) {
    int *max = arr;

    if (longitud == 0) {
        return NULL; /* Verifico que el array no tengo longitud nula */
    }

    for (int i = 0; i < longitud; i++) {
        if(arr[i] > *max) {
            max = &arr[i];
        }
    }

    return max;
}

int main(void) {
    int arr[] = {2,1,3,4,6,8,90,3};
    int longitud = sizeof(arr) / sizeof(arr[0]);

    int *resultado = mayor(arr, longitud);

    if (resultado != NULL) {
        printf("\nEl elemento de mayor valor del array es el: %d\n", *resultado);
    } else {
        printf("\nEl array esta vacio.\n");
    }


    return 0;
}