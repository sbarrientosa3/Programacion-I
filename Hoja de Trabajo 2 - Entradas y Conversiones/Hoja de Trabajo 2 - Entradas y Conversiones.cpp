
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    string nombreCompleto;
    double precio, subtotal, iva, total;
    int cantidad;
    const double IVA = 0.12;

    cout << "Bienvenido al Sistema de Ventas UMG" << endl;
    cout << "Ingrese nombre completo del cliente: ";
    getline(cin, nombreCompleto);

    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    cout << "Ingrese la cantidad comprada: ";
    cin >> cantidad;

    subtotal = precio * cantidad;
    iva = subtotal * IVA;
    total = subtotal + iva;

    cout << "FACTURA DE VENTA" << endl;
    cout << "Cliente: " << nombreCompleto << endl;
    cout << "Cantidad: " << cantidad << endl;
    
    cout << fixed << setprecision(2);
    cout << "Subtotal: Q" << subtotal << endl;
    cout << "IVA (12%): Q" << iva << endl;
    cout << "Total a pagar: Q" << total << endl;

    return 0;
}
