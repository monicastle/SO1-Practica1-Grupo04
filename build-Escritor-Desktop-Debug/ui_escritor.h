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
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
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
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(390, 80, 151, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(390, 120, 151, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 70, 41, 31));
        pushButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Descargas/buscar(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(30, 30));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 200, 131, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 200, 131, 25));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(400, 250, 131, 25));
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
        pushButton->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Escritor", "Generar nuevo ID", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Escritor", "Modificar", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Escritor", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Escritor: public Ui_Escritor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCRITOR_H
