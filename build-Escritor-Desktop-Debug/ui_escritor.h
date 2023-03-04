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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Escritor
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Escritor)
    {
        if (Escritor->objectName().isEmpty())
            Escritor->setObjectName(QString::fromUtf8("Escritor"));
        Escritor->resize(531, 404);
        centralwidget = new QWidget(Escritor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Escritor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Escritor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 531, 22));
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
    } // retranslateUi

};

namespace Ui {
    class Escritor: public Ui_Escritor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCRITOR_H
