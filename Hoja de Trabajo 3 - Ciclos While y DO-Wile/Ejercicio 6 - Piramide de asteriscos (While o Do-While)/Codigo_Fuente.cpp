#include <iostream>
using namespace std;

int main() {
    int n, fila = 1;

    cout << "Ingrese la altura de la piramide: ";
    cin >> n;

    while (fila <= n) {
        int espacios = n - fila;
        while (espacios > 0) {
            cout << " ";
            espacios--;
        }
        int asteriscos = 1;
        while (asteriscos <= fila) {
            cout << "*";
            asteriscos++;
        }

        cout << endl;
        fila++;
    }
    return 0;
}