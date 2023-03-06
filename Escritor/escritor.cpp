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

    pid_t pid = getpid(); // get process ID
    sprintf(shm_name, "/my_shm_%d", pid);

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

    // SEMAPHORES
    // Create a named semaphore for synchronization
        /*sem_ptr = sem_open("/semaphoreArchivo", O_CREAT | O_EXCL, 0666, 1);
        if (sem_ptr == SEM_FAILED) {
            perror("sem_open");
            exit(1);
        }*/
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

    // Close and unlink the semaphore
        /*if (sem_close(sem_ptr) == -1) {
            perror("sem_close");
            exit(1);
        }
        if (sem_unlink("/semaphoreArchivo") == -1) {
            perror("sem_unlink");
            exit(1);
        }*/
}

empleado_tipo Generar_Empleado();

void Escritor::on_btn_id_clicked()
{
    // Wait for the semaphore to become available
            /*if (sem_wait(sem_ptr) == -1) {
                perror("sem_wait");
                exit(1);
            }*/

    empleado_tipo empleadoAgregar = Generar_Empleado();
        qDebug() << "MEHHHHHHHHHHH: ";

    // Validacion que no pase el limite de empleados posibles
    if(segment->empleados.size() < 1000){
        qDebug() << "NO ENTRA ESTA VAINA";
        segment->empleados.push_back(empleadoAgregar);
        segment->numEmpleados_Arreglo = segment->empleados.size();

        QMessageBox::information(this, "EXITO","¡Se ha creado un nuevo empleado exitosamente!");
        qDebug() << "EMPLEADO CREADO: " << segment->empleados.size();
    } else {
        QMessageBox::information(this, "ERROR","Se ha llegado al maximo de empleados");
    }
    // Release the semaphore
           /* if (sem_post(sem_ptr) == -1) {
                perror("sem_post");
                exit(1);
            } */

}


void Escritor::on_btn_mod_clicked()
{
    bool existe = false;

    QString id_usuario =ui->txt_id->text();
    for (int i = 0; i < segment->empleados.size(); i++){
        if(segment->empleados[i].id == id_usuario){
            existe = true;
            QString sueldo_empleado =ui->sdp_sueldo ->text();
            segment->empleados[i].sueldo = sueldo_empleado.toFloat();
            QMessageBox::information(this, "EXITO","¡Se ha modificado al empleado exitosamente!");
        }
    }

    if(existe == false){
        QMessageBox::information(this, "ERROR","No se pudo modificar al empleado ya que el ID ingresado no existe");
    }
    shmdt(segment);
}


void Escritor::on_btn_eliminar_clicked()
{
    bool existe = false;

    QString id_usuario =ui->txt_id->text();
    for (int i = 0; i < segment->empleados.size(); i++){
        if(segment->empleados[i].id == id_usuario){
            existe = true;
            segment->empleados.erase(segment->empleados.begin() + i);
            segment->numEmpleados_Arreglo = segment->empleados.size();
            QMessageBox::information(this, "EXITO","¡Se ha eliminado al empleado exitosamente!");
        }
    }

    if(existe == false){
        QMessageBox::information(this, "ERROR","No se pudo eliminar al empleado ya que el ID ingresado no existe");
    }
    shmdt(segment);
}








