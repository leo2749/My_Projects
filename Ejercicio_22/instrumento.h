#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <QDebug>

class Instrumento
{
public:
    Instrumento();

    virtual void sonar();
    virtual void verlo();
    QString getMarca() const;
    void setMarca(const QString &value);

private:
    QString marca;
};

#endif // INSTRUMENTO_H
