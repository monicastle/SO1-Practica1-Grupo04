#include "escritor.h"
#include "ui_escritor.h"

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


void Escritor::on_btn_buscar_clicked()//sirve para validar en caso de que se quiera modificar el sueldo que el ID sea valido
{
      QString id_usuario = ui ->txt_id->text();//guuardar el nombre
}


void Escritor::on_btn_nuevoid_clicked()
{
    //ui->btn_buscar->setText("Se ha generado un nuevo ID");
}


void Escritor::on_btn_mod_clicked()
{
   QString sueldo_user = QString::number(ui->sdp_sueldo->value());//guardar valor del sueldo
}


void Escritor::on_btn_eliminar_clicked()
{

}

