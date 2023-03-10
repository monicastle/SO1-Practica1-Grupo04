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

    shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Error al abrir o crear el archivo de memoria compartida");
        exit(1);
    }

    if (ftruncate(shm_fd, shm_size) == -1) {
        perror("Error al establecer el tamano del archivo");
        exit(1);
    }

    // Map the shared memory into this process's address space
    segment = static_cast<Segmento*>(mmap(NULL, shm_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (segment == MAP_FAILED) {
        perror("Error al realizar el mapeo del segmento");
        exit(1);
    }

    sem_init(&segment->mutex, 1, 1);
}

Escritor::~Escritor()
{
    delete ui;

    if (munmap(segment, shm_size) == -1) {
        perror("Error en el Mapeo");
        exit(1);
    }

    if (shm_unlink(shm_name) == -1) {
        perror("Error en el unlink");
        exit(1);
    }

    sem_destroy(&segment->mutex);
}

empleado_tipo Generar_Empleado();

void Escritor::on_btn_id_clicked()
{
    sem_wait(&segment->mutex);

    empleado_tipo empleadoAgregar = Generar_Empleado();

    bool existeEmpleado = false;
    bool hayPosLibre = false;

    for (int i = 0; i <= segment->nTotal; i++){
        if(segment->empleados[i].id == empleadoAgregar.id){
            existeEmpleado = true;
            break;
        }
    }

    if(!existeEmpleado){
        if(segment->numEmpleados_Arreglo < 1000){
            for (int i = 0; i < segment->nTotal; i++){
                if(segment->empleados[i].id == -1){
                    segment->empleados[i] = empleadoAgregar;
                    segment->numEmpleados_Arreglo++;
                    QMessageBox::information(this, "EXITO","??Se ha creado un nuevo empleado exitosamente 1!");
                    hayPosLibre = true;
                    break;
                }
            }

            if(!hayPosLibre){
                segment->empleados[segment->numEmpleados_Arreglo] = empleadoAgregar;
                segment->numEmpleados_Arreglo++;
                segment->nTotal++;

                QMessageBox::information(this, "EXITO","??Se ha creado un nuevo empleado exitosamente 2!");
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
        for (int i = 0; i < segment->nTotal; i++){
            if(segment->empleados[i].id == id_usuario.toInt()){
                existe = true;
                QString sueldo_empleado =ui->sdp_sueldo ->text();
                segment->empleados[i].sueldo = sueldo_empleado.toFloat();
                qDebug() << "SUELDO NUEVO: " << segment->empleados[i].sueldo;
                QMessageBox::information(this, "EXITO","??Se ha modificado al empleado exitosamente!");
            }
        }

        if(existe == false){
            QMessageBox::information(this, "ERROR","No se pudo modificar al empleado ya que el ID ingresado no existe");
        }
    } else {
        QMessageBox::information(this, "ERROR","El ID ingresado no es valido");
    }
    ui->sdp_sueldo->setValue(0);
    ui->txt_id->setText("");
    sem_post(&segment->mutex);
}


void Escritor::on_btn_eliminar_clicked()
{
    sem_wait(&segment->mutex);
    bool existe = false;

    QString id_usuario =ui->txt_id->text();
    for (int i = 0; i < segment->nTotal; i++){
        if(segment->empleados[i].id == id_usuario.toInt()){
            existe = true;
            segment->empleados[i].id = -1;
            segment->numEmpleados_Arreglo--;
            QMessageBox::information(this, "EXITO","??Se ha eliminado al empleado exitosamente!");
        }
    }

    if(existe == false){
        QMessageBox::information(this, "ERROR","No se pudo eliminar al empleado ya que el ID ingresado no existe");
    }
    ui->txt_id->setText("");
    sem_post(&segment->mutex);
}








