#ifndef header
#define header

#define ej1
#define ej2
#define ej3
#define ej4
#define ej5
#define ej6

/* ------------------------- STRUCTS -------------------------  */
/* ----------------- EJERCICIO 2 ----------------- */
typedef struct {
    int id;
    float temperatura;
    float presion;
    float humedad;
} sensorData;

/* ----------------- EJERCICIO 3 ----------------- */
typedef struct {
    float x;
    float y;
} vector;

/* ----------------- EJERCICIO 4 ----------------- */
/*Estructura para representar las horas (incluye hora, minutos y segundos)*/
typedef struct {
    int horas;
    int minutos;
    int segundos;
} Hora;

/* ----------------- EJERCICIO 5 ----------------- */
struct DatosPersonales {
    char nombre[30];
    int edad;
    char sexo;
};

struct Lectura {
    float frecuenciaCardiaca;
    float temperatura;
    float presion;
};

struct Paciente {
    int id;
    struct DatosPersonales datos;
    struct Lectura ultimaLectura;
};

/* struct para la segunda manera de resolver el ejercicio (es este + los de lectura y datos)*/
/* typedef struct {
    int id;
    struct DatosPersonales datos;
    struct Lectura ultimaLectura;
} paciente_t; */

/* ----------------- EJERCICIO 6 ----------------- */
typedef enum {
    TEXTO, 
    SENSOR_ID,
    SENSOR_LEIDO
} TipoMensaje;

typedef struct {
    TipoMensaje tipo;

    union LecturaSensor {
        char texto[50];
        int ID;
        float valorLeido;
        
    } LecturaSensor;
    
} Mensaje;


/* ------------------------- FUNCIONES -------------------------  */

/* ----------------- EJERCICIO 1 ----------------- */
void mostrar_lectura(uint16_t dato);

/* ----------------- EJERCICIO 2 ----------------- */
void  cargar_sensor(sensorData arr[], int n);
void mostrar_promedios(sensorData arr[], int n);

/* ----------------- EJERCICIO 3 ----------------- */
vector suma_vectores(vector v1, vector v2);
float modulo_vector(vector v);

/* ----------------- EJERCICIO 4 ----------------- */
Hora diferenciaHoras(Hora h1, Hora h2);

/* ----------------- EJERCICIO 5 ----------------- */
void guardarPaciente();
/*void savePaciente(paciente_t paciente); --> es la otra manera de hacer la funcion */
void promedios(const char *archivo);

/* ----------------- EJERCICIO 6 ----------------- */
void mensaje();

#endif /* Es el endif del header */