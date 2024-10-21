#include <iostream>
#include <string>

using namespace std;

struct Jugador {
string nombre;
int habilidad;
};

struct NodoJugador {
Jugador* jugador;
NodoJugador* sgte;
};

struct Equipo {
int codigoEquipo;
NodoJugador* jugadores;
};

Equipo equipos[20];

/*1. void inicializarEquipos(Equipo equipos[], int cantidad);
Inicializa todos los equipos, estableciendo los código de los equipos del 10 al 30 y asegurando
que las listas de titulares y suplentes estén vacías.*/

void inicializarEquipos(Equipo equipos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (equipos[i].jugadores != nullptr) {
            equipos[i].jugadores = nullptr;
        }
        equipos[i].codigoEquipo = i + 10;
    }
}
/*2. void agregarJugador(Equipo equipos[], int codigoEquipo, string nombreJugador, int habilidad, int
cantidadEquipos);
Agrega un jugador a la lista del equipo indicado por codigoEquipo*/

NodoJugador* crearJugador (string nombre, int habilidad) {
    NodoJugador* nuevoJugador = new NodoJugador;
    nuevoJugador->jugador->nombre = nombre;
    nuevoJugador->jugador->habilidad = habilidad;
    nuevoJugador->sgte = nullptr;
    return nuevoJugador;
}

void agregarJugador(Equipo equipos[], int codigoEquipo, string nombreJugador, int habilidad, int cantidadEquipos) {
    for (int i = 0; i < cantidadEquipos; i++) {
        if (equipos[i].codigoEquipo == codigoEquipo) {
            NodoJugador* nuevoJugador = crearJugador (nombreJugador, habilidad);
            if (equipos[i].jugadores == nullptr) {
                equipos[i].jugadores = nuevoJugador;
            } else {
                NodoJugador* actual = equipos[i].jugadores;
                while (actual->sgte != nullptr) {
                    actual = actual->sgte;
                }
                actual->sgte = nuevoJugador;
            }
            return;
        }
    }
}

/*3. Jugador obtenerCapitan(Equipo equipos[], int codigoEquipo);
Devuelve al mejor jugador del equipo.*/

Jugador* obtenerCapitan(Equipo equipos[], int codigoEquipo, int cantidadEquipos) {
    Jugador* juagadorMax = nullptr;
    for (int i = 0; i < cantidadEquipos; i++) {
        if (equipos[i].codigoEquipo == codigoEquipo) {
            NodoJugador* actual = equipos[i].jugadores;
            if (actual == nullptr) {
                return nullptr;
            }
            juagadorMax = actual->jugador;
            while (actual != nullptr) {
                if (actual->jugador->habilidad > juagadorMax->habilidad) {
                    juagadorMax = actual->jugador;
                }
                actual = actual->sgte;
            }
        }
    }
    return juagadorMax;
}
