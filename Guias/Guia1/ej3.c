/* Que numeros distintos se pueden representar con...?
        a. 8 bits sin signo
        b. 32 bits sin signo
        c. 8 bits con signo
        d. 32 bits con signo
        e. N bits con signo y sin signo
        f. 2 digitos hexadecimales sin signo
        g. 8 digitos hexadecimales sin signo
        h. N digitos hexadecimales sin signo
        i. Con 8 bits usando codificacion BDC sin signo
*/

/* ------- 8 BITS SIN SIGNO ------- 
   - Cada bit puede ser 0 o 1
   - Rango: 0 a 2^8 - 1 = 255
   - Se pueden representar 256 numeros distintos.
*/

/* ------- 32 BITS SIN SIGNO ------- 
   - Rango: 0 a 2^32 - 1
   - Se pueden representar 4.294.967.295 numeros distintos.
*/

/* ------- 8 BITS CON SIGNO ------- 
(usando complemento a dos, que es el estandar en C)
   - Rango: -2^7 a 2^7 - 1 = -128 a 127
   - Se pueden representar 256 numeros distintos.
*/

/* ------- 32 BITS CON SIGNO ------- 
   - Rango: -2^31 a 2^31 - 1 = −2.147.483.648a2.147.483.647
   - Se pueden representar 4.294.967.296 numeros distintos.
*/

/* ------- N BITS ------- 
   - Sin signo: 0 a 2^N - 1 --> 2^N numeros
   - Con signo: -2^(N-1) a 2^(N-1) - 1 --> 2^N numeros
*/

/* ------- 2 DIGITOS HEXADECIMALES SIN SIGNO ------- 
   - Cada digito hexadecimal = 4 bits
   - 2 hexadecimel = 8 bits.
   - Rango: 0x00 a 0xFF = 0 a 255
   - Se pueden representar 256 numeros distintos
*/

/* ------- 8 DIGITOS HEXADECIMALES SIN SIGNO ------- 
   - 8 hexadecimel = 32 bits.
   - Rango: 0x00000000 a 0xFFFFFFFF = 0 a 4.294.967.295
   - Se pueden representar 4.294.967.296 numeros distintos
*/

/* ------- N DIGITOS HEXADECIMALES SIN SIGNO ------- 
   - Cada dígito hexadecimal = 4 bits
   - N digitos hexadecimales = 4N bits
   - Rango: 0 a 16^N - 1
   - Se pueden representar 16^N numeros distintos
*/

/* ------- 8 BITS USANDO CODIFICACION BDC (SIN SIGNO) ------- 
   - En BDC (Binary Coded Decimal), cada nibble (4 bits) representa un digito decimal entre 0 - 9.
   - Con 8 bits --> 2 digitos decimales
   - Rango: 00 a 99
   - Se pueden representar 100 numeros distintos 
   (no 256, porque no se usan las combinaciones binarias de 10-15 en cada nibble)
*/
