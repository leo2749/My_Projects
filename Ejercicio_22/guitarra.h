#ifndef GUITARRA_H
#define GUITARRA_H
#include "instrumento.h"


class Guitarra : public Instrumento
{
public:
    Guitarra();
    void sonar();
    int getCuerdas() const;
    void setCuerdas(int value);

private:
    int cuerdas = 6;
};

#endif // GUITARRA_H
