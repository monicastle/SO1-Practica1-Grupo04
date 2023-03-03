#include "lector.h"
#include "ui_lector.h"

Lector::Lector(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lector)
{
    ui->setupUi(this);
}

Lector::~Lector()
{
    delete ui;
}

