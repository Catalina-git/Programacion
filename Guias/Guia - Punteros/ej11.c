/* Escriba una funcion que reciba dos punteros a cadenas de caracteres 
   y copie el contenido de la segunda cadena en la primera. 
   Luego, llame a esta funcion desde main 
   y muestre las cadenas antes y despues de la copia.
   */

#include <stdio.h>
#include <stdlib.h>

void copiarCadena(char *cadena1, const char *cadena2) { 
    /* --> Uso 'char' cuando voy a modificar el contenido de la cadena.
       --> Uso 'const char' cuando no voy a modificar la cadena, solo leerla */
    while (*cadena2 != '\0') {
        *cadena1 = *cadena2;
        *cadena1++;
        *cadena2++;
    }
    
    *cadena1 = '\0'; /* Me aseguro que sea el fin de la cadena */
}

int main(void) {
    char cadena1[100] = "Hola Mundo";
    const char *cadena2 = "Nuevo Hola Mundo";
    
    printf("\nCadenas antes de la copia...\n");
    printf("Cadena 1: %s\n", cadena1);
    printf("Cadena 2: %s\n", cadena2);

    copiarCadena(cadena1, cadena2);

    printf("\nCadenas despues de la copia...\n");
    printf("Cadena 1: %s\n", cadena1);
    printf("Cadena 2: %s\n", cadena2);

    return 0;
}
