#include "teclado.h"

Teclado::Teclado():teclas(61)
{

}

int Teclado::getTeclas() const
{
    return teclas;
}

void Teclado::setTeclas(int value)
{
    teclas = value;
}

void Teclado::sonar()
{
    qDebug() << "Teclado suena...";
}
