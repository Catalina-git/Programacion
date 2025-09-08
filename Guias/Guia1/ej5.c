/* Implemente un codigo que convierta un numero decimal ingresado por el usuario
   a su representacion en BDC y viceversa. */

#include <stdio.h>

int main(){
    long numOriginal, aux, numOriginal2;
    int numBDC[164];

    printf("\nIngrese un numero decimal: ");
    scanf("%d", &numOriginal);
    while (getchar() != '\n');

    /* ---------------- DECIMAL → BDC ---------------- */
    printf("El numero ingresado en su formato BDC es: ");
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

    /* ---------------- BDC → DECIMAL ---------------- */

    printf("\n\nIngrese un numero en BDC: ");
    scanf("%lx", &numOriginal2); /* El %lx es porque lee en hexadecimal */
    while (getchar() != '\n');

    long decimal = 0;
    long factor = 1;
    aux = numOriginal2;

    /* Tomo de a 4 bits (1 digito BDC) y reconstruyo el decimal */
    while (aux > 0) {
        int digito = aux & 0xF; /* Obtengo los ultimos 4 bits */
        decimal += digito * factor;
        aux >>= 4; /* Avanzo 4 bits */
        factor *= 10;
    }

    printf("El numero ingresado en decimal es: %ld\n", decimal);

    printf("\n\n");

    return 0;
}