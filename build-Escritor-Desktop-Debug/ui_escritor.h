/********************************************************************************
** Form generated from reading UI file 'escritor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESCRITOR_H
#define UI_ESCRITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Escritor
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *txt_id;
    QPushButton *btn_buscar;
    QPushButton *btn_mod;
    QPushButton *btn_eliminar;
    QDoubleSpinBox *sdp_sueldo;
    QPushButton *btn_id;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Escritor)
    {
        if (Escritor->objectName().isEmpty())
            Escritor->setObjectName(QString::fromUtf8("Escritor"));
        Escritor->resize(611, 446);
        centralwidget = new QWidget(Escritor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -10, 611, 431));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Escritor.png")));
        label->setScaledContents(true);
        txt_id = new QLineEdit(centralwidget);
        txt_id->setObjectName(QString::fromUtf8("txt_id"));
        txt_id->setGeometry(QRect(390, 80, 151, 21));
        btn_buscar = new QPushButton(centralwidget);
        btn_buscar->setObjectName(QString::fromUtf8("btn_buscar"));
        btn_buscar->setGeometry(QRect(550, 70, 41, 31));
        btn_buscar->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Descargas/buscar(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_buscar->setIcon(icon);
        btn_buscar->setIconSize(QSize(30, 30));
        btn_mod = new QPushButton(centralwidget);
        btn_mod->setObjectName(QString::fromUtf8("btn_mod"));
        btn_mod->setGeometry(QRect(470, 200, 131, 25));
        btn_eliminar = new QPushButton(centralwidget);
        btn_eliminar->setObjectName(QString::fromUtf8("btn_eliminar"));
        btn_eliminar->setGeometry(QRect(400, 250, 131, 25));
        sdp_sueldo = new QDoubleSpinBox(centralwidget);
        sdp_sueldo->setObjectName(QString::fromUtf8("sdp_sueldo"));
        sdp_sueldo->setGeometry(QRect(390, 120, 151, 26));
        btn_id = new QPushButton(centralwidget);
        btn_id->setObjectName(QString::fromUtf8("btn_id"));
        btn_id->setGeometry(QRect(330, 200, 121, 25));
        Escritor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Escritor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 611, 22));
        Escritor->setMenuBar(menubar);
        statusbar = new QStatusBar(Escritor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Escritor->setStatusBar(statusbar);

        retranslateUi(Escritor);

        QMetaObject::connectSlotsByName(Escritor);
    } // setupUi

    void retranslateUi(QMainWindow *Escritor)
    {
        Escritor->setWindowTitle(QCoreApplication::translate("Escritor", "Escritor", nullptr));
        label->setText(QString());
        btn_buscar->setText(QString());
        btn_mod->setText(QCoreApplication::translate("Escritor", "Modificar", nullptr));
        btn_eliminar->setText(QCoreApplication::translate("Escritor", "Eliminar", nullptr));
        btn_id->setText(QCoreApplication::translate("Escritor", "Crear Nuevo ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Escritor: public Ui_Escritor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCRITOR_H
