#ifndef LECTOR_H
#define LECTOR_H

#include <QMainWindow>

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

private:
    Ui::Lector *ui;
};
#endif // LECTOR_H
