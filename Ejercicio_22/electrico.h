#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <QDebug>


class Electrico
{
public:
    Electrico();
    ~Electrico();


    int getVoltaje() const;
    void setVoltaje(int value);

private:
    int voltaje = 220;
};

#endif // ELECTRICO_H
