#include <iostream>
using namespace std;

int main() {

    int numeros[10];
    bool HayRepetidos = false;

    cout << "Ingrese 10 numeros enteros:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> numeros[i];
    }

    cout << "Analizando..." << endl;

    bool YaImpreso[10] = {false};

    for (int i = 0; i < 10; i++) {
        bool EsRepetido = false;
        for(int k = 0; k < i; k++) {
            if(numeros[i] == numeros[k]) {
                YaImpreso[i] = true;
                break;
            }
        }

        if (!YaImpreso[i]) {
            for (int j = i + 1; j < 10; j++) {
                if (numeros[i] == numeros[j]) {
                    EsRepetido = true;
                    HayRepetidos = true;
                    break;
                }
            }
            if (EsRepetido) {
                if (HayRepetidos && i == 0) {
                    cout << "Existen numeros repetidos." << endl;
                    cout << "Numeros repetidos encontrados:" << endl;
                } else if (HayRepetidos && i > 0 && !YaImpreso[0]) {
                    static bool TituloImpreso = false;
                    if(!TituloImpreso){
                        cout << "Existen numeros repetidos." << endl;
                        cout << "Numeros repetidos encontrados:" << endl;
                        TituloImpreso = true;
                    }
                }
                cout << numeros[i] << endl;
            }
        }
    }

    if (!HayRepetidos) {
        cout << "No existen numeros repetidos." << endl;
    }

    return 0;
}