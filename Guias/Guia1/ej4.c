/* Implementar un codigo que convierta un numero decimal ingresado por el usuario a binario, octal y hexadecimal.*/

#include <stdio.h>

int main() {
    long numOriginal, aux;
    char numHexa[16];

    printf("\nIngrese un numero decimal: ");
    scanf("%d", &numOriginal);
    while (getchar() != '\n');

    /* ---------------- DECIMAL → BINARIO ---------------- */
    printf("\nNumero ingresado en su formato binario: ");
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numOriginal >> i) & 1);
    }
    printf("\n");


    /* ---------------- DECIMAL → OCTAL ---------------- */
    printf("\nNumero ingresado en su formato octal: %o\n", numOriginal);


    /* ---------------- DECIMAL → HEXADECIMAL ---------------- */
    aux = numOriginal;
    printf("\nNumero ingresado en su formato hexadecimal: ");
    if (aux == 0) {
        printf("0");
    } else {
        int i = 0;
        while (aux > 0) {
            if ((aux % 16) < 10) {
                numHexa[i] = (aux % 16) + '0'; /* Esto es para pasar de int a char */
            } else {
                numHexa[i] = (aux % 16) - 10 + 'A';
            }
            i++;
            aux /= 16;
        }
        for (int j = i - 1; j >= 0; j--) {
        printf("%c", numHexa[j]);
        }
    }

    printf("\n\n");

    return 0;
}