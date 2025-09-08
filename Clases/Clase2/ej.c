/* union --> si tengo x numero finito de datos, y quiero guardar un solo dato que no se relaciona con los otros uso un union */
/* Si en algun valor me paso de la cantidad de espacio que puede tener, me imprime un numero que no tiene nada que ver con el original (lo rompe). 
   El signo menos es porque el numero despues de hasta donde mi computadora puede guardar es un 1. */
/* Si declaro un char y le pongo un numero, me hace la conversion con la tabla aski, y me escribe la letra (o char) que corresponda a ese numero.
   Es independiente si escribo numero o letra, ya sea short, long, char, etc. a la computadora le da lo mismo, me lo va a pasar a lo que le pase como valor (int, char, long), me lo "transforma" */
/* Si es un booleano: --> if (is_ok)
                      --> if (!is_ok)
*/
/* En C, son consideradas TRUE todas las variables distintas de cero. */

/* 1- Piense una estructura para guardar los datos bancarios de una persona, estos son: 
    - Nombre (max 20 caracteres)
    - Numero de cuenta
    - En caso de ser argentino, DNI (10 digitos)
    - En caso de no ser argentino, pasaporte (12 digitos)

    Utilizar la menos cantidad de memoria posible

  2- Inicialize los datos e imprima los valores.*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char nombre[20];
    short nroCuenta;
    short esArg; /* Es por si tengo un archivo de mil datos, el programa va a leer unos y ceros, entonces con eso es mas facil reconocer si es argentino o no. */

    union nacionalidad{
        int DNI;
        char pasaporte[12];
    } nacionalidad;
} datos_t; /* Si pongo "dato_t", es para indicar que es un tipo de dato */

int main() {
    datos_t persona1 = {
        .nombre = "Catalina",
        .nroCuenta = 33,
        .esArg = 1, /*Es un booleano, entonces es verdadero*/
        .nacionalidad.DNI = 44714717
    };

    printf("\nNombre: %s\n", persona1.nombre); /* Si pongo %c es porque tengo un solo caracter, si pongo %s tengo una cadena de caracteres */
    printf("Numero de cuenta: %ld\n", persona1.nroCuenta);

    if (persona1.esArg) {
        printf("DNI: %d\n", persona1.nacionalidad.DNI);
    } else {
        strcpy(persona1.nacionalidad.pasaporte, "ABC123456");
        printf("\nPasaporte: %s\n", persona1.nacionalidad.pasaporte);
    }
    
/*
    printf("DNI: %d\n\n", persona1.nacionalidad.DNI);
    strcpy(persona1.nacionalidad.pasaporte, "ABC123456");

    printf("\nPasaporte: %s\n", persona1.nacionalidad.pasaporte);
    printf("DNI: %d\n\n", persona1.nacionalidad.DNI);

Es otra manera, pero queda mejor con el esArg, mas facil cuando tengo archivos grandes 
Si hago esta manera, voy a ver como se me pisan los datos de dni y pasaporte */ 
    printf("\n\n---------------------------------------------------------------------------\n\n");

    datos_t persona2 = {
        .nombre = "Joaquin",
        .nroCuenta = 4,
        .esArg = 0, /*Es un booleano, entonces es verdadero*/
        .nacionalidad.DNI = 44673892
    };

    printf("\nNombre: %s\n", persona2.nombre); /* Si pongo %c es porque tengo un solo caracter, si pongo %s tengo una cadena de caracteres */
    printf("Numero de cuenta: %ld\n", persona2.nroCuenta);

    if (persona2.esArg) {
        printf("DNI: %d\n", persona2.nacionalidad.DNI);
    } else {
        strcpy(persona2.nacionalidad.pasaporte, "ABC123456");
        printf("Pasaporte: %s\n", persona2.nacionalidad.pasaporte);
    }

    return 0;
}