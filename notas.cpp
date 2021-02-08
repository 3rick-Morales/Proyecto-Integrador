#include "notas.h"
#include "ui_notas.h"

#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
using namespace std;

Notas::Notas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notas)
{
    ui->setupUi(this);
    connect(ui->cmdListar, SIGNAL(released()),
            this, SLOT(listar()));
    connect(ui->mnuListar, SIGNAL(triggered()),
            this, SLOT(listar()));
    connect(ui->mnuGuardar, SIGNAL(triggered()),
            this, SLOT(guardar()));
    connect(ui->mnuAbrir, SIGNAL(triggered()),
            this, SLOT(abrir()));
    connect(ui->cmdAgregar, SIGNAL(released()),
            this, SLOT(agregar()));
    connect(ui->mnuAcerca, SIGNAL(triggered()),
            this, SLOT(acercade()));
    connect(ui->cmdGuardado, SIGNAL(released()),
            this, SLOT(guardarNotas()));
    connect(ui->cmdAbierto, SIGNAL(released()),
            this, SLOT(abrirNotas()));
    connect(ui->mnuSalir, SIGNAL(triggered(bool)),
            this, SLOT(close()));
}

Notas::~Notas()
{
    delete ui;
}
void Notas::listar()
{
    m_nombre=ui->inNombre->text();
    QString resultado = m_nombre;
    if (resultado == ""){
        ui->statusbar->showMessage("No se ha ingresado un nombre para listar", 5000);
        return;
    }
    ui->outLista->appendPlainText(resultado);
    limpiar();
}

void Notas::guardar()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Guardar Datos", QDir::currentPath(), "Archivo(*.csv)");
    QFile data(fileName);
    if (data.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream salida(&data);
        salida << ui->outLista->toPlainText();
        ui->statusbar->showMessage("Datos Almacenados en: " + fileName, 5000);
    }
}

void Notas::abrir()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "Abrir datos",QDir::currentPath(), "Archivo(*.csv)");
    QFile data(filename);
    if (!data.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&data);
    while (!in.atEnd()){
        QString linea = in.readLine();
        m_estudiantes.append(new Estudiante (linea));
        ui->outLista->appendPlainText(linea);
    }
    for(int i=0; i < m_estudiantes.length(); i++){
        ui->inEstudiante->addItem(m_estudiantes.at(i)->nombre());
    }
    data.close();
}

void Notas::limpiar()
{
    ui->inNombre->setText("");
}
void Notas::limp()
{
    QString p = ui->inEstudiante->currentText();
    p = "";
    ui->inN1->setValue(0);
    ui->inN2->setValue(0);
}
void Notas::agregar()
{

    m_n1=ui->inN1->value();
    m_n2=ui->inN2->value();
    QString e  = ui->inEstudiante->currentText();
    float promedio = m_promedio;
    promedio = (m_n1+m_n2)/2;
    if (e == ""){
        ui->statusbar->showMessage("No se ha ingresado un estudiante para agregar",5000);
        return;
    }
    QString result = "Estudiante: " + e + ", ";
    result += "Nota 1: " + QString::number(m_n1) + ", ";
    result += "Nota 2: " + QString::number(m_n2)  + ", ";
    result += "Promedio: " + QString::number(promedio) + "\n";
    result += "--------------------------------------------------------------------------------------------------";
    ui->outNotas->appendPlainText(result);
    limp();

}

void Notas::acercade()
{
    Acerca_de *acerca_de = new Acerca_de(this);
    acerca_de->setModal(true);
    acerca_de->show();
}

void Notas::guardarNotas()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Guardar Datos", QDir::currentPath(), "Archivo(*.csv)");
    QFile data(fileName);
    if (data.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream salida(&data);
        salida << ui->outNotas->toPlainText();
        ui->statusbar->showMessage("Datos Almacenados en: " + fileName, 5000);
    }
}

void Notas::abrirNotas()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Abrir Datos", QDir::currentPath(), "Archivo(*.csv)");
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while (!in.atEnd()){
            QString linea = in.readAll();
            ui->outNotas->setPlainText(linea);
        }

    }
    limp();
}
/*struct nodo{
    int dato;
    struct nodo *izq, *der;
};
typedef struct nodo *ARBOL;
ARBOL crearNodo(int x){
    ARBOL nuevoNodo = new(struct nodo);
    nuevoNodo->dato = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}
void insertar(ARBOL &arbol, int x){
    if(arbol == NULL){
        arbol = crearNodo(x);
    }else if(x < arbol->dato){
        insertar(arbol->izq, x);
    }else if(x > arbol->dato){
        insertar(arbol->der, x);
    }
}
void verArbol(ARBOL &arbol, int n){
    ARBOL temporal = new(struct nodo);
    temporal = arbol;
    if(temporal == NULL){
        return;
    }
    verArbol (temporal->der, n+1);
    for(int i=0; i<n; i++){
        qDebug() << "   ";
    }
    qDebug() << temporal->dato << endl;
    verArbol(temporal->izq, n+1);
}
int main(){
    ARBOL arbol = NULL; //Crear Arbol

    int opcion;
    int valor;
    do{
        cin >> opcion;
        switch(opcion){
            case 1:
                qDebug() << "\n INSERTAR NODO EN EL ARBOL: "; cin >> valor;
                insertar( arbol, valor);
                break;
            case 2:
                qDebug() << "\n\n Ver Arbol  : \n";
                verArbol( arbol, 0);
                break;
        }
    }while (opcion != 3);
    system ("pause");
    return 0;
}*/
