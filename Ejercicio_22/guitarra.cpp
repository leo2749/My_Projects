#include "guitarra.h"

Guitarra::Guitarra():cuerdas(6)
{

}

void Guitarra::sonar()
{
    qDebug() << "Guitarra suena...";
}

int Guitarra::getCuerdas() const
{
    return cuerdas;
}

void Guitarra::setCuerdas(int value)
{
    cuerdas = value;
}
