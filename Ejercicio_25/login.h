#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admindb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    AdminDB * adminDB;
    bool exito;


private:
    Ui::Login *ui;

private slots:
    void emit_siganl();
    void validar_usuario();

signals:
    void signal_registro();
    void signal_usuarioValidado();

};
#endif // LOGIN_H
