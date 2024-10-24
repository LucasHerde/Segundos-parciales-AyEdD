#include <iostream>
#include <string>

using namespace std;

struct NodoTarea {
string descripcion;
NodoTarea* siguiente;
};

struct ListaPorTipo {
NodoTarea* pilaDeTareas;
int codigoTipo;
ListaPorTipo* siguiente;
};

ListaPorTipo* lista = nullptr;

/*1. ListaPorTipo* agregarNuevaListaPorTipo(ListaPorTipo* lista, int codigoTipo);
Agregar nueva lista de tareas según su tipo */

ListaPorTipo* crearLista (int codigoTipo) {
    ListaPorTipo* nuevaLista = new ListaPorTipo;
    nuevaLista->codigoTipo = codigoTipo;
    nuevaLista->siguiente = nullptr;
    nuevaLista->pilaDeTareas = nullptr;
    return nuevaLista;
}

ListaPorTipo* agregarNuevaListaPorTipo(ListaPorTipo* lista, int codigoTipo) {
    ListaPorTipo* nuevaLista = crearLista(codigoTipo);
    if (lista == nullptr) {
        lista = nuevaLista;
    } else {
        ListaPorTipo* actual = lista;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevaLista;
    }
    return lista;
}

/*2. void agregarTarea(ListaPorTipo* lista, int codigoTipo, string descripcion);
Agrega una tarea a la pila de acuerdo a su código. Si no existe pila de dicho tipo debe agregarla,
puedes usar la función del punto 1.*/

NodoTarea* crearTarea (string descripcion) {
    NodoTarea* nuevaTarea = new NodoTarea;
    nuevaTarea->descripcion = descripcion;
    nuevaTarea->siguiente = nullptr;
    return nuevaTarea;
}

void agregarTarea(ListaPorTipo* lista, int codigoTipo, string descripcion) {
    if (lista == nullptr) {
        cout << "No hay listas cargadas." << endl;
        return;
    }
    ListaPorTipo* actual = lista;
    bool encontrado = false;
    while (actual != nullptr && !encontrado) {
        if (actual->codigoTipo == codigoTipo) {
            NodoTarea* nuevaTarea = crearTarea (descripcion);
            nuevaTarea->siguiente = actual->pilaDeTareas;   
            encontrado = true;
            actual->pilaDeTareas = nuevaTarea;
        }
        actual = actual->siguiente;
    }
    if (!encontrado) {
        agregarNuevaListaPorTipo(lista, codigoTipo);
    }
    lista->pilaDeTareas = actual->pilaDeTareas;
}

/*3. string dameProximaTarea(ListaPorTipo* lista, int codigoTipo);
Retorna la próxima tarea correspondiente al código expuesto. Retorna “No tengo” si no hay.*/

string dameProximaTarea(ListaPorTipo* lista, int codigoTipo) {
    if (lista == nullptr) {     
        return "No hay listas cargadas";
    }
    ListaPorTipo* actual = lista;
    if (actual->pilaDeTareas == nullptr) {
        return "No tengo";
    }
    bool encontrado = false;
    while (actual != nullptr && !encontrado) {
        if (actual->codigoTipo == codigoTipo) {
            encontrado = true;
            return actual->pilaDeTareas->descripcion;
        }
        actual = actual->siguiente; 
    }
    if (!encontrado) return "No tengo";
}

/*4. int dameCantidadDePilasConTareasPendientes(ListaPorTipo* lista);
Retorna la cantidad de pilas con tareas pendientes.*/

int dameCantidadDePilasConTareasPendientes(ListaPorTipo* lista) {
    if (lista == nullptr) {
        cout << "No hay listas." << endl;
        return -1;
    }
    int contador = 0;
    ListaPorTipo* actual = lista;
    while (actual != nullptr) {
        if (actual->pilaDeTareas != nullptr) {
            contador ++;
        }
        actual = actual->siguiente;
    }
    return contador;
}

