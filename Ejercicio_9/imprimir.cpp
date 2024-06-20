#include <iostream>
#include "imprimir.h"

template <class T>
void imprimir(T* v, int cantidad, bool mayor_a_menor) {
    // Ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i) {
        T key = v[i];
        int j = i - 1;

        if (mayor_a_menor) {
            // Ordenar de mayor a menor
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
        } else {
            // Ordenar de menor a mayor
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
        }
        v[j + 1] = key;
    }

    // Imprimir el array ordenado
    for (int i = 0; i < cantidad; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

// Incluyendo la definición de la plantilla en el encabezado
template void imprimir<int>(int* v, int cantidad, bool mayor_a_menor);
template void imprimir<float>(float* v, int cantidad, bool mayor_a_menor);
