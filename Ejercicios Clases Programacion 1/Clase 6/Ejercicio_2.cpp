//
// Created by ferna on 15/03/2026.
//
#include <iostream>
using namespace std;
int main (){
    /*
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    double suma;

    cout << "Ingrese el primer valor" << endl;
    cin >> num1;
    cout << "Ingrese el segundo valor" << endl;
    cin >> num2;
    cout << "Ingrese el tercer valor" << endl;
    cin >> num3;
    cout << "Ingrese el quarto valor" << endl;
    cin >> num4;
    cout << "Ingrese el quinto valor" << endl;
    cin >> num5;

    double suma = num1 + num2 + num3 + num4 + num5 ;
    cout << "La suma total es: " suma << endl;*/

    int num = 0, suma = 0;
    for (int contador = 1; contador <= 3; contador++) {
        cout << "Ingrese un numero: " << endl;
        cin >> num;
        suma += num;
    } cout << "La suma total es: " << suma << endl;
    return 0;
}