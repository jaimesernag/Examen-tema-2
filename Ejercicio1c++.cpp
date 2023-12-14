#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

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

using namespace std;

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

    void registrarAsistencia(string fecha, string materia, string estado) {
        Asistencia nuevaAsistencia(fecha, materia, estado);
        asistencias.push_back(nuevaAsistencia);
    }

    void mostrarAsistencias() {
        cout << "Asistencias de " << nombre << ":\n";
        for (const auto& asistencia : asistencias) {
            asistencia.mostrarAsistencia();
            cout << endl;
        }
    }
};

int main() {
    Estudiante estudiante("Juan", 20, 85.5f);
    estudiante.registrarAsistencia("2023-12-01", "Fisica", "Asistió");
    estudiante.registrarAsistencia("2023-12-03", "Historia", "Falta");

    estudiante.mostrarAsistencias();

    return 0;
}

using namespace std;

// Excepción personalizada para manejar errores en el formato de la fecha
class FormatoFechaInvalido : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Formato de fecha inválido.";
    }
};

// Excepción personalizada para manejar materias no registradas
class MateriaNoRegistrada : public exception {
private:
    string nombreMateria;

public:
    MateriaNoRegistrada(const string& nombre) : nombreMateria(nombre) {}

    const char* what() const noexcept override {
        return ("Error: La materia '" + nombreMateria + "' no está registrada.").c_str();
    }
};

class Asistencia {
private:
    string fecha;
    string materia;
    string estado;

public:
    Asistencia(string fecha, string materia, string estado)
            : fecha(fecha), materia(materia), estado(estado) {}

    void mostrarAsistencia() const {
        cout << "Fecha: " << fecha << endl;
        cout << "Materia: " << materia << endl;
        cout << "Estado: " << estado << endl;
    }
};

class Estudiante {
private:
    string nombre;
    vector<string> materiasRegistradas;
    vector<Asistencia> asistencias;

public:
    Estudiante(string nombre, const vector<string>& materias)
            : nombre(nombre), materiasRegistradas(materias) {}

    void registrarAsistencia(string fecha, string materia, string estado) {
        // Verificar si la materia está registrada
        if (find(materiasRegistradas.begin(), materiasRegistradas.end(), materia) == materiasRegistradas.end()) {
            throw MateriaNoRegistrada(materia);
        }

        // Aquí puedes agregar la lógica para verificar el formato de la fecha si lo deseas

        // Si todo está bien, registrar la asistencia
        Asistencia nuevaAsistencia(fecha, materia, estado);
        asistencias.push_back(nuevaAsistencia);
    }

    void mostrarAsistencias() const {
        cout << "Asistencias de " << nombre << ":\n";
        for (const auto& asistencia : asistencias) {
            asistencia.mostrarAsistencia();
            cout << endl;
        }
    }
};

int main() {
    vector<string> materiasRegistradas = {"Fisica", "Historia", "Matematicas"};
    Estudiante estudiante("Juan", materiasRegistradas);

    try {
        estudiante.registrarAsistencia("2023-12-01", "Fisica", "Asistió");
        estudiante.registrarAsistencia("2023-12-03", "Geografía", "Falta"); // Intentando registrar una materia no registrada
    } catch (const MateriaNoRegistrada& e) {
        cout << "Excepción capturada: " << e.what() << endl;
    }

    estudiante.mostrarAsistencias();

    return 0;
}
