/* Implemente un codigo que pida al usuario una frase y cuente cuantas vocales hay en la frase */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> /*es la libreria que me permite usar la funcion tolower*/

int main() {
    char frase[1000];
    int vocales = 0;

    printf("\nIngrse una frase:\n");
    fgets(frase, sizeof(frase), stdin);

    for(int i = 0; i < strlen(frase); i++){
        char letra = tolower(frase[i]); /*convierte todas las letras en minuscula para que sea mas facil comparar*/
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
            vocales++;
        }
    }

    printf("\nLa frase contiene %d vocales\n\n", vocales);

    return 0;
}