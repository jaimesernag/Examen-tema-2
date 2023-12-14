#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

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
    cout << "Materias inscritas por " << estudiante.nombre << ":" << endl;
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
}
