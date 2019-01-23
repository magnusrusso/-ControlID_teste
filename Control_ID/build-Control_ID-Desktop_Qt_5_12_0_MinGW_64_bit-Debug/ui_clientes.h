/********************************************************************************
** Form generated from reading UI file 'clientes.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTES_H
#define UI_CLIENTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_clientes
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *clientes)
    {
        if (clientes->objectName().isEmpty())
            clientes->setObjectName(QString::fromUtf8("clientes"));
        clientes->resize(644, 482);
        listWidget = new QListWidget(clientes);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 641, 441));

        retranslateUi(clientes);

        QMetaObject::connectSlotsByName(clientes);
    } // setupUi

    void retranslateUi(QDialog *clientes)
    {
        clientes->setWindowTitle(QApplication::translate("clientes", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientes: public Ui_clientes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTES_H
