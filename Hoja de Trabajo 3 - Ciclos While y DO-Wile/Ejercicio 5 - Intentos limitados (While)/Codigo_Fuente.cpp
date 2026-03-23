#include <iostream>
using namespace std;

int main() {
    string password;
    int intentos = 1;
    bool acierto = false;

    while (intentos <= 3 && !acierto) {
        cout << "Intento " << intentos << "Ingrese contrasena: ";
        cin >> password;

        if (password == "1234") {
            acierto = true;
        } else {
            cout << "Incorrecto." << endl;
            intentos++;
        }
    }

    if (acierto) {
        cout << "Bienvenido" << endl;
    } else {
        cout << "Acceso denegado" << endl;
    }

    return 0;
}