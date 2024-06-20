#include "login.h"
#include "admin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Admin w;
    w.iniciar();
    return a.exec();
}
