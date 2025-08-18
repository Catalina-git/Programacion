/* Implemente un codigo que imprima los numeros del 1 al 10 usando un bucle for */

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\n=== Numeros del 1 al 10 ===\n\n");
    for (int i = 1; i < 11; i++) {
        printf("%d", i);
        if (i < 10) {
            printf(" - ");
        }
    } 
    printf("\n\n");

    return 0;
}