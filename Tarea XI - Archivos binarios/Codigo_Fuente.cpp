#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

struct Producto {
    int codigo;
    char nombre[40];
    char categoria[30];
    int stock;
    float precio;
    bool activo;
};

void menu();
void RegistrarProducto();
void ListarProductos();
void MostrarEncabezado();
void PausarSistema();

const char* ARCHIVO_PRODUCTOS = "productos.dat";

int main() {
    menu();
    return 0;
}

void MostrarEncabezado() {
    cout << " SISTEMA DE VENTAS E INVENTARIO\n";
}

void PausarSistema() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}

void menu() {
    int opcion;
    do {
        system("cls");
        MostrarEncabezado();

        cout << "1. Registrar producto\n";
        cout << "2. Listar productos\n";
        cout << "3. Salir\n\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 0;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(opcion) {
            case 1:
                RegistrarProducto();
                break;
            case 2:
                ListarProductos();
                break;
            case 3:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo.\n";
                PausarSistema();
                break;
        }
    } while(opcion != 3);
}

void RegistrarProducto() {
    system("cls");
    MostrarEncabezado();
    cout << "REGISTRAR NUEVO PRODUCTO\n\n";

    Producto rp;

    cout << "Ingrese el Codigo: ";
    cin >> rp.codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese el Nombre: ";
    cin.getline(rp.nombre, 40);

    cout << "Ingrese la Categoria: ";
    cin.getline(rp.categoria, 30);

    cout << "Ingrese el Stock: ";
    cin >> rp.stock;

    cout << "Ingrese el Precio: ";
    cin >> rp.precio;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    rp.activo = true;

    ofstream archivo(ARCHIVO_PRODUCTOS, ios::binary | ios::app);

    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<char*>(&rp), sizeof(Producto));
        archivo.close();
        cout << "\n[!] Producto registrado y guardado exitosamente.\n";
    } else {
        cout << "\n[X] Error: No se pudo abrir el archivo para guardar.\n";
    }

    PausarSistema();
}

void ListarProductos() {
    system("cls");
    MostrarEncabezado();
    cout << "LISTADO DE PRODUCTOS\n\n";

    Producto lp;
    bool HayProductos = false;

    ifstream archivo(ARCHIVO_PRODUCTOS, ios::in | ios::binary);

    if (archivo.is_open()) {
        while (archivo.read(reinterpret_cast<char*>(&lp), sizeof(Producto))) {
            HayProductos = true;
            cout << "Codigo: " << lp.codigo << "\n";
            cout << "Nombre: " << lp.nombre << "\n";
            cout << "Categoria: " << lp.categoria << "\n";
            cout << "Stock: " << lp.stock << "\n";
            cout << "Precio: Q" << lp.precio << "\n";
            cout << "Estado: " << (lp.activo ? "Activo" : "Inactivo") << "\n";
        }
        archivo.close();

        if (!HayProductos) {
            cout << "No hay productos registrados actualmente.\n";
        }
    } else {
        cout << "El archivo de productos no existe o esta vacio. Registre un producto primero.\n";
    }

    PausarSistema();
}