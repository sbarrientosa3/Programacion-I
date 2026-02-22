#include <iostream>
using namespace std;

int main() {
    char letra;
    cout << "Ingrese una letra: ";
    cin >> letra;
    cout << "Letra ingresada: " << letra << endl;
    cout << "Repeticion: " << letra << letra << letra << endl;
    cout << "Valor numerico (ASCII): " << int(letra) << endl;
    return 0;
}
