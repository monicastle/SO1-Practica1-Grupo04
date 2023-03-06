#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <QMainWindow>
#include "segmento.h"
#include "tipo_empleado.h"

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

    void on_btn_buscar_clicked();

private:
    Ui::Escritor *ui;
    QSharedMemory m_sharedMemory;
};
#endif // ESCRITOR_H
