/* Implemente un codigo que pida al usuario una palabra y busque cuantas veces aparece esa palabra en un archivo de texto */

#include <stdio.h>
#include <string.h>

#define MAX_LINEA 1000

int main() {
    FILE *archivo;
    char palabra[100], linea[MAX_LINEA], *posicion;
    int contador = 0;

    archivo = fopen("nombres.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    printf("Ingrese la palabra que desea buscar en el archivo: ");
    scanf("%99s", palabra); /* Lee una palabra (sin espacios) del teclado, maximo 99 caracteres (evita el overflow)*/

    while (fgets(linea, MAX_LINEA, archivo) != NULL) { /*Lee una linea del archivo por vez (incluye el '\n' si es que hay) */
        posicion = linea; /* Empiezo buscando por el principio de la lista */
        while ((posicion = strstr(posicion, palabra)) != NULL) { /*Busca 'palabra' dentro de 'posicion' */
            contador++; /* Si la encuentra, incrementa el contador */
            posicion += strlen(palabra); /*Avanzo el puntero despues de que coincida la palabra leida con la buscada*/
        }
    }

    fclose(archivo);

    printf("La palabra '%s' aparece %d veces en el archivo.\n", palabra, contador);
    return 0;
}