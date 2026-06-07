#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <cctype>
#include <algorithm>

using namespace std;


struct Producto {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
    int ventasAcumuladas;
    bool activo;
};

struct DetalleVenta {
    int codigoProducto;
    int cantidad;
    float subtotal;
};

struct Venta {
    int mes;
    int dia;
    int cantidadArticulos;
    float subtotal;
    float iva;
    float descuento;
    float total;
    int numDetalles;
    DetalleVenta detalles[20];
};

string aMinusculas(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

bool esCoincidencia(const Producto& p, string busqueda) {
    string b = aMinusculas(busqueda);
    string nombre = aMinusculas(string(p.nombre));
    string codigo = to_string(p.codigo);

    // Retorna verdadero si la búsqueda está en el nombre O en el código
    return (nombre.find(b) != string::npos) || (codigo.find(b) != string::npos);
}

int leerEnteroSeguro(const string& mensaje);
float leerFloatSeguro(const string& mensaje);

void menuGestionProductos();
void registrarProducto();
void listarProductos();
void buscarProductoCodigoONombre();
void actualizarStock();
void modificarPrecio();
void eliminarProducto();

void crearVenta();
void ordenarProductosBurbuja();
void reporteVentasPorMes();
void exportarReporteTxt();

const string ARCHIVO_PROD = "productos.dat";
const string ARCHIVO_VENTAS = "ventas.dat";
constexpr float TASA_IVA = 0.12f;

int leerEnteroSeguro(const string& mensaje) {
    while (true) {
        cout << mensaje;
        string entrada;
        getline(cin, entrada);
        if (entrada.empty()) continue;
        try {
            size_t pos = 0;
            int numero = stoi(entrada, &pos);
            if (pos != entrada.length()) throw invalid_argument("Caracteres no validos");
            return numero;
        } catch (const exception&) {
            cout << "  [!] Error: Ingreso invalido. Debe ser un numero entero sin letras.\n";
        }
    }
}

float leerFloatSeguro(const string& mensaje) {
    while (true) {
        cout << mensaje;
        string entrada;
        getline(cin, entrada);
        if (entrada.empty()) continue;
        try {
            size_t pos = 0;
            float numero = stof(entrada, &pos);
            if (pos != entrada.length()) throw invalid_argument("Caracteres no validos");
            return numero;
        } catch (const exception&) {
            cout << "  [!] Error: Ingreso invalido. Debe ser un numero decimal.\n";
        }
    }
}

void menuGestionProductos() {
    int opcion;
    do {
        cout << "\n--- SUBMENU: GESTION DE PRODUCTOS ---\n";
        cout << "1. Registrar producto\n";
        cout << "2. Listar productos activos\n";
        cout << "3. Buscar producto (por codigo o nombre)\n";
        cout << "4. Actualizar stock\n";
        cout << "5. Modificar precio\n";
        cout << "6. Eliminar/desactivar producto\n";
        cout << "0. Volver al Menu Principal\n";

        opcion = leerEnteroSeguro("Seleccione una opcion: ");

        switch (opcion) {
            case 1: registrarProducto(); break;
            case 2: listarProductos(); break;
            case 3: buscarProductoCodigoONombre(); break;
            case 4: actualizarStock(); break;
            case 5: modificarPrecio(); break;
            case 6: eliminarProducto(); break;
            case 0: cout << "Regresando...\n"; break;
            default: cout << "  [!] Opcion no valida.\n";
        }
    } while (opcion != 0);
}

void registrarProducto() {
    Producto p{};
    cout << "\n--- REGISTRAR PRODUCTO ---\n";
    p.codigo = leerEnteroSeguro("Ingrese Codigo: ");

    cout << "Ingrese Nombre: ";
    string tempNombre;
    getline(cin, tempNombre);
    strncpy(p.nombre, tempNombre.c_str(), sizeof(p.nombre) - 1);
    p.nombre[sizeof(p.nombre) - 1] = '\0';

    p.precio = leerFloatSeguro("Ingrese Precio (Q): ");
    p.stock = leerEnteroSeguro("Ingrese Stock Inicial: ");
    p.ventasAcumuladas = 0;
    p.activo = true;

    try {
        ofstream archivo(ARCHIVO_PROD, ios::binary | ios::app);
        if (!archivo) throw runtime_error("No se pudo abrir productos.dat");
        archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
        archivo.close();
        cout << "  [+] Producto registrado con exito.\n";
    } catch (const exception& e) {
        cout << "  [!] Error de archivo: " << e.what() << "\n";
    }
}

void listarProductos() {
    Producto p{};
    ifstream archivo(ARCHIVO_PROD, ios::binary);
    if (!archivo) {
        cout << "  [!] No hay productos registrados aun.\n";
        return;
    }
    cout << "\n--- LISTADO DE PRODUCTOS ACTIVOS ---\n";
    cout << left << setw(10) << "Codigo" << setw(20) << "Nombre" << setw(10) << "Precio" << setw(10) << "Stock" << "\n";
    cout << "------------------------------------------------------\n";
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        if (p.activo) {
            cout << left << setw(10) << p.codigo << setw(20) << p.nombre << "Q" << setw(9) << fixed << setprecision(2) << p.precio << setw(10) << p.stock << "\n";
        }
    }
    archivo.close();
}

