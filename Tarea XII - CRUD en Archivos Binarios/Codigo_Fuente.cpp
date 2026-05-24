#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <limits>

using namespace std;

struct producto {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
    bool activo;
};

const char* ARCHIVO = "productos.dat";
const float TASA_IVA = 0.12;

void MenuPrincipal();
void MenuGestion();
void Registrarproducto();
void Listarproductos();
void BuscarPorCodigo();
void BuscarPorNombre();
void ModificarPrecio();
void ActualizarStock();
void Eliminarproducto();
void ProcesoVenta();

bool Existeproducto(int codigo);
void LimpiarBuffer();
void InicializarArchivo();

int main() {
    InicializarArchivo();
    MenuPrincipal();
    return 0;
}

void LimpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void InicializarArchivo() {
    fstream archivo(ARCHIVO, ios::in | ios::binary);
    if (!archivo) {
        ofstream nuevo(ARCHIVO, ios::out | ios::binary);
        nuevo.close();
    } else {
        archivo.close();
    }
}

bool Existeproducto(int codigo) {
    ifstream archivo(ARCHIVO, ios::in | ios::binary);
    producto exprod;
    while (archivo.read(reinterpret_cast<char*>(&exprod), sizeof(producto))) {
        if (exprod.codigo == codigo && exprod.activo) {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

void MenuPrincipal() {
    int opcion;
    do {
        cout << "SISTEMA DE VENTAS UMG" << endl;
        cout << "1. Gestion de productos" << endl;
        cout << "2. Proceso de venta" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            LimpiarBuffer();
            opcion = 0;
        }

        switch (opcion) {
            case 1: MenuGestion(); break;
            case 2: ProcesoVenta(); break;
            case 3: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion invalida. Intente de nuevo" << endl;
        }
    } while (opcion != 3);
}

void MenuGestion() {
    int opcion;
    do {
        cout << "GESTION DE PRODUCTOS" << endl;
        cout << "1. Registrar producto" << endl;
        cout << "2. Listar productos activos" << endl;
        cout << "3. Buscar producto por codigo" << endl;
        cout << "4. Buscar producto por nombre" << endl;
        cout << "5. Modificar precio" << endl;
        cout << "6. Actualizar stock" << endl;
        cout << "7. Eliminar / desactivar producto" << endl;
        cout << "8. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            LimpiarBuffer();
            opcion = 0;
        }

        switch (opcion) {
            case 1: Registrarproducto(); break;
            case 2: Listarproductos(); break;
            case 3: BuscarPorCodigo(); break;
            case 4: BuscarPorNombre(); break;
            case 5: ModificarPrecio(); break;
            case 6: ActualizarStock(); break;
            case 7: Eliminarproducto(); break;
            case 8: cout << "Regresando..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 8);
}

void Registrarproducto() {
    producto rp;
    cout << "\nRegistrar producto\n";
    cout << "Ingrese codigo: ";
    cin >> rp.codigo;

    if (Existeproducto(rp.codigo)) {
        cout << "Error: Ya existe un producto activo con ese codigo.\n";
        return;
    }

    LimpiarBuffer();
    cout << "Ingrese nombre: ";
    cin.getline(rp.nombre, 50);

    cout << "Ingrese precio: ";
    cin >> rp.precio;
    cout << "Ingrese stock inicial: ";
    cin >> rp.stock;

    rp.activo = true;

    if (rp.precio < 0 || rp.stock < 0) {
        cout << "Error: El precio y el stock no pueden ser negativos.\n";
        return;
    }

    ofstream archivo(ARCHIVO, ios::app | ios::binary);
    archivo.write(reinterpret_cast<char*>(&rp), sizeof(producto));
    archivo.close();
    cout << "producto registrado exitosamente.\n";
}

void Listarproductos() {
    ifstream archivo(ARCHIVO, ios::in | ios::binary);
    producto lp;
    bool Hayproductos = false;

    cout << "\nLista de productos Activos\n";
    cout << left << setw(10) << "Codigo" << setw(20) << "Nombre"
         << setw(10) << "Precio" << setw(10) << "Stock" << endl;
    cout << "--------------------------------------------------\n";

    while (archivo.read(reinterpret_cast<char*>(&lp), sizeof(producto))) {
        if (lp.activo) {
            cout << left << setw(10) << lp.codigo
                 << setw(20) << lp.nombre
                 << "Q " << setw(8) << lp.precio
                 << setw(10) << lp.stock << endl;
            Hayproductos = true;
        }
    }
    archivo.close();

    if (!Hayproductos) {
        cout << "No hay productos registrados o activos.\n";
    }
}

void BuscarPorCodigo() {
    int codigo;
    cout << "\nIngrese el codigo a buscar: ";
    cin >> codigo;

    ifstream archivo(ARCHIVO, ios::in | ios::binary);
    producto bpc;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&bpc), sizeof(producto))) {
        if (bpc.codigo == codigo && bpc.activo) {
            cout << "\nproducto encontrado:\n";
            cout << "Nombre: " << bpc.nombre << "\nPrecio: Q" << bpc.precio
                 << "\nStock: " << bpc.stock << endl;
            encontrado = true;
            break;
        }
    }
    archivo.close();

    if (!encontrado) cout << "producto no encontrado.\n";
}

