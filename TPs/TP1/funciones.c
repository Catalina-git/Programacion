#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "header.h"

void mostrar_lectura(uint16_t dato) {
    uint8_t frecuencia_cardiaca;
    uint8_t saturacion_oxigeno;

    /* Saco los datos */
    uint16_t frecuencia = (dato >> 8) & 0xFF;
    uint16_t saturacion = dato & 0xFF;

    /* Imprimo los valores en pantalla */
    printf("Frecuencia cardiaca: %u bpm\t|\tPorcentaje de Saturacion de oxigeno: %u%%\n", frecuencia, saturacion);

}

void  cargar_sensor(sensorData arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Sensor %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &arr[i].id);

        printf("Temperatura: ");
        scanf("%f", &arr[i].temperatura);

        printf("Presion: ");
        scanf("%f", &arr[i].presion);

        printf("Humedad: ");
        scanf("%f", &arr[i].humedad);

        printf("\n");
    }
}

void mostrar_promedios(sensorData arr[], int n) {
    float sum_temp = 0, sum_presion = 0, sum_hum = 0;

    for (int i = 0; i < n; i++) {
        sum_temp += arr[i].temperatura;
        sum_presion += arr[i].presion;
        sum_hum += arr[i].humedad;
    }
    
    printf("\nPromedio de temperatura: %f\n", sum_temp);
    printf("\nPromedio de presion: %f\n", sum_presion);
    printf("\nPromedio de humedad: %f\n", sum_hum);

    printf("\n");
}

vector suma_vectores(vector v1, vector v2) {
    vector resultado;

    resultado.x = v1.x + v2.x;
    resultado.y = v1.y + v2.y;

    return resultado;
}

float modulo_vector(vector v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Hora diferenciaHoras(Hora h1, Hora h2) {
    Hora diferencia; 

    /*Convertir ambas horas en segundos*/
    int totalSegundos1 = h1.horas * 3600 + h1.minutos * 60 + h1.segundos;
    int totalSegundos2 = h2.horas * 3600 + h2.minutos * 60 + h2.segundos;

    if (totalSegundos2 < totalSegundos1) {
        printf("\nFormato invalido.\n\n");
    } else {
        /*Calcular la diferencia en segundos (se asume que h2 es posterior a h1)*/
        int diferenciaSegundos = totalSegundos2 - totalSegundos1;

        /*Converir la diferencia de segundos a horas, minutos y segundos*/
        diferencia.horas = diferenciaSegundos / 3600; /*Dividios por 3600 para obtener las horas*/
        diferenciaSegundos %= 3600; /*Obtenemos el resto de la division*/
        diferencia.minutos = diferenciaSegundos / 60; /*Dividimos por 60 para obtener los minutos*/
        diferencia.segundos = diferenciaSegundos % 60; /*Obtenemos el resto de la division*/

        printf("\nDiferencia entre ambos timestamps: %d:%d:%d\n\n", diferencia.horas, diferencia.minutos, diferencia.segundos);
    }
}