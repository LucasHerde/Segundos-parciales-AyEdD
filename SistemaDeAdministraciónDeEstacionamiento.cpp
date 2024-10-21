#include <iostream>
#include <string>

using namespace std;

struct Vehiculo {
string patente;
int tipoVehiculo;
};

struct NodoVehiculo {
Vehiculo* vehiculo;
NodoVehiculo* sgte;
};

struct Seccion {
NodoVehiculo* vehiculos;
int tipoVehiculo;
};

Seccion secciones[4];

/*1. void inicializarEstacionamiento(Sección secciones[], int cantidad);
Inicializa todas las secciones del estacionamiento asegurando que estén sin vehiculos.*/

void inicializarEstacionamiento(Seccion secciones[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        secciones[i].vehiculos = nullptr;
        secciones[i].tipoVehiculo = i;
    }
}

/*2. void registrarVehiculo(Sección secciones[], string patente, int tipoVehiculo);
Registra un vehículo en la sección correspondiente.*/

NodoVehiculo* crearVehiculo (string patente, int tipoVehiculo) {
    NodoVehiculo* nuevoVehiculo = new NodoVehiculo;
    nuevoVehiculo->vehiculo = new Vehiculo;
    nuevoVehiculo->vehiculo->patente = patente;
    nuevoVehiculo->vehiculo->tipoVehiculo = tipoVehiculo;
    nuevoVehiculo->sgte = nullptr;
    return nuevoVehiculo;
}



void registrarVehiculo(Seccion secciones[], int cantidad, string patente, int tipoVehiculo) {
    for (int i = 0; i < cantidad; i++) {
        if (secciones[i].tipoVehiculo == tipoVehiculo) {
            NodoVehiculo* nuevoVehiculo = crearVehiculo (patente, tipoVehiculo);
            if (secciones[i].vehiculos == nullptr) {
                secciones[i].vehiculos = nuevoVehiculo;
                return;
            } else {
                NodoVehiculo* vehiculoActual = secciones[i].vehiculos;
                while (vehiculoActual->sgte != nullptr) {
                    vehiculoActual = vehiculoActual->sgte;
                }
                vehiculoActual->sgte = nuevoVehiculo;
                break;
            }
        }
    }
}

/*3. int cantidadVehiculos(Estacionamiento* est, int tipoVehiculo);
Devuelve la cantidad de vehículos en una sección dada*/

int cantidadVehiculos (Seccion secciones[], int tipoVehiculo, int cantidad) {
    int contador = 0;
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (secciones[i].tipoVehiculo == tipoVehiculo) {
            encontrado = true;
            NodoVehiculo* vehiculos = secciones[i].vehiculos;
            while (vehiculos != nullptr) {
                contador ++;
                vehiculos = vehiculos->sgte;
            }
            break;
        }
    }
    if (!encontrado) {
        cout << "No se ha encontrado la seccion dada. " << endl;
        return -1;
    } else {
        return contador;
    }  
}
