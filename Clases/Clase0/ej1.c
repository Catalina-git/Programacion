/*
Gestion de Empleados en una Empresa
Escriba un programa que gestione los empleados de una empresa. 
Los dats deben manejarse a traves de archivos binerios.
Este debe constar de las siguientes opciones: 

1) Agregar nombre
    Pida al usuario el nombre del empleado.
    Guarde el nombre en un archivo nombres.bin como un registro unico
    
2) Mostrar nombres
    Lea todos los nombres del archivo y muestrelos en un formato legible.
    
3) Buscar nombre 
    Pida al usuario el nombre del empleado.
    Si este esta en la lista imprima el nombre y la posicion.
*/

#include <stdio.h>
#include <string.h>

int main () {
    FILE *file;
    const char *filename = "nombres.bin";

    char empleado[20], buscado[20];
    int opcion, posicion;
    int encontrado = 0;

    file = fopen(filename, "wb+"); /* Lee el archivo */
    if (file == NULL)
        perror("Error al abrir el archivo");

    do {
        printf("\n\nSeleccione una opcion\n");
        printf("\t1: Agregar nombre\n");
        printf("\t2: Mostrar nombre\n");
        printf("\t3: Buscar nombre\n");
        printf("\t0: Cerrar programa\n");

        printf("\nOpcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n');

        switch (opcion) {
            case 0:
                printf("\nCerrando programa...");
                break;

            case 1:
                printf("\nIngrese el nombre del empleado: ");
                fgets(empleado, sizeof(empleado), stdin); /*fgets lo uso para guardar lo que el usuario escribio. Lee el input del usuario, parecido al scanf*/
                empleado[strcspn(empleado, "\n")] = 0; /*Esto es para no guardaar el \n*/

                fseek(file, 0, SEEK_END); /* Mover el puntero al final del archivo */
                fwrite(&empleado, sizeof(empleado), 1, file);

                printf("Nombre agregado y guardado correctamente en el archivo nombres.bin.\n");
                break;

            case 2:
                rewind(file); /*Vuelvo al principio del archivo*/
                while (fread(&empleado, sizeof(empleado), 1, file) != 0) {
                    printf("%s \n", empleado);
                };
                break;

            case 3:
                rewind(file);
                /* 1. Pido un nombre al usuario
                   2. Recorro el archivo y comparo con el nombre ingresado
                   3. Devuelvo la posicion o no encontrado */
                printf("\nIngrese la empleado: ");
                fgets(buscado, sizeof(buscado), stdin);
                buscado[strcspn(buscado, "\n")] = 0; /* Limpia el buffer */

                encontrado = 0;
                posicion = 1;

                while (fread(&buscado, sizeof(buscado), 1, file) != 0) {
                    if (strstr(buscado, empleado) != NULL) { /*strstr = stringstring, compara dos strings */
                        printf("Se encontro el nombre del empleado: %s\n", buscado);
                        encontrado = 1;
                        break;
                    }
                    posicion++;
                };
                printf("El nombre %s se encontro en la posicion: %d", buscado, posicion);

                if (encontrado != 1)
                    printf("No se encontró el nombre buscado.\n");
                break;

            default:
            printf("\nOpcion invalida\n");
            break;
        }
    } while (opcion != 0);

    fclose(file);
    return 0;

}