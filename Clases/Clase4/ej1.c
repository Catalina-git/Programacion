#include <stdio.h>
#include <stdlib.h>

void intercambio(int *ptr_a, int *ptr_b) { /*"int *a" --> a es un puntero * que apunta a un int --> a es una direccion de memoria
    Para modificar la variable hago "*a" --> eso me dice lo que esta adentro de la direccion de memoria*/
    int aux = *ptr_a; 
    *ptr_a = *ptr_b; /* Lo que tengo en ptr_b, lo pego en ptr_a --> lo leo de derecha a izquierda */
    *ptr_b = aux;
}   

int main(void) {
    int a = 4, b = 0, c = 7;
    int ptr_a = &a;

    printf("\nAntes del intercambio...\na = %d \nb = %d\n", a, b);

    intercambio(ptr_a, &b);

    printf("\nLuego del intercambio...\na = %d \nb = %d\n", a, b);

}
