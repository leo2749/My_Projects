#include <QCoreApplication>
#include "persona.h"
#include "poste.h"
#include "describir.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Creación de dos objetos de la clase Persona
    Persona persona1("Lucrecia");
    Persona persona2("Juan");

    // Creación de dos objetos de la clase Poste
    Poste poste1(8.0, 15.0);
    Poste poste2(10.5, 20.0);

    // Uso de la función genérica para describir los objetos
    describirObjeto(persona1);
    describirObjeto(persona2);
    describirObjeto(poste1);
    describirObjeto(poste2);

    return a.exec();
}
