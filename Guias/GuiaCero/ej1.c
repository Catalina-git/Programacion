/* Implemente un codigo que pida al usuario un numero y determine si es par o impar */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    printf("Ingrese un numero entero: \n");
    scanf("%d", &numero);

    if (numero == 0) {
        printf("El numero es cero.\n");
        return 0;
    } else if(numero % 2 == 0) {
        printf("El numero %d es par.\n", numero);
    } else {
        printf("El numero %d es impar.\n", numero);
    }
    
    return 0;
}
