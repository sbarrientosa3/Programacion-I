#include <iostream>
using namespace std;
int main() {
    int opcion;
    float saldo = 500.0;
    float movimiento;

    do {
        cout << "CAJERO AUTOMATICO" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Depositar dinero" << endl;
        cout << "3. Retirar dinero" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Saldo actual: Q" << saldo << endl;
                break;
            case 2:
                cout << "Ingrese monto a depositar: ";
                cin >> movimiento;
                saldo += movimiento;
                cout << "Deposito realizado correctamente" << endl;
                cout << "Nuevo saldo: Q" << saldo << endl;
                break;
            case 3:
                cout << "Ingrese monto a retirar: ";
                cin >> movimiento;
                if (movimiento <= saldo) {
                    saldo -= movimiento;
                    cout << "Retiro realizado correctamente." << endl;
                    cout << "Nuevo saldo: Q" << saldo << endl;
                } else {
                    cout << "Fondos insuficientes" << endl;
                }
                break;
            case 4:
                cout << "Gracias por usar el sistema" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);
    return 0;
}