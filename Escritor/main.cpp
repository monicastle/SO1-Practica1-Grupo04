#include "escritor.h"
#include <QApplication>
#include <QSharedMemory>
#include <QDataStream>
#include <QDebug>
#include  <QMessageBox>
#include <iostream>
using namespace std;
int numero =0;
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

string Empleados (){
    string nombres;
    if(numero%2 == 0){
        string nombresA[] = {"Skarleth", "Ana", "Bessy", "Maria", "Claudia", "Daniela", "Sofia", "Elena", "Lucia", "Fatima", "Sahory", "Monica", "Grabriela", "Helen", "Indira", "Karla", "Carmen", "Vanesa", "Laura", "Merlina", "Valeria", "Jimena", "Eva", "Paula", "Paola", "Danna", "Zoe", "Belinda", "Anahi", "Isabella" };
        string apellidos[] = {"Cano", "Herrera", "Castillo", "Mendoza", "Meraz", "Duarte", "Hernandez", "Fernandez", "Rodriguez", "Murillo", "Aguilar", "Gonsalez", "Lainez", "Cruz", "Flores", "Zepeda", "Castellano", "Lopez", "Solorzano", "Navarro", "Rivera", "Garcia", "Ramirez", "Matamoros", "Perez", "Sosa", "Torres", "Diaz", "Ortiz", "Gutierrez" };
        srand(time(0));
        int indice = rand() % 30;
        int indice1 = rand() % 30;
        int indice2 = rand() % 30;
        int indice3 = rand() % 30;
        nombres = nombresA[indice] + " " + nombresA[indice1] + " " + apellidos[indice2] + " " + apellidos[indice3];
        numero++;
    }else{
        string nombresA[] = {"Juan", "Ariel", "Pedro", "Bernardo", "Jose", "Luis", "Cesar", "Carlos", "Daniel", "Miguel", "Elvin", "Fabricio", "Jesus", "Mario", "Carlos", "Josue", "Gabriel", "Hector", "Adrian", "Andres", "Ivan", "Jonathan", "Oscar", "Ruben", "Denis", "Omar", "Angel", "Noah", "Alessio", "Santiago" };
        string apellidos[] = {"Cano", "Herrera", "Castillo", "Mendoza", "Meraz", "Duarte", "Hernandez", "Fernandez", "Rodriguez", "Murillo", "Aguilar", "Gonsalez", "Lainez", "Cruz", "Flores", "Zepeda", "Castellano", "Lopez", "Solorzano", "Navarro", "Rivera", "Garcia", "Ramirez", "Matamoros", "Perez", "Sosa", "Torres", "Diaz", "Ortiz", "Gutierrez" };
        srand(time(0));
        int indice = rand() % 30;
        int indice1 = rand() % 30;
        int indice2 = rand() % 30;
        int indice3 = rand() % 30;
        nombres = nombresA[indice] + " " + nombresA[indice1] + " " + apellidos[indice2] + " " + apellidos[indice3];
        numero++;
    }
    return nombres;
}
