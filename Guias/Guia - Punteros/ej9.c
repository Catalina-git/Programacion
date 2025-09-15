/* Escribe una funcion que reciba un puntero a una cadena (\\0 representa el final de la cadena)
   de caracteres (string) y devuelva su longitud.
   Luego, llama a esta funcion desde main y muestre el resultado */

#include <stdio.h>
#include <stdlib.h>

int longitudCadena(const char *cadena) {
    int longitud = 0;

    while (cadena[longitud] != '\0') {
        longitud++;
    }

    return longitud;
}

int main(void) {
    const char *texto = "Hola Mundo!";
    int resultado = longitudCadena(texto);

    printf("\nLa cadena tiene una longitud de: %d\n", resultado);

    return 0;
}