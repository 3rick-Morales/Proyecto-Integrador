#include "estudiante.h"

Estudiante::Estudiante(QObject *parent) : QObject(parent)
{

}

Estudiante::Estudiante(QString nombre)
{
    m_nombre = nombre;
}

Estudiante::Estudiante(QString nombre, float nota1, float nota2, float prom)
{
    m_nombre = nombre;
    m_nota1 = nota1;
    m_nota2 = nota2;
    m_prom = prom;
}

QString Estudiante::nombre() const
{
    return m_nombre;
}

float Estudiante::nota1() const
{
    return m_nota1;
}

float Estudiante::nota2() const
{
    return m_nota2;
}

float Estudiante::prom() const
{
    return m_prom;
}

