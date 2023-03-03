#include "escritor.h"
#include "ui_escritor.h"

Escritor::Escritor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Escritor)
{
    ui->setupUi(this);
}

Escritor::~Escritor()
{
    delete ui;
}

