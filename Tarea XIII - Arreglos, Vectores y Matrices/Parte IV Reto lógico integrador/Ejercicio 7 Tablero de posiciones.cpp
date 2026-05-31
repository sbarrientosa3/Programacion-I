#include <iostream>
using namespace std;

int main() {

    int tablero[5][5] = {0};
    int fila, columna;

    while (true) {
        cout << "Ingrese fila (0-4): ";
        cin >> fila;
        cout << "Ingrese columna (0-4): ";
        cin >> columna;

        if (fila >= 0 && fila < 5 && columna >= 0 && columna < 5) {
            tablero[fila][columna] = 1;
            break;
        } else {
            cout << "Error: Posicion fuera de rango. Intente nuevamente (los valores deben ser entre 0 y 4)." << endl;
        }
    }

    cout << "Tablero: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}