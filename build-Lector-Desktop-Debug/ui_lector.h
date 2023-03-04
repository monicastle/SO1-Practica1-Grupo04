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
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Lector)
    {
        if (Lector->objectName().isEmpty())
            Lector->setObjectName(QString::fromUtf8("Lector"));
        Lector->resize(599, 510);
        centralwidget = new QWidget(Lector);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 601, 491));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Lector.png")));
        label->setScaledContents(true);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(170, 120, 71, 26));
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(390, 120, 71, 26));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 170, 291, 25));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 120, 51, 25));
        pushButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Descargas/buscar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 170, 51, 25));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;"));
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(25, 25));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(50, 210, 501, 211));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 440, 231, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(440, 440, 89, 25));
        Lector->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Lector);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 599, 22));
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
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("Lector", "Calcular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lector: public Ui_Lector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTOR_H
