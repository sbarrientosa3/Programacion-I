#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string nombre;
    int edad;
    double promedio;
    int miembroclub;
    bool acceso = false;


    cout << "Ingrese nombre completo: ";
    getline(cin, nombre);
    cout << "Ingrese su edad: ";
    cin >> edad;
    cout << "Ingrese su promedio academico: ";
    cin >> promedio;
    cout << "Si es parte del club de programacion utilice el 1, de lo contrario utilice el 0: ";
    cin >> miembroclub;

    if (nombre == "David Alvarez")
    {
        cout << "Acceso especial concedido";
        return 0;
    }


    if (edad >= 18 && promedio >= 85)
    {
        acceso = true;
    }
    else if (miembroclub == 1 && promedio >= 75)
    {
        acceso = true;
    }
    else if (promedio >= 95)
    {
        acceso = true;
    }


    if (acceso)
    {
        size_t posicionEspacio = nombre.find(' ');
        string primerNombre = nombre.substr(0, posicionEspacio);
        cout << "Bienvenido " << primerNombre << endl;
        cout << "Acceso autorizado" << endl;
        return 0;
    }
    else
    {
        cout << "Acceso denegado" << endl;
        return 0;
    }

    return 0;
}