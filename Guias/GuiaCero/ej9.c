/*Implemente un codigo que pida nombres y los guarde en un archivo "nombres.bin", hasta que el usuario ingrese "Fin"*/

#include <stdio.h>
#include <string.h>

#define max_nombre 1000

int main() {
    FILE *archivo;
    char nombres[max_nombre];

    archivo = fopen("nombres.bin", "ab"); // Abrir en modo binario y agregar
    if (archivo == NULL){
        perror("Error al abrir el archivo");
        return 1;
    }

    while(1){
        printf("\nIngrese un nombre (escriba 'Fin' para terminar): ");
        fgets(nombres, sizeof(nombres), stdin);
        nombres[strcspn(nombres, "\n")] = 0; // Elimina el salto de línea

        if (strcasecmp(nombres, "Fin") == 0){
            break;
        }

        fwrite(nombres, sizeof(char), strlen(nombres), archivo);
        fwrite("\n", sizeof(char), 1, archivo); // Agrega salto de línea
        fflush(archivo);
        printf("Nombre agregado correctamente al archivo 'nombres.bin'\n");
    }

    fclose(archivo);
    printf("Cerrando programa...\n\n");
    return 0;
}
