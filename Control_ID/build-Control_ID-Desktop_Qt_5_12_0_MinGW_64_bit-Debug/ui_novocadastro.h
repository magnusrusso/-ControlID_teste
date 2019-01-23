/********************************************************************************
** Form generated from reading UI file 'novocadastro.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVOCADASTRO_H
#define UI_NOVOCADASTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_novocadastro
{
public:
    QPushButton *cadastrar;
    QComboBox *escolha;
    QFrame *line;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nome;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *senha;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLineEdit *id;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *l_id;
    QLineEdit *txtid;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *l_numero;
    QLineEdit *txtcartao;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *l_user;
    QLineEdit *txtuser;
    QComboBox *novo;
    QLabel *l_bio;
    QLineEdit *user_bio;

    void setupUi(QDialog *novocadastro)
    {
        if (novocadastro->objectName().isEmpty())
            novocadastro->setObjectName(QString::fromUtf8("novocadastro"));
        novocadastro->resize(289, 199);
        cadastrar = new QPushButton(novocadastro);
        cadastrar->setObjectName(QString::fromUtf8("cadastrar"));
        cadastrar->setGeometry(QRect(210, 70, 75, 23));
        escolha = new QComboBox(novocadastro);
        escolha->addItem(QString());
        escolha->addItem(QString());
        escolha->addItem(QString());
        escolha->setObjectName(QString::fromUtf8("escolha"));
        escolha->setGeometry(QRect(210, 10, 69, 22));
        line = new QFrame(novocadastro);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(40, 90, 211, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(novocadastro);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 171, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        nome = new QLineEdit(layoutWidget);
        nome->setObjectName(QString::fromUtf8("nome"));

        horizontalLayout->addWidget(nome);

        layoutWidget1 = new QWidget(novocadastro);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 70, 171, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        senha = new QLineEdit(layoutWidget1);
        senha->setObjectName(QString::fromUtf8("senha"));
        senha->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(senha);

        layoutWidget2 = new QWidget(novocadastro);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 122, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        id = new QLineEdit(layoutWidget2);
        id->setObjectName(QString::fromUtf8("id"));

        horizontalLayout_3->addWidget(id);

        layoutWidget3 = new QWidget(novocadastro);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 110, 151, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        l_id = new QLabel(layoutWidget3);
        l_id->setObjectName(QString::fromUtf8("l_id"));
        l_id->setFont(font);

        horizontalLayout_4->addWidget(l_id);

        txtid = new QLineEdit(layoutWidget3);
        txtid->setObjectName(QString::fromUtf8("txtid"));

        horizontalLayout_4->addWidget(txtid);

        layoutWidget4 = new QWidget(novocadastro);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 140, 221, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        l_numero = new QLabel(layoutWidget4);
        l_numero->setObjectName(QString::fromUtf8("l_numero"));
        l_numero->setFont(font);

        horizontalLayout_5->addWidget(l_numero);

        txtcartao = new QLineEdit(layoutWidget4);
        txtcartao->setObjectName(QString::fromUtf8("txtcartao"));

        horizontalLayout_5->addWidget(txtcartao);

        layoutWidget5 = new QWidget(novocadastro);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 170, 221, 22));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        l_user = new QLabel(layoutWidget5);
        l_user->setObjectName(QString::fromUtf8("l_user"));
        l_user->setFont(font);

        horizontalLayout_6->addWidget(l_user);

        txtuser = new QLineEdit(layoutWidget5);
        txtuser->setObjectName(QString::fromUtf8("txtuser"));

        horizontalLayout_6->addWidget(txtuser);

        novo = new QComboBox(novocadastro);
        novo->addItem(QString());
        novo->addItem(QString());
        novo->setObjectName(QString::fromUtf8("novo"));
        novo->setGeometry(QRect(210, 40, 69, 22));
        l_bio = new QLabel(novocadastro);
        l_bio->setObjectName(QString::fromUtf8("l_bio"));
        l_bio->setGeometry(QRect(10, 110, 88, 20));
        l_bio->setFont(font);
        user_bio = new QLineEdit(novocadastro);
        user_bio->setObjectName(QString::fromUtf8("user_bio"));
        user_bio->setGeometry(QRect(100, 110, 51, 20));

        retranslateUi(novocadastro);

        QMetaObject::connectSlotsByName(novocadastro);
    } // setupUi

    void retranslateUi(QDialog *novocadastro)
    {
        novocadastro->setWindowTitle(QApplication::translate("novocadastro", "Dialog", nullptr));
        cadastrar->setText(QApplication::translate("novocadastro", "Cadastrar", nullptr));
        escolha->setItemText(0, QApplication::translate("novocadastro", "Senha", nullptr));
        escolha->setItemText(1, QApplication::translate("novocadastro", "Cart\303\243o", nullptr));
        escolha->setItemText(2, QApplication::translate("novocadastro", "Biometria", nullptr));

        label->setText(QApplication::translate("novocadastro", "Nome", nullptr));
        label_2->setText(QApplication::translate("novocadastro", "Senha", nullptr));
        label_3->setText(QApplication::translate("novocadastro", "Id", nullptr));
        l_id->setText(QApplication::translate("novocadastro", "Id do Cart\303\243o", nullptr));
        l_numero->setText(QApplication::translate("novocadastro", "Numero Cart\303\243o", nullptr));
        l_user->setText(QApplication::translate("novocadastro", "Id do Usu\303\241rio", nullptr));
        novo->setItemText(0, QApplication::translate("novocadastro", "Novo ", nullptr));
        novo->setItemText(1, QApplication::translate("novocadastro", "Existente", nullptr));

        l_bio->setText(QApplication::translate("novocadastro", "Id do Usu\303\241rio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class novocadastro: public Ui_novocadastro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVOCADASTRO_H
