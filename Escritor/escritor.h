#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <QMainWindow>
#include "segmento.h"
#include "tipo_empleado.h"
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Escritor; }
QT_END_NAMESPACE

class Escritor : public QMainWindow
{
    Q_OBJECT

public:
    Escritor(QWidget *parent = nullptr);

    ~Escritor();

private slots:

    void on_btn_id_clicked();

    void on_btn_mod_clicked();

    void on_btn_eliminar_clicked();

private:
    Ui::Escritor *ui;
    int shm_fd;
    Segmento* segment;
    const int shm_size = sizeof(Segmento) * 1000 + sizeof(int);
    const char* shm_name = "memoriaCompartida";
};
#endif // ESCRITOR_H
