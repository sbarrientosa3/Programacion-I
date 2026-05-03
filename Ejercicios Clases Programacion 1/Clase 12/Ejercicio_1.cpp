#include <iostream>
using namespace std;

struct Producto {
    inst id;
    string nombre;
    float precio;
    int stock;
};
int mani (){
    Producto p1;

    p1.id = 1;
    p1.nombre = "Mouse";
    p1.precion = 150;
    p1.stock = 25;

    cout << "Producto: " << p1.nombre <<endl;
    cout << "Precion; Q" << p1.precio <<endl;

    return 0;
}
