#include "ventana.h"
#include "ui_ventana.h"
#include "admindb.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);


    if(AdminDB::getInstancia()->conectar( "../Ejercicio_25/bd.sqlite")){
         usuarios = AdminDB::getInstancia()->select("SELECT * FROM usuarios");

         for(int i = 0; i<usuarios.size();i++){
             QTreeWidgetItem *item =new QTreeWidgetItem(ui->tUsuarios);
             item->setText(0,QString::number(usuarios.at(i).getId()));
             item->setText(1,usuarios.at(i).getUsuario());
             item->setFlags(item->flags() | Qt::ItemIsEditable);
             item->setText(2,usuarios.at(i).getClave());
             ui->tUsuarios->addTopLevelItem(item);

         }

    }





}

Ventana::~Ventana()
{
    delete ui;
}
