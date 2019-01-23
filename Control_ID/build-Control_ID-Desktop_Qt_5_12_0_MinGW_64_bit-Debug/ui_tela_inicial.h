/********************************************************************************
** Form generated from reading UI file 'tela_inicial.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELA_INICIAL_H
#define UI_TELA_INICIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tela_inicial
{
public:
    QWidget *centralWidget;
    QTextEdit *log;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *conectar;
    QPushButton *cadastrar;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *acionar;
    QPushButton *alterar;
    QPushButton *sair;
    QPushButton *listar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *tela_inicial)
    {
        if (tela_inicial->objectName().isEmpty())
            tela_inicial->setObjectName(QString::fromUtf8("tela_inicial"));
        tela_inicial->resize(559, 215);
        tela_inicial->setMaximumSize(QSize(559, 215));
        centralWidget = new QWidget(tela_inicial);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        log = new QTextEdit(centralWidget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(10, 90, 541, 71));
        QFont font;
        font.setPointSize(10);
        log->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 221, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        conectar = new QPushButton(layoutWidget);
        conectar->setObjectName(QString::fromUtf8("conectar"));

        horizontalLayout->addWidget(conectar);

        cadastrar = new QPushButton(layoutWidget);
        cadastrar->setObjectName(QString::fromUtf8("cadastrar"));

        horizontalLayout->addWidget(cadastrar);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 10, 311, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        acionar = new QPushButton(layoutWidget1);
        acionar->setObjectName(QString::fromUtf8("acionar"));

        horizontalLayout_2->addWidget(acionar);

        alterar = new QPushButton(layoutWidget1);
        alterar->setObjectName(QString::fromUtf8("alterar"));

        horizontalLayout_2->addWidget(alterar);

        sair = new QPushButton(layoutWidget1);
        sair->setObjectName(QString::fromUtf8("sair"));

        horizontalLayout_2->addWidget(sair);

        listar = new QPushButton(centralWidget);
        listar->setObjectName(QString::fromUtf8("listar"));
        listar->setGeometry(QRect(10, 50, 107, 23));
        tela_inicial->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(tela_inicial);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 559, 21));
        tela_inicial->setMenuBar(menuBar);
        mainToolBar = new QToolBar(tela_inicial);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        tela_inicial->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(tela_inicial);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        tela_inicial->setStatusBar(statusBar);

        retranslateUi(tela_inicial);

        QMetaObject::connectSlotsByName(tela_inicial);
    } // setupUi

    void retranslateUi(QMainWindow *tela_inicial)
    {
        tela_inicial->setWindowTitle(QApplication::translate("tela_inicial", "tela_inicial", nullptr));
        conectar->setText(QApplication::translate("tela_inicial", "Conectar", nullptr));
        cadastrar->setText(QApplication::translate("tela_inicial", "Cadastrar acesso", nullptr));
        acionar->setText(QApplication::translate("tela_inicial", "Acionar Rel\303\252", nullptr));
        alterar->setText(QApplication::translate("tela_inicial", "Alterar Data / Hora", nullptr));
        sair->setText(QApplication::translate("tela_inicial", "Sair", nullptr));
        listar->setText(QApplication::translate("tela_inicial", "Clientes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tela_inicial: public Ui_tela_inicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELA_INICIAL_H
