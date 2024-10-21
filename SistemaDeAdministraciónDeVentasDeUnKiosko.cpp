#include <iostream>
#include <string>

using namespace std;

struct Producto {
string nombre;
float precio;
int cantidad;
};

struct NodoProducto {
Producto* producto;
NodoProducto* siguiente;
};

struct NodoVentasDelDia {
NodoProducto* productosVendidos;
int dia; // 1..5
NodoVentasDelDia* siguiente;
};

NodoVentasDelDia* ventasSemanal = nullptr;

/*1. NodoVentasDelDia* dameVentasSemanalInicializado();
Devuelve la lista de ventas semanales con 5 nodos, uno para cada día. Donde cada día es
representado por un número del 1 al 5 y asegurandose que todos los dias arranquen sin
productos vendidos.*/

NodoVentasDelDia* crearDia (int dia) {
    NodoVentasDelDia* nuevoDia = new NodoVentasDelDia;
    nuevoDia->productosVendidos = nullptr;
    nuevoDia->dia = dia;
    nuevoDia->siguiente = nullptr;
    return nuevoDia;
}

NodoVentasDelDia* cargarLista (NodoVentasDelDia* inicio, int dia) {
    NodoVentasDelDia* nuevoDia = crearDia (dia);
    if (inicio == nullptr) {
        inicio = nuevoDia;
    } else {
        NodoVentasDelDia* actual = inicio;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoDia;
    }
    return inicio;
}

NodoVentasDelDia* dameVentasSemanalInicializado() {
    for (int i = 1; i <= 5; i++) {
        ventasSemanal = cargarLista (ventasSemanal, i);
    }
    return ventasSemanal;
}

/*2. void registrarVenta(NodoVentasDelDia* ventasSemanal, int dia, string nombre, int cantidad, float
precio);
Registra una venta de un producto en el día correspondiente. Da por hecho que ya está validado
previamente si el día esta entre 1 y 5.*/

void registrarVenta (NodoVentasDelDia* ventasSemanal, int dia, string nombre, int cantidad, float precio) {
    NodoVentasDelDia* diaActual = ventasSemanal;
    if (diaActual == nullptr) {
        cout << "No hay nada guardado." << endl;
        return;
    }
    while (diaActual != nullptr) {
        if (diaActual->dia == dia) {
            NodoProducto* productoVendido = new NodoProducto;
            productoVendido->producto = new Producto;
            productoVendido->producto->cantidad = cantidad;
            productoVendido->producto->nombre = nombre;
            productoVendido->producto->precio = precio;
            productoVendido->siguiente = nullptr;
            if (diaActual->productosVendidos == nullptr) {
                diaActual->productosVendidos = productoVendido;
            } else {
                NodoProducto* productoActual = diaActual->productosVendidos;
                while (productoActual->siguiente != nullptr) {
                    productoActual = productoActual->siguiente;
                }
                productoActual->siguiente = productoVendido;
            }
            return;
        }
        diaActual = diaActual->siguiente;
    }
}

/*3. int dameDiaMasExitoso(NodoVentasDelDia* ventasSemanal);
Devuelve el día en el que se generó más ingresos por ventas*/

int dameDiaMasExitoso(NodoVentasDelDia* ventasSemanal) {
    NodoVentasDelDia* diaActual = ventasSemanal;
    if (diaActual == nullptr) {
        cout << "No hay dias cargados. " << endl;
        return -1;
    }
    int ventas [5] = {0, 0, 0, 0, 0};
    int i = 0;
    while (diaActual != nullptr) {
        NodoProducto* productosVendidos = diaActual->productosVendidos;
        while (productosVendidos != nullptr) {
            ventas [i] = ventas [i] + (productosVendidos->producto->cantidad * productosVendidos->producto->precio);
            productosVendidos = productosVendidos->siguiente;
        }
        i++;
        diaActual = diaActual->siguiente;
    }
    int diaMax = 0;
    for (i = 1; i < 5; i++) {
        if (ventas [i] > ventas [diaMax]) {
            diaMax = i;
        }
    }
    return diaMax + 1; //Retorna el indice
}
