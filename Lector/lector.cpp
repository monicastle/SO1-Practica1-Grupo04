#include "lector.h"
#include "ui_lector.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <iostream>
#include <QDebug>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>

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
   ui->tableWidget->setColumnWidth(0,100);
   ui->tableWidget->setColumnWidth(1,300);
   ui->tableWidget->setColumnWidth(2,160);
   ui->tableWidget->setColumnWidth(3,100);


   // Create shared memory object
   shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
   if (shm_fd == -1) {
       perror("shm_open");
       exit(1);
   }

   // Set the size of the shared memory object
   if (ftruncate(shm_fd, shm_size) == -1) {
       perror("ftruncate");
       exit(1);
   }

   // Map the shared memory into this process's address space
   segment = static_cast<Segmento*>(mmap(NULL, shm_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
   if (segment == MAP_FAILED) {
       perror("mmap failed");
       exit(1);
   }

   sem_init(&segment->mutex, 1, 1);
   sem_init(&segment->sem_Lector, 1, 1);

}

Lector::~Lector()
{
    delete ui;

    if (munmap(segment, shm_size) == -1) {
        perror("munmap");
        exit(1);
    }

    // Unlink shared memory object
    if (shm_unlink(shm_name) == -1) {
        perror("shm_unlink");
        exit(1);
    }

    sem_destroy(&segment->mutex);
    sem_destroy(&segment->sem_Lector);
}


void Lector::on_btn_busq_edad_clicked()
{
    //QString valor_min = QString::number(ui->spb_min->value());//guardar valor min
    //QString valor_max = QString::number(ui->spb_max->value());//guardar vallor max

    int edad_min = ui->spb_min->value(); // Valor mínimo de edad
    int edad_max = ui->spb_max->value(); // Valor máximo de edad

    for (int i = 0; i < segment->numEmpleados_Arreglo; i++) {
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

    QString nombre = ui->txt_nombre->text(); // Obtener el nombre de la entrada de texto
    QStringList palabras = nombre.split(" "); // Dividir el nombre en palabras separadas por espacios

    for (int i = 0; i < segment->numEmpleados_Arreglo; i++) {
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
            // Get a pointer to the data in the shared memory

            // Resize the table widget to match the new data

            float totalSueldos = 0.0f;

            for (int i = 0; i < segment->numEmpleados_Arreglo; i++) {
                totalSueldos += segment->empleados[i].sueldo;
            }

            ui->txt_total->setText(QString::number(totalSueldos));
}



void Lector::on_pushButton_clicked()
{

        // Resize the table widget to match the new data

        // Update the table widget with the new data
        for (int i = 0; i < segment->numEmpleados_Arreglo; i++)
        {
            int fila;
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            fila=ui->tableWidget->rowCount() - 1;
            ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(segment->empleados[i].id));
            ui->tableWidget->setItem(fila, NOMBRE, new QTableWidgetItem(segment->empleados[i].nombreCompleto));
            ui->tableWidget->setItem(fila, SALARIO, new QTableWidgetItem(segment->empleados[i].sueldo));
            ui->tableWidget->setItem(fila, EDAD, new QTableWidgetItem(segment->empleados[i].edad));
        }
}

