#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> original;
    vector<int> filtrado;
    int numero, eliminar;

    cout << "Ingrese numeros enteros positivos, para finalizar el programa ingrese el numeor 0: " << endl;
    while (true) {
        cin >> numero;
        if (numero == 0) break;
        if (numero > 0) {
            original.push_back(numero);
        } else {
            cout << "Solo se permiten numeros positivos." << endl;
        }
    }

    if (original.empty()) {
        cout << "No se ingresaron datos." << endl;
        return 0;
    }

    cout << "Vector original:" << endl;
    for (int i = 0; i < original.size(); i++) {
        cout << original[i] << " ";
    }
    cout << endl;

    cout << "Numero a eliminar: ";
    cin >> eliminar;

    for (int i = 0; i < original.size(); i++) {
        if (original[i] != eliminar) {
            filtrado.push_back(original[i]);
        }
    }

    cout << "Vector resultante:" << endl;
    for (int i = 0; i < filtrado.size(); i++) {
        cout << filtrado[i] << " ";
    }
    cout << endl;

    return 0;
}