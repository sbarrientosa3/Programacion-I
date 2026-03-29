#include <iostream>
using namespace std;
int main() {
    int voto;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    do {
        cout << "ENCUESTA DE SATISFACCION" << endl;
        cout << "1. Malo" << endl;
        cout << "2. Regular" << endl;
        cout << "3. Bueno" << endl;
        cout << "4. Excelente" << endl;
        cout << "0. Finalizar encuesta" << endl;
        cout << "Ingrese su calificacion: ";
        cin >> voto;
        if (voto == 0) {
            cout << "Finalizando registro de datos" << endl;
            break;
        }
        switch (voto) {
            case 1:
                c1++;
                cout << "Respuesta registrada" << endl;
                break;
            case 2:
                c2++;
                cout << "Respuesta registrada" << endl;
                break;
            case 3:
                c3++;
                cout << "Respuesta registrada" << endl;
                break;
            case 4:
                c4++;
                cout << "Respuesta registrada" << endl;
                break;
            default:
                cout << "Opcion invalida Intente nuevamente" << endl;
        }

    } while (voto != 0);
    int total = c1 + c2 + c3 + c4;
    cout << "RESULTADOS FINALES" << endl;
    cout << "Total de respuestas: " << total << endl;
    cout << "Malo:      " << c1 << endl;
    cout << "Regular:   " << c2 << endl;
    cout << "Bueno:     " << c3 << endl;
    cout << "Excelente: " << c4 << endl;
    return 0;
}

