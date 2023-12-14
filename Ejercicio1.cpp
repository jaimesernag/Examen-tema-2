#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Materia {
    string nombre;
};


struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<Materia> materias; // Vector de materias
};