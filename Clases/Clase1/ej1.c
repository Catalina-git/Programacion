/* Se tiene un sensor que mide temperatura y humedad 
   
   int dataSensor = 0b1001010111100010;
   - Los 8 bits mas significativos corresponden a los datos de Humedad
   - Los 8 bits menos significativos corresponden a los datos de Temperatura
   
   Imprima los datos en pantalla
*/

#include <stdio.h>

int main(){
    int dataSensor = 0b1001010111100010;
    int Humedad, Temperatura;

    Humedad = dataSensor >> 8;
    Temperatura = dataSensor & 0xFF; /* El 0xFF son ocho 1 y el resto ceros, por ende al hacer el AND, me van a quedar solo los 8 menos significativos del dataSensor*/

    printf("\nHumedad: %d", Humedad);
    printf("\nTemperatura: %d C°", Temperatura);
    printf("\n");

    return 0; 
}
