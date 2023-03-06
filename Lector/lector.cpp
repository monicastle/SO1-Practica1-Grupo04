#include "lector.h"
#include "ui_lector.h"

Lector::Lector(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lector)
{
    ui->setupUi(this);
    setWindowTitle("Lector");

    m_sharedMemory.setKey("MySharedMemory");
    m_sharedMemory.attach();
}

Lector::~Lector()
{
    delete ui;
}


void Lector::on_btn_busq_edad_clicked()
{
    QString valor_min = QString::number(ui->spb_min->value());//guardar valor min
    QString valor_max = QString::number(ui->spb_max->value());//guaardar vallor max
}


void Lector::on_btn_busq_nombre_clicked()
{
    QString nombre = ui ->txt_nombre->text();//guuardar el nombre
}


void Lector::on_btn_calcular_clicked()
{

}