void buscarProductoCodigoONombre() {
    cout << "\nIngrese el Codigo o el Nombre a buscar: ";
    string entrada;
    getline(cin, entrada);
    if (entrada.empty()) return;

    Producto p{};
    bool encontrado = false;
    ifstream archivo(ARCHIVO_PROD, ios::binary);

    cout << "\nResultados:\n";
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        if (p.activo && esCoincidencia(p, entrada)) {
            cout << "- [" << p.codigo << "] " << p.nombre << " | Q" << p.precio << " | Stock: " << p.stock << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "  [!] No se encontraron productos activos.\n";
    archivo.close();
}

void actualizarStock() {
    cout << "\nIngrese Codigo o Nombre del producto para actualizar stock: ";
    string entrada;
    getline(cin, entrada);
    if (entrada.empty()) return;

    bool esCodigo = true;
    for (char c : entrada) { if (!isdigit(c)) { esCodigo = false; break; } }

    fstream archivo(ARCHIVO_PROD, ios::binary | ios::in | ios::out);
    if (!archivo) { cout << "  [!] Error al abrir inventario.\n"; return; }

    Producto p{};
    bool procesado = false;
    long pos = 0;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        bool coincide = false;
        if (p.activo) {
            if (esCodigo && p.codigo == stoi(entrada)) coincide = true;
            else if (!esCodigo && strstr(p.nombre, entrada.c_str()) != nullptr) coincide = true;
        }

        if (coincide) {
            cout << "\nProducto encontrado: [" << p.codigo << "] " << p.nombre << " | Stock actual: " << p.stock << "\n";
            int confirmar = leerEnteroSeguro("Es este el articulo que busca? (1 = Si, 0 = No): ");

            if (confirmar == 1) {
                p.stock = leerEnteroSeguro("Ingrese el nuevo stock total: ");
                archivo.seekp(pos, ios::beg);
                archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
                cout << "  [+] Stock actualizado correctamente.\n";
                procesado = true;
                break;
            }
        }
        pos = archivo.tellg();
    }
    if (!procesado) cout << "  [*] No se actualizo ningun producto.\n";
    archivo.close();
}

void modificarPrecio() {
    cout << "\nIngrese Codigo o Nombre del producto para modificar precio: ";
    string entrada;
    getline(cin, entrada);
    if (entrada.empty()) return;

    bool esCodigo = true;
    for (char c : entrada) { if (!isdigit(c)) { esCodigo = false; break; } }

    fstream archivo(ARCHIVO_PROD, ios::binary | ios::in | ios::out);
    if (!archivo) { cout << "  [!] Error al abrir inventario.\n"; return; }

    Producto p{};
    bool procesado = false;
    long pos = 0;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        bool coincide = false;
        if (p.activo) {
            if (esCodigo && p.codigo == stoi(entrada)) coincide = true;
            else if (!esCodigo && strstr(p.nombre, entrada.c_str()) != nullptr) coincide = true;
        }

        if (coincide) {
            cout << "\nProducto encontrado: [" << p.codigo << "] " << p.nombre << " | Precio actual: Q" << p.precio << "\n";
            int confirmar = leerEnteroSeguro("Es este el articulo que busca? (1 = Si, 0 = No): ");

            if (confirmar == 1) {
                p.precio = leerFloatSeguro("Ingrese el nuevo precio (Q): ");
                archivo.seekp(pos, ios::beg);
                archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
                cout << "  [+] Precio modificado correctamente.\n";
                procesado = true;
                break;
            }
        }
        pos = archivo.tellg();
    }
    if (!procesado) cout << "  [*] No se modifico ningun precio.\n";
    archivo.close();
}

