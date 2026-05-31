#include <iostream>
using namespace std;

int main() {
    int notas[5] = {80, 75, 90, 60, 100};
    notas[2] = 95;
    cout << "Nueva nota: " << notas[2] << endl;
    return 0;
}