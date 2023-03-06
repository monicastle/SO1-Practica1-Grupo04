#include "escritor.h"
#include "segmento.h"
#include "tipo_empleado.h"
#include <QApplication>
#include <QSharedMemory>
#include <QDataStream>
#include <iostream>
#include <fstream>
#include <QStringList>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//m_sharedMemory.setKey("MySharedMemory");
//m_sharedMemory.create(sizeof(Segmento));

//Segmento *segment = static_cast<Segmento*>(m_sharedMemory.data());

empleado_tipo Generar_Empleado();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");//estilo de ventana
    Escritor w;
    w.show();

    return a.exec();
}

empleado_tipo Generar_Empleado(){
    string nombreArchivo = "empleados.txt";
    ifstream archivoEmpleado(nombreArchivo);

    // Validacion si el archivo existe o no
    if (!archivoEmpleado.is_open()){
        cout << "Ha sucedido un error al abrir el archivo" << endl;
    } else {
        // Vector para almacenar las lineas de empleaados del archivo
        vector<string> lineasEmpleados;
        string linea;

        while (getline(archivoEmpleado, linea)){
            lineasEmpleados.push_back(linea);
        }
        archivoEmpleado.close();

        // Aleatoriamente elige a un empleado del archivo
        srand(time(0));
        int randomEmpleado = rand() % lineasEmpleados.size();

        //Tokenizamos la linea
        QString str = QString::fromStdString(lineasEmpleados[randomEmpleado]);
        QStringList tokens = str.split(",");

        // Creacion del Nuevo Empleado
        empleado_tipo nuevoEmpleado;
        nuevoEmpleado.id = tokens[0].toInt();
        QByteArray byteArray = tokens[1].toUtf8();
        strcpy(nuevoEmpleado.nombreCompleto, byteArray.constData());
        nuevoEmpleado.sueldo = tokens[2].toFloat();
        nuevoEmpleado.edad = tokens[3].toInt();

        return nuevoEmpleado;
    } // Fin If
}
