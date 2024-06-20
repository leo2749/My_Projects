#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Hello, QLabel!");
    QWidget widget;
    QPushButton button("Hello, QPushButton!");
    QLineEdit lineEdit;

    // Muestra cada objeto de forma independiente
    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    return app.exec();
}
