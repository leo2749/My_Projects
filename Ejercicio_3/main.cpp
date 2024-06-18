#include <iostream>
#include <cstdlib>
#include <ctime>
#include<vector>

int generarAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

int encontrarModa(const std::vector<int>& numeros) {
    std::vector<int> frecuencia(16, 0);


    for (int num : numeros) {
        frecuencia[num]++;
    }

    int moda = 1;
    int maxFrecuencia = frecuencia[1];


    for (int i = 2; i <= 15; ++i) {
        if (frecuencia[i] > maxFrecuencia) {
            moda = i;
            maxFrecuencia = frecuencia[i];
        }
    }

    return moda;
}


int main() {
    std::vector<int> numeros;


    srand(time(0));


    for (int i = 0; i < 30; ++i) {
        numeros.push_back(generarAleatorio(1, 15));
    }


    std::cout << std::endl;

    int moda = encontrarModa(numeros);
    std::cout << "La moda es: " << moda << std::endl;

    return 0;
}
