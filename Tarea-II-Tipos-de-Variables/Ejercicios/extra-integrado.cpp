#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre;
    int edad;
    float altura;
    double precio;
    char inicialApellido;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su edad: ";
    cin >> edad;
    cout << "Ingrese su altura (ejemplo 1.75): ";
    cin >> altura;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    cout << "Ingrese la inicial de su apellido: ";
    cin >> inicialApellido;
    cout << "DATOS PREVIAMENTE INGRESADOS" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " anos" << endl;
    cout << "Altura: " << altura << " metros" << endl;
    cout << "Precio del producto: $" << precio << endl;
    cout << "Inicial del apellido: " << inicialApellido << endl;
    return 0;
}
