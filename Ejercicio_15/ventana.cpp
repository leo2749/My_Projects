#include "ventana.h"
#include "ui_ventana.h"
#include <QRandomGenerator>
#include <QString>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    int randomNumber = QRandomGenerator::global()->bounded(1, 10001);

     QString randomString = QString::number(randomNumber);

     ui->lCaptcha->setText(randomString);

     connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(validar()));


}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::validar()
{
    if(ui->leLegajo->text() != "" && ui->leNombre->text() != "" && ui->leApellido->text() != "" && ui->lCaptcha->text() == ui->leCaptcha->text()){
        this->close();
    }

}
