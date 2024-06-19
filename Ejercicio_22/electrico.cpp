#include "electrico.h"

Electrico::Electrico()
{

}

Electrico::~Electrico()
{
    qDebug() << "Desenchufado";
}

int Electrico::getVoltaje() const
{
    return voltaje;
}

void Electrico::setVoltaje(int value)
{
    voltaje = value;
}
