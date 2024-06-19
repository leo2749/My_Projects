#include "parser.h"
#include "ui_parser.h"
#include <QRegularExpression>
#include <QtDebug>

Parser::Parser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Parser)
{
    ui->setupUi(this);




    connect(ui->parse, SIGNAL(pressed()),this,SLOT(getRecursos()));

}

Parser::~Parser()
{
    delete ui;
}

QStringList Parser::getRecursos()
{
        QString inputText = ui->lineEdit->text();
        QStringList resourceList;

        // Expresión regular para encontrar recursos en el HTML (como URLs de imágenes, scripts, etc.)
        QRegularExpression resourceRegex(R"((src|href)=\"([^\s"<>]+))");
        QRegularExpressionMatchIterator it = resourceRegex.globalMatch(inputText);

        while (it.hasNext()) {
            QRegularExpressionMatch match = it.next();
            // Solo nos interesa el segundo grupo capturado que contiene la URL
            resourceList.append(match.captured(2));
        }

        // Ahora resourceList contiene todas las URLs de recursos encontradas en el HTML
        // Puedes usar resourceList para lo que necesites, como guardarlas en un archivo o procesarlas de alguna otra manera

        // A modo de ejemplo, imprimimos las URLs encontradas en la consola
        qDebug("funciona");
        qDebug() << "Recursos encontrados:";
            foreach (const QString &resource, resourceList) {
                qDebug() << resource;
            }

        return resourceList;
}


