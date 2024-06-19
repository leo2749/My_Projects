#ifndef BATERIA_H
#define BATERIA_H
#include "instrumento.h"


class Bateria : public Instrumento
{
public:
    Bateria();
    int getTambores() const;
    void setTambores(int value);
    void sonar();

private:
    int tambores = 5;
};

#endif // BATERIA_H
