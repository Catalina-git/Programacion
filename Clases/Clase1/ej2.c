/* Escriba un programa en C que: 
   1) Pida al usuario ingresar un numero decimal.
   2) Pida al usuario una mascara (numero entero decimal).
   3) Muestre las representaciones binarias de ambos.
   4) Aplique al numero original las operaciones (AND, OR, NOT y MODULO), y muestre el resultado en binario.
*/

#include <stdio.h>
#include <string.h>

int main() {
    long numOriginal, numMascara;

    /* ---------------- ITEM 1 ----------------*/
    printf("\n\n---------------- ITEM 1 ----------------\n\n");
    printf("Ingrese un numero decimal: ");
    scanf("%ld", &numOriginal);
    while (getchar() != '\n');

    /* ---------------- ITEM 2 ----------------*/
    printf("\n---------------- ITEM 2 ----------------\n");
    printf("\nIngrese un numero mascara (numero entero decimal): ");
    scanf("%ld", &numMascara);
    while (getchar() != '\n');

    /* ---------------- ITEM 3 ----------------*/
    printf("\n---------------- ITEM 3 ----------------\n\n");
    printf("Numero original: ");
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numOriginal >> i) & 1);
    }

    printf("\nNumero mascara: ");
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numMascara >> i) & 1);
    }

    /* Estos for recorren todo el numero que ingreso el usuario, desde el bit 15 (el de la izquierda) hasta el bit 0 (el de la derecha), y muestran si ese bit es 0 o 1
       - num >> i: desplaza los bits de num hacia la derecha i posiciones. Esto hace que el bit que estaba en la posicion i pase a la posicion 0.
       - & 1: hace una mascara binaria con todos ceros menos el bit en la posicion 0 que es 1, para extraer solo el bit menos significativo (el que quedo en la posicion 0).
       - Y luego el printf imprime ese bit como un numero (0 o 1)
    */

   printf("\n");

    /* ---------------- ITEM 4 ---------------- */
    printf("\n---------------- ITEM 4 ----------------\n");
    printf("\nAND: ", numOriginal & numMascara);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numOriginal & numMascara >> i) & 1);
    }

    printf("\nOR: ", numOriginal | numMascara);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numOriginal | numMascara >> i) & 1);
    }

    printf("\nNOT: ", ~numOriginal);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", ((~numOriginal) >> i) & 1);
    }

    printf("\nNOT: ", ~numMascara);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", ((~numMascara) >> i) & 1);
    }

    printf("\nMODULO: ", numOriginal % numMascara); /* Aca el modulo es el resto de dividir ambos numeros */
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numOriginal % numMascara >> i) & 1);
    }

    printf("\n\n");

    return 0;
}