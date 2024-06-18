#include "auto.h"
#include <iostream>

Auto::Auto(const QString& Marca, const QString& modelo, int antiguedad) : m_Marca(Marca), m_Modelo(modelo), m_Antiguedad(antiguedad) {}


QString Auto::Marca() const {
    return m_Marca;
}

void Auto::setMarca(const QString& nombre) {
    m_Marca = nombre;
}

QString Auto::Modelo() const {
    return m_Modelo;
}

void Auto::setModelo(const QString& modelo) {
    m_Modelo = modelo;
}

int Auto::Antiguedad() const {
    return m_Antiguedad;
}

void Auto::setAntiguedad(int antiguedad) {
    m_Antiguedad = antiguedad;
}

