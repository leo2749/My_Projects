#include <iostream>
#include "imprimir.h"

int main() {
    int arrInt[] = {5, 3, 8, 6, 2};
    float arrFloat[] = {4.5, 2.3, 9.1, 5.6, 1.2};

    int cantidadInt = sizeof(arrInt) / sizeof(arrInt[0]);
    int cantidadFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);

    std::cout << "Array de enteros ordenado de mayor a menor: ";
    imprimir(arrInt, cantidadInt, true);

    std::cout << "Array de floats ordenado de menor a mayor: ";
    imprimir(arrFloat, cantidadFloat, false);

    return 0;
}
