#ifndef PUNTO_H
#define PUNTO_H

#include <QPoint>
#include <QColor>

class Punto  {
private:
    QPoint point;
    QColor color;

public:
    Punto(QPoint point, QColor color ) : point( point )  {
}
    QPoint getPoint() const;
    void setPoint(const QPoint &value);
    QColor getColor() const;
    void setColor(const QColor &value);
};

#endif // PUNTO_H
