#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    vector<string> palabras;
    string entrada;

    cout << "Ingrese palabras (escriba 'fin' para terminar):" << endl;
    while (true) {
        cin >> entrada;
        if (entrada == "fin") break;
        palabras.push_back(entrada);
    }

    if (palabras.empty()) {
        cout << "No se ingresaron palabras." << endl;
        return 0;
    }

    string MasLarga = palabras[0];
    string MasCorta = palabras[0];
    int mayor5 = 0;

    for (int i = 0; i < palabras.size(); i++) {
        if (palabras[i].length() > MasLarga.length()) MasLarga = palabras[i];
        if (palabras[i].length() < MasCorta.length()) MasCorta = palabras[i];
        if (palabras[i].length() > 5) mayor5++;
    }

    cout << "Resultados" << endl;
    cout << "Cantidad total de palabras: " << palabras.size() << endl;
    cout << "Palabra mas larga: " << MasLarga << endl;
    cout << "Palabra mas corta: " << MasCorta << endl;
    cout << "Palabras con mas de 5 letras: " << mayor5 << endl;

    cout << "Palabras en orden inverso: ";
    for (int i = palabras.size() - 1; i >= 0; i--) {
        cout << palabras[i] << " ";
    }
    cout << endl;

    return 0;
}