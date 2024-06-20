#include "jugador.h"

// Constructor
Jugador::Jugador(int velocidad, int fuerza, std::string nombre)
    : velocidad(velocidad), fuerza(fuerza), nombre(nombre) {}

// Destructor
Jugador::~Jugador() {}

// Setters
void Jugador::setVelocidad(int velocidad) {
    this->velocidad = velocidad;
}

void Jugador::setFuerza(int fuerza) {
    this->fuerza = fuerza;
}

void Jugador::setNombre(const std::string &nombre) {
    this->nombre = nombre;
}

// Getters
int Jugador::getVelocidad() const {
    return velocidad;
}

int Jugador::getFuerza() const {
    return fuerza;
}

std::string Jugador::getNombre() const {
    return nombre;
}
