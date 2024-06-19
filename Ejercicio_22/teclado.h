#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico
{
public:
    Teclado();

    int getTeclas() const;
    void setTeclas(int value);
    void sonar();

private:
    int teclas = 61;
};

#endif // TECLADO_H
