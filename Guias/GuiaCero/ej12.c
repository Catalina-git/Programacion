/* Implemente un codigo que lea un archivo de texto y cuente cuantas lineas tiene*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *archivo;
    int contador = 1; /*Contador para ir contando cuantas lineas tiene el archivo*/
    char c; /*Variable para almacenar cada caracter leido*/

    archivo = fopen("nombres.txt", "r"); // Abrir en modo binario y agregar
    if(archivo == NULL){
        perror("Error al abrir el archivo de texto");
        return 1;
    }

    /*Tengo que ir recorriendo el archivo y leyendolo, y voy a ir aumentando el contador a medida que hay un slato de linea */
    while ((c = fgetc(archivo)) != EOF){ /* Lee el archivo caracter por caracter hasta llegar al final (EOF) */
        if (c == '\n'){
            contador++;
        }   
    }

    fclose(archivo);
    printf("\nEl archivo 'nombres.txt' tiene %d lineas\n\n", contador);

    return 0;
}