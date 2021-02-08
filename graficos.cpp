#include "graficos.h"
#include "ui_graficos.h"

#include <QPainter>
#include <QPaintEvent>

Graficos::Graficos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Graficos)
{
    ui->setupUi(this);
    ui->setupUi(this);
    lienzo = QPixmap(400,600);
    lienzo.fill(Qt::white);
    this->dibujar();
}

Graficos::~Graficos()
{
    delete ui;
}

void Graficos::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);
        painter.drawPixmap(40, 40, lienzo);
        event->accept();
}

void Graficos::dibujar()
{
    QPainter painter(&lienzo);
    //Crear un pincel para los bordes
    QPen pincel;
    //int n1=ui->inNota1->value();
    int x=0;
    int y=0;

    //Cambiando propiedades del pincel
    pincel.setWidth(2);
    pincel.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pincel);

    //Crear un objeto a la barra Azul
    QColor colorRelleno( 0, 0, 0 );
    //Volver el pincel al "pintor"(borde)
    painter.setPen(pincel);
    //Creando colores para la tercera barra
    QColor cRellenoBarra3( 0, 0, 0 );
    //Establecinedo colores al pincel y al painter
    painter.setPen(pincel);
    //Dibujar Linea de medidas Y
    painter.drawLine(x+20,y+145, 20,450);
    //Dibujar Linea de medidas X
    painter.drawLine(x+20,y+450, 500,450);

    //Cordenada
        x=0;
    int metrica =150;
    for (int i=145;i<450;i+=20) {
        QString numeros= QString::number(metrica);
        metrica-=10;
        painter.drawText(x+30,i,numeros);
        painter.drawLine(x+20,i,x+25,i);
    }
     painter.drawText(90,465,"");
     painter.drawText(205,465,"");
     painter.drawText(325,465,"");
}

