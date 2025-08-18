/* Implemente un codigo que lea e imprima en pantala, todos los datos contenidos en el archivo "nombres.bin" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_nombre 1000

int main() {
    FILE *archivo;
    char nombres[max_nombre];

    archivo = fopen("nombres.bin", "rb"); // Abrir en modo binario y agregar
    if (archivo == NULL){
        perror("Error al abrir el archivo");
        return 1;
    }

    printf("Los nombres guardados en el archivo 'nombres.bin' son: \n\n");
    rewind(archivo); /*Para mover el puntero al inicio del archivo antes de leerlo*/

    while (fgets(nombres, sizeof(nombres), archivo) != NULL) {
        printf("- %s \n", nombres);
    }
    
    fclose(archivo);
    printf("\nCerrando programa...\n\n");

    return 0;
}