/* Realice un codigo que, tomando un uint16 como entrada, 
   devuelva los 8 bits mas significativos. 
   Ej: 1001 0101 1110 0100 --> 1001 0101*/

#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t entrada = 50000; 

    uint8_t salida = (entrada >> 8) & 0xFF;

    printf("\nMi entrada en binario es: ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (entrada >> i) & 1);
    }
    printf("\n");

    printf("\nEntonces mi salida en binario es: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (salida >> i) & 1);
    }
    
    printf("\n");

    return 0;
}