void eliminarProducto() {
    cout << "\nIngrese Codigo o Nombre del producto a ELIMINAR/DESACTIVAR: ";
    string entrada;
    getline(cin, entrada);
    if (entrada.empty()) return;

    bool esCodigo = true;
    for (char c : entrada) { if (!isdigit(c)) { esCodigo = false; break; } }

    fstream archivo(ARCHIVO_PROD, ios::binary | ios::in | ios::out);
    if (!archivo) { cout << "  [!] Error al abrir inventario.\n"; return; }

    Producto p{};
    bool procesado = false;
    long pos = 0;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        bool coincide = false;
        if (p.activo) {
            if (esCodigo && p.codigo == stoi(entrada)) coincide = true;
            else if (!esCodigo && strstr(p.nombre, entrada.c_str()) != nullptr) coincide = true;
        }

        if (coincide) {
            cout << "\nProducto encontrado: [" << p.codigo << "] " << p.nombre << "\n";
            int confirmar = leerEnteroSeguro("Esta completamente seguro de desactivarlo? (1 = Si, 0 = No): ");

            if (confirmar == 1) {
                p.activo = false;
                archivo.seekp(pos, ios::beg);
                archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
                cout << "  [+] Producto desactivado correctamente. Ya no aparecera en ventas.\n";
                procesado = true;
                break;
            } else {
                cout << "  [*] Operacion cancelada.\n";
                procesado = true;
                break;
            }
        }
        pos = archivo.tellg();
    }
    if (!procesado) cout << "  [!] Producto no encontrado o ya estaba inactivo.\n";
    archivo.close();
}

void crearVenta() {
    Venta v{};
    v.numDetalles = 0;
    v.cantidadArticulos = 0;
    v.subtotal = 0;

    cout << "\n--- NUEVA VENTA ---\n";
    v.mes = leerEnteroSeguro("Mes de la venta (1-12): ");
    v.dia = leerEnteroSeguro("Dia de la venta (1-31): ");

    int opc = 1;
    while (opc == 1 && v.numDetalles < 20) {
        cout << "\nIngrese Codigo o Nombre de producto a vender: ";
        string entrada;
        getline(cin, entrada);
        if (entrada.empty()) continue;

        bool esCodigo = true;
        for (char c : entrada) { if (!isdigit(c)) { esCodigo = false; break; } }

        fstream archivo(ARCHIVO_PROD, ios::binary | ios::in | ios::out);
        Producto p{};
        bool procesado = false;
        long pos = 0;

        while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
            bool coincide = false;
            if (p.activo) {
                if (esCodigo && p.codigo == stoi(entrada)) coincide = true;
                else if (!esCodigo && strstr(p.nombre, entrada.c_str()) != nullptr) coincide = true;
            }

            if (coincide) {
                cout << "\nProducto encontrado: [" << p.codigo << "] " << p.nombre << " | Q" << p.precio << " | Stock actual: " << p.stock << "\n";
                int confirmar = leerEnteroSeguro("Es este el producto que desea vender? (1 = Si, 0 = No): ");

                if (confirmar == 1) {
                    int cant = leerEnteroSeguro("Cantidad a vender: ");
                    if (p.stock >= cant) {
                        p.stock -= cant;
                        p.ventasAcumuladas += cant;
                        archivo.seekp(pos, ios::beg);
                        archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));

                        v.detalles[v.numDetalles].codigoProducto = p.codigo;
                        v.detalles[v.numDetalles].cantidad = cant;
                        v.detalles[v.numDetalles].subtotal = p.precio * static_cast<float>(cant);

                        v.subtotal += v.detalles[v.numDetalles].subtotal;
                        v.cantidadArticulos += cant;
                        v.numDetalles++;
                        cout << "  [+] Agregado al carrito: " << p.nombre << " x" << cant << "\n";
                    } else {
                        cout << "  [!] Stock insuficiente para la cantidad solicitada.\n";
                    }
                    procesado = true;
                    break;
                }
            }
            pos = archivo.tellg();
        }
        if (!procesado) cout << "  [!] Producto no encontrado o el usuario cancelo la busqueda.\n";
        archivo.close();

        opc = leerEnteroSeguro("\nDesea agregar otro producto a esta venta? (1 = Si, 0 = No): ");
    }

    if (v.numDetalles > 0) {
        v.iva = v.subtotal * TASA_IVA;
        float subtotalConIva = v.subtotal + v.iva;
        v.descuento = 0;

        if (subtotalConIva > 500) v.descuento += (subtotalConIva * 0.05f);
        if (v.cantidadArticulos % 5 == 0) {
            cout << "  [*] BONO APLICADO: Descuento extra por comprar multiplos de 5 articulos\n";
            v.descuento += 20.00f;
        }

        v.total = subtotalConIva - v.descuento;
        v.total = round(v.total * 100.0f) / 100.0f;

        ofstream archVenta(ARCHIVO_VENTAS, ios::binary | ios::app);
        archVenta.write(reinterpret_cast<char*>(&v), sizeof(Venta));
        archVenta.close();

        cout << "\n--- RECIBO ---\n";
        cout << "Subtotal: Q" << fixed << setprecision(2) << v.subtotal << "\n";
        cout << "IVA (12%): Q" << v.iva << "\n";
        cout << "Descuentos: Q" << v.descuento << "\n";
        cout << "TOTAL A PAGAR: Q" << v.total << "\n";
    }
}

