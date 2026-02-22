#include <iostream>
using namespace std;

int main() {
    double precio, total;
    int cantidad;
    cout << "Ingrese precio del producto: ";
    cin >> precio;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    total = precio * cantidad;
    cout << "Total a pagar es: " << total << endl;
    return 0;
}
