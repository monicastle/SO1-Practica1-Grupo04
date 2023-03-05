#include "escritor.h"
#include <QApplication>
#include <QSharedMemory>
#include <QDataStream>
#include <QDebug>
#include  <QMessageBox>
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
    a.setStyle("fusion");//estilo de ventana
    Escritor w;
    w.show();

    // Llave para la Memoria Compartida
    //const int sharedMemorySize = sizeof(Segmento);
    const QString sharedMemoryKey = "MySharedMemory";
    QSharedMemory sharedMemory(sharedMemoryKey);

    if (!sharedMemory.isAttached() && !sharedMemory.attach()) {
        qWarning("Unable to attach to shared memory segment: %s", sharedMemory.errorString().toUtf8().constData());
        return 1;
    }


    Segmento* sharedMemoryPointer = (Segmento*) sharedMemory.data();
    Segmento segment = *sharedMemoryPointer;

    qDebug("Data read to shared memory: %d, %d", segment.numEmpleados_Arreglo, segment.numMax_Empleados);

    return a.exec();
}

void Escritor::on_btn_id_clicked()
{
    QMessageBox::information(this, "Informacion","Crear nuevo id");
}


void Escritor::on_btn_mod_clicked()
{
    QMessageBox::information(this, "Informacion","Modificar");
}


void Escritor::on_btn_eliminar_clicked()
{
    QMessageBox::information(this, "Informacion","Eliminar");
}

void Escritor::on_btn_buscar_clicked()
{
    QMessageBox::information(this, "Informacion","Buscar");
}


