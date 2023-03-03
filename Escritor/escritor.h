#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Escritor; }
QT_END_NAMESPACE

class Escritor : public QMainWindow
{
    Q_OBJECT

public:
    Escritor(QWidget *parent = nullptr);
    ~Escritor();

private:
    Ui::Escritor *ui;
};
#endif // ESCRITOR_H
