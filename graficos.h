#ifndef GRAFICOS_H
#define GRAFICOS_H

#include <QMainWindow>
#include "notas.h"

namespace Ui {class Graficos;}

class Graficos : public QMainWindow
{
    Q_OBJECT

public:
    explicit Graficos(QWidget *parent = nullptr);
    ~Graficos();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Graficos *ui;
    QPixmap lienzo;
    void dibujar();
};

#endif // GRAFICOS_H
