#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    printf("\nIngrese un numero del 1 al 7: ");
    scanf("%d", &numero);
    printf("\n");
    if (numero == 1) {
        printf("\nEL dia de la semana que corresponde al numero ingresado es LUNES.\n\n");
    } else if(numero == 2) {
        printf("\nEL dia de la semana que corresponde al numero ingresado es MARTES.\n\n");
    } else if (numero == 3) {
        printf("\nEL dia de la semana que corresponde al numero ingresado es MIERCOLES.\n\n");
    } else if (numero == 4) {
        printf("\nEL dia de la semana que corresponde al numero ingresado es JUEVES.\n\n");
    } else if (numero == 5) {
        printf("\nEL dia de la semana que corresponde al numero ingresado es VIERNES.\n\n");
    } else if (numero == 6) {
        printf("\nEL dia de la semana que corresponde al numero ingresado es SABADO.\n\n");
    } else if (numero == 7) {
        printf("\nEL dia de la semana que corresponde al numero ingresado es DOMINGO.\n\n");
    } else {
        printf("\nEl numero ingresado no es valido.\n\n");
    }

    return 0;
}