#include "escritor.h"
#include "ui_escritor.h"
#include <qstring.h>
#include <QMessageBox>
#include <string>
#include <cstring>
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


Escritor::Escritor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Escritor)
{
    ui->setupUi(this);
    setWindowTitle("Escritor");

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
}

Escritor::~Escritor()
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
}

empleado_tipo Generar_Empleado();

void Escritor::on_btn_id_clicked()
{
    sem_wait(&segment->mutex);

    empleado_tipo empleadoAgregar = Generar_Empleado();

    qDebug() << "TAM INICIAL ARREGLO: " << segment->numEmpleados_Arreglo;

    bool existeEmpleado = false;
    bool hayPosLibre = false;

    for (int i = 0; i <= segment->numMax_Empleados; i++){
        if(segment->empleados[i].id == empleadoAgregar.id){
            existeEmpleado = true;
            break;
        }
    }

    if(!existeEmpleado){
        if(segment->numEmpleados_Arreglo < 1000){
            for (int i = 0; i < segment->numMax_Empleados; i++){
                if(segment->empleados[i].id == -1){
                    segment->empleados[segment->numEmpleados_Arreglo] = empleadoAgregar;
                    segment->numEmpleados_Arreglo++;
                    QMessageBox::information(this, "EXITO","¡Se ha creado un nuevo empleado exitosamente!");
                    qDebug() << "tam arreglo: " << segment->numEmpleados_Arreglo;
                    qDebug() << "ID: " << segment->empleados[segment->numEmpleados_Arreglo].id;
                    qDebug() << "NAME: " << segment->empleados[segment->numEmpleados_Arreglo].nombreCompleto;
                    qDebug() << "SUELDO: " << segment->empleados[segment->numEmpleados_Arreglo].sueldo;
                    qDebug() << "EDAD: " << segment->empleados[segment->numEmpleados_Arreglo].edad;
                    hayPosLibre = true;
                    break;
                }
            }

            if(!hayPosLibre){
                segment->numEmpleados_Arreglo++;
                segment->empleados[segment->numEmpleados_Arreglo] = empleadoAgregar;

                QMessageBox::information(this, "EXITO","¡Se ha creado un nuevo empleado exitosamente!");
                qDebug() << "tam arreglo: " << segment->numEmpleados_Arreglo;
                qDebug() << "ID: " << segment->empleados[segment->numEmpleados_Arreglo].id;
                qDebug() << "NAME: " << segment->empleados[segment->numEmpleados_Arreglo].nombreCompleto;
                qDebug() << "SUELDO: " << segment->empleados[segment->numEmpleados_Arreglo].sueldo;
                qDebug() << "EDAD: " << segment->empleados[segment->numEmpleados_Arreglo].edad;
            }

        } else {
            QMessageBox::information(this, "ERROR","Se ha llegado al maximo de empleados");
        }
    } else {
        QMessageBox::information(this, "ERROR","El id del empleado ya existe");
    }
    sem_post(&segment->mutex);
}


void Escritor::on_btn_mod_clicked()
{
    sem_wait(&segment->mutex);
    bool existe = false;

    QString id_usuario =ui->txt_id->text();
    if(id_usuario.toInt() >=  1){
        for (int i = 0; i < segment->numMax_Empleados; i++){
            if(segment->empleados[i].id == id_usuario.toInt()){
                existe = true;
                QString sueldo_empleado =ui->sdp_sueldo ->text();
                segment->empleados[i].sueldo = sueldo_empleado.toFloat();
                qDebug() << "SUELDO NUEVO: " << segment->empleados[i].sueldo;
                QMessageBox::information(this, "EXITO","¡Se ha modificado al empleado exitosamente!");
            }
        }

        if(existe == false){
            QMessageBox::information(this, "ERROR","No se pudo modificar al empleado ya que el ID ingresado no existe");
        }
    } else {
        QMessageBox::information(this, "ERROR","El ID ingresado no es valido");
    }
    sem_post(&segment->mutex);
}


void Escritor::on_btn_eliminar_clicked()
{
    bool existe = false;

    QString id_usuario =ui->txt_id->text();
    for (int i = 0; i < segment->numEmpleados_Arreglo; i++){
        if(segment->empleados[i].id == id_usuario.toInt()){
            existe = true;
            segment->empleados[i].id = -1;
            segment->numEmpleados_Arreglo--;
            QMessageBox::information(this, "EXITO","¡Se ha eliminado al empleado exitosamente!");
            qDebug() << "tam arreglo: " << segment->numEmpleados_Arreglo;
        }
    }

    if(existe == false){
        QMessageBox::information(this, "ERROR","No se pudo eliminar al empleado ya que el ID ingresado no existe");
    }
    shmdt(segment);
}








