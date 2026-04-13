#include <iostream>
using namespace std;

float CalcularPromedio(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}


int main() {
    float num1, num2, num3;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    cout << "Ingrese el tercer numero: ";
    cin >> num3;

    float promedio = CalcularPromedio(num1, num2, num3);

    cout << "El promedio de los 3 numeros es: " << promedio << endl;

    return 0;
}