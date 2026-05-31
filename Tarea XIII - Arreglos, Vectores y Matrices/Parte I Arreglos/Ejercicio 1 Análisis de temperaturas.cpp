#include <iostream>
using namespace std;

int main() {
    float temps[7];
    float suma = 0, promedio;
    float maxTemp, minTemp;

    for (int i = 0; i < 7; i++) {
        cout << "Ingrese la temperatura del dia " << i + 1 << ": ";
        cin >> temps[i];
        suma += temps[i];
    }

    promedio = suma / 7.0;
    maxTemp = temps[0];
    minTemp = temps[0];

    for (int i = 1; i < 7; i++) {
        if (temps[i] > maxTemp) maxTemp = temps[i];
        if (temps[i] < minTemp) minTemp = temps[i];
    }

    int arriba = 0, debajo = 0;
    for (int i = 0; i < 7; i++) {
        if (temps[i] > promedio) arriba++;
        else if (temps[i] < promedio) debajo++;
    }

    cout << "Resultados" << endl;
    cout << "Temperaturas ingresadas: ";
    for (int i = 0; i < 7; i++) cout << temps[i] << " ";

    cout << "\nTemperatura mas alta: " << maxTemp << endl;
    cout << "Temperatura mas baja: " << minTemp << endl;
    cout << "Promedio semanal: " << promedio << endl;
    cout << "Dias arriba del promedio: " << arriba << endl;
    cout << "Dias debajo del promedio: " << debajo << endl;

    return 0;
}