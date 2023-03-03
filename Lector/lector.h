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

private:
    Ui::Lector *ui;
};
#endif // LECTOR_H
