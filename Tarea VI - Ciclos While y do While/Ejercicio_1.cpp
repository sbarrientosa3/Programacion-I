#include <iostream>
#include <string>
using namespace std;
int main() {
    cout << "Acceso al Sistema" << endl;

    string usuario;
    int contrasena;
    int fallidos = 0;

    cout << "Ingrese usuario: ";
    cin >> usuario;
    cout << "Ingrese contrasena: ";
    cin >> contrasena;

    while (usuario != "admin" || contrasena != 2026) {
        fallidos++;
        cout << "Datos incorrectos" << endl;

        cout << "Ingrese usuario: ";
        cin >> usuario;
        cout << "Ingrese contrasena: ";
        cin >> contrasena;
    }

    cout << "Bienvenido al sistema" << endl;
    cout << "Acceso concedido" << endl;
    cout << "Intentos incorrectos: " << fallidos << endl;

    return 0;
}