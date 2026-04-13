#include <iostream>
using namespace std;

string DeterminarAprobacion(float nota) {
    if (nota >= 61) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}
int main() {
    float notaFinal;

    cout << "Ingrese la nota final del estudiante: ";
    cin >> notaFinal;
    cout << "El estudiante esta: " << DeterminarAprobacion(notaFinal) << endl;

    return 0;
}