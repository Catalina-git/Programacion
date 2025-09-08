/* Se tiene un sensor que devuelve los datos en un uint16 de la siguiente manera:
   temperatura (8 bits) - humedad (8 bits),
   Realice un codigo que se ocupe de, cada 1s, leer estos datos e imprimirlos en pantalla.
*/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h> /*Es la libreria para la función sleep()*/

int main() {
    srand(time(NULL)); /* Inicializa un generador aleatorio */
    
    while (1){
        uint8_t temperatura = rand() % 256;
        uint8_t humedad = rand() % 256;

        uint16_t dataSensor = (temperatura << 8) | humedad;
        
        /* Saco los datos */
        uint16_t temp = (dataSensor >> 8) & 0xFF;
        uint16_t hum = dataSensor & 0xFF;

        /* Imprimo los valores en pantalla */
        printf("Temperatura: %u°C\tHumedad: %u%%\n", temp, hum);

        SLEEP(1000); // Espera 1 segundo
    }

    return 0;
}