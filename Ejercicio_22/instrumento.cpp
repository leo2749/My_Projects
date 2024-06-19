#include "instrumento.h"

Instrumento::Instrumento() : marca("Yamaha")
{

}

void Instrumento::verlo()
{
    qDebug() << "Marca:" << marca;
}

QString Instrumento::getMarca() const
{
    return marca;
}

void Instrumento::setMarca(const QString &value)
{
    marca = value;
}
