/* Escriba un programa que se encargue de manejar el inicio de sesion de una computadora. 
   Este debe constar de 4 opciones: 
        a. Crear usuario: pida al usuario un nombre y contraseña y los guarde en un archivo "credenciales.bin".
        b. Iniciar sesion: pida al usuario un nombre y contraseña y los compare con los guardados.
        c. Cambiar nombre.
        d. Cambiar contraseña.
*/

#include <stdio.h>
#include <string.h>

int main() {
        FILE *archivo;
        int opcion;

        archivo = fopen("credenciales.bin", "ab+");
        if (archivo == NULL) {
                perror("Error al abrir el archivo");
                return 1;
        }

        do {
                printf("\n-----------------------------------------");
                printf("\nSeleccione una opcion\n");
                printf("\t1: Crear usuario\n");
                printf("\t2: Iniciar sesion\n");
                printf("\t3: Cambiar nombre\n");
                printf("\t4: Cambiar contrasena\n");
                printf("\t5: Salir\n");
                printf("\t0: Cerrar programa\n");
                printf("\nOpcion: ");
                scanf("%d", &opcion);
                while (getchar() != '\n'); /*Limpiar el buffer de entrada*/

                switch (opcion) {
                        case 1:
                                char nombre[100], contrasena[100];

                                /* Creo y guardo el nombre de usuario */
                                printf("Ingrese un nombre de usuario: ");
                                fgets(nombre, sizeof(nombre), stdin);
                                nombre[strcspn(nombre, "\n")] = 0;

                                /* Creo y guardo la contraseña */
                                printf("Ingrese una contrasena: ");
                                fgets(contrasena, sizeof(contrasena), stdin);
                                contrasena[strcspn(contrasena, "\n")] = 0; 

                                fwrite(nombre, sizeof(char), strlen(nombre), archivo);
                                fwrite("\n", sizeof(char), 1, archivo); // Agrega salto de línea
                                fflush(archivo);
                                printf("Usuario creado correctamente\n");

                                break;

                        case 2: 
                                char nombre_login[100], contrasena_login[100];

                                /* Pido el nombre de usuario */
                                printf("Ingrese su nombre de usuario: ");
                                fgets(nombre_login, sizeof(nombre_login), stdin);
                                nombre_login[strcspn(nombre_login, "\n")] = 0;

                                /* Pido la contraseña */
                                printf("Ingrese su contrasena: ");
                                fgets(contrasena_login, sizeof(contrasena_login), stdin);
                                contrasena_login[strcspn(contrasena_login, "\n")] = 0;

                                char linea[200];
                                int encontrado = 0;

                                rewind(archivo); // Volver al inicio del archivo
                                while (fgets(linea, sizeof(linea), archivo) != NULL) {
                                        char *nombre_archivo = strtok(linea, "\n");
                                        char *contrasena_archivo = strtok(NULL, "\n");
                                        if (nombre_archivo && contrasena_archivo) {
                                                if (strcmp(nombre_login, nombre_archivo) == 0 && strcmp(contrasena_login, contrasena_archivo) == 0) {
                                                        printf("Inicio de sesion exitoso\n");
                                                        encontrado = 1;
                                                        break;
                                                }
                                        }
                                }
                                if (!encontrado) {
                                        printf("Nombre de usuario o contrasena incorrectos\n");
                                }

                                break;

                        case 3: 
                        
    
        }








        return 0;
}