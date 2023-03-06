#include "lector.h"
#include "ui_lector.h"
#include <QMessageBox>
#include <iostream>
#include <string>
using namespace std;
Lector::Lector(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lector)
{
    ui->setupUi(this);
    QStringList  titulos;
    setWindowTitle("Lector");
    ui->tableWidget->setColumnCount(4);
    titulos << "ID" << "Nombre" <<  "Sueldo" << "Edad";

   ui->tableWidget->setHorizontalHeaderLabels(titulos);
   ui->tableWidget->setColumnWidth(0,130);
   ui->tableWidget->setColumnWidth(0,130);
   ui->tableWidget->setColumnWidth(2,130);
   ui->tableWidget->setColumnWidth(3,130);
    m_sharedMemory.setKey("MySharedMemory");
    m_sharedMemory.attach();

}

Lector::~Lector()
{
    delete ui;
}


void Lector::on_btn_busq_edad_clicked()
{
    //QString valor_min = QString::number(ui->spb_min->value());//guardar valor min
    //QString valor_max = QString::number(ui->spb_max->value());//guardar vallor max

    int edad_min = ui->spb_min->value(); // Valor mínimo de edad
    int edad_max = ui->spb_max->value(); // Valor máximo de edad

    Segmento *segment = static_cast<Segmento*>(m_sharedMemory.data());

    for (int i = 0; i < segment->empleados.size(); i++) {
        if (segment->empleados[i].edad >= edad_min && segment->empleados[i].edad <= edad_max) {
            int fila;
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            fila=ui->tableWidget->rowCount() - 1;
            ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(segment->empleados[i].id));
            ui->tableWidget->setItem(fila, NOMBRE, new QTableWidgetItem(segment->empleados[i].nombreCompleto));
            ui->tableWidget->setItem(fila, SALARIO, new QTableWidgetItem(segment->empleados[i].sueldo));
            ui->tableWidget->setItem(fila, EDAD, new QTableWidgetItem(segment->empleados[i].edad));

        }
    }

}


void Lector::on_btn_busq_nombre_clicked()
{

   // QString nombre = ui ->txt_nombre->text();//guardar el nombre
  //  QString palabra = nombre;

    Segmento *segment = static_cast<Segmento*>(m_sharedMemory.data());

    QString nombre = ui->txt_nombre->text(); // Obtener el nombre de la entrada de texto
    QStringList palabras = nombre.split(" "); // Dividir el nombre en palabras separadas por espacios

    for (int i = 0; i < segment->empleados.size(); i++) {
        for (int j = 0; j < palabras.size(); j++) {
            if (QString(segment->empleados[i].nombreCompleto).contains(palabras[j], Qt::CaseInsensitive)) {
                int fila;
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                fila=ui->tableWidget->rowCount() - 1;
                ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(segment->empleados[i].id));
                ui->tableWidget->setItem(fila, NOMBRE, new QTableWidgetItem(segment->empleados[i].nombreCompleto));
                ui->tableWidget->setItem(fila, SALARIO, new QTableWidgetItem(segment->empleados[i].sueldo));
                ui->tableWidget->setItem(fila, EDAD, new QTableWidgetItem(segment->empleados[i].edad));
            }
        }
    }




}


void Lector::on_btn_calcular_clicked()
{
             m_sharedMemory.lock();
            // Get a pointer to the data in the shared memory
            Segmento *segment = static_cast<Segmento*>(m_sharedMemory.data());

            // Resize the table widget to match the new data

            float totalSueldos = 0.0f;

            for (int i = 0; i < segment->empleados.size(); i++) {
                totalSueldos += segment->empleados[i].sueldo;
            }

            ui->txt_total->setText(QString::number(totalSueldos));

}



void Lector::on_pushButton_clicked()
{
        m_sharedMemory.lock();
        // Get a pointer to the data in the shared memory
        Segmento *segment = static_cast<Segmento*>(m_sharedMemory.data());

        // Resize the table widget to match the new data

        // Update the table widget with the new data
        for (int i = 0; i < segment->empleados.size(); i++)
        {
            int fila;
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            fila=ui->tableWidget->rowCount() - 1;
            ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(segment->empleados[i].id));
            ui->tableWidget->setItem(fila, NOMBRE, new QTableWidgetItem(segment->empleados[i].nombreCompleto));
            ui->tableWidget->setItem(fila, SALARIO, new QTableWidgetItem(segment->empleados[i].sueldo));
            ui->tableWidget->setItem(fila, EDAD, new QTableWidgetItem(segment->empleados[i].edad));
        }

        // Detach from the shared memory
        m_sharedMemory.unlock();
}

