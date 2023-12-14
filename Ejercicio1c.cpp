#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
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

