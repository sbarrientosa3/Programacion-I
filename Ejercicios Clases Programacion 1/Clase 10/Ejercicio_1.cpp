#include <iostream>
#include  <fstream>
using namespace std;

int main () {
    ofstream
    archivo("datos.txt");

    archivo << "Hola Mundo";
    archivo << "Guardando Informacion";

    archivo.close();
    return 0;
}