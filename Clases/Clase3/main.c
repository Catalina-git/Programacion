/* --------------- CONSIGNAS --------------- */

/* ------ EJERCICIO 1 ------ */
/*Crear una funcion dentro de la cual, se le pida el nombre al usuario y se imprima "Hola {nombre}!"*/

/* ------ EJERCICIO 2 ------ */
/* Crear una funcion que tome 2 numeros como entrada e imprima todos los numeros 
   cuya suma de los de los digitos elevado a la cantidad de digitos sea igual al numero original*/

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "funciones.c"

int main() {
   #ifndef ej1

   saludo();

   #endif /* ej1 */

   #ifdef ej2
   
   comparacion(10, 1000);

   #endif /* ej2 */










   return 0;
}