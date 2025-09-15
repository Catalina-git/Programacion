/* Escriba una funcion que recib un puntero a una cadena de caracteres y un caracter, 
   y devuelva la posicion (indice) de la primera ocurrencia del caracter en la cadena. 
   Si el caracter no se encuentra en la cadena, la funcion debe devolver un -1.
   Luego, llame a esta funcion desde main y muestre el resultado. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* Libreria para usar 'tolower' */

int buscarCaracter(const char *cadena, char caracter) {
    int indice = 0;
    char buscado = tolower(caracter);

    /* La funcion 'tolower' convierte cualquier letra a su version minuscula */

    while (cadena[indice] != '\0') {
        if (tolower(cadena[indice]) == buscado) {
            return indice;
        }
        indice++;
    }

    return -1; /* No se encontro ese caracter en la cadena */
}


int main(void) {
    const char *cadena = "Hola Mundo";
    char caracter = 'm';

    int encontrado = buscarCaracter(cadena, caracter);

    if (encontrado != -1) {
        printf("\nEl caracter '%c' se encuentra en la posicion %d.\n", caracter, encontrado);
    } else {
        printf("\nEl caracter '%c' no se encuentra en la cadena.\n", caracter);
    }

    return 0;
}
