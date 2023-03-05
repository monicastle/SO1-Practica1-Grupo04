#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Escritor; }
QT_END_NAMESPACE

extern int id_usuario;
extern char nombre_Completo_user[50];
extern float sueldo_user;
extern int edad_user;


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
};
#endif // ESCRITOR_H
