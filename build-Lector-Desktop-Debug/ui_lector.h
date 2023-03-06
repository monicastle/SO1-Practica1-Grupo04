/********************************************************************************
** Form generated from reading UI file 'lector.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTOR_H
#define UI_LECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lector
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QSpinBox *spb_min;
    QSpinBox *spb_max;
    QLineEdit *txt_nombre;
    QPushButton *btn_busq_edad;
    QPushButton *btn_busq_nombre;
    QTableWidget *tableWidget;
    QLineEdit *txt_total;
    QPushButton *btn_calcular;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Lector)
    {
        if (Lector->objectName().isEmpty())
            Lector->setObjectName(QString::fromUtf8("Lector"));
        Lector->resize(787, 639);
        centralwidget = new QWidget(Lector);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 791, 601));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagen_grande_final.png")));
        label->setScaledContents(true);
        spb_min = new QSpinBox(centralwidget);
        spb_min->setObjectName(QString::fromUtf8("spb_min"));
        spb_min->setGeometry(QRect(180, 130, 151, 26));
        spb_max = new QSpinBox(centralwidget);
        spb_max->setObjectName(QString::fromUtf8("spb_max"));
        spb_max->setGeometry(QRect(450, 130, 171, 26));
        txt_nombre = new QLineEdit(centralwidget);
        txt_nombre->setObjectName(QString::fromUtf8("txt_nombre"));
        txt_nombre->setGeometry(QRect(180, 180, 441, 25));
        btn_busq_edad = new QPushButton(centralwidget);
        btn_busq_edad->setObjectName(QString::fromUtf8("btn_busq_edad"));
        btn_busq_edad->setGeometry(QRect(650, 130, 51, 25));
        btn_busq_edad->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Descargas/buscar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_busq_edad->setIcon(icon);
        btn_busq_edad->setIconSize(QSize(25, 25));
        btn_busq_nombre = new QPushButton(centralwidget);
        btn_busq_nombre->setObjectName(QString::fromUtf8("btn_busq_nombre"));
        btn_busq_nombre->setGeometry(QRect(650, 180, 51, 25));
        btn_busq_nombre->setStyleSheet(QString::fromUtf8("border: none;"));
        btn_busq_nombre->setIcon(icon);
        btn_busq_nombre->setIconSize(QSize(25, 25));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(60, 220, 671, 311));
        txt_total = new QLineEdit(centralwidget);
        txt_total->setObjectName(QString::fromUtf8("txt_total"));
        txt_total->setGeometry(QRect(290, 550, 231, 25));
        btn_calcular = new QPushButton(centralwidget);
        btn_calcular->setObjectName(QString::fromUtf8("btn_calcular"));
        btn_calcular->setGeometry(QRect(530, 550, 89, 25));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(740, 130, 41, 31));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/sincronizar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(28, 28));
        Lector->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Lector);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 787, 22));
        Lector->setMenuBar(menubar);
        statusbar = new QStatusBar(Lector);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Lector->setStatusBar(statusbar);

        retranslateUi(Lector);

        QMetaObject::connectSlotsByName(Lector);
    } // setupUi

    void retranslateUi(QMainWindow *Lector)
    {
        Lector->setWindowTitle(QCoreApplication::translate("Lector", "Lector", nullptr));
        label->setText(QString());
        btn_busq_edad->setText(QString());
        btn_busq_nombre->setText(QString());
        btn_calcular->setText(QCoreApplication::translate("Lector", "Calcular", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Lector: public Ui_Lector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTOR_H
