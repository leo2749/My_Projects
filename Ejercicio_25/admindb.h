#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include "usuario.h"

class AdminDB : public QObject
{
    Q_OBJECT


private:
    static AdminDB * instancia;
    AdminDB();
    QSqlDatabase db;


public:
    static AdminDB * getInstancia();
    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();
    int getLinea();
    QVector<Usuario> select(QString comando);
    bool validar_usuario(QString comando);

signals:

};

#endif // ADMINDB_H