void BuscarPorNombre() {
    char nombreBusqueda[50];
    LimpiarBuffer();
    cout << "\nIngrese el nombre (o parte de el) a buscar: ";
    cin.getline(nombreBusqueda, 50);

    ifstream archivo(ARCHIVO, ios::in | ios::binary);
    producto bpn;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&bpn), sizeof(producto))) {
        if (bpn.activo && strstr(bpn.nombre, nombreBusqueda) != nullptr) {
            cout << "\nCodigo: " << bpn.codigo << " | Nombre: " << bpn.nombre
                 << " | Precio: Q" << bpn.precio << " | Stock: " << bpn.stock << endl;
            encontrado = true;
        }
    }
    archivo.close();

    if (!encontrado) cout << "Ningun producto coincide con esa busqueda.\n";
}

void ModificarPrecio() {
    int codigo;
    cout << "\nIngrese el codigo del producto a modificar: ";
    cin >> codigo;

    fstream archivo(ARCHIVO, ios::in | ios::out | ios::binary);
    producto modP;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&modP), sizeof(producto))) {
        if (modP.codigo == codigo && modP.activo) {
            float nuevoPrecio;
            cout << "Precio actual: Q" << modP.precio << "\nIngrese nuevo precio: ";
            cin >> nuevoPrecio;

            if (nuevoPrecio >= 0) {
                modP.precio = nuevoPrecio;
                archivo.seekp(-static_cast<int>(sizeof(producto)), ios::cur);
                archivo.write(reinterpret_cast<char*>(&modP), sizeof(producto));
                cout << "Precio actualizado.\n";
            } else {
                cout << "Precio invalido.\n";
            }
            encontrado = true;
            break;
        }
    }
    archivo.close();
    if (!encontrado) cout << "producto no encontrado.\n";
}

void ActualizarStock() {
    int codigo;
    cout << "\nIngrese el codigo del producto: ";
    cin >> codigo;

    fstream archivo(ARCHIVO, ios::in | ios::out | ios::binary);
    producto actS;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&actS), sizeof(producto))) {
        if (actS.codigo == codigo && actS.activo) {
            int nuevoStock;
            cout << "Stock actual: " << actS.stock << "\nIngrese la nueva cantidad de stock: ";
            cin >> nuevoStock;

            if (nuevoStock >= 0) {
                actS.stock = nuevoStock;
                archivo.seekp(-static_cast<int>(sizeof(producto)), ios::cur);
                archivo.write(reinterpret_cast<char*>(&actS), sizeof(producto));
                cout << "Stock actualizado.\n";
            } else {
                cout << "Stock invalido.\n";
            }
            encontrado = true;
            break;
        }
    }
    archivo.close();
    if (!encontrado) cout << "producto no encontrado.\n";
}

void Eliminarproducto() {
    int codigo;
    cout << "\nIngrese el codigo del producto a eliminar: ";
    cin >> codigo;

    fstream archivo(ARCHIVO, ios::in | ios::out | ios::binary);
    producto ep;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&ep), sizeof(producto))) {
        if (ep.codigo == codigo && ep.activo) {
            ep.activo = false;
            archivo.seekp(-static_cast<int>(sizeof(producto)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&ep), sizeof(producto));
            cout << "producto eliminado (desactivado) exitosamente.\n";
            encontrado = true;
            break;
        }
    }
    archivo.close();
    if (!encontrado) cout << "producto no encontrado o ya eliminado.\n";
}

void ProcesoVenta() {
    int codigo, cantidad;
    cout << "\nPROCESO DE VENTA" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;

    fstream archivo(ARCHIVO, ios::in | ios::out | ios::binary);
    producto venP;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&venP), sizeof(producto))) {
        if (venP.codigo == codigo && venP.activo) {
            encontrado = true;
            cout << "producto: " << venP.nombre << " | Precio unitario: Q" << venP.precio
                 << " | Stock disponible: " << venP.stock << endl;

            cout << "Ingrese cantidad a comprar: ";
            cin >> cantidad;

            if (cantidad <= 0) {
                cout << "Cantidad invalida. Debe ser mayor a 0.\n";
            } else if (cantidad > venP.stock) {
                cout << "Stock insuficiente. Solo hay " << venP.stock << " disponibles.\n";
            } else {
                float subtotal = cantidad * venP.precio;
                float iva = subtotal * TASA_IVA;
                float total = subtotal + iva;

                cout << "\nResumen de la Venta\n";
                cout << "Subtotal: Q" << fixed << setprecision(2) << subtotal << endl;
                cout << "IVA (12%): Q" << iva << endl;
                cout << "TOTAL:    Q" << total << endl;

                venP.stock -= cantidad;
                archivo.seekp(-static_cast<int>(sizeof(producto)), ios::cur);
                archivo.write(reinterpret_cast<char*>(&venP), sizeof(producto));
                cout << "\nVenta realizada exitosamente. Stock actualizado.\n";
            }
            break;
        }
    }
    archivo.close();
    if (!encontrado) cout << "producto no encontrado.\n";
}