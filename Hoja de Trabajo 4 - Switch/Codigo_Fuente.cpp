#include <iostream>
using namespace std;
int main() {
    int opcion;
    int num1
    do {
        cout << "1. Mostrar los numeros del 1 al 5" << endl;
        cout << "2. Mostrar los numeros pares del 2 al 10" << endl;
        cout << "3. Ingresar un numero y mostrar si es positivo o negativo" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Numeros del 1 al 5:" << endl;
                for (int i = 1; i <= 5; i++) {
                    cout << i << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Numeros pares del 2 al 10:" << endl;
                for (int i = 2; i <= 10; i += 2) {
                    cout << i << " ";
                }
                cout << endl;
                break;
            case 3:
                cout << "Ingrese un numero: ";
                cin >> num1;
                if (num1 > 0) {
                    cout << "El numero es POSITIVO." << endl;
                } else if (num1 < 0) {
                    cout << "El numero es NEGATIVO." << endl;
                } else {
                    cout << "El numero es CERO." << endl;
                }
                break;
            case 4:
                cout << "Saliendo del programa... ¡Hasta la vista!" << endl;
                break;

            default:
                cout << "Error: Opcion no valida. Intente de nuevo." << endl;
                continue;
        }
    } while (opcion != 4);
    return 0;
}