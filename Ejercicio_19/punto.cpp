#include "punto.h"

QColor Punto::getColor() const
{
    return color;
}

void Punto::setColor(const QColor &value)
{
    color = value;
}

QPoint Punto::getPoint() const
{
    return point;
}

void Punto::setPoint(const QPoint &value)
{
    point = value;
}

