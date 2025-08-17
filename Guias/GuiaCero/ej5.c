#include <stdio.h>
#include <stdlib.h>

int main() {
    int vector[5];
    printf("\nIngrese 5 numeros enteros:\n"); 
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vector[i]);
    }

    printf("\nLos numeros ingresados son:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d  ", vector[i]);
    } 

    return 0;
}