#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include "punto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Pintura; }
QT_END_NAMESPACE

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);
    int Tamano;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::Pintura *ui;
    QList<Punto> points;
    QPen pen;

};

#endif // PINTURA_H
