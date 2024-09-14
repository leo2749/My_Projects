#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct usuario {
    string nombre, contra;
};


struct fecha {
    int dia, mes, anio;
};
vector <usuario> vu;

void carga(usuario u) {
    int cant = 0;
    ofstream archivo;
    archivo.open("login.dat", ios::app | ios::binary);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo.";
        exit(0);
    }   
    archivo.write((char*)&u, sizeof(usuario));    
    archivo.close();
}


void cambiar_contra(string usuario) {


    for (int i = 0; i < size(vu); i++) {
        if (vu[i].nombre == usuario) {
            cout << "--------------------------------" << endl;
            cout << "Nueva contraseña: ";
            cin >> vu[i].contra;
            cout << "Contraseña cambiada con exito. :)" << endl;
            return;
        }
    }
}

void eliminar_usuario() {
    string nombre;
    cin.ignore();
    cout << "Nombre del Usuario que desea eliminar: " << endl;
    getline(cin, nombre);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < size(vu); i++) {
        if (vu[i].nombre == nombre) {
            vu.erase(vu.begin() + (i));
            break;
        }
    }
    cout << "Usuario eliminado con exito :)" << endl;
}

int existe(usuario u) {
    int d = 0;
    for (int i = 0; i < size(vu); i++) {
        if (vu[i].nombre == u.nombre and vu[i].contra == u.contra) {
            d = 1;
            break;
        }
    } 
    return d;
}

void configuracion(usuario u) {
    int op = 0;
    while (op != 4)
    {
        cout << "              CONFIGURACION                    " << endl;
        cout << endl;
        cout << "Elija la opcion que desee hacer: " << endl;
        cout << "[1] Cambiar contraseña" << endl;
        cout << "[2] Eliminar usuario" << endl;
        cout << "[3] Salir" << endl;
        cout << "Opcion elegida: ";
        cin >> op;
        if (op == 1) {
            cout << endl;
            cambiar_contra(u.nombre);
        }
        if (op == 2) {
            eliminar_usuario();
        }
        if (op == 3) {
            ofstream archivo;
            archivo.open("login.dat", ios::out | ios::binary);
            if (archivo.fail()) {
                cout << "No se pudo abrir el archivo.";
                exit(0);
            }
            for (int i = 0; i < size(vu); i++) {
                archivo.write((char*)&vu[i], sizeof(usuario));
            }
            archivo.close();
            cout << "Se cerrara el programa para aplicar los cambios.";
            exit(0);
        }
    }
}



int main()
{
    usuario u;
    ifstream archivo;
    archivo.open("login.dat", ios::in | ios::binary);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo.";
        exit(0);
    }
    archivo.read((char*)&u, sizeof(usuario));
    while (!archivo.eof()) {
        vu.push_back(u);
        archivo.read((char*)&u, sizeof(usuario));
    }
    archivo.close();


    char confi;
    int ex = 0;
    fecha f;
    cout << "Para iniciar el programa se necesita la fecha:" << endl;
    cout << "Dia: ";
    cin >> f.dia;
    cout << "Mes: ";
    cin >> f.mes;
    cout << "Anio: ";
    cin >> f.anio;

    cout << "LOG IN " << endl;
    cout << "¿Tiene usuario registrado? [s] si /[n] no ";
    cin >> confi;
    if (confi == 's') {
        cout << "NOMBRE DE USUARIO: ";
        cin >> u.nombre;
        cout << "CONTRASENIA: ";
        cin >> u.contra;
        ex = existe(u);
        while (ex == 0) {
            cout << "El usuario o la contraseña son incorrectos." << endl;
            cout << "Ingrese nuevamente" << endl;
            cout << "NOMBRE DE USUARIO: ";
            cin >> u.nombre;
            cout << "CONTRASENIA: ";
            cin >> u.contra;
            ex = existe(u);
        }
        if (ex == 1) {
            char config = 'n';
            cout << "Desea realizar algun cambio en la configuracion de usuario? [s]si/[n]no: ";
            cin >> config;
            if (config == 'n') {
                ofstream archivo;
                archivo.open("resumen_diario.txt", ios::app);
                archivo << "-----------------------" << endl;
                archivo << u.nombre << endl;
                archivo << f.dia << "/" << f.mes << "/" << f.anio << endl;
                archivo.close();
                string opc = "s";
                
                system("C:\\Users\\Alexis\\source\\repos\\PARCIAL_3\\menu_opciones\\x64\\Debug\\menu_opciones.exe");
                
            }
            else {
                configuracion(u);
            }           
        }
    }
    else {
        
        cout << "Ingrese su nombre de usuario: ";
        cin >> u.nombre;
        cout << "Ingrese su contrasenia: ";
        cin >> u.contra;
        carga(u);
    }
    cout << "----------------------------------------------------";
    return 0;
}

