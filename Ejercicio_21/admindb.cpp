#include "admindb.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QVector>


AdminDB * AdminDB::instancia = nullptr;

AdminDB::AdminDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool AdminDB::conectar(QString archivoSqlite) {
    db.setDatabaseName(archivoSqlite);

    if (db.open())
        return true;

    return false;
}

bool AdminDB::select(QString comando)
{
    if(db.open()){
       QSqlQuery query = db.exec(comando);

       while (query.next()) {
           return true;
       }

       return false;

    }
    return false;
}

AdminDB * AdminDB::getInstancia() {
    if (instancia == nullptr) {
        instancia = new AdminDB;
    }
    return instancia;
}

