#include <iostream>
#include <vector>
#include "jugador.h"

int main() {
    std::vector<Jugador> jugadores;

    // Crear 10 jugadores con datos distintos
    jugadores.push_back(Jugador(10, 20, "Jugador 1"));
    jugadores.push_back(Jugador(15, 25, "Jugador 2"));
    jugadores.push_back(Jugador(20, 30, "Jugador 3"));
    jugadores.push_back(Jugador(25, 35, "Jugador 4"));
    jugadores.push_back(Jugador(30, 40, "Jugador 5"));
    jugadores.push_back(Jugador(35, 45, "Jugador 6"));
    jugadores.push_back(Jugador(40, 50, "Jugador 7"));
    jugadores.push_back(Jugador(45, 55, "Jugador 8"));
    jugadores.push_back(Jugador(50, 60, "Jugador 9"));
    jugadores.push_back(Jugador(55, 65, "Jugador 10"));

    // Publicar los datos de cada jugador
    for (const auto &jugador : jugadores) {
        std::cout << "Nombre: " << jugador.getNombre()
                  << ", Velocidad: " << jugador.getVelocidad()
                  << ", Fuerza: " << jugador.getFuerza()
                  << std::endl;
    }

    return 0;
}
