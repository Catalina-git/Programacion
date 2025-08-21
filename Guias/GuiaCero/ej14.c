/* Escriba un programa que se encargue de manejar el inicio de sesion de una computadora. 
   Este debe constar de 4 opciones: 
        a. Crear usuario: pida al usuario un nombre y contraseña y los guarde en un archivo "credenciales.bin".
        b. Iniciar sesion: pida al usuario un nombre y contraseña y los compare con los guardados. 
        --> tengo que recorrer el archivo "credenciales.bin" y ver si el nombre de usuario ingresado coincide con alguno de los guardados en el archivo.
        c. Cambiar nombre.
        d. Cambiar contraseña.
*/

#include <stdio.h>
#include <string.h>

int main() {
        FILE *archivo;
        int opcion;
        char nombre[100], password[100];
        char nombreIngresado[100], passwordIngresada[100]; /* Son las variables que voy a usar para que el usuario pueda iniciar sesion */
        char nuevoNombre[100];
        int encontrado = 0;

        archivo = fopen("credenciales.bin", "r+b"); /* Abrir el archivo en modo lectura y escritura binaria */
        if (archivo == NULL) {
                perror("Error al abrir el archivo");
                return 1;
        }

        do {
                printf("\n----------------------------------------------------------\n");
                printf("\nSeleccione una opcion\n");
                printf("\t1: Crear usuario\n");
                printf("\t2: Iniciar sesion\n");
                printf("\t3: Cambiar nombre\n");
                printf("\t4: Cambiar contraseña\n");
                printf("\t5: Salir\n");
                printf("\nOpcion: ");
                scanf("%d", &opcion);
                while (getchar() != '\n'); /*Limpiar el buffer de entrada*/

                switch (opcion) {
                        case 1:
                                printf("\nIngrese un nombre de usuario: ");
                                fgets(nombre, sizeof(nombre), stdin);
                                nombre[strcspn(nombre, "\n")] = 0; /* Elimina el salto de línea */

                                printf("Ingrese una contraseña: ");
                                fgets(password, sizeof(password), stdin);
                                password[strcspn(password, "\n")] = 0; /* Elimina el salto de línea */

                                fprintf(archivo, "%s\n", nombre); /* Guardar el nombre en el archivo */
                                fprintf(archivo, "%s\n", password); /* Guardar la contraseña en el archivo */
                                /* fwrite(nombre, sizeof(char), strlen(nombre) + 1, archivo); /* El + 1 es para incluir el caracter nulo '\0' 
                                -> en la memoria los nombres se guardan asi: 'j' 'o' 'a' 'q' 'i' 'n' '\0' 
                                fwrite(password, sizeof(char), strlen(password) + 1, archivo); */
                                fflush(archivo);
                                printf("\nUsuario creado exitosamente!\n");

                                break;

                        case 2: 
                        /* Voy a hacer un bucle, hasta que el nombre ingresado coincida con alguno de los guardados, o con ninguno */ 
                                rewind(archivo); /* Mover el puntero al inicio del archivo */
                                encontrado = 0;

                                printf("\nIngrese su nombre de usuario: ");
                                fgets(nombreIngresado, sizeof(nombreIngresado), stdin);
                                nombreIngresado[strcspn(nombreIngresado, "\n")] = 0;
                                
                                printf("Ingrese su contraseña: ");
                                fgets(passwordIngresada, sizeof(passwordIngresada), stdin);
                                passwordIngresada[strcspn(passwordIngresada, "\n")] = 0;

                                while (fgets(nombre, sizeof(nombre), archivo) && fgets(password, sizeof(password), archivo)) {
                                /* Primero se ejecuta el fgets(nombre...), si eso es verdadero (se cumple), se va a ejecutar el fgets(password...) 
                                   ---> el fgets lee el input del usuario, lo uso para guardar lo que el usuario ingresa*/
                                        nombre[strcspn(nombre, "\n")] = 0;
                                        password[strcspn(password, "\n")] = 0;

                                        if (strcmp(nombre, nombreIngresado) == 0) {
                                                encontrado = 1;
                                                if(strcmp(password, passwordIngresada) == 0) {
                                                        printf("\nInicio de sesion exitoso! Bienvenido/a %s\n", nombreIngresado);
                                                        break;
                                                } else {
                                                        printf("\nContraseña incorrecta. Intente de nuevo.\n");
                                                        break;
                                                }
                                        }
                                }
                                
                                if (!encontrado) {
                                        printf("\nNombre de usuario no encontrado. Intente de nuevo.\n");
                                        break;
                                }

                                break;
                        case 3: 
                        /* Tengo que buscar el nombre de usuario que se desea cambiar --> pido al usuario el nombre que quiere cambiar
                           Despues busco ese nombre en el archivo, si encuentro uno que coincida lo guardo en una variable temporal, y la modifico por el nuevo nombre*/
                                rewind(archivo); /* Mover el puntero al inicio del archivo */
                                encontrado = 0;

                                printf("\nIngrese el nombre de usuario que desea cambiar: ");
                                scanf("%s", nombreIngresado);

                                while (fgets(nombre, sizeof(nombre), archivo)) {
                                /* Primero se ejecuta el fgets(nombre...), si eso es verdadero (se cumple), se va a ejecutar el fgets(password...) 
                                   ---> el fgets lee el input del usuario, lo uso para guardar lo que el usuario ingresa*/
                                        nombre[strcspn(nombre, "\n")] = 0;
                                        /* Si el nombre ingresado por el usuario coincide con el nombre guardado en el archivo, lo reemplazo */
                                        /* strcmp() compara dos cadenas de caracteres y devuelve 0 si son iguales */

                                        if (strcmp(nombre, nombreIngresado) == 0) {
                                                encontrado = 1;
                                                /* Le pido al usuario que ingrese el nuevo nombre de usuario y lo guardo en 'nombre' para reemplazar el existente*/
                                                printf("Ingrese el nuevo nombre de usuario: ");
                                                scanf("%s", nuevoNombre);

                                                fseek(archivo, -strlen(nombre) - 1, SEEK_CUR); /* Mover el puntero al inicio del nombre encontrado, para poder reemplazarlo */
                                                fwrite(nuevoNombre, sizeof(char), strlen(nuevoNombre), archivo); /* Reemplazar el nombre en el archivo */
                                                fflush(archivo); /* Asegurar que los cambios se guarden en el archivo */
                                        }
                                }
                                
                                if (!encontrado) {
                                        printf("\nNombre de usuario no encontrado. Intente de nuevo.\n");
                                        break;
                                } else {
                                        printf("\nNombre de usuario cambiado exitosamente!\n");
                                }

                                break;

                        case 4: 
                        
                                break;
                        case 5: 
                                printf("\nSaliendo del programa...\n");
                                fclose(archivo);
                                return 0;
                        default:
                                printf("Opcion no valida. Intente de nuevo.\n");
                                break;
                }
        } while (opcion != 5);

        fclose(archivo);

        return 0;
}

