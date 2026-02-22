#include <iostream>
using namespace std;

int main() {
    double monto, porcentaje, nuevoMonto;
    cout << "Ingrese monto inicial: ";
    cin >> monto;
    cout << "Ingrese porcentaje de incremento: ";
    cin >> porcentaje;
    nuevoMonto = monto + (monto * porcentaje / 100);
    cout << "El porcentaje del monto inicial es: " << nuevoMonto << endl;
    return 0;
}
