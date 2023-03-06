#include "lector.h"
#include <QApplication>
#include <QSharedMemory>
#include <QDataStream>
#include <QSystemSemaphore>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion"); //estilo de ventana
    Lector w;
    w.show();

    return a.exec();
}
