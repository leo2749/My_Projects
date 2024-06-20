#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // LABEL_H
