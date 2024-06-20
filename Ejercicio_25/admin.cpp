#include "admin.h"
#include "QDebug"

Admin::Admin(QObject *parent) : QObject(parent)
{

    login = new Login();
    ventana = new Ventana();


   connect(login, SIGNAL(signal_usuarioValidado()), this, SLOT(usuario_logueado()));
   connect(login, SIGNAL(signal_registro()), this, SLOT(Alta_Usuario()));

}
void Admin::iniciar()
{
    login->show();
}

void Admin::usuario_logueado()
{
     qDebug() << "Usuario logueado correctamente.";

    login->hide();
    ventana->show();

}

void Admin::Alta_Usuario()
{
    qDebug() << "entra.";
    login->hide();
    alta = new Alta();
    alta->show();
}
