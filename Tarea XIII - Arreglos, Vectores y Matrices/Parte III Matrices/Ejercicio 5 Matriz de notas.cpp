#include <iostream>
using namespace std;

int main() {

    float notas[4][3];

    for (int i = 0; i < 4; i++) {
        cout << "Estudiante" << i + 1 << " ---" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Nota evaluacion " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }

    cout << "Matriz Completa" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Estudiante " << i + 1 << ":\t";
        for (int j = 0; j < 3; j++) {
            cout << notas[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Promedios por Estudiante" << endl;
    float MejorPromedioEstudiante = -1.0;
    int IndiceMejorEstudiante = 0;

    for (int i = 0; i < 4; i++) {
        float suma = 0;
        for (int j = 0; j < 3; j++) {
            suma += notas[i][j];
        }
        float prom = suma / 3.0;
        cout << "Estudiante " << i + 1 << ": " << prom << endl;

        if (prom > MejorPromedioEstudiante) {
            MejorPromedioEstudiante = prom;
            IndiceMejorEstudiante = i + 1;
        }
    }

    cout << "Promedios por Evaluacion" << endl;
    float PeorPromedioEvaluacion = 101.0;
    int IndicePeorEvaluacion = 0;

    for (int j = 0; j < 3; j++) {
        float suma = 0;
        for (int i = 0; i < 4; i++) {
            suma += notas[i][j];
        }
        float prom = suma / 4.0;
        cout << "Evaluacion " << j + 1 << ": " << prom << endl;

        if (prom < PeorPromedioEvaluacion) {
            PeorPromedioEvaluacion = prom;
            IndicePeorEvaluacion = j + 1;
        }
    }

    cout << "Estudiante con mejor promedio: Estudiante " << IndiceMejorEstudiante << endl;
    cout << "Evaluacion con promedio mas bajo: Evaluacion " << IndicePeorEvaluacion << endl;

    return 0;
}