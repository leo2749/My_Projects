#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <mapa.h>

class Login:public QWidget {
private:
    QLabel * Usuario, *Clave;
    QLineEdit * leUsuario, * leClave;
    QPushButton * pbEntrar;
    QGridLayout * layout;
    Mapa *mapa;
private slots:
    void slot_validarUsaurio();

public:
    Login();
};
