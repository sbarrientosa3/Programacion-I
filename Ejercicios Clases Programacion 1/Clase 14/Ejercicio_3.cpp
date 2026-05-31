#include <iostream>
using namespace std;

int main() {
    // const
    int TAM = 5;
    int notas[TAM];
    TAM = 10;
    for (int i = 0; i < TAM; i++) {
        cout << "Ingree nota" << i +1 <<":";
        cin >> notas[i];
    }
    return 0;
}