#include "instrumento.h"
#include "guitarra.h"
#include "teclado.h"
#include "bateria.h"
#include <vector>

int main()
{

    std::vector<Instrumento>instrumentos;
    Guitarra g;
    Bateria b;
    Teclado t;
    Bateria b2;
    Guitarra g2;
    instrumentos.push_back(g);
    instrumentos.push_back(b);
    instrumentos.push_back(t);
    instrumentos.push_back(b2);
    instrumentos.push_back(g2);

    for(int i = 0; i < static_cast<int>(instrumentos.size());i++){

        qDebug() << "Marca: " << instrumentos.at(i).getMarca();

    }





    return 0;
}
