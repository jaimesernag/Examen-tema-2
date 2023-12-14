#include <iostream>
#include <vector>
#include <string>
using namespace std;
#GESTION DE MATERIAS
struct Materia {
    string nombre;
};


struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<Materia> materias;
};
void mostrarMaterias(const Estudiante& estudiante) {
    cout << "Materias inscritas por " << estudiante.nombre << ":" << std::endl;
    for (const auto& materia : estudiante.materias) {
        cout << "- " << materia.nombre << endl;
    }
}

void agregarMateria(Estudiante& estudiante, const string& nombreMateria) {
    Materia nuevaMateria {nombreMateria};
    estudiante.materias.push_back(nuevaMateria);
}
void eliminarMateria(Estudiante& estudiante, const string& nombreMateria) {
    estudiante.materias.erase(remove_if(estudiante.materias.begin(), estudiante.materias.end(),
                                             [&nombreMateria](const Materia& materia) {
                                                 return materia.nombre == nombreMateria;
                                             }), estudiante.materias.end());
}
int main() {
    Estudiante estudiante {"Jaime", 19, 85.0f};
    agregarMateria(estudiante, "Fisica");
    agregarMateria(estudiante, "Historia");
    mostrarMaterias(estudiante);

    eliminarMateria(estudiante, "Historia");
    cout << "\nDespués de eliminar la materia 'Historia':\n";
    mostrarMaterias(estudiante);

    return 0;
#REGISTRO DE ASISTENCIA
    struct Materia {
        char nombre[20];
    };


    struct Estudiante {
        char nombre[20];
        int edad;
        float promedio;
        struct Materia* materias;
        int cantidadMaterias;
    };
    void mostrarMaterias(const struct Estudiante* estudiante) {
        printf("Materias inscritas por %s:\n", estudiante->nombre);
        for (int i = 0; i < estudiante->cantidadMaterias; ++i) {
            printf("- %s\n", estudiante->materias[i].nombre);
        }
    }

    void agregarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
        estudiante->materias = realloc(estudiante->materias, (estudiante->cantidadMaterias + 1) * sizeof(struct Materia));
        strcpy(estudiante->materias[estudiante->cantidadMaterias].nombre, nombreMateria);
        estudiante->cantidadMaterias++;
    }
    void eliminarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
        for (int i = 0; i < estudiante->cantidadMaterias; ++i) {
            if (strcmp(estudiante->materias[i].nombre, nombreMateria) == 0) {
                for (int j = i; j < estudiante->cantidadMaterias - 1; ++j) {
                    strcpy(estudiante->materias[j].nombre, estudiante->materias[j + 1].nombre);
                }
                estudiante->cantidadMaterias--;
                estudiante->materias = realloc(estudiante->materias, estudiante->cantidadMaterias * sizeof(struct Materia));
                break;
            }
        }
    }
    int main() {
        struct Estudiante estudiante = {"Jaime", 22, 85.0f, NULL, 0};
        agregarMateria(&estudiante, "Fisica");
        agregarMateria(&estudiante, "Historia");
        mostrarMaterias(&estudiante);

        eliminarMateria(&estudiante, "Historia");
        printf("\nDespués de eliminar la materia 'Historia':\n");
        mostrarMaterias(&estudiante);

        free(estudiante.materias);

        return 0;
    }
    class Asistencia {
    private:
        string fecha;
        string materia;
        string estado;

    public:
        Asistencia(string fecha, string materia, string estado)
                : fecha(fecha), materia(materia), estado(estado) {}

        void mostrarAsistencia() {
            cout << "Fecha: " << fecha << endl;
            cout << "Materia: " << materia << endl;
            cout << "Estado: " << estado << endl;
        }
    };
    class Estudiante {
    private:
        string nombre;
        int edad;
        float promedio;
        vector<Asistencia> asistencias;

    public:
        Estudiante(string nombre, int edad, float promedio)
                : nombre(nombre), edad(edad), promedio(promedio) {}
