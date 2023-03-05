#include "escritor.h"
#include "ui_escritor.h"
//#include  <qstring.h>
//#include  <QMessageBox>
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







