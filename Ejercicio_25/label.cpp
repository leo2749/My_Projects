#include "label.h"

Label::Label()
{

}

void Label::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
    QLabel::mousePressEvent(event);

}
