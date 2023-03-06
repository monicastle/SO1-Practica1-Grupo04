#include "escritor.h"
#include "ui_escritor.h"
#include  <qstring.h>
#include  <QMessageBox>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;


Escritor::Escritor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Escritor)
{
    ui->setupUi(this);
    setWindowTitle("Escritor");
}

Escritor::~Escritor()
{
    delete ui;
}

empleado_tipo Generar_Empleado();

void Escritor::on_btn_id_clicked()
{
    empleado_tipo empleadoAgregar = Generar_Empleado();
    Segmento *segment = static_cast<Segmento*>(m_sharedMemory.data());

    // Validacion que no pase el limite de empleados posibles
    if(segment->empleados.size() < 1000){
        m_sharedMemory.lock();
        segment->empleados.push_back(empleadoAgregar);
        segment->numEmpleados_Arreglo = segment->empleados.size();

        m_sharedMemory.unlock();

        QMessageBox::information(this, "EXITO","¡Se ha creado un nuevo empleado exitosamente!");
    } else {
        QMessageBox::information(this, "ERROR","Se ha llegado al maximo de empleados");
    }
}


void Escritor::on_btn_mod_clicked()
{
    QMessageBox::information(this, "Informacion","Modificar");
    //primero validar que el  id  sea el correcto
    QString id_usuario =ui->txt_id->text();
    //despues  tomar el valor del sueldo y actualizarlo
    QString sueldo_empleado =ui->sdp_sueldo ->text();
}


void Escritor::on_btn_eliminar_clicked()
{
    QMessageBox::information(this, "Informacion","Eliminar");
    //tomar el ID y eliminarlo
     QString id_usuario =ui->txt_id->text();
}

void Escritor::on_btn_buscar_clicked()
{
    QMessageBox::information(this, "Informacion","Buscar");
    //tomar el ID y buscarlo
    QString id_usuario =ui->txt_id->text();
}








