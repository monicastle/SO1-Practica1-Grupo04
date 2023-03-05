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

 string Empleados ();

void Escritor::on_btn_id_clicked()
{
      QMessageBox::information(this, "Informacion","Crear nuevo id");
    //aqui  deberia de llamar el metodo que crea un nuevo empleado
       cout<<Empleados ()<<endl;
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
    //tomar el ID y buuscarlo
    QString id_usuario =ui->txt_id->text();
}








