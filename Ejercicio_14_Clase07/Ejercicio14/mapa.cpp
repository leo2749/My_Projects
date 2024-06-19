#include "mapa.h"

void Mapa::paintEvent(QPaintEvent *){
    QPainter painter (this);
    painter.drawLine(0,0,this->width(), this->height());
    //painter.drawImage();
}
