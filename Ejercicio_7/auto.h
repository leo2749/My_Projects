#ifndef AUTO_H
#define AUTO_H
#include <QString>

class Auto
{


public:
    Auto();
    Auto(const QString& Marca, const QString& modelo, int antiguedad);

    QString Marca() const;
    void setMarca(const QString& Marca);

    QString Modelo() const;
    void setModelo(const QString& modelo);

    int Antiguedad() const;
    void setAntiguedad(int antiguedad);

    // Método para imprimir la información del animal
    void imprimirInformacion() const;

  private:
    QString m_Marca;
    QString m_Modelo;
    int m_Antiguedad;
};

#endif // AUTO_H
