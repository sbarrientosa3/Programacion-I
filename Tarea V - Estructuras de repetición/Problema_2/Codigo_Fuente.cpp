#include <iostream>
using namespace std;

int main() {
    int meses;
    float AhorroMensual, TotalAhorrado = 0, PromedioMensual;
    float MayorAhorro = -1.0;
    int MesMayorAhorro = 0;
    int MesesConMeta = 0;

    cout << "Cajero de Ahorro Programado" << endl;
    cout << "Ingrese la cantidad de meses a ahorrar: ";
    cin >> meses;

    for (int i = 1; i <= meses; i++) {
        cout << "Monto ahorrado en el mes " << i << ": Q";
        cin >> AhorroMensual;
        TotalAhorrado += AhorroMensual;

        if (AhorroMensual > MayorAhorro) {
            MayorAhorro = AhorroMensual;
            MesMayorAhorro = i;
        }

        if (AhorroMensual >= 500) {
            MesesConMeta++;
        }
    }

    if (meses > 0) {
        PromedioMensual = TotalAhorrado / meses;

        cout << "Resumen de Ahorro" << endl;
        cout << "Total ahorrado: Q" << TotalAhorrado << endl;
        cout << "Promedio mensual: Q" << PromedioMensual << endl;
        cout << "Mayor ahorro realizado en el mes: " << MesMayorAhorro << endl;
        cout << "Meses con ahorro de Q500 o mas: " << MesesConMeta << endl;
    } else {
        cout << "Cantidad de meses no valida." << endl;
    }

    return 0;
}
