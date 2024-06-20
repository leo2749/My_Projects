#include "describir.h"

template <>
void describirObjeto(const Persona &persona) {
    std::cout << "Persona con nombre " << persona.nombre.toStdString() << std::endl;
}

template <>
void describirObjeto(const Poste &poste) {
    std::cout << "Poste con altura de " << poste.altura << " metros y " << poste.diametro << " cm de diámetro" << std::endl;
}
