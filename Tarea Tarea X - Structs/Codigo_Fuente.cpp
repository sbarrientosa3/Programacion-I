 #include <iostream>
#include <string>
#include <limits>

using namespace std;

struct mascota {
    string nombre;
    string especie;
    string raza;
    int edad;
    float peso;
};
void RegistrarMascota(mascota &m);
void MostrarMascota(const mascota &m);
void CalcularEdadEquivalente(int edad);
void ClasificarPeso(float peso);
void ModificarMascota(mascota &m);

int main() {
    mascota MiMascota;
    int opcion;
    bool registrado = false;

    do {
        cout << "REGISTRO DE MASCOTA" << endl;
        cout << "1. Registrar mascota" << endl;
        cout << "2. Mostrar mascota" << endl;
        cout << "3. Calcular edad equivalente" << endl;
        cout << "4. Clasificar por peso" << endl;
        cout << "5. Modificar datos" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                RegistrarMascota(MiMascota);
                registrado = true;
                break;
            case 2:
                if (registrado) MostrarMascota(MiMascota);
                else cout << "Error: Primero debe registrar una mascota" << endl;
                break;
            case 3:
                if (registrado) CalcularEdadEquivalente(MiMascota.edad);
                else cout << "Error: Primero debe registrar una mascota" << endl;
                break;
            case 4:
                if (registrado) ClasificarPeso(MiMascota.peso);
                else cout << "Error: Primero debe registrar una mascota" << endl;
                break;
            case 5:
                if (registrado) ModificarMascota(MiMascota);
                else cout << "Error: Primero debe registrar una mascota" << endl;
                break;
            case 6:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo" << endl;
        }
    } while (opcion != 6);

    return 0;
}

void RegistrarMascota(mascota &m) {
    cout << "Ingrese Datos de la Mascota" << endl;
    cout << "Nombre: ";
    getline(cin, m.nombre);
    cout << "Especie: ";
    getline(cin, m.especie);
    cout << "Raza: ";
    getline(cin, m.raza);
    cout << "Edad (años): ";
    cin >> m.edad;
    cout << "Peso (kg): ";
    cin >> m.peso;
    cout << "¡Registro completado con exito!" << endl;
}

void MostrarMascota(const mascota &m) {
    cout << "Informacion Registrada" << endl;
    cout << "Nombre: " << m.nombre << endl;
    cout << "Especie: " << m.especie << endl;
    cout << "Raza: " << m.raza << endl;
    cout << "Edad: " << m.edad << " anios" << endl;
    cout << "Peso: " << m.peso << " kg" << endl;
}

void CalcularEdadEquivalente(int edad) {
    int edadHumana = edad * 7;
    cout << "La edad equivalente en años humanos es: " << edadHumana << " años" << endl;
}

void ClasificarPeso(float peso) {
    cout << "Clasificacion: ";
    if (peso < 5.0) {
        cout << "mascota pequena" << endl;
    } else if (peso >= 5.0 && peso <= 20.0) {
        cout << "mascota mediana" << endl;
    } else {
        cout << "mascota grande" << endl;
    }
}

void ModificarMascota(mascota &m) {
    int SubOpcion;
    cout << "¿Que dato desea modificar?" << endl;
    cout << "1. Nombre\n2. Especie\n3. Raza\n4. Edad\n5. Peso\nSeleccione: ";
    cin >> SubOpcion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (SubOpcion) {
        case 1:
            cout << "Nuevo nombre: "; getline(cin, m.nombre);
            break;
        case 2:
            cout << "Nueva especie: "; getline(cin, m.especie);
            break;
        case 3:
            cout << "Nueva raza: "; getline(cin, m.raza);
            break;
        case 4:
            cout << "Nueva edad: "; cin >> m.edad;
            break;
        case 5:
            cout << "Nuevo peso: "; cin >> m.peso;
            break;
        default:
            cout << "Opcion no valida." << endl;
    }
}