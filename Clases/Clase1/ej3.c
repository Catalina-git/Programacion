/* 1) Pida al usuario ingresar un numero entero decimal. 
   2) Convierta y muestre el numero en sus representaciones:
        - BINARIA
        - HEXADECIMAL
        - BDC 
*/

#include <stdio.h>
#include <string.h>

int main() {
    long numOriginal, aux;
    char numHexa[16];
    int numBDC[164];

    printf("Ingrese un numero decimal: ");
    scanf("%ld", &numOriginal);
    while (getchar() != '\n'); /* Limpia el buffer de entrada para evitar problemas con fgets */

    /* ---------------- PASAJE A BINARIO ---------------- */
    printf("\n---------------- PASAJE A BINARIO ----------------\n\n");
    printf("Numero original en binario: ");
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numOriginal >> i) & 1);
    }
    printf("\n");

    /* ---------------- PASAJE A HEXADECIMAL ---------------- */
    printf("\n---------------- PASAJE A HEXADECIMAL ----------------\n\n");
    aux = numOriginal;
    printf("Numero original en hexadecimal: ");
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

    /* ---------------- PASAJE A BDC ---------------- */
    printf("\n\n---------------- PASAJE A BDC ----------------\n");
    printf("\nNumero original en BDC: ");
    aux = numOriginal;
    int i = 0, j = 0;

    while (aux > 0) {
        numBDC[j++] = aux % 10;
        aux /= 10;
    }
    for (j--; j >= 0; j--) {
        for (i = 3; i >= 0; i--) {
            printf("%d", (numBDC[j] >> i) & 1);
        }
        printf(" ");
    }

    printf("\n\n");

    return 0;
}