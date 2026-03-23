#include <iostream>
using namespace std;

int main() {
    int num = -1;
    int suma = 0;

    while (num != 0) {
        cout << "Ingrese un numero, para finalizar el programa ingrese en numero 0: ";
        cin >> num;
        suma += num;
    }

    cout << "El total acumulado es: " << suma << endl;

    return 0;
}