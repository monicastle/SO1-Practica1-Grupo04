#ifndef LECTOR_H
#define LECTOR_H

#include <QMainWindow>
#include "segmento.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lector; }
QT_END_NAMESPACE

class Lector : public QMainWindow
{
    Q_OBJECT

public:
    Lector(QWidget *parent = nullptr);
    ~Lector();

private slots:
    void on_btn_busq_edad_clicked();
    void on_btn_busq_nombre_clicked();
    void on_btn_calcular_clicked();
    void on_pushButton_clicked();

private:
    Ui::Lector *ui;
    QSharedMemory m_sharedMemory;

    enum columna{
        ID,NOMBRE,SALARIO,EDAD
    };
};
#endif // LECTOR_H
