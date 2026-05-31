#include <iostream>
using namespace std;

int main() {

    int matriz[3][3];
    int buscar;
    bool encontrado = false;

    cout << "Ingrese 9 numeros enteros para completar una matriz de 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Posicion [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz ingresada:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Numero a buscar: ";
    cin >> buscar;

    cout << "El numero aparece en:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == buscar) {
                cout << "Fila " << i << ", columna " << j << endl;
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "El numero no existe en la matriz." << endl;
    }

    return 0;
}