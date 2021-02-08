#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QObject>

class Estudiante : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nombre READ nombre)
    Q_PROPERTY(float nota1 READ nota1)
    Q_PROPERTY(float nota2 READ nota2)
public:
    explicit Estudiante(QObject *parent = nullptr);
    Estudiante(QString nombre);
    Estudiante(QString nombre, float nota1, float nota2, float prom);
    //Geters
    QString nombre() const;
    float nota1() const;
    float nota2() const;
    float prom() const;

signals:

private:
    QString m_nombre;
    float m_nota1;
    float m_nota2;
    float m_prom;
};

#endif // ESTUDIANTE_H
