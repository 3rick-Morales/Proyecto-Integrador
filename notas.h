#ifndef NOTAS_H
#define NOTAS_H

#include <QMainWindow>

#include "estudiante.h"
#include "graficos.h"
#include "acerca_de.h"
#include <cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui { class Notas; }
QT_END_NAMESPACE

class Notas : public QMainWindow
{
    Q_OBJECT

public:
    Notas(QWidget *parent = nullptr);
    ~Notas();

private slots:
    void listar();
    void guardar();
    void abrir();
    void agregar();
    void acercade();
    void guardarNotas();
    void abrirNotas();
private:
    Ui::Notas *ui;
    QList<Estudiante*> m_estudiantes;
    QList<Estudiante*> m_est;
    void limpiar();
    QString m_nombre;
    float m_n1;
    float m_n2;
    float m_promedio;
    void limp();
};
#endif // NOTAS_H
