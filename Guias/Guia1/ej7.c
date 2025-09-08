/* Realice un codigo que, tomando un uint16 como entrada, defina si el numero es o no par.
   a) utilizando el operador %
   b) sin utilizar el operador %
*/

#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t entrada = 50001;

    /* ------- ITEM a ------- */
    /* Usando el operador % */ 
    if (entrada % 2 == 0) {
        printf("El numero ");
        for (int i = 15; i >= 0; i--) {
            printf("%d", (entrada >> i) & 1);
        }
        printf(" es par.\n");
    } else {
        printf("El numero ");
        for (int i = 15; i >= 0; i--) {
            printf("%d", (entrada >> i) & 1);
        }
        printf(" es impar.\n");
    }

    /* ------- ITEM b ------- */ 
    /* Sin usar el operador % */
    if ((entrada & 1) == 0) { /*Un número es par si su bit menos significativo es 0*/
        printf("El numero ");
        for (int i = 15; i >= 0; i--) {
            printf("%d", (entrada >> i) & 1);
        }
        printf(" es par.\n");
    } else {
        printf("El numero ");
        for (int i = 15; i >= 0; i--) {
            printf("%d", (entrada >> i) & 1);
        }
        printf(" es impar.\n");
    }


    return 0;
}