/* Armar un codigo en C para mostrar por pantalla los diferentes tamaños de los tipos:
   - char
   - short
   - int
   - long
   - float
   - double
*/

#include <stdio.h>

int main() {
    char c = 'A';
    short s = 0303;
    int i = 3;
    long l = 922337;
    float f = 0.5;
    double dd = 3.5;

    printf("\nTamaño de un char: %ld", sizeof(c));
    printf("\nValor = %c", c);

    printf("\n\nTamaño de un short: %ld", sizeof(s));
    printf("\nValor = %d", s);

    printf("\n\nTamaño de un int: %ld", sizeof(i));
    printf("\nValor = %d", i);

    printf("\n\nTamaño de un long: %ld", sizeof(l));
    printf("\nValor = %ld", l);

    printf("\n\nTamaño de un char: %ld", sizeof(f));
    printf("\nValor = %f", f);

    printf("\n\nTamaño de un char: %ld", sizeof(dd));
    printf("\nValor = %f", dd);

    return 0;
}