#include <iostream>
using namespace std;

int main() {
    float nota, total = 0, promedio;
    int aprobadas = 0, reprobadas = 0;

    cout << "Control de Calificaciones" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Ingrese la nota " << i << ": ";
        cin >> nota;

        total += nota;

        if (nota >= 61) {
            aprobadas++;
        } else {
            reprobadas++;
        }
    }
    promedio = total / 5;

    cout << "Resultados Finales" << endl;
    cout << "Suma total: " << total << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Notas aprobadas: " << aprobadas << endl;
    cout << "Notas reprobadas: " << reprobadas << endl;

    if (promedio >= 61) {
        cout << "Resultado final: Aprueba" << endl;
    } else {
        cout << "Resultado final: Reprueba" << endl;
    }

    return 0;
}
