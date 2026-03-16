//
// Created by ferna on 15/03/2026.
//

#include <iostream>
using namespace std;
int main (){
    int num1;

    cout << "Ingrese un numero: ";
    cin >> num1;
    for (int multi = 1; multi <= 3; multi++) {
        cout << num1 << " x " << multi << " = " << num1* multi <<endl;
    }

    return 0;
}