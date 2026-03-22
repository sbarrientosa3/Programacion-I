#include <iostream>
using namespace std;

int main() {
    int i = 1;
    int num;
    cout << "Ingresa un numero: ";
    cin >> num;

    while (num >= 1) {
        cout << num << endl;
        num--;
    }
    return 0;
}