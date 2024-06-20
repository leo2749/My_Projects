#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

class Usuario
{
public:
    Usuario();

    QString getUsuario() const;
    void setUsuario(const QString &value);

    QString getClave() const;
    void setClave(const QString &value);

    int getId() const;
    void setId(int value);

private:
    int id;
    QString usuario;
    QString clave;
};

#endif // USUARIO_H
