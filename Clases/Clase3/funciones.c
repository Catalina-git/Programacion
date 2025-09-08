#include <stdio.h>
#include <string.h>
#include <math.h>

void saludo(void) {
    char nombre[20];

    printf("Ingrese su nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    printf("Hola %s!\n", nombre); /* El %s me imprime una cadena de caracteres, si pongo %c me imprime un solo caracter */

    return;
}

void comparacion(int start, int end) { /* Le paso un intervalo, y que me analice cada numero en ese intervalo */
    /* Separo el numero en digitos --> Uso el resto de la division por diez */
    /* Contar cuantos digitos tiene el numero --> divido al numero por diez n veces hasta que tenga un numero de una cifra, y el numero original tiene n + 1 digito*/
    /* Hago la suma, elevo y comparo */
    int numero;
    int cantidad_digitos = 0, suma = 0;

    for (int i = start; i < end + 1; i++) {
        numero = 1;
        suma = 0;
        while (numero > 0) {
            /*printf("%d\n", numero % 10); -->  8     5   4   2 */
            numero /= 10;                   /* 245   24   2   0 */
            /* Es lo mismo que hacer num = num / 10*/
            cantidad_digitos++;
        }

        numero = i;
        while (numero > 0) {
            suma += pow((numero % 10), cantidad_digitos);
            numero /= 10;
        }

        if (suma == i) {
            printf("%d cumple las condiciones\n", i);
        }
    }
    
}