void ordenarProductosBurbuja() {
    Producto arr[100];
    int n = 0;
    ifstream archivo(ARCHIVO_PROD, ios::binary);
    if (!archivo) return;
    while (archivo.read(reinterpret_cast<char*>(&arr[n]), sizeof(Producto)) && n < 100) {
        if (arr[n].activo) n++;
    }
    archivo.close();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].stock > arr[j + 1].stock) {
                Producto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\n--- PRODUCTOS ORDENADOS POR STOCK (MENOR A MAYOR) ---\n";
    for(int i = 0; i < n; i++) cout << "- [" << arr[i].codigo << "] " << arr[i].nombre << " | Stock: " << arr[i].stock << "\n";
}

void reporteVentasPorMes() {
    float ventasPorMes[12][31] = {0};
    Venta v{};
    ifstream archivo(ARCHIVO_VENTAS, ios::binary);
    if (!archivo) { cout << "  [!] No hay ventas registradas\n"; return; }

    while (archivo.read(reinterpret_cast<char*>(&v), sizeof(Venta))) {
        if (v.mes >= 1 && v.mes <= 12 && v.dia >= 1 && v.dia <= 31) {
            ventasPorMes[v.mes - 1][v.dia - 1] += v.total;
        }
    }
    archivo.close();

    cout << "\n--- VENTAS MENSUALES ACUMULADAS ---\n";
    for (int m = 0; m < 12; m++) {
        float totalMes = 0;
        for (int d = 0; d < 31; d++) {
            totalMes += ventasPorMes[m][d];
        }
        if (totalMes > 0) cout << "Mes " << (m + 1) << ": Q" << fixed << setprecision(2) << totalMes << "\n";
    }
}

void exportarReporteTxt() {
    try {
        ofstream txt("reporte_general.txt");
        if (!txt) throw runtime_error("Error al crear txt");

        txt << "REPORTE GENERAL DE INVENTARIO\n\n";
        Producto p{};
        ifstream archivo(ARCHIVO_PROD, ios::binary);
        while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
            if (p.activo) {
                txt << "Codigo: " << p.codigo << " | Nombre: " << p.nombre << " | Stock: " << p.stock << " | Ventas: " << p.ventasAcumuladas << "\n";
            }
        }
        archivo.close();
        txt.close();
        cout << "  [+] Reporte exportado a reporte_general.txt correctamente.\n";
    } catch (const exception& e) {
        cout << "  [!] " << e.what() << "\n";
    }
}

int main() {
    int opcion;

    cout << "============================================\n";
    cout << "       SISTEMA DE GESTION Y VENTAS          \n";
    cout << "       Universidad Mariano Galvez           \n";
    cout << "============================================\n";

    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Modulo: Gestion de Productos (Catalogo)\n";
        cout << "2. Modulo: Proceso de Venta\n";
        cout << "3. Reporte: Productos con Menor Stock\n";
        cout << "4. Reporte: Ventas por Mes (Matriz)\n";
        cout << "5. Utilidad: Exportar Inventario a TXT\n";
        cout << "0. Salir del Sistema\n";
        cout << "============================================\n";

        opcion = leerEnteroSeguro("Seleccione una opcion: ");

        switch (opcion) {
            case 1: menuGestionProductos(); break;
            case 2: crearVenta(); break;
            case 3: ordenarProductosBurbuja(); break;
            case 4: reporteVentasPorMes(); break;
            case 5: exportarReporteTxt(); break;
            case 0: cout << "\nSaliendo del sistema de forma segura...\n"; break;
            default: cout << "  [!] Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}