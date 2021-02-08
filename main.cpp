#include "notas.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator T;
    QStringList langs;
    langs << "ESPAÑOL" << "PORTUGUESE" << "RUSO" << "FRANCES";
    const QString lang = QInputDialog::getItem(NULL, "Language", "Select lenguage", langs);
    if (lang == "Portugues"){
        T.load(":/portugues.qm");
    }else if (lang == "RUSO"){
        T.load(":/ruso.qm");
    }
    if (lang != "Español"){
        a.installTranslator(&T);
    }
    a.setStyle("fusion");
    Notas w;
    w.show();
    return a.exec();
}
