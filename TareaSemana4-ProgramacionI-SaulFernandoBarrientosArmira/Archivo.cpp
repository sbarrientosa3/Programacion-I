/*
PARTE I – Análisis de expresiones
12 + 6 * 2 = 24: Por prioridad de operadores, la multiplicación se ejecuta antes que la suma 
(12 + 6) * 2 = 36: Los paréntesis tienen la mayor prioridad, alterando el orden natural
double x = 5 / 2 = 2.0: Ocurre una división entera porque ambos valores operados son enteros
(double)5  / 2 = 2.5: Se aplica un cambio explícito al 5, convirtiéndolo en double. Esto fuerza una división de punto flotante


PARTE II – Conversión de tipos
double a = 7: Conversión implícita el resultado es 7.0 y no hay pérdida.
int b = 4.9: Conversión implícita el resultado es 4 y sí existe pérdida.
double c = 7 / 2: Operación entera y asignación implícita el resultado es 3.0 sí hay pérdida. 
*/
  
// PARTE III – Programa práctico 
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
    string nombreEstudiante;
    string nombreCliente;
    double precio;
    int cantidad;
    double subtotal, iva, total;
    const double IVA = 0.12;

    cout << "Ingresa tu nombre completo: ";
    getline (cin, nombreEstudiante);
    cout << "Ingrese el nombre completo del cliente: ";
    getline(cin, nombreCliente);
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    cout << "Ingrese la cantidad comprada: ";
    cin >> cantidad;
    subtotal = precio * cantidad;
    iva = subtotal * IVA;
    total = subtotal + iva;
    cout << "Cliente: " << nombreCliente << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal: Q" << subtotal << endl;
    cout << "IVA (12%): Q" << iva << endl;
    cout << "Total a pagar: Q" << total << endl;
    cout << endl;
    cout << "Desarrollado por: " << nombreEstudiante << endl;

    return 0;
}
