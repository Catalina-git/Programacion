#include <stdio.h>
#include <string.h>

struct persona {
    char nombre[20];
    int edad;
    float altura;
};

int main() {
    struct persona personas[5]; // espacio para 5 personas

    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre de la persona %d: ", i+1);
        scanf("%19s", personas[i].nombre); // lee string (máx 19 chars)

        printf("Ingrese la edad de la persona %d: ", i+1);
        scanf("%d", &personas[i].edad);

        printf("Ingrese la altura de la persona %d: ", i+1);
        scanf("%f", &personas[i].altura);

        printf("\n");
    }

    // Mostrar lo guardado
    printf("Personas ingresadas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Persona %d: %s, %d años, %.2f m\n",
               i+1,
               personas[i].nombre,
               personas[i].edad,
               personas[i].altura);
    }

    return 0;
}