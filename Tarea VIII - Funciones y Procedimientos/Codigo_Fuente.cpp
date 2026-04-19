#include <iostream>
#include <string>
using namespace std;

float CalcularPromedio(float notas[], int cantidad);
string DeterminarEstado(float promedio);
string DeterminarCategoria(float promedio);
void MostrarResultado(string nombre, string curso, float promedio, string estado, string categoria);

int main() {
    string NombreEstudiante, NombreCurso;
    int CantidadNotas;
    cout << "SISTEMA DE EVALUACION ESTUDIANTIL" << endl;
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, NombreEstudiante);

    cout << "Ingrese el curso: ";
    getline(cin, NombreCurso);
    cout << "Ingrese la cantidad de notas: ";
    cin >> CantidadNotas;
    float notas[CantidadNotas];

    for (int i = 0; i < CantidadNotas; i++) {
        cout << "Ingrese la nota " << (i + 1) << ": ";
        cin >> notas[i];
    }

    float promedioFinal = CalcularPromedio(notas, CantidadNotas);
    string estado = DeterminarEstado(promedioFinal);
    string categoria = DeterminarCategoria(promedioFinal);

    MostrarResultado(NombreEstudiante, NombreCurso, promedioFinal, estado, categoria);

    return 0;
}

float CalcularPromedio(float notas[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma = suma + notas[i];
    }
    return suma / cantidad;
}

string DeterminarEstado(float promedio) {
    if (promedio >= 61) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

string DeterminarCategoria(float promedio) {
    if (promedio >= 85 && promedio <= 100) {
        return "Excelente";
    } else if (promedio >= 70) {
        return "Bueno";
    } else if (promedio >= 61) {
        return "Regular";
    } else {
        return "Deficiente";
    }
}

void MostrarResultado(string nombre, string curso, float promedio, string estado, string categoria) {
    cout << "RESULTADO FINAL" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Curso: " << curso << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Estado: " << estado << endl;
    cout << "Categoria: " << categoria << endl;
}