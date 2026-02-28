
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
    string nombreCliente;
    double precio;
    int cantidad;
    double subtotal, iva, total;
    const double IVA = 0.12;

    cout << "Ingrese el nombre completo del cliente: ";
    getline(cin, nombreCliente);
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    cout << "Ingrese la cantidad comprada: ";
    cin >> cantidad;
    subtotal = precio * cantidad;
    iva = subtotal * IVA;
    total = subtotal + iva;
    cout << "Cliente: " << nombreCliente << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal: Q" << subtotal << endl;
    cout << "IVA (12%): Q" << iva << endl;
    cout << "Total a pagar: Q" << total << endl;

    return 0;
}