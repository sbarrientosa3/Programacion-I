#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void GuardarUsuario();
void MostrarUsuarios();
int MostrarMenu();

int main() {
    int opcion;
    do {
        opcion = MostrarMenu();
        switch (opcion) {
            case 1:
                GuardarUsuario();
                break;
            case 2:
                MostrarUsuarios();
                break;
            case 3:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo" << endl;
        }
        cout << "\n";
    } while (opcion != 3);
    return 0;
}
int MostrarMenu() {
    int opt;
    cout << "MENU DE USUARIOS" << endl;
    cout << "1. Guardar usuario" << endl;
    cout << "2. Mostrar usuarios" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opt;
    cin.ignore();
    return opt;
}
void GuardarUsuario() {
    string nombre, posicion;
    int edad;
    ofstream archivo;

    archivo.open("usuarios.txt", ios::app);

    if (archivo.fail()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    cout << "Registrar Nuevo Usuario" << endl;
    cout << "Nombre completo: ";
    getline(cin, nombre);
    cout << "Posicion en la empresa: ";
    getline(cin, posicion);
    cout << "Edad: ";
    cin >> edad;
    archivo << nombre << "," << posicion << "," << edad << endl;

    archivo.close();

    cout << "¡Usuario guardado con exito!" << endl;
}
void MostrarUsuarios() {
    string linea;
    ifstream archivo;

    archivo.open("usuarios.txt");

    if (archivo.fail()) {
        cout << "No hay registros o el archivo no existe aun." << endl;
        return;
    }

    cout << "Listado de Usuarios Registrados" << endl;
    cout << "Nombre, Posicion, Edad" << endl;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}