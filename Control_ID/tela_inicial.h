#ifndef TELA_INICIAL_H
#define TELA_INICIAL_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class tela_inicial;

}

class tela_inicial : public QMainWindow
{
    Q_OBJECT

public:
    explicit tela_inicial(QWidget *parent = nullptr);
    ~tela_inicial();
    int contador;
    Ui::tela_inicial *ui ;
    QString idd;


private slots:
    void on_sair_clicked();

    void on_conectar_clicked();

    void on_acionar_clicked();

    void on_alterar_clicked();

    void on_cadastrar_clicked();

    void on_listar_clicked();

    void on_visual_qtb_cellDoubleClicked();

    void on_atualiza_clicked();

private:
    QString sessionCode;

    //- data (mes)
    int mes ;

};

#endif // TELA_INICIAL_H
