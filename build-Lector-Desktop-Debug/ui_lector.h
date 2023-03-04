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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lector
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Lector)
    {
        if (Lector->objectName().isEmpty())
            Lector->setObjectName(QString::fromUtf8("Lector"));
        Lector->resize(548, 379);
        centralwidget = new QWidget(Lector);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 67, 17));
        Lector->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Lector);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 548, 22));
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
        label->setText(QCoreApplication::translate("Lector", "Prueba", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lector: public Ui_Lector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTOR_H
