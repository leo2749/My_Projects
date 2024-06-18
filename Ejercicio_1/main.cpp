#include <iostream>
#include <random>
#include <ctime> // Necesario para obtener el tiempo actual

int main() {
    // Obtener la hora actual como semilla para el generador de números aleatorios
    unsigned seed = std::time(0);
    std::srand(seed);

    for(int i = 0;i<10;i++){
        int randomNumber = 1 + std::rand() % 20;
        std::cout << "Numero aleatorio entre 1 y 20: " << randomNumber << std::endl;

    }

    return 0;
}
