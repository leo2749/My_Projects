#ifndef DESCRIBIR_H
#define DESCRIBIR_H

#include <iostream>
#include <QString>
#include "persona.h"
#include "poste.h"

// Función genérica para imprimir la descripción de cualquier objeto
template <typename T>
void describirObjeto(const T &obj);

// Especialización de la función para la clase Persona
template <>
void describirObjeto(const Persona &persona);

// Especialización de la función para la clase Poste
template <>
void describirObjeto(const Poste &poste);

#endif // DESCRIBIR_H
