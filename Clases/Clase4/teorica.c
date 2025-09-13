#include <stdio.h>
#include <stdlib.h>

/* Un puntero guarda direcciones de memoria, en principio de una variable.
   A su vez, cada puntero tiene su propia direccion de memoria.
   Me sirve para crear estructuras variables.
   Cuando asigno un puntero estoy guardando direcciones de memoria.
   La direccion de memoria me dice donde esta la informacion.
*/

int modificar_variables(int *a, int *b, int *c) { /*Aca le paso la direccion de memoria de cada variable (su cajita) --> me va a permitir cambiar su valor original xq se donde esta */
    *a = 7;
    *b = 14;
    *c = *a * *b;
}


int main(void) {
    int a = 4, b = 0, c = 7;

    modificar_variables(&a, &b, &c);

    printf("\na = %d\nb = %d\nc = %d\n", a, b, c);





    return 0;
}