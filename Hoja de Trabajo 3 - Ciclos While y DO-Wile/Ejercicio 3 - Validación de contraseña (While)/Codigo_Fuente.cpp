#include <iostream>
using namespace std;

int main() {
    string password = "";

    while (password != "1234") {
        cout << "Ingrese la contrasena: ";
        cin >> password;

        if (password != "1234") {
            cout << "ERROR: Contrasena incorrecta. Intente de nuevo." << endl;
        }
    }

    cout << "Acceso Autorizado" << endl;
    return 0;
}