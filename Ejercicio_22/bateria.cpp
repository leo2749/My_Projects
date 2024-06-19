#include "bateria.h"

Bateria::Bateria():tambores(5)
{

}

int Bateria::getTambores() const
{
    return tambores;
}

void Bateria::setTambores(int value)
{
    tambores = value;
}

void Bateria::sonar()
{
    qDebug() << "Bateria suena...";
}
