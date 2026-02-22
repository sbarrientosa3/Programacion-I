#include <iostream>
using namespace std;

int main() {
    float altura, peso, imc;
    cout << "Ingrese su altura en metros: ";
    cin >> altura;
    cout << "Ingrese su peso en libras: ";
    cin >> peso;
    imc = peso / (altura * altura);
    cout << "Su IMC es: " << imc << endl;
    return 0;
}
