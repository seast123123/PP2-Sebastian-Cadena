
//Prueba Progreso 2 Sebastian Cadena

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

// Función para obtener el promedio de calificaciones de un alumno
float obtenerPromedioAlumno(float calificaciones[]) {
    float suma = 0;
    for (int i = 0; i < NUM_PROGRESOS; i++) {
        suma += calificaciones[i];
    }
    return suma / NUM_PROGRESOS;
}

// Función para obtener la nota promedio del grupo
float obtenerPromedioGrupo(float calificaciones[][NUM_PROGRESOS]) {
    float suma = 0;
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        suma += obtenerPromedioAlumno(calificaciones[i]);
    }
    return suma / NUM_ALUMNOS;
}

// Función para encontrar el alumno con el mayor promedio
int obtenerMejorAlumno(float calificaciones[][NUM_PROGRESOS]) {
    int mejorAlumno = 0;
    float mejorPromedio = obtenerPromedioAlumno(calificaciones[0]);
    for (int i = 1; i < NUM_ALUMNOS; i++) {
        float promedio = obtenerPromedioAlumno(calificaciones[i]);
        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            mejorAlumno = i;
        }
    }
    return mejorAlumno;
}

int main() {
    float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS];

    // Generar calificaciones aleatorias
    srand(time(NULL));  // Inicializar la semilla aleatoria
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            calificaciones[i][j] = (rand() % 10) + 1;  // Generar una calificación aleatoria entre 1 y 10
        }
    }

    // Obtener el promedio de calificaciones de cada alumno
    printf("Promedio de calificaciones de cada alumno:\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        float promedio = obtenerPromedioAlumno(calificaciones[i]);
        printf("Alumno %d: %.2f\n", i+1, promedio);
    }

    // Obtener la nota promedio del grupo
    float promedioGrupo = obtenerPromedioGrupo(calificaciones);
    printf("\nNota promedio del grupo: %.2f\n", promedioGrupo);

    // Obtener el alumno con el mayor promedio
    int mejorAlumno = obtenerMejorAlumno(calificaciones);
    printf("\nAlumno con el mayor promedio: Alumno %d\n", mejorAlumno+1);

    return 0;
}
