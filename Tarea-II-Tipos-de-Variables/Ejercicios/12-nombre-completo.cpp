#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre, apellido;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su apellido: ";
    cin >> apellido;
    cout << "Su nombre completo: " << nombre << " " << apellido << endl;
    return 0;
}
