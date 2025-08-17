#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    double num1, num2, resultado;
    char operacion;

    printf("Ingrese un numero entero: ");
    scanf("%lf", &num1);
    printf("Ingrese otro numero entero: ");
    scanf("%lf", &num2);

    printf("Ingrese una operacion (+, -, *, /): ");
    scanf(" %c", &operacion);

    switch (operacion) {
        case '+':
            resultado = num1 + num2;
            printf("El resultado de la suma es: %.2lf\n", resultado);
            break;

        case '-': 
            resultado = num1 - num2;
            printf("El resultado de la resta es: %.2lf\n", resultado);
            break;

        case '*':
            resultado = num1 * num2;
            printf("El resultado de la multiplicacion es: %.2lf\n", resultado);
            break;

        case '/':
            if (num2 == 0) {
                printf("Error: No se puede dividir por cero.\n");
            } else {
                resultado = num1 / num2;
                printf("El resultado de la division es: %.2lf\n", resultado);
            }
    }

    return 0; 
}