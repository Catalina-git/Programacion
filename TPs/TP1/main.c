#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "header.h"
#include "funciones.c"

int main() {
    #ifndef ej1

    uint16_t datos = (75 << 8) | 98;
    mostrar_lectura(datos);
    
    #endif /* ej1 */

    #ifndef ej2

    sensorData sensores[5];
    cargar_sensor(sensores, 5);
    mostrar_promedios(sensores, 5);

    #endif /* ej2 */

    #ifndef ej3

    vector v1 = {3, 4};
    vector v2 = {1, 2};

    vector resultado = suma_vectores(v1, v2);

    float modulo = modulo_vector(resultado);

    printf("\nVector resultante: (%.2f, %.2f)\n", resultado.x, resultado.y);
    printf("\nModulo del vector resultante: %.2f\n\n", modulo);

    #endif /* ej3 */

    #ifndef ej4

    Hora h1 = {14, 30, 15}; /* 14 horas, 30 minutos, 15 segundos */
    Hora h2 = {30, 20, 3}; /* 15 horas, 20 minutos, 3 segundos */

    Hora resultado = diferenciaHoras(h1, h2);
    
    #endif /* ej4 */

    #ifndef ej5
    

    
        

    
    #endif /* ej5 */

    #ifdef ej6

    mensaje();
    
    #endif /* ej6 */

   return 0; 
}