#ifndef NOVOCADASTRO_H
#define NOVOCADASTRO_H


#include <QDialog>

namespace Ui {
class novocadastro;
}

class novocadastro : public QDialog
{
    Q_OBJECT

public:
    explicit novocadastro(QWidget *parent = nullptr,QString idd="");
    ~novocadastro();

     QString nome;
     QString idp= "0";
     int id;
     QString senhacript;
     QString numerocartao;
     int id_user;
     QString users = "0";
     QString sessionCode;
     QString p_bio = "0";
     QString idd;
     QString nasc, rg,  cpf, tel,  rua ;
     QString bair, cid, pais, email ;
     int check;
     QByteArray inByteArray;

private slots:
    void on_cadastrar_clicked();

    //void on_cartao_clicked();

    void on_escolha_activated(const QString &arg1);

    void on_novo_activated(const QString &arg1);

    void on_escolha_currentTextChanged(const QString &arg1);

    void on_cadastrar_dados_clicked();

    void on_edit_cadastro_clicked();

    void on_b_edit_foto_clicked();

    void on_b_salvar_foto_clicked();

    void on_b_foto_web_clicked();

private:
    Ui::novocadastro *ui;
    QString saltcript;
    int verifica = 1;


};

#endif // NOVOCADASTRO_H
