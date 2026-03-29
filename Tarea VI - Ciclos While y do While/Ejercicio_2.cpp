#include <iostream>
using namespace std;
int main() {
    float monto = -1;
    float totalAcumulado = 0;
    int totalCompras = 0;
    int mayores100 = 0;
    int menores100 = 0;

    while (monto != 0) {
        cout << "Ingrese el monto de la compra, utilizando 0 para finalizar: ";
        cin >> monto;

        if (monto < 0) {
            cout << "Monto invalido. Intente nuevamente" << endl;
        } else if (monto > 0) {
            totalAcumulado += monto;
            totalCompras++;

            if (monto >= 100) {
                mayores100++;
            } else {
                menores100++;
            }
        }
    }

    if (totalCompras > 0) {
        cout << "Resumen de Compras" << endl;
        cout << "Total acumulado: Q" << totalAcumulado << endl;
        cout << "Cantidad de compras: " << totalCompras << endl;
        cout << "Promedio de compra: Q" << (totalAcumulado / totalCompras) << endl;
        cout << "Compras mayores o iguales a Q100: " << mayores100 << endl;
        cout << "Compras menores a Q100: " << menores100 << endl;
    } else {
        cout << "No se registraron compras validas" << endl;
    }

    return 0;
}