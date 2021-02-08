QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acerca_de.cpp \
    estudiante.cpp \
    graficos.cpp \
    main.cpp \
    notas.cpp

HEADERS += \
    acerca_de.h \
    estudiante.h \
    graficos.h \
    notas.h

FORMS += \
    acerca_de.ui \
    graficos.ui \
    notas.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    iconos.qrc \
    traducciones.qrc

DISTFILES += \
    estudiantes.csv \
    resource/estudiante.png
