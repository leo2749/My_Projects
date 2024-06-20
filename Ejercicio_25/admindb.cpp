#include "admindb.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

AdminDB * AdminDB::instancia = nullptr;

AdminDB::AdminDB()  {
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

bool AdminDB::conectar(QString archivoSqlite)
{
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        qDebug("BD CONECTADA CON EXITO.");
        return true;

    return false;
}

QVector <Usuario> AdminDB::select( QString comando )  {
    QVector <Usuario>usuarios;


    if(db.open()){
        QSqlQuery query = db.exec(comando);

        while( query.next() )  {

               Usuario u;
               u.setId(query.value(0).toInt());
               u.setUsuario(query.value(1).toString());
               u.setClave(query.value(2).toString());
               usuarios.push_back(u);
               return usuarios ;
        }
    }
    return usuarios ;
}

bool AdminDB::validar_usuario(QString comando)
{
    if(db.open()){
        QSqlQuery query = db.exec(comando);

        while( query.next() )  {

               return true;
        }

    }
    return false;
}


AdminDB * AdminDB::getInstancia()  {
    if( instancia == nullptr )  {
        instancia = new AdminDB;
    }
    return instancia;
}

