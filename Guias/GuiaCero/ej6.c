/* Implemente un codigo que pida al usuario un numero y calcule su factorial utilizando un bucle for/while */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, factorial = 1, i = 1;
    printf("\nIngrese un numero entero positivo: \n");
    scanf("%d", &numero);


    while (i <= numero) {
        factorial *= i;
        i++;
    }
    printf("\nEl factorial de %d es: %d\n", numero, factorial);

    return 0;
}