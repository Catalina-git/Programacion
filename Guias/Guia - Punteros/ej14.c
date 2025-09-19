/* Dado el array de numeros del archivi 'lista.h':
   a. Calcule la suma de todos los numeros del vector.
   b. Calcule el promedio de todas las direcciones de memoria de los numeros del vector. 
   c. Ordene los numeros de menor a mayor, de acuerdo a la suma de sus digitos.
      Por ejemplo: 32, 50, 19 -- sorted --> 32,  50, 19 o 50, 32, 19
      Imprima los primeros y ultimos 5 numeros del vector ordenado, junto con sus direcciones de memoria.
   d. Modifique los valores de los numeros en el array de acuerdo a las siguientes condiciones: 
        i. Si la direccion de memoria, en binario, tiene una cantidad PAR de unos, multipliquelo por 5.
        ii. Si el numero es IMPAR dividalo por 5.
    e. Calcule una vez mas la suma de los numeros y el promedio de las direcciones de memoria del vector. 
       Imprima un mensaje indicando si son iguales o distintos que los calculados anteriormente. 
      */

#include <stdio.h>
#include <stdlib.h>

/* ITEM a */
int suma(int lista[], int largo) {
    int suma = 0;

    for (int i = 0; i < largo; i++) {
        suma += lista[i];
    }

    return suma;
}

/* ITEM b */
float promedioDirecciones(int lista[], int largo) {
    uintptr_t suma = 0; /* uintptr_t es un tipo de dato que toma la direccion de memoria y la convierte en un entero */

    for (int i = 0; i < largo; i++) {
        suma += (uintptr_t)lista[i];
    }

    float promedio = suma / largo;

    return promedio; 
}

/* ITEM c */
int sumadorDigitos(int num) {
    int resto;
    int suma = 0;

    while (num % 10 > 0 || (num / 10) != 0) {
        resto = num % 10;
        num = num / 10;
        suma += resto;
    }

    return suma;
}

void intercambio(int *ptr_a, int *ptr_b) { /*"int *a" --> a es un puntero * que apunta a un int --> a es una direccion de memoria
    Para modificar la variable hago "*a" --> eso me dice lo que esta adentro de la direccion de memoria*/
    int aux = *ptr_a; 
    *ptr_a = *ptr_b; /* Lo que tengo en ptr_b, lo pego en ptr_a --> lo leo de derecha a izquierda */
    *ptr_b = aux;
}  

void BubbleSort(int *lista, int longitud) {
    for (int j = 0; j < longitud - 1; j++) {
        for (int i = 0; i < longitud - j - 1; i++) {
            int suma1 = sumadorDigitos(lista[i]);
            int suma2 = sumadorDigitos(lista[i + 1]);
            if (suma1 > suma2) {
                intercambio(&lista[i], &lista[i + 1]);
            }
        }
    }
}

void mostrarLista(int lista[], int longitud){
    printf("\nPrimeros 5 elementos de la lista...\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor: %d  -  Direccion de memoria: %p\n", lista[i], &lista[i]);
    }

    printf("\nUltimos 5 elementos de la lista...\n");
    for (int j = longitud; j > longitud - 5; j--) {
        printf("Valor: %d  -  Direccion de memoria: %p\n", lista[j], &lista[j]);
    }
}

void mostrarVector(int *vector, int longitud){
    for (int i = 0; i < longitud; i++) {
        printf("%d - ", vector[i]);
    }

    printf("\n");
}

/* ITEM d */
int contadorUnos(int* numero) {
    int temporal = (uintptr_t)numero;
    int cantidadUnos = 0; 

    for (int i = 0; i < 31; i++) {
        int aux = (temporal>>i) & 1;
        if (aux == 1) {
            cantidadUnos++;            
        }
        temporal = numero;
    }

    return cantidadUnos;
}


int main(void) {
    int lista[] = {32, 19, 51, 14, 45, 89, 776, 132, 147, 90, 54, 35};
    int largo = sizeof(lista) / sizeof(lista[0]);

    printf("\n---------------- Punto a) ----------------\n");

    int sum = suma(lista, largo);
    printf("\nLa suma de todos los numeros del vector es: %d\n", sum);


    printf("\n\n---------------- Punto b) ----------------\n");

    float prom = promedioDirecciones(lista, largo);
    printf("\nEl promedio de todas las direcciones de memoria es: %.3f\n", prom);


    printf("\n\n---------------- Punto c) ----------------\n");

    printf("\nLista inicial...\n");
    mostrarVector(lista, largo);
    BubbleSort(lista, largo);
    printf("\nLista ordenada con BubbleSort...\n");
    for (int i = 0; i < largo; i++) {
        printf("Valor: %d  -  Direccion de memoria: %p\n", lista[i], &lista[i]);
    }


    printf("\n\n---------------- Punto d) ----------------\n");

    for (int i = 0; i < largo; i++) {
        int unos = contadorUnos(&lista[i]);
        if (unos % 2 == 0) {
            lista[i] = lista[i] * 5;
        } else {
            lista[i] = lista[i] / 5;
        }
    }

    printf("\n");
    mostrarVector(lista, largo);


    printf("\n\n---------------- Punto e) ----------------\n");

    int sum2 = suma(lista, largo);
    printf("\nLa suma de todos los numeros del vector modificado es: %d\n", sum2);
    if (sum == sum2) {
        printf("\nLas sumas son iguales.\n");
    } else {
        printf("\nLas sumas son distintas.\n");
    }

    int prom2 = suma(lista, largo);
    printf("\nEl promedio de todas las direcciones de memoria del vector modificado es: %.3f\n", prom2);
    if (prom == prom2) {
        printf("\nLos promedios son iguales.\n");
    } else {
        printf("\nLos promedios son distintos.\n");
    }

    return 0;
}
