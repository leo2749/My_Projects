#include "login.h"
#include "ui_login.h"

#include <QDebug>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

     exito = AdminDB::getInstancia()->conectar( "../Ejercicio_25/bd.sqlite" );
     connect(ui->pbIngresar,SIGNAL(pressed()),this,SLOT(validar_usuario()));
     connect(ui->label, SIGNAL(clicked()), this, SLOT(emit_siganl()));
}

Login::~Login()
{
    delete ui;
}

void Login::emit_siganl()
{
    emit signal_registro();
    qDebug() << "enviando señal.";
}

void Login::validar_usuario()
{

        QString usuario = ui->leUsuario->text();
        QString clave = ui->leClave->text();

        if (exito) {
            bool validar = AdminDB::getInstancia()->validar_usuario("SELECT usuario,clave FROM usuarios WHERE usuario = '" + usuario + "' AND clave = '" + clave + "'");

            if (validar) {
                emit signal_usuarioValidado();

            }
        }
}

