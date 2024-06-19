#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QDebug>

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
    bool select(QString comando);

signals:

};

#endif // ADMINDB_H
