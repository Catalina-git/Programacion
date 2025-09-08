/* 
   a. Que significa la palabra unsigned en lenguaje C? 
   b. Como de usa? 
   c. Modifica el tamaño que ocupa el tipo de dato? 
*/

/* ------------- RESPUESTA -------------*/
/* ------- ITEM a ------- 
   En C, la palabra 'unsigned' indica que una variable no puede almacenar valores negativos, solo valores enteros >= 0.
   Por defecto, los enteros (int, char, etc) en C son signes (con signo), lo que significa que se usa un bit para representar el signo (positivo o negativo).
   Con 'unsigned', ese bit de signo se reutiliza para ampliar el rango positivo. */

/* ------- ITEM b ------- 
   Se puede aplicar a varios enteros:
   unsigned int x; --> entero sin signo
   unsigned char c; --> caracter sin signo (0 a 255)
   unsigned short s; --> entero corto sin signo
   unsigned long l; --> entero largo sin signo

   Tambien se puede escribir simplemente 'unsigned', que por defecto equivale a unsigned int.
*/

/* ------- ITEM c ------- 
   No modifica el tamaño en memoria. 
   Un int y un unsigned int ocupan la misma cantidad de bytes )usualmente 4 bytes en la mayoria de compiladores).

| Tipo                | Signed (con signo)             | Unsigned (sin signo) |
| ------------------- | ------------------------------- | -------------------- |
| char (1 byte)       | -128 a 127                     | 0 a 255              |
| short (2 bytes)     | -32,768 a 32,767               | 0 a 65,535           |
| int (4 bytes)       | -2,147,483,648 a 2,147,483,647 | 0 a 4,294,967,295    |
| long long (8 bytes) | -2⁶³ a 2⁶³−1                   | 0 a 2⁶⁴−1            |

   En resumen:
        - Mismo tamaño en memoria.
        - Doble rango positivo porque no hay negativos.
*/

/* Cuando conviene usar 'unsigned'? 
   - Cuando se trabaja con valores que no pueden ser negativos (contadores, tamaños de arrays, mascaras de bits, direcciones de memoria).
   - Para operaciones de bajo nivel (bits, registros de hardware, flags).
*/

/* EJEMPLO 
# include <stdio.h>
int main() {
    int a = -10;
    unsigned int b = 10;
    
    printf("a = %d\n", a);
    printf("b = %u\n", b);
    
    return 0;   
}
*/