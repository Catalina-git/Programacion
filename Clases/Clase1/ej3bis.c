/* Mismo ejercicio que el 3 pero otra manera de resolverlo */

#include <stdio.h>

int main() {
    int numOriginal, aux;
    int i, j, cantDigitos = 0;

    printf("\nIngrese un numero decimal: ");
    scanf("%d", &numOriginal);
    while (getchar() != '\n'); /* Limpia el buffer de entrada para evitar problemas con fgets */

    /* La contra de este metodo es que tengo que definir la cantidad de digitos antes */
    /* Cuento la cantidad de digitos */
    aux = numOriginal;
    while (aux != 0) {
        aux /= 10;
        cantDigitos++;
    }

    /* ---------------- PASAJE A BINARIO ---------------- */
    printf("\n---------------- PASAJE A BINARIO ----------------\n\n");
    printf("Número original en binario: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (numOriginal >> i) & 1);
        if (i % 4 == 0) {
            printf(" ");
        }
    }

    /* ---------------- PASAJE A HEXADECIMAL ---------------- */
    printf("\n\n---------------- PASAJE A HEXADECIMAL ----------------\n\n");
    aux = numOriginal;
    printf("Número original en hexadecimal: ");
    for (j = cantDigitos - 1; j >= 0; j--) {
        aux = numOriginal;
        for (i = 0; i < j; i++) {
            aux /= 16;
        }
        if (aux == 0) {
            continue; /* Para no imprimir ceros a la izquierda */
        }

        if ((aux % 16) < 10) {
            printf("%d", (aux % 16));
        } else {
            printf("%c", ((aux % 16) - 10 + 'A')); /* Para pasar de int a char */
        }
    }

    /* ---------------- PASAJE A BDC ---------------- */
    printf("\n\n---------------- PASAJE A BDC ----------------\n");
    aux = numOriginal;
    printf("\nNúmero original en BCD: ");

    for (j = cantDigitos - 1; j >= 0; j--) {
        aux = numOriginal;
        for (i = 0; i < j; i++) {
            aux /= 10;
        }

        for (i = 3; i >= 0; i--) {
            printf("%d", ((aux %= 10) >> i) & 1);
        }
        printf(" ");
    }

    printf("\n\n");

    return 0;

}