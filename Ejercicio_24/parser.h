#ifndef PARSER_H
#define PARSER_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Parser; }
QT_END_NAMESPACE

class Parser : public QMainWindow
{
    Q_OBJECT

public:
    Parser(QWidget *parent = nullptr);
    ~Parser();
    void SetUrl(QUrl url);
    void descargar(QString url, QString directorio);

public slots:
    QStringList getRecursos();




private:
    Ui::Parser *ui;
};
#endif // PARSER_H
