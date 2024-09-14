#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct producto {
    string nombre, categoria;
    int cantidad ;
    float precio ;
};

vector <producto> stocks;

void listar_stock() {// muestra el stock 
    for (int i = 0;i < size(stocks);i++) {
        cout << "Nombre: " << stocks[i].nombre << endl;
        cout << "Categoria: " << stocks[i].categoria << endl;
        cout << "Cantidad: " << stocks[i].cantidad << endl;
        cout << "Precio: " << stocks[i].precio << endl;
        cout << "--------------------------------" << endl;
    }
}

void anadir_stock() {// añade productos nuevos 
    system("cls");
    producto obj;
    int cant =0 ;
    cout << "Ingrese la cantidad de productos a ingresar: ";
    cin >> cant;
    for (int i = 0; i < cant; i++) {
        cin.ignore();
        cout << "--------------------------" << endl;
        cout << "Nombre: ";
        getline(cin, obj.nombre);
        cout << "Categoria: ";
        getline(cin, obj.categoria);
        cout << "Cantidad: ";
        cin >> obj.cantidad;
        cout << "Precio: ";
        cin >> obj.precio;
        
        stocks.push_back(obj);
    }
   
}


void modificar_stock() { // modifica el producto 
    system("cls");
    int op = 0;
    string nombre;
    cout << "Nombre del producto que desea buscar: " ;
    cin.ignore();
    getline (cin, nombre);
    cout << "-----------------------------------" << endl;
    for (int i = 0;i < size(stocks);i++) {
        if (stocks[i].nombre == nombre) {
            cout << "Que desea modificar?: " << endl;
            cout << "[1] Categoria del producto" << endl;
            cout << "[2] Stock del producto" << endl;
            cout << "[3] Precio del producto" << endl;
            cout << "La opcion elegida es: ";
            cin >> op;          
            if (op == 1) {
                cout << "Categoria actual del producto: " << stocks[i].categoria << endl;
                cout << "Nueva categoria del producto: ";
                cin.ignore();
                getline(cin, stocks[i].categoria);
            }
            if (op == 2) {
                cout << "Stock actual del producto: " << stocks[i].cantidad << endl;
                cout << "Nuevo stock del producto: ";
                cin >> stocks[i].cantidad;
            }
            if (op == 3) {
                cout << "Precio actual del producto: " << stocks[i].precio << endl;
                cout << "Nuevo precio del producto: ";
                cin >> stocks[i].precio;
            }
            return;
        }
    }
    
}


void eliminar_stock() {// elimina un producto de la lista de productos 
    system("cls");
    string nombre;
    cin.ignore();
    cout << "Nombre del producto que desea eliminar: " << endl;
    getline (cin, nombre);
    cout << "-----------------------------------" << endl;
    for (int i = 0;i < size(stocks);i++) {
        if (stocks[i].nombre == nombre) {
            stocks.erase(stocks.begin() + (i));
            cout << "Producto eliminado con exito :)" << endl;
            return;
        }
    }
    cout << "No se encontro el producto." << endl;
}



int main()
{

    cout << "SISTEMA DE STOCK" << endl;
    producto p;

    ifstream archivo;
    archivo.open("C:\\Users\\Alexis\\source\\repos\\PARCIAL_3\\sistema_de_stock\\sistema_de_stock\\stock.dat", ios::app | ios::binary);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo.";
        exit(0);
    }
    archivo.read((char*)&p, sizeof(producto));
    while (!archivo.eof()) {
        stocks.push_back(p);
        archivo.read((char*)&p, sizeof(producto));
    }
    archivo.close();


    int op = 0;
    do
    {
        
        cout << endl;
        cout <<"-----------------------------------------"<<endl;
        cout << "Elija la opcion que desee hacer: " << endl;
        cout << "[1] Mostrar stock" << endl;
        cout << "[2] Añadir producto/s al stock" << endl;
        cout << "[3] Modificar stock" << endl;
        cout << "[4] Eliminar producto/s del stock" << endl;
        cout << "[5] Salir" << endl;
        cout << "Opcion elegida: ";
        cin >> op;
        switch (op) {
        case 1:
                cout << endl;
                listar_stock();
                break;
        case 2:
                anadir_stock();
                break;
        case 3:
                modificar_stock();
                break;
        case 4:
                eliminar_stock();
                break;
        case 5:
                ofstream archivo;
                archivo.open("C:\\Users\\Alexis\\source\\repos\\PARCIAL_3\\sistema_de_stock\\sistema_de_stock\\stock.dat", ios::out | ios::binary);
                
                for (int i = 0; i < size(stocks); i++) {
                    archivo.write((char*)&stocks[i], sizeof(producto));
                }

                archivo.close();

                system("C:\\Users\\Alexis\\source\\repos\\PARCIAL_3\\menu_opciones\\x64\\Debug\\menu_opciones.exe");
                break;
        }
        
    } while (op != 6);
    
}
