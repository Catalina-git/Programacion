#include <stdio.h>

/* ------------ EJERCICIO 1 ------------ */
// int a = 3;

// void suma_global(int a) {
//     a+=2;
// }

// int main() {
//     suma_global(0);
//     printf("a vale %d", a);
//     return 0;
// }


/* ------------ EJERCICIO 2 ------------ */
// float contador(void) {
//     static float n = 0;
//     n = n + 1.2;
//     return n;
// }

// int main(void) {
//     int j = 0;
//     j = contador();
//     j = contador();
//     j = contador();

//     printf("j vale: %d", j);

//     return 0;
// }


/* ------------ EJERCICIO 3 ------------ */
// const int x = 10;

// int main(void) {
//     int x = 5;

//     printf("x vale %d\n", x);

//     return 0;
// }


/* ------------ EJERCICIO 5 ------------ */
typedef struct
{
  int prioridad;
  int estado;
  char tipo[15]; 
} modulo_t;

// // bits 0 - 2  : prioridad (0 a 7)
// // bits 3       : estado (0 = inactivo, 1 = activo)
// // bits 4 - 7  : Tipo de módulo
// //                        - 0001 = Sensor
// //                        - 0010 = Actuador
// //                        - 0011 = Controlador
// //                        - 0100 = Comuniación

int main() {
    FILE *archivo;
    modulo_t modulo;

    archivo = fopen("modulos.bin", "rb"); 
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 0;
    }

    rewind(archivo);

    int contador = 0; 
    int suma_prioridad = 0;
    float promedio_prioridad = 0.0;

    while (fread(&modulo, sizeof(modulo_t), 1, archivo) == 1) {
        printf("\n\nPrioridad: %d\n\n", modulo.prioridad);
        suma_prioridad += modulo.prioridad;
        contador++;
    }

    fclose(archivo);

    promedio_prioridad = (float)suma_prioridad / contador;

    printf("\nLa prioridad promedio es: %.3f\n\n", promedio_prioridad);

    return 0;
}




