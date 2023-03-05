#include "lector.h"
#include <QApplication>
#include <QSharedMemory>
#include <QDataStream>

// Especie de clase para un Empleado
struct empleado_tipo {
    int id;
    char nombreCompleto[50];
    float sueldo;
    int edad;
};

// Segmento con la data para la Memoria Compartida
struct Segmento {
    constexpr static int numMax_Empleados = 1000;
    empleado_tipo empleados[numMax_Empleados];
    int numEmpleados_Arreglo;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion"); //estilo de ventana
    Lector w;
    w.show();

    // Llave para la Memoria Compartida
    const int sharedMemorySize = sizeof(Segmento);
    const QString sharedMemoryKey = "MySharedMemory";
    QSharedMemory sharedMemory(sharedMemoryKey);

    //
    Segmento segment;
    //segment.numEmpleados_Arreglo = sizeof(segment.empleados);
    segment.numEmpleados_Arreglo = 777;

    if (!sharedMemory.create(sharedMemorySize)) {
        qWarning("Unable to create shared memory segment: %s", sharedMemory.errorString().toUtf8().constData());
        return 1;
    }

    if (!sharedMemory.isAttached() && !sharedMemory.attach()) {
        qWarning("Unable to attach to shared memory segment: %s", sharedMemory.errorString().toUtf8().constData());
        return 1;
    }

    Segmento* sharedMemoryPointer = (Segmento*) sharedMemory.data();
    memcpy(sharedMemoryPointer, &segment, sharedMemorySize);

    qDebug("Data written to shared memory: %d, %d", segment.numEmpleados_Arreglo, segment.numMax_Empleados);

    return a.exec();
}
