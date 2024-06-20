#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include "admindb.h"

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();
     AdminDB * adminDB;
     QVector <Usuario> usuarios;

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
