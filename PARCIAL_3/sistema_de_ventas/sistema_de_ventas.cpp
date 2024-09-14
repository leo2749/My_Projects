#include <iostream>
#include <fstream>
#include <vector> 
#include <string>

using namespace std;

struct producto {
    string nombre, categoria;
    int cantidad = 0;
    float precio = 0.0;
};

struct venta {
    string nombre;
    int cant_vendida;
    float precio;
    
};

vector <producto> productos;
vector <venta> carrito;
vector <venta> ventas;

char buscar() {
    
    string l; 
    cout << "Bucar libro: ";   
    getline(cin, l);

    char op = 'n';
    for (int i = 0; i < size(productos); i++) {
        venta v1;
        if (productos[i].nombre == l) {
            cout << "Libro encontrado." << endl;
            cout << "Stock: " << productos[i].cantidad << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << "------------------------------" << endl;
            cout << "¿Desea añadir el libro al carrito?(Si[s]/No[n]): ";
            cin >> op;
            if (op == 's') {
                cout << "cuantos desea comprar? ";
                cin >> v1.cant_vendida;
                v1.nombre = productos[i].nombre;
                v1.precio = productos[i].precio * v1.cant_vendida;
                carrito.push_back(v1);
                productos[i].cantidad -= v1.cant_vendida;
                cout << "Producto agregado." << endl;
                cout << "Desea buscar otro libro?(Si[s]/No[n]): " << endl;
                cin >> op;
                if (op == 's') {
                    cin.ignore();
                    op = buscar();
                    return op;

                }
                else {
                    return op;
                }                                
            }
            else {
                cout << "Desea buscar otro libro?(Si[s]/No[n]): " << endl;
                cin >> op;
                if (op == 's') {
                    cin.ignore();
                    op = buscar();
                    return op;
                    
                }
                else {
                    return op;
                }
            }
        }        
    }

    cout << "No se encontro el libro." << endl;
    cout << "Desea buscar otro libro?(Si[s]/No[n]): " << endl;
    cin >> op;
    if (op == 's') {
        cin.ignore();
        op = buscar();
        return op;
    }
    return op;
}


int main()
{
    float total_ventas = 0.0;
    float total_tarj=0;
    ifstream archivo;
    producto p;
    archivo.open("C:\\Users\\leonel\\Downloads\\PARCIAL_3\\sistema_de_stock\\sistema_de_stock\\stock.dat", ios::in | ios::binary);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo.";
        exit(0);
    }
    archivo.read((char*)&p, sizeof(producto));
    while (!archivo.eof()) {
        productos.push_back(p);
        archivo.read((char*)&p, sizeof(producto));
    }
    archivo.close();

    cout << "               ------------------------------               " << endl;
    cout << "               |     Sistema de ventas       |              " << endl;
    cout << "               ------------------------------               " << endl;   
    cout << endl;
    char op = buscar();
    do {
        
        while (op == 's') {
            op = buscar();
            cout << "Desea agregar mas productos al carrito?(Si[s]/No[n]): ";
            cin >> op;
            if (op == 'n') {
                break;
            }
            cin.ignore();
            op = buscar();
        }
        if (op == 'n') {
            cout << "SU COMPRA ES: " << endl;
            float cont = 0.0;
            for (int i = 0; i < size(carrito); i++) {
                cout << "Libro: " << carrito[i].nombre << endl;
                cout << "Precio: " << carrito[i].precio << endl;
                cout << "------------------------------------------" << endl;
                cont += carrito[i].precio;
                ventas.push_back(carrito[i]);
            }
            int tipo = 0;
            cout << "TOTAL DE LA COMPRA: $" << cont << endl;
            cout << "Ingrese el metodo de pago ([1] Efectivo / [2] Tarjeta / [0] suprimir venta)";
            cin >> tipo;
            if (tipo == 0) {                
                for (int i = 0; i < size(carrito); i++) {
                    carrito.erase(carrito.begin() + (i));
                }
                ventas.pop_back();
                cout << "Venta suprimida." << endl;
            }
            if (tipo == 1) {
                total_ventas += cont;
            }
            if (tipo == 2) {
                total_ventas += cont;
                total_tarj += cont;
            }
        }
        
        cout << "Desea realizar otra venta? (Si[s]/No[n]):";
        cin >> op;
        for (int i = 0; i < size(carrito); i++) {
            carrito.erase(carrito.begin() + (i));    
        }

    } while (op == 's');


    ofstream archivo2;
    archivo2.open("C:\\Users\\leonel\\Downloads\\PARCIAL_3\\PARCIAL_3_LOGIN\\resumen_diario.txt", ios::app);
    archivo2 << "-----------------------" << endl;
    for (int i = 0; i < size(ventas); i++) {
        archivo2 << "Nombre: " << ventas[i].nombre << "| Cantidad vendida: "<< ventas[i].cant_vendida<<"| Precio: $"<< ventas[i].precio << endl;
    }
    archivo2 << "TOTAL DE VENTAS DEL DIA : $" << total_ventas <<endl;
    archivo2 << "LAS VENTAS EN TARJETA SON: $" << total_tarj << endl;
    archivo2 << "LAS VENTAS EN EFECTIVO SON: $" << total_ventas - total_tarj<< endl;
    archivo2.close();


    ofstream archivo_stock;
    archivo_stock.open("C:\\Users\\Alexis\\source\\repos\\PARCIAL_3\\sistema_de_stock\\sistema_de_stock\\stock.dat", ios::out | ios::binary);
    for (int i = 0; i < size(productos); i++) {
        archivo_stock.write((char*)&productos[i], sizeof(producto));
    }
    archivo_stock.close();

    system("C:\\Users\\Alexis\\source\\repos\\PARCIAL_3\\menu_opciones\\x64\\Debug\\menu_opciones.exe");
}
