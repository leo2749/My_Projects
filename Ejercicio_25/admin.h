#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include "login.h"
#include "alta.h"
#include "ventana.h"


class Admin : public QObject
{
    Q_OBJECT

public:
    explicit Admin(QObject *parent = nullptr);
    void iniciar();

private slots:
    void usuario_logueado();
    void Alta_Usuario();

private:
    Login *login;
    Alta  *alta;
    Ventana *ventana;
};

#endif // ADMIN_H
