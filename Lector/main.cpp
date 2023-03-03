#include "lector.h"

#include <QApplication>

struct empleado_tipo {
int id;
char nombreCompleto[50];
float sueldo;
int edad;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lector w;
    w.show();
    return a.exec();
}
