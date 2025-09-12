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

void guardarPaciente() {
    FILE *archivo;
    struct Paciente paciente;

    printf("Función llamada correctamente.\n");

    archivo = fopen("pacientes.dat", "ab"); /* Abro el archivi en modo ab para que cada vez que se llame a la funcion me cree un nuevo datos_t y no me sobreescriba */
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    printf("Ingrese su ID: ");
    scanf("%d", &paciente.id);
    getchar();
    fprintf(archivo, "%d\n", paciente.id); /* Guarda el id en el archivo */

    printf("Ingrese el nombre del paciente: ");
    fgets(paciente.datos.nombre, sizeof(paciente.datos.nombre), stdin);
    paciente.datos.nombre[strcspn(paciente.datos.nombre, "\n")] = 0; /* Elimina el salto de linea */
    fprintf(archivo, "%s\n", paciente.datos.nombre); /* Guardar el nombre en el archivo */

    printf("Ingrese su edad: ");
    scanf("%d", &paciente.datos.edad);
    getchar();
    fprintf(archivo, "%d\n", paciente.datos.edad); /* Guarda la edad en el archivo */

    printf("Ingrese el sexo (M para masculino, F para femenino): ");
    scanf("%c", &paciente.datos.sexo);
    getchar();
    fprintf(archivo, "%c\n", paciente.datos.sexo); /* Guardar el nombre en el archivo */
    /* No necesitas strcspn para un int, simplemente usa scanf y limpia el buffer si es necesario */
    
    printf("Ingrese el frecuencia cardiaca del paciente: ");
    scanf("%f", &paciente.ultimaLectura.frecuenciaCardiaca);
    getchar();
    fprintf(archivo, "%f\n", paciente.ultimaLectura.frecuenciaCardiaca); /* Guardar el nombre en el archivo */

    printf("Ingrese su temperatura: ");
    scanf("%f", &paciente.ultimaLectura.temperatura);
    getchar();
    fprintf(archivo, "%f\n", paciente.ultimaLectura.temperatura); /* Guarda la edad en el archivo */

    printf("Ingrese su presion: ");
    scanf("%f", &paciente.ultimaLectura.presion);
    getchar();
    fprintf(archivo, "%f\n", paciente.ultimaLectura.presion); /* Guardar el nombre en el archivo */
    /* No necesitas strcspn para un int, simplemente usa scanf y limpia el buffer si es necesario */

    fwrite(&paciente, sizeof(struct Paciente), 1, archivo);
    fclose(archivo);

}



void mensaje() {
    Mensaje mensaje;
    int opcion;

    printf("Seleccione el tipo de mensaje:\n");
    printf("1. Texto\n2. Lectura Sensor (ID)\n3. Lectura Sensor (valor leido)\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    getchar(); /* Limpiar buffer */

    switch (opcion) {
        case 1:
            mensaje.tipo = TEXTO; 
            printf("Ingrese el mensaje de tipo texto: ");
            fgets(mensaje.LecturaSensor.texto, sizeof(mensaje.LecturaSensor.texto), stdin);
            mensaje.LecturaSensor.texto[strcspn(mensaje.LecturaSensor.texto, "\n")] = 0; /* Elimina el salto de linea */

            printf("Mensaje recibido...\n");
            printf("%s", mensaje.LecturaSensor.texto);

            break;

        case 2:
            mensaje.tipo = SENSOR_ID; 
            printf("Ingrese el ID del sensor: ");
            scanf("%d", &mensaje.LecturaSensor.ID);

            printf("Mensaje recibido...\n");
            printf("%d", mensaje.LecturaSensor.ID);

            break;

        case 3: 
            mensaje.tipo = SENSOR_LEIDO; 
            printf("Ingrese el valor leido por el sensor: ");
            scanf("%f", &mensaje.LecturaSensor.valorLeido);

            printf("Mensaje recibido...\n");
            printf("%f", mensaje.LecturaSensor.valorLeido);

            break;

    }
}
