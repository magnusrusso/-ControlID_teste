/********************************************************************************
** Form generated from reading UI file 'altera_hora.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTERA_HORA_H
#define UI_ALTERA_HORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_altera_hora
{
public:
    QPushButton *altera;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *dia;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *mes;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *ano;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *hora;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *minuto;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *segundo;

    void setupUi(QDialog *altera_hora)
    {
        if (altera_hora->objectName().isEmpty())
            altera_hora->setObjectName(QString::fromUtf8("altera_hora"));
        altera_hora->resize(284, 144);
        altera = new QPushButton(altera_hora);
        altera->setObjectName(QString::fromUtf8("altera"));
        altera->setGeometry(QRect(80, 110, 111, 23));
        widget = new QWidget(altera_hora);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 111, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        dia = new QSpinBox(widget);
        dia->setObjectName(QString::fromUtf8("dia"));
        dia->setMinimum(1);
        dia->setMaximum(31);

        horizontalLayout->addWidget(dia);

        widget1 = new QWidget(altera_hora);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 40, 111, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        mes = new QSpinBox(widget1);
        mes->setObjectName(QString::fromUtf8("mes"));
        mes->setMinimum(1);
        mes->setMaximum(12);

        horizontalLayout_2->addWidget(mes);

        widget2 = new QWidget(altera_hora);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(10, 70, 111, 22));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        ano = new QSpinBox(widget2);
        ano->setObjectName(QString::fromUtf8("ano"));
        ano->setMinimum(1);
        ano->setMaximum(9999);

        horizontalLayout_3->addWidget(ano);

        widget3 = new QWidget(altera_hora);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(160, 10, 111, 22));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        hora = new QSpinBox(widget3);
        hora->setObjectName(QString::fromUtf8("hora"));
        hora->setMaximum(23);

        horizontalLayout_4->addWidget(hora);

        widget4 = new QWidget(altera_hora);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(160, 40, 111, 22));
        horizontalLayout_5 = new QHBoxLayout(widget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        minuto = new QSpinBox(widget4);
        minuto->setObjectName(QString::fromUtf8("minuto"));
        minuto->setMaximum(60);

        horizontalLayout_5->addWidget(minuto);

        widget5 = new QWidget(altera_hora);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(160, 70, 111, 22));
        horizontalLayout_6 = new QHBoxLayout(widget5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        segundo = new QSpinBox(widget5);
        segundo->setObjectName(QString::fromUtf8("segundo"));
        segundo->setMaximum(60);

        horizontalLayout_6->addWidget(segundo);


        retranslateUi(altera_hora);

        QMetaObject::connectSlotsByName(altera_hora);
    } // setupUi

    void retranslateUi(QDialog *altera_hora)
    {
        altera_hora->setWindowTitle(QApplication::translate("altera_hora", "Dialog", nullptr));
        altera->setText(QApplication::translate("altera_hora", "Alterar Data / Hora", nullptr));
        label->setText(QApplication::translate("altera_hora", "Dia", nullptr));
        label_2->setText(QApplication::translate("altera_hora", "M\303\252s", nullptr));
        label_3->setText(QApplication::translate("altera_hora", "Ano", nullptr));
        label_4->setText(QApplication::translate("altera_hora", "Hora", nullptr));
        label_5->setText(QApplication::translate("altera_hora", "Minuto", nullptr));
        label_6->setText(QApplication::translate("altera_hora", "Segundo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class altera_hora: public Ui_altera_hora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERA_HORA_H
