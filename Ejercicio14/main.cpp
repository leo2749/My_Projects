#include "login.h"


Login::Login(){
    Usuario = new QLabel("Usuario");
    Clave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    pbEntrar = new QPushButton("Entrar");
    layout = new QGridLayout;
    mapa = new Mapa;

    layout ->addWidget(Usuario, 0,0,1,1);
    layout ->addWidget(Clave, 1,0,1,1);
    layout ->addWidget(leUsuario,0,1,1,2);
    layout ->addWidget(leClave, 1,1,1,2);
    layout ->addWidget(pbEntrar, 2,1,1,1);

    this->setLayout(layout);
}
void Login::slot_validarUsaurio(){
    if(leUsuario->text() == "admin" && leClave->text() == "1234"){
        mapa->show();
        this->close();
    }else{
        leClave->clear();
    }
}
