#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    int cantidadMaterias;
    id materias;
};

void mostrarEstudiante(struct Estudiante estudiante) {
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d\n", estudiante.edad);
    printf("Promedio: %.2f\n", estudiante.promedio);
}
int main() {
    struct Estudiante alumno = {"Juan", 20, 85.5};
    printf("Detalles del estudiante:\n");
    mostrarEstudiante(alumno);

    return 0;
}
#define MAX_MATERIAS 10
#define MAX_NOMBRE 50

struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][MAX_NOMBRE];
    int cantidadMaterias;
};
void mostrarMaterias(struct Estudiante estudiante) {
    printf("Materias inscritas por %s:\n", estudiante.nombre);
    if (estudiante.cantidadMaterias == 0) {
        printf("El estudiante no está inscrito en ninguna materia.\n");
    } else {
        for (int i = 0; i < estudiante.cantidadMaterias; i++) {
            printf("- %s\n", estudiante.materias[i]);
        }
    }
}
void agregarMateria(struct Estudiante *estudiante, const char *nombreMateria) {
    if (estudiante->cantidadMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->cantidadMaterias], nombreMateria);
        estudiante->cantidadMaterias++;
    } else {
        printf("El estudiante ha alcanzado el límite de materias.\n");
    }
}

// Función para eliminar una materia del estudiante
void eliminarMateria(struct Estudiante *estudiante, const char *nombreMateria) {
    for (int i = 0; i < estudiante->cantidadMaterias; i++) {
        if (strcmp(estudiante->materias[i], nombreMateria) == 0) {
            for (int j = i; j < estudiante->cantidadMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->cantidadMaterias--;
            break;
        }
    }
}

int main() {
    struct Estudiante alumno = {"Juan", 20, 85.5, {{"Matemáticas"}, {"Física"}, {"Historia"}}, 3};

    mostrarMaterias(alumno);

    agregarMateria(&alumno, "Química");

    printf("\nDespués de agregar una materia:\n");
    mostrarMaterias(alumno);

    eliminarMateria(&alumno, "Física");

    printf("\nDespués de eliminar una materia:\n");
    mostrarMaterias(alumno);

    return 0;
}
