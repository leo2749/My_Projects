#include <iostream>
using namespace std;


int main()
{
    int opc = 0;
    system("cls");
    cout << "Elija que sistema desea usar: " << endl;
    cout << "[1] Sistema de stock" << endl;
    cout << "[2] Sistema de ventas" << endl;
    cout << "[3] Salir" << endl;

    cout << "opcion elegida: ";
    cin >> opc;
    switch (opc) {
    case 1:
        system("cls");
        system("C:\\Users\\Alexis\\source\\repos\\PARCIAL_3\\sistema_de_stock\\x64\\Debug\\sistema_de_stock.exe");
        break;

    case 2:
        system("cls");
        system("C:\\Users\\Alexis\\source\\repos\\PARCIAL_3\\sistema_de_ventas\\x64\\Debug\\sistema_de_ventas.exe");
        break;

    case 3:
        exit(1);

    }
    
}
