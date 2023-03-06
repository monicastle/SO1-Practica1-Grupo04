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

   ui->tableWidget->clearContents();
   ui->tableWidget->setRowCount(0);

   qDebug() << "PARTE 1 LA CORRE  ";

  // Open shared memory object
  shm_fd = shm_open(shm_name, O_RDONLY, 0666);
  if (shm_fd == -1) {
      perror("shm_open");
      exit(1);
  }

   qDebug() << "PARTE 2 LA CORRE  ";

  // Map shared memory object into process address space
  segment = static_cast<Segmento*>(mmap(NULL, shm_size, PROT_READ, MAP_SHARED, shm_fd, 0));
  if (segment == MAP_FAILED) {
      perror("mmap");
      exit(1);
  }

   qDebug() << "PARTE 3 LA CORRE ";
  //sem_init(&segment->mutex, 1, 1); // AQUI ME TRUENA
  qDebug() << "PARTE 4 LA CORRE ";
  //sem_init(&segment->sem_Lector, 1, 1);
  qDebug() << "PARTE 5 LA CORRE ";

  for (int i = 0; i < segment->nTotal; i++)
  {
      if(segment->empleados[i].id >= 1){
          // Update the table widget with the new data
          int fila;
          ui->tableWidget->insertRow(ui->tableWidget->rowCount());
          fila=ui->tableWidget->rowCount() - 1;
          ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(QString::number(segment->empleados[i].id)));
          ui->tableWidget->setItem(fila, NOMBRE, new QTableWidgetItem(segment->empleados[i].nombreCompleto));
          ui->tableWidget->setItem(fila, SALARIO, new QTableWidgetItem(QString::number(segment->empleados[i].sueldo)));
          ui->tableWidget->setItem(fila, EDAD, new QTableWidgetItem(QString::number(segment->empleados[i].edad)));
      }
  }

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

    //sem_destroy(&segment->mutex);
    //sem_destroy(&segment->sem_Lector);
}


void Lector::on_btn_busq_edad_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int edad_min = ui->spb_min->value(); // Valor mínimo de edad
    int edad_max = ui->spb_max->value(); // Valor máximo de edad

    bool rangoEdadesFound = false;

    for (int i = 0; i < segment->nTotal; i++) {
        if(segment->empleados[i].id >= 1){
            if (segment->empleados[i].edad >= edad_min && segment->empleados[i].edad <= edad_max) {
                int fila;
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                fila=ui->tableWidget->rowCount() - 1;
                ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(QString::number(segment->empleados[i].id)));
                ui->tableWidget->setItem(fila, NOMBRE, new QTableWidgetItem(segment->empleados[i].nombreCompleto));
                ui->tableWidget->setItem(fila, SALARIO, new QTableWidgetItem(QString::number(segment->empleados[i].sueldo)));
                ui->tableWidget->setItem(fila, EDAD, new QTableWidgetItem(QString::number(segment->empleados[i].edad)));
                rangoEdadesFound = true;
            }
        }
    }
    if(!rangoEdadesFound){
        QMessageBox::information(this, "ERROR","No hay ninguna edad que coincida con el rango de edades");
    }

    ui->spb_min->setValue(0);
    ui->spb_max->setValue(0);
    ui->txt_total->setText("");
}


void Lector::on_btn_busq_nombre_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QString nombre = ui->txt_nombre->text(); // Obtener el nombre de la entrada de texto
    QStringList palabras = nombre.split(" "); // Dividir el nombre en palabras separadas por espacios

    bool nameFound = false;

    for (int i = 0; i < segment->nTotal; i++) {
        for (int j = 0; j < palabras.size(); j++) {
            if(segment->empleados[i].id >= 1){
                if (QString(segment->empleados[i].nombreCompleto).contains(palabras[j], Qt::CaseInsensitive)) {
                    int fila;
                    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                    fila=ui->tableWidget->rowCount() - 1;
                    ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(QString::number(segment->empleados[i].id)));
                    ui->tableWidget->setItem(fila, NOMBRE, new QTableWidgetItem(segment->empleados[i].nombreCompleto));
                    ui->tableWidget->setItem(fila, SALARIO, new QTableWidgetItem(QString::number(segment->empleados[i].sueldo)));
                    ui->tableWidget->setItem(fila, EDAD, new QTableWidgetItem(QString::number(segment->empleados[i].edad)));
                    nameFound = true;
                }
            }
        }
    }

    if(!nameFound){
        QMessageBox::information(this, "ERROR","No hay ningun nombre que coincida con la busqueda");
    }
    ui->txt_nombre->setText("");
    ui->txt_total->setText("");
}


void Lector::on_btn_calcular_clicked()
{
            float totalSueldos = 0.0f;

            for (int i = 0; i < segment->nTotal; i++) {
                if(segment->empleados[i].id >= 1){
                    totalSueldos += segment->empleados[i].sueldo;
                }
            }

            ui->txt_total->setText(QString::number(totalSueldos));
}


void Lector::on_pushButton_clicked()
{

    /**sem_wait(&segment->sem_Lector);
        if (segment->nLector == 0){
            sem_wait(&segment->mutex);
        }
        segment->nLector++;
        sem_post(&segment->sem_Lector);*/

            // Resize the table widget to match the new data

            // Update the table widget with the new data
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);
            for (int i = 0; i < segment->nTotal; i++)
            {
                if(segment->empleados[i].id >= 1){
                    // Update the table widget with the new data
                    int fila;
                    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                    fila=ui->tableWidget->rowCount() - 1;
                    ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(QString::number(segment->empleados[i].id)));
                    ui->tableWidget->setItem(fila, NOMBRE, new QTableWidgetItem(segment->empleados[i].nombreCompleto));
                    ui->tableWidget->setItem(fila, SALARIO, new QTableWidgetItem(QString::number(segment->empleados[i].sueldo)));
                    ui->tableWidget->setItem(fila, EDAD, new QTableWidgetItem(QString::number(segment->empleados[i].edad)));
                }
            }
        ui->txt_total->setText("");
        /*sem_wait(&segment->sem_Lector);
        segment->nLector--;

        if (segment->nLector == 0){
            sem_post(&segment->mutex);
        }
        sem_post(&segment->sem_Lector);*/
}

