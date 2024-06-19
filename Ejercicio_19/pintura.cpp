#include "ui_pintura.h"
#include "pintura.h"

Pintura::Pintura(QWidget *parent) : QWidget(parent), ui(new Ui::Pintura) {
    ui->setupUi(this);
    setFixedSize(800, 600);
    setWindowTitle("Pintura con Qt");
    setMouseTracking(true);
    pen = QPen(Qt::black, 2);
    Tamano = 5;

}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    for (int i = 1; i < points.size(); ++i) {
//       painter.drawLine(points[i - 1], points[i]);
       painter.drawLine(points.at( i - 1).getPoint(), points.at(i).getPoint());
       points.at( i ).getColor();

       painter.setPen(pen);
    }
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {

        Punto punto(event->pos(),Qt::black);
        points.push_back(punto);
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        Punto punto(event->pos(),Qt::black);
        points.push_back(punto);
        update();
    }
}

void Pintura::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        Punto punto(event->pos(),Qt::black);
        points.push_back(punto);
        update();
    }
    if (event->button() == Qt::RightButton) {
        points.clear();
    }
}

void Pintura::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0) {
            Tamano++;
            pen = QPen(Qt::black, Tamano);
            ui->lSize->setNum(Tamano);

        } else {
            Tamano--;
            pen = QPen(Qt::black, Tamano);
            ui->lSize->setNum(Tamano);
    }
}

void Pintura::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {

        case Qt::Key_R:{
            pen = QPen(Qt::red, 2);
            ui->rRed->setChecked(true);
            break;
        }
    case Qt::Key_G:{
            pen = QPen(Qt::green, 2);
            ui->rGreen->setChecked(true);
            break;
        }
        case Qt::Key_B:{
            pen = QPen(Qt::blue, 2);
            ui->rBlue->setChecked(true);
            break;
        }
        case Qt::Key_Escape:{
            points.clear();
            break;
        }

    }
}




