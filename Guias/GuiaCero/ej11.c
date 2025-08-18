/* Repita los puntos 9 y 10 para un archivo "nombres.dat" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_nombre 1000

int main() {
    FILE *archivo;
    char nombres[max_nombre];

    archivo = fopen("nombres.dat", "rb+"); // Abrir en modo binario y agregar
    if (archivo == NULL){
        perror("Error al abrir el archivo");
        return 1;
    }

    while(1){
        printf("\nIngrese un nombre (escriba 'Fin' para terminar): ");
        fgets(nombres, sizeof(nombres), stdin);
        nombres[strcspn(nombres, "\n")] = 0; // Elimina el salto de línea

        if (strcasecmp(nombres, "Fin") == 0){
            break; /* Si el usuario escribe fin salgo del bucle */
        }

        fwrite(nombres, sizeof(char), strlen(nombres), archivo);
        fwrite("\n", sizeof(char), 1, archivo); // Agrega salto de línea
        fflush(archivo);
        printf("Nombre agregado correctamente al archivo 'nombres.dat'\n");
    }

    printf("\n\nLos nombres guardados en el archivo 'nombres.dat' son: \n\n");
            rewind(archivo); /*Para mover el puntero al inicio del archivo antes de leerlo*/

        while (fgets(nombres, sizeof(nombres), archivo) != NULL) {
            printf("- %s \n", nombres);
        }
    
    fclose(archivo);
    printf("\nCerrando programa...\n\n");

    return 0;
}