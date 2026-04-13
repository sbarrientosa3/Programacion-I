#include <iostream>
#include <limits>
using namespace std;

int main() {
    int opcion = 0;
    int NumeroIngresado = 0;
    int ContadorTotal = 0;
    int SumaTotal = 0;
    int contadorPares = 0;
    int ContadorImpares = 0;
    char ContinuarIngresando;

    do {
        cout << "SISTEMA DE GESTION SIMPLE PERO INTERACTIVO" << endl;
        cout << "1. Registrar numeros" << endl;
        cout << "2. Mostrar estadisticas" << endl;
        cout << "3. Clasificar numeros" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                do {
                    cout << "Ingrese un numero: ";
                    cin >> NumeroIngresado;

                    if (NumeroIngresado < 0) {
                        cout << "Error, no se permiten numeros negativos" << endl;
                        continue;
                    }

                    SumaTotal += NumeroIngresado;
                    ContadorTotal++;

                    if (NumeroIngresado % 2 == 0 && NumeroIngresado >= 0) {
                        contadorPares++;
                    } else if (NumeroIngresado % 2 != 0 || NumeroIngresado == 1) {
                        ContadorImpares++;
                    }

                    cout << "Si Desea ingresar otro numero ingrese la letra S de lo contrario ingrese la letra N: ";
                    cin >> ContinuarIngresando;

                } while (ContinuarIngresando == 's' || ContinuarIngresando == 'S');
                break;

            case 2:
                if (ContadorTotal > 0) {
                    double promedio = static_cast<double>(SumaTotal) / ContadorTotal;
                    cout << "ESTADISTICAS" << endl;
                    cout << "Total de numeros ingresados: " << ContadorTotal << endl;
                    cout << "Suma total: " << SumaTotal << endl;
                    cout << "Promedio: " << promedio << endl;
                } else {
                    cout << "No hay informacion disponible, primero registre algun numero" << endl;
                }
                break;

            case 3:
                if (ContadorTotal > 0) {
                    cout << "CLASIFICACION" << endl;
                    cout << "Cantidad de numeros pares: " << contadorPares << endl;
                    cout << "Cantidad de numeros impares: " << ContadorImpares << endl;
                } else {
                    cout << "No hay datos para clasificar" << endl;
                }
                break;

            case 4:
                cout << "Saliendo del sistema, gracias por utilizar el programa" << endl;
                break;

            default:
                cout << "Opcion no valida, intente de nuevo" << endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}