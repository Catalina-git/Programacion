/* Implemente un codigo que pida numeros hasta que el usuario ingrese 0
    a. Calcule la suma de los numeros ingresados
    b. Devuelva el numero mas grande 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, suma = 0, maximo = 0;
    printf("\nIngrese numeros enteros (cero para terminar): \n");

    while(1) { /*El while 1 es un bucle infinito, hasta que yo lo termine*/
        scanf("%d", &numero);
        if (numero == 0) {
            break; /*Si el numero es cero, salimos del bucle*/
        } 
        suma += numero; /*Acumulamos la suma de los numeros ingresados*/
        if (numero > maximo) {
            maximo = numero; /*Si el numero ingresado es mayor que el maximo, lo actualizamos*/
        }
    }

    printf("\nLa suma de los numeros ingresados es: %d\n", suma);
    printf("\nEl numero mas grande de todos los numeros ingresados es el %d\n\n", maximo);

    return 0;
}