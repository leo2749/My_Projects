#include "auto.h"

#include <QVector>

int main(){
    QVector <Auto> autos;
    Auto Auto1("Honda","fit",2010);
    Auto Auto2("Toyota","fit",2011);
    Auto Auto3("Chevrolet","fit",2012);
    Auto Auto4("Tesla","fit",2013);

    autos.push_back(Auto1);
    autos.push_back(Auto2);
    autos.push_back(Auto3);
    autos.push_back(Auto4);
}
