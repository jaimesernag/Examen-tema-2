#include <stdio.h>
#include <string.h>

#define MAX_MATERIAS 10
#define MAX_NOMBRE 50
#define MAX_ASISTENCIAS 50


struct Asistencia {
    char fecha[MAX_NOMBRE];
    char materia[MAX_NOMBRE];
    char estado[MAX_NOMBRE];
};

struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][MAX_NOMBRE];
    int cantidadMaterias;
    struct Asistencia asistencias[MAX_ASISTENCIAS];
    int cantidadAsistencias;
};

int agregarMateria(struct Estudiante *estudiante, const char *nombreMateria) {
    if (estudiante->cantidadMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->cantidadMaterias], nombreMateria);
        estudiante->cantidadMaterias++;
        return 1; // Éxito al agregar la materia
    } else {
        return 0; // Error: límite de materias alcanzado
    }
}

int registrarAsistencia(struct Estudiante *estudiante, const char *fecha, const char *materia, const char *estado) {
    int materiaEncontrada = 0;
    for (int i = 0; i < estudiante->cantidadMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            materiaEncontrada = 1;
            break;
        }
    }
    if (materiaEncontrada && estudiante->cantidadAsistencias < MAX_ASISTENCIAS) {
        strcpy(estudiante->asistencias[estudiante->cantidadAsistencias].fecha, fecha);
        strcpy(estudiante->asistencias[estudiante->cantidadAsistencias].materia, materia);
        strcpy(estudiante->asistencias[estudiante->cantidadAsistencias].estado, estado);
        estudiante->cantidadAsistencias++;
        return 1; // Éxito al registrar la asistencia
    } else {
        return 0; // Error: materia no encontrada o límite de asistencias alcanzado
    }
}

int main() {
    struct Estudiante alumno = {"Jaime", 19, 86.5, {}, 0, {}, 0};

    if (!agregarMateria(&alumno, "Fisica")) {
        printf("Error: Límite de materias alcanzado\n");
    }
    if (!agregarMateria(&alumno, "Historia")) {
        printf("Error: Límite de materias alcanzado\n");
    }

    if (!registrarAsistencia(&alumno, "2023-12-01", "Fisica", "Asistio")) {
        printf("Error: Materia no encontrada o límite de asistencias alcanzado\n");
    }
    if (!registrarAsistencia(&alumno, "2023-12-03", "Matematicas", "Falta")) {
        printf("Error: Materia no encontrada o límite de asistencias alcanzado\n");
    }

    return 0;
}
