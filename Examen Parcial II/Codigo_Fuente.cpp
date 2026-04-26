#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct venta {
    string producto;
    int cantidad;
    float precio;
};

void MostrarMenu();
void RegistrarVenta();
void MostrarReporte();
void limpiar();

int main() {
    int opcion;

    do {
        MostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                RegistrarVenta();
                break;
            case 2:
                MostrarReporte();
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 3);

    return 0;
}

void MostrarMenu() {
    cout << "SISTEMA DE VENTAS UMG" << endl;
    cout << "1. Registrar Venta" << endl;
    cout << "2. Ver Reporte de Ventas" << endl;
    cout << "3. Salir" << endl;
}

void RegistrarVenta() {
    ofstream archivo;
    venta v;

    archivo.open("ventas.txt", ios::app);

    if (archivo.fail()) {
        cout << "Error: No se pudo abrir el archivo" << endl;
        return;
    }

    limpiar();
    cout << "Nombre del producto: ";
    getline(cin, v.producto);

    cout << "Cantidad: ";
    cin >> v.cantidad;

    cout << "Precio unitario: Q";
    cin >> v.precio;

    archivo << v.producto << endl;
    archivo << v.cantidad << endl;
    archivo << v.precio << endl;

    archivo.close();
    cout << "Venta registrada exitosamente" << endl;
}

void MostrarReporte() {
    ifstream archivo;
    string NombreProducto;
    int cantidad;
    float precio;
    float TotalVenta;
    float GranTotal = 0;

    archivo.open("ventas.txt", ios::in);

    if (archivo.fail()) {
        cout << "No hay registros de ventas todavia" << endl;
        return;
    }

    cout << "PRODUCTO CANTIDAD PRECIO TOTAL" << endl;

    while (getline(archivo, NombreProducto)) {
        archivo >> cantidad;
        archivo >> precio;

        archivo.ignore();

        TotalVenta = cantidad * precio;

        cout << NombreProducto << "\t"
             << cantidad << "\t"
             << "Q" << precio << "\t"
             << "Q" << TotalVenta << endl;

        GranTotal += TotalVenta;
    }

    cout << "TOTAL ACUMULADO: Q" << GranTotal << endl;

    archivo.close();
}

void limpiar() {
    cin.ignore(1000, '\n');
}