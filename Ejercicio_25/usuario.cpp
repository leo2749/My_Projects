#include "usuario.h"

Usuario::Usuario()
{

}

QString Usuario::getUsuario() const
{
    return usuario;
}

void Usuario::setUsuario(const QString &value)
{
    usuario = value;
}

QString Usuario::getClave() const
{
    return clave;
}

void Usuario::setClave(const QString &value)
{
    clave = value;
}

int Usuario::getId() const
{
    return id;
}

void Usuario::setId(int value)
{
    id = value;
}
