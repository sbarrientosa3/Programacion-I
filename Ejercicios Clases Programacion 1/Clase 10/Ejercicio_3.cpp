#include <iostream>
#include <fstream>
using namespace std;

int main () {
    string nombre;
    cout<<"Ingrese su nombre completo: ";
    getline(cin, nombre);

    ofstream archivo1 ("usuario.txt", ios::out);
    archivo1 << nombre << endl;
    archivo1.close();

    ifstream archivo2 ("usuario.txt", ios::in);
    while (getline(archivo2, nombre)) {
        cout << nombre << endl;
    }
    archivo2.close();
    return 0;